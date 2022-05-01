// Room: /d/xingxiu/jushi.c
// Last Modified by Lonely on Apr. 25 2001

#include <ansi.h>
inherit ROOM;
int xxdazuo(object me);
int halt_xxdazuo(object me);
void create()
{
        set("short", HIB"巨石"NOR);
        set("long", @LONG
你落脚在一块黑褐色的巨石上。你身在半空，向下一望，不由得头晕目眩。
因此只好远望对面山色。一阵山风吹来，令人心旷神怡，你才顿时发觉此乃练
功(liangong)一佳地。
LONG
        );
        set("exits", ([
                "down" : __DIR__"xiaolu",
        ]));
        set("outdoors", "xingxiu");
        set("coor/x", -49900);
        set("coor/y", 20200);
        set("coor/z", 100);
        setup();
}

void init()
{
        object me = this_player();
        object ob = this_object();
        object        *inv = all_inventory( ob );
        
        if( query("family/family_name", me) != "星宿派" && !wizardp(me) )
                for ( int i = 0; i < sizeof(inv); i++ )
                        if( (userp(inv[i]) && inv[i] != me && !wizardp(inv[i])) || time()-query_temp("LAST_PKER_TIME", me)<7200 )
                        {        
                                write( WHT"你爬上巨石，却发现上面已无容身之处，只好悻悻的退了下来。\n"NOR );
                                me->move( __DIR__"xiaolu" );
                                return;
                        }

        add_action("do_xxdazuo", "liangong");
}

int do_xxdazuo(string arg)
{     
        int xxdazuo_cost;
        mapping fam;
        object me;
        me = this_player();   
        fam=query("family", this_player());

//        if (!fam || fam["family_name"] != "星宿派")
//               return notify_fail("你偷上星宿派禁地，还敢在这里打坐？\n");
    
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( query("max_qi", me)<400 )
                return notify_fail("你现在的气太少了，无法在此练功。\n");

        if(me->query_skill("force") < 100 )
                return notify_fail("你的内功根基还不够，在此练功有害无益。\n");

        if( !stringp(me->query_skill_mapped("force")) )
        return notify_fail("你必须先用 enable 选择你要用的特殊内功。\n");

              if( (me->query_skill("force")*8+query("combat_exp", me)/1000) <= query("max_neili", me) )
              return notify_fail("这里已经无助于你的修为了。\n");

        if( !arg || !sscanf(arg, "%d", xxdazuo_cost))
                return notify_fail("你要花多少气练功？\n");
        if (xxdazuo_cost < 10)
        return notify_fail("你无法控制内息运行到如此精细的程度！\n");

        if( query("qi", me)<xxdazuo_cost )
                return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

        if( query("jing", me)*100/query("max_jing", me)<70 )
                return notify_fail("你现在精不够，无法控制内息的流动！\n");

        message_vision("$N盘膝坐下运功，身体渐渐被一股青烟所包围。\n",me); 
        write(BLU"你坐在巨石上，运动丹田内劲，你感觉到在山风的压迫下体内的内劲开始有所加强了。\n"NOR);

        set_temp("pending/xxdazuo", 1, me);
        set_temp("xxdazuo_cost", xxdazuo_cost, me);
        me->start_busy((: xxdazuo :), (:halt_xxdazuo:));
        return 1;
}

int xxdazuo(object me)
{
        int xxdazuo_cost=query_temp("xxdazuo_cost", me);
        int neili_gain = 1 + (int)me->query_skill("force") / 10
                * (1 + (int)me->query_skill("force") / 300);    

        if (neili_gain > xxdazuo_cost) neili_gain = xxdazuo_cost;
        neili_gain = neili_gain + random(neili_gain) / 2;
        addn("neili", neili_gain, me);
        set_temp("xxdazuo_cost", xxdazuo_cost-=neili_gain, me);
        me->receive_damage("qi", neili_gain);

        if (xxdazuo_cost > 0) return 1;

        delete_temp("pending/exercise", me);
        delete_temp("pending/xxdazuo", me);
        message_vision("山风渐渐加强，$N终于忍耐不住，双眼一睁，站了起来。\n", me);    
//        me->improve_skill("huagong-dafa", 1);
        if ((int)me->query_skill("force",1)<150)
            me->improve_skill("force", 1); 
        if( query("neili", me)<query("max_neili", me)*2 )
                return 0;
     if( (me->query_skill("force")*8+query("combat_exp", me)/1000) <= query("max_neili", me)){
                write("你的内力修为已经达到了此地所能帮助你的极限。\n"); 
                set("neili",query("max_neili",  me), me);
                return 0;
        }
        addn("max_neili", 1, me);
        set("neili",query("max_neili",  me), me);
        write("你的内力修为增加了！！\n");   
        return 0;
}



int halt_xxdazuo(object me)
{
        if( query("neili", me)>(query("max_neili", me)*2) )
        {
                message_vision("$N强压住内息，双眼一睁，站了起来。\n", me); 
                set("neili", (query("max_neili", me)*2), me);
        }
        delete_temp("pending/xxdazuo", me);
        return 1;
}
