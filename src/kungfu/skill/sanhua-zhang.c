// sanhua-zhang.c 散花掌

#include <ansi.h>;
inherit SHAOLIN_SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
int is_pbsk() { return 1; }

mapping *action = ({
([      "action" : "$N合掌抱球，一式"HIG"「春深芳草尽」"NOR"，双掌变幻吞吐，缓缓推向$n的$l",
        "lvl" : 0,
        "skill_name" : "春深芳草尽"
]),
([      "action" : "$N五指绽开，一式"GRN"「夏闲独兰馨」"NOR"，左右掌穿插翻飞，疾向$n的$l拍去",
        "lvl" : 20,
        "skill_name" : "夏闲独兰馨"
]),
([      "action" : "$N使一式"YEL"「秋酣菊霜清」"NOR"，左掌虚托，右掌乍伸乍合，猛地插往$n的$l",
        "lvl" : 40,
        "skill_name" : "秋酣菊霜清"
]),
([      "action" : "$N双掌血红，一式"MAG"「冬卧听梅吟」"NOR"，幻成漫天梅花朵朵，雨点般向$n击去",
        "lvl" : 60,
        "skill_name" : "冬卧听梅吟"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="nianhua-zhi"; }

int valid_learn(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("练散花掌必须空手。\n");

        if ((int)me->query_skill("force", 1) < 60)
                return notify_fail("你的内功火候不够，无法学散花掌。\n");

        if( query("max_neili", me)<300 )
                return notify_fail("你的内力太弱，无法练散花掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("sanhua-zhang", 1))
                return notify_fail("你的基本掌法火候水平有限，无法领会更高深的散花掌。\n");

        if ((int)me->query_skill("weituo-gun", 1) < 60
        &&  (int)me->query_skill("cibei-dao", 1) < 60
        &&  (int)me->query_skill("pudu-zhang", 1) < 60
        &&  (int)me->query_skill("fengyun-shou", 1) < 60)
                return notify_fail("你必须在韦陀棍，慈悲刀，普渡杖，和风云手中任选一门练到一定境界才能练散花掌。\n");

        return 1;
}
int practice_skill(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("你的必须空手才能练习。\n");
        if( query("qi", me)<30 )
                return notify_fail("你的体力太低了。\n");
        if( query("neili", me)<20 )
                return notify_fail("你的内力不够练散花掌。\n");
        me->receive_damage("qi", 30);
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
        int d_e1 = -25;
        int d_e2 = -5;
        int p_e1 = 15;
        int p_e2 = 45;
        int f_e1 = 140;
        int f_e2 = 250;
        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int) me->query_skill("sanhua-zhang", 1);
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
                "damage_type" : random(2) ? "内伤" : "瘀伤",
        ]);
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
        return __DIR__"sanhua-zhang/" + action;
}

int help(object me)
{
        write(HIC"\n散花掌："NOR"\n");
        write(@HELP

    散花掌为少林七十二绝技之一。
    可与拈花指互备。

        学习要求：
                混元一气功20级
                内力100
HELP
        );
        return 1;
}
