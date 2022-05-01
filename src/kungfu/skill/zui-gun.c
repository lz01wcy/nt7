// This program is a part of NT MudLIB
// zui-gun.c 少林醉棍

#include <ansi.h>;
inherit SHAOLIN_SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
int is_pbsk() { return 1; }

mapping *action = ({
([        "action":""BLU"「蓝采和，提篮劝酒醉朦胧」"NOR"，$N手中$w半提，缓缓划向$n的$l",
        "lvl" : 0,
        "skill_name" : "蓝采和，提篮劝酒醉朦胧"
]),
([        "action":""HIM"「何仙姑，拦腰敬酒醉仙步」"NOR"，$N左掌护胸，右臂挟棍猛地扫向$n的腰间",
        "lvl" : 10,
        "skill_name" : "何仙姑，拦腰敬酒醉仙步"
]),
([        "action":""CYN"「曹国舅，千杯不醉倒金盅」"NOR"，$N倒竖$w，指天打地，向$n的$l劈去",
        "lvl" : 20,
        "skill_name" : "曹国舅，千杯不醉倒金盅"
]),
([        "action":""HIG"「韩湘子，铁棍提胸醉拔萧」"NOR"，$N横提$w，棍端划了个半圈，击向$n的$l",
        "lvl" : 30,
        "skill_name" : "韩湘子，铁棍提胸醉拔萧"
]),
([        "action":""YEL"「汉钟离，跌步翻身醉盘龙」"NOR"，$N手中棍花团团，疾风般向卷向$n",
        "lvl" : 40,
        "skill_name" : "汉钟离，跌步翻身醉盘龙"
]),
([        "action":""HIY"「铁拐李，踢倒金山醉玉池」"NOR"，$N单腿支地，一腿一棍齐齐击向$n的$l",
        "lvl" : 50,
        "skill_name" : "铁拐李，踢倒金山醉玉池"
]),
([        "action":""RED"「张果老，醉酒抛杯倒骑驴」"NOR"，$N扭身反背，$w从胯底钻出，戳向$n的胸口",
        "lvl" : 60,
        "skill_name" : "张果老，醉酒抛杯倒骑驴"
]),
([        "action":""HIW"「吕洞宾，酒醉提壶力千钧」"NOR"，$N腾空而起，如山棍影，疾疾压向$n",
        "lvl" : 70,
        "skill_name" : "吕洞宾，酒醉提壶力千钧"
]),
});

int valid_enable(string usage) { return usage == "club" || usage == "parry"; }
int valid_learn(object me)
{
        if( query("max_neili", me)<250 )
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 50)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("club", 1) < (int)me->query_skill("zui-gun", 1))
                return notify_fail("你的基本棍法水平有限，无法领会更高深的醉棍。\n");

        return 1;
}
int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon=query_temp("weapon", me) )
                 || query("skill_type", weapon) != "club" )
                return notify_fail("你使用的武器不对。\n");
        if( query("qi", me)<50 || query("neili", me)<50 )
                return notify_fail("你的内力或气不够练少林醉棍。\n");
        me->receive_damage("qi", 25);
        addn("neili", -15, me);
        return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
        int d_e1 = -50;
        int d_e2 = -35;
        int p_e1 = 10;
        int p_e2 = 20;
        int f_e1 = 250;
        int f_e2 = 300;
        int m_e1 = 100;
        int m_e2 = 200;
        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int) me->query_skill("zui-gun", 1);
        for(i = ttl; i > 0; i--)
                if(lvl > action[i-1]["lvl"])
                {
                        seq = i; /* 获得招数序号上限 */
                        break;
                }
        seq = random(seq);       /* 选择出手招数序号 */
        return ([
                "action"      : action[seq]["action"],
                "dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
                "parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
                "force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
                "damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
                "damage_type" : "挫伤",
        ]);
}

void skill_improved(object me)
{
        if( (int)me->query_skill("zui-gun", 1) >= 200
        &&  (int)me->query_skill("wuchang-zhang", 1) >= 200
         && !query("sl_gift/zg", me)){
                addn("dex", 1, me);
                set("sl_gift/zg", 1, me);
                tell_object(me, "你的醉棍和无常杖学有所成，提高了你的身法。\n");
        }
}

string perform_action_file(string action)
{
        return __DIR__"zui-gun/" + action;
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
        write(HIC"\n少林醉棍："NOR"\n");
        write(@HELP

    少林醉棍为少林七十二绝技之一。

        学习要求：
                混元一气功20级
                内力100
HELP
        );
        return 1;
}
