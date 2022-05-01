// Code of ShenZhou
// /d/zhongnan/obj/qz_force.c 玄门内功心法
/*
        修正内力计算方法
        修正使用者躲于safe room使用避免使者的不当之使用方式
        修正使用者在坐骑上修炼内力亦可行动之BUG
        mantian /may/1/2001
*/


inherit ITEM;
string *koujue = ({
                                         "《修真活计有何凭，心死群情今不生》",
                                         "《精气充盈功行具，灵光照耀满神京》",
                                         "《秘语师传悟本初，来时无久去无馀》",
                                         "《历年尘垢揩磨尽，偏体灵明耀太虚》"
});

int do_dazuo(string arg);
int exercising(object me);
int halt_exercise(object me);


void setup()
{}

/*
void init()
{
        add_action("do_dazuo", "lianqi");
}
*/

void create()
{
        set_name("玄门内功心法", ({ "neigong xinfa", "xinfa" }));
        set_weight(600);
        /*if( clonep() )
        set_default_object(__FILE__);
        else*/
        {
                set("unit", "本");
                set("long", "这是一本线装书，上书《玄门内功心法》，原来是全真教的练气(lianqi)秘籍。\n");
                set("value", 5000);
                set("material", "paper");
                set("skill", ([
                        "name":                        "force",        // name of the skill
                        "exp_required":        0,                        // minimum combat experience required
                        "jing_cost":        30,                        // jing cost every time study this
                        "difficulty":        10,                        // the base int to learn this skill
                        "max_skill":        150                        // the maximum level you can learn
                        ]) );
        }
}

int do_dazuo(string arg)
{
        object me = this_player();
        int exercise_cost;
        object where;

        seteuid(getuid());
        where = environment(me);

        if (!present("neigong xinfa", me))
                return 0;

        if( query("pigging", where) )
                return notify_fail("你还是专心拱猪吧！\n");

        if( query("sleep_room", where) )
                return notify_fail("不能在睡房里修炼内功，这会影响他人。\n");

        if( query("no_fight", where) )
                return notify_fail("你不能集中精神，只感体内真气乱窜，无法专心修练内功。\n");

        if( query("name", where) == "大车里" )
                return notify_fail("车里太颠簸, 修练内功会走火入魔. \n");

        if( me->is_busy() || query_temp("pending/exercising", me) )
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能练内功，会走火入魔。\n");

        if( query("rided", me) )
                return notify_fail("在坐骑上修练内功，会走火入魔。\n");

        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

        if( !arg || !sscanf(arg, "%d", exercise_cost))
                return notify_fail("你要花多少气练功？\n");
        if (exercise_cost < 10)
                return notify_fail("你的内功还没有达到那个境界！\n");

        if( query("qi", me)<exercise_cost )
                return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

        if( query("jing", me)*100/query("max_jing", me)<70 )
                return notify_fail("你现在精不够，无法控制内息的流动！\n");

        write("你按着玄门内功心法的气诀坐下来运气用功，一股内息开始在体内流动。\n");

        set_temp("pending/exercise", 1, me);
        set_temp("exercise_cost", exercise_cost, me);
        message_vision("$N盘膝坐下，开始修炼内力。\n", me);
        me->start_busy((: exercising :), (:halt_exercise:));
        return 1;
}

int exercising(object me)
{
        int cost;
        object  where = environment(me);
        int exercise_cost=query_temp("exercise_cost", me);
         int neili_gain = 1 + (int)me->query_skill("force") / 2.5;
        if (exercise_cost < 1)
                return 0;
        addn("neili", neili_gain, me);
        set_temp("exercise_cost", exercise_cost-=neili_gain, me);

        //me->addn("qi", -neili_gain);
        cost = neili_gain*3/2;
        if( base_name(where) == "/d/quanzhen/yangxin" )
                cost = cost/3*2;

        if( me->query_skill_mapped("force") == "xiantian-gong" )
        {
                write("你默念着"+koujue[random(4)]+"，只觉得一股内息在体内迅速流动，全身都感到舒畅无比。\n");

                me->receive_damage("qi", cost);
                me->receive_damage("jing", cost/10);
                set_temp("die_reason", "打坐走火入魔死了", me);
        }
        else
        {
                if( random(6)==3 )
                {
                        if(me->query_skill_mapped("force") == "bitao-xuangong")
                        {
                                write("你默念着"+koujue[random(4)]+"，只觉得一股内息在体内窜来窜去，让你觉得不对劲，难道是走火入魔的前兆？\n");
                                cost = neili_gain + random(neili_gain*100);
                        }
                        else
                        {
                                write("你默念着"+koujue[random(4)]+"，只觉得一股内息在体内窜来窜去，让你觉得不对劲。\n");
                                cost = neili_gain + random(neili_gain*10);
                                me->receive_damage("qi", cost);
                                set_temp("die_reason", "打坐走火入魔死了", me);
                        }
                        }
                        else
                        {
                        write("你念着"+koujue[random(4)]+"，似乎有点体会，只觉得一股内息在体内迅速流动，全身都感到舒畅无比。\n");

                        me->receive_damage("qi", cost, "打坐走火入魔死了");
                        me->receive_damage("jing", cost/10, "打坐走火入魔死了");
                        }

                }
        if (exercise_cost > 0)
                return 1;

        set_temp("pending/exercise", 0, me);
        message_vision("$N运功完毕，深深吸了口气，站了起来。\n", me);
        if( query("neili", me)<query("max_neili", me)*2 )
                 return 0;
        else
        {
                if( query("max_neili", me)>me->query_skill("force")*query("con", me)*2/3 )
                {
                        write("你的内力修为似乎已经达到了瓶颈。\n");
                        set("neili",query("max_neili",  me), me);
                        return 0;
                }
                else
                {
                        addn("max_neili", 1, me);
                        set("neili",query("max_neili",  me), me);
                        write("你的内力增加了！！\n");
                        return 0;
                }
        }
}

int halt_exercise(object me)
{
        if( query("neili", me)>query("max_neili", me)*2 )
                set("neili",query("max_neili",  me)*2, me);
                set_temp("pending/exercise", 0, me);
                return 1;
}