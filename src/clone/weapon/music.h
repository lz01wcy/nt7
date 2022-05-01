// Code of ShenZhou
//music.h 乐器
#include <ansi.h>

int do_lianxi(string arg)
{
        string msg;
        object ob, me, where, weapon;
        int cost;

        string* zither_msg = ({
        "轮指","琐","滚拂","拨刺","进退","吟猱","绰注",
        "两引上","罨","带起","撮指","打圆","抹挑","勾剔",
        });

        string* flute_msg = ({
        "颤指", "吐音", "历音","花舌音", "飞指颤音",
        });

        me = this_player();
        where = environment(me);
        weapon=query_temp("weapon", me);
        if( query("pigging", where) )
                return notify_fail("你还是专心拱猪吧！\n");

        if( query("sleep_room", where) )
                return notify_fail("在睡房里不能练习演奏乐器，这会影响他人。\n");

        if( query("no_fight", where) )
                return notify_fail("这里不适合练习演奏乐器。\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("你无法在战斗中专心下来练习演奏！\n");

        if(!arg || !objectp(ob = present(arg, me)) )
                return notify_fail("你要练习演奏什么？\n");

        if( !query("shape", ob) || 
        (query("shape", ob) != "flute" && query("shape", ob) != "zither") )
                return notify_fail("你不能练习演奏"+ob->name()+"。\n");

        if( ob != weapon )
                return notify_fail("你必需先装备"+ob->name()+"。\n");

        if( (int)me->query_skill("music", 1) < 10 ) {
                if( query("shape", ob) == "zither" )
                message_vision("$N手抚$n，弹了几下，所成调子严重走音。\n"NOR, me, ob);
                if( query("shape", ob) == "flute" )
                message_vision("$N将$n放在唇边一吹，结果发出一阵五音不全的声响。\n"NOR, me, ob);
                return 1;
        }

        if( query("potential", me)<1 )
                return notify_fail("你的潜能已达极限，没有办法领悟更精妙的乐理。\n");


        cost=50+random(40)*(40-query("int", me))/20;
        if (cost < 10) cost = 10; // minimum cost

        if( query("jing", me)>cost){
                if( query("shape", ob) == "zither"){
                msg = zither_msg[random(sizeof(zither_msg))] ;
                message_vision("$N手抚$n，反覆练习著「"+msg+"」的技巧。\n"NOR, me, ob);
                if( query("family/family_name", me) == "桃花岛" && me->query_skill("music",1)<333 )
                me->improve_skill("music", me->query_int()*2 + 1);
                }
                else if( query("shape", ob) == "flute"){
                msg = flute_msg[random(sizeof(flute_msg))] ;
                message_vision("$N手按$n，徐徐吹奏，专心练习著「"+msg+"」的技巧。\n"NOR, me, ob);
                if( query("family/family_name", me) == "桃花岛" && me->query_skill("music",1)<333 )
                me->improve_skill("music", me->query_int()*2 + 1);

                }
                else return notify_fail("你左看看，右看看，实在不知道该怎麽演奏"+ob->name()+"。\n");
                }
        else {
                cost=query("jing", me);
                if (cost < 0) cost = 0;
                write("你现在过于疲倦，无法专心下来练习演奏乐器。\n");
                return 1;
        }

        me->receive_damage("jing", cost/2, "心力绞瘁死了");
        addn("jingli", -cost/4, me);
        if( random(3) == 0)addn("potential", -random(2), me);
        return 1;
}