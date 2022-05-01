// shenxing-baibian.c 神行百变
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

int is_pbsk() { return 1; }

string *dodge_msg = ({
"$n一式"HIC"「行云流水」"NOR"，身不倾，脚不移，身体如行云流水般直滑出丈余。\n",
"$n一式"BLU"「潜音夜行」"NOR"，忽然一弯腰，全身贴地而行，顿时闪过了$N的凌厉攻势。\n",
"$n一式"HIW"「移步换形」"NOR"，足不动，手不抬，一转眼间便绕到了$N的身后。\n",
"$n一式"MAG"「分身化影」"NOR"，一转身间，四面八方飘动着无数个$n的身影，令$N手足无措。\n",
"$n一式"HIB"「凌波微步」"NOR"，左踏巽，右转乾，身行一晃，便到几丈远的地方。\n",
"$n一式"HIM"「更上层楼」"NOR"，身在空中，左脚在右足上一点，从$N头顶腾空而过。\n",
"$n一式"HIW"「仙子出水」"NOR"，长袖一拂，全身化为一道白影，幽幽地从$N头顶飘落。\n",
"$n一式"HIG"「峰回路转」"NOR"，身体如陀螺般急转，登时一股气流涌出，令$N难以动弹。\n",
"$n一式"GRN"「临行秋波」"NOR"，身行倏的从$N的眼前直绕到身后，$N瞪大了两眼，不明所以。\n",
"$n一式"HIY"「浪子回头」"NOR"，身行倏的从$N的眼前飘过，长发一甩，潇洒之极。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{
        if( query("kar", me)<25
              || query("int", me)<21 )
                return notify_fail("看来你无缘领悟神行百变。\n");
        return 1;
}
int practice_skill(object me)
{
        if( query("qi", me)<40 || query("neili", me)<8 )
                return notify_fail("你的体力太差了，不能练神行百变。\n");
        me->receive_damage("qi", 40);
        addn("neili", -8, me);
        return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) {
        if( query("skybook/luding/dubi", me))return 1.4;
        else        return 0.9; }
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("shenxing-baibian", 1) < 50 ||
            ! living(me))
                return;

        mp = ob->query_skill("martial-cognize", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("dodge", 1) / 2 +
             me->query_skill("shenxing-baibian", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                 result += (["msg" : HIC "$n" HIC "施展神行百变，神光离合，一转身间，四面八方飘动着无数个$n的身影，\n"
                                    HIC "$N" HIC "手足无措，头脑发昏，只觉得四面都是$n的身影，所发招数尽数落空。\n" NOR]);
                return result;
        }
}

int help(object me)
{
        write(HIC"\n神行百变："NOR"\n");
        write(@HELP

    神行百变是铁剑门木桑道长所传下来的轻功绝技，是逃命的高招。

        学习要求：
           一定的机缘向独臂神尼学习
HELP
        );
        return 1;
}
