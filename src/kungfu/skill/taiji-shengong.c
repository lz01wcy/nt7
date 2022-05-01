// taiji-shengong.c 太极神功

#include <ansi.h>;

inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }
int valid_force(string force) { return 1; }

int query_neili_improve(object me)
{
        int lvl;
        lvl = (int)me->query_skill("taiji-shengong", 1);
        return lvl * lvl * 22 * 15 / 100 / 200;
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("taiji-shengong", 1);


        if( query("gender", me) == "无性" && lvl>49 )
                return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");

        if( query("class", me) == "bonze" )
                return notify_fail("太极神功讲究阴阳调合，有违佛家六根清净之意，"
                        + RANK_D->query_respect(me) + "欲修此功，已是罪过。\n");

        if( lvl>10 && query("shen", me)<lvl*100
             && me->query_skill("taoism", 1) < 100)
                return notify_fail("你的侠义正气太低了。\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"taiji-shengong/" + func;
}

int help(object me)
{
        write(HIC"\n太极神功："NOR"\n");
        write(@HELP

    太极神功乃武当不传之秘，讲究「冲」、「虚」、「圆」、「
通」，是修习武当派各种高深武功的根基。武当弟子配合太极神功
和道学心法可以养精练气，有延年益寿之功效。

        学习要求：
                和尚不能学
                太监无法领悟50级以上的太极神功
                基本内功10级
                相应的正气
HELP
        );
        return 1;
}
