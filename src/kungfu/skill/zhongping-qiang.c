//zhongping-qiang.c 中平枪法
// Last Modified by Lonely on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
int is_pbsk() { return 1; }

mapping *action = ({
([        "action": "$N双手一别，尽力前伸，使出一招"HIW"「中平无敌」"NOR"，手中$w平平直出，刺向$n的$l",
        "lvl" : 0,
        "skill_name" : "中平无敌"
]),
([        "action": "$N手中$w盘旋回转，风响阵阵，屈身下蹲，反手一招"HIB"「夜叉探海」"NOR"自下向$n的$l刺去",
        "lvl" : 10,
        "skill_name" : "夜叉探海"
]),
([        "action": "$N举起$w，抖出一朵枪花，一招"HIB"「灵蛇出洞」"NOR"向$n分心扎去",
        "lvl" : 20,
        "skill_name" : "灵蛇出洞"
]),
([        "action": "$N一招"HIM"「反身拿枪」"NOR"，手中$w划个小圈消去$n的后招，而后$w微抬，指向$n的$l",
        "lvl" : 30,
        "skill_name" : "反身拿枪"
]),
});

int valid_enable(string usage) { return usage=="club" || usage=="parry"; }
int valid_learn(object me)
{
        object weapon;

        if( !objectp(weapon=query_temp("weapon", me) )
            || query("skill_type", weapon) != "club" )
                return notify_fail("你必须先找一根棍子才能练中平枪法。\n");

        if( query("max_neili", me)<1000 )
                return notify_fail("你的内力修为不足，没有办法练中平枪法。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功火候太浅，没有办法练中平枪法。\n");

        if ((int)me->query_skill("club", 1) < 80)
                return notify_fail("你的棍法根基不足，没有办法练中平枪法。\n");

        if ((int)me->query_skill("club", 1) < (int)me->query_skill("zhongping-qiang", 1))
                return notify_fail("你的基本棍法水平不够，无法领会更高深的中平枪法。\n");

        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon=query_temp("weapon", me) )
                 || query("skill_type", weapon) != "club" )
                return notify_fail("你使用的武器不对。\n");
        if( query("qi", me)<50 || query("neili", me)<50 )
                return notify_fail("你的内力或气不够练中平枪法。\n");
        me->receive_damage("qi", 20);
        addn("neili", -20, me);
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
        int d_e1 = -30;
        int d_e2 = -10;
        int p_e1 = 0;
        int p_e2 = 20;
        int f_e1 = 200;
        int f_e2 = 300;
        int m_e1 = 200;
        int m_e2 = 350;
        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int) me->query_skill("zhongping-qiang", 1);
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
                "damage_type" : "刺伤",
        ]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
        return __DIR__"zhongping-qiang/" + action;
}

int help(object me)
{
        write(HIC"\n中平枪法："NOR"\n");
        write(@HELP

    中平枪法是花铁干的成名武功。

        学习要求：
                内力70
HELP
        );
        return 1;
}
