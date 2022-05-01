// xiuluo-dao.c 修罗刀

#include <ansi.h>;
inherit SHAOLIN_SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
int is_pbsk() { return 1; }

mapping *action = ({
([        "action" : "$N藏刀内收，一招"HIY"「割肉饲鹰」"NOR"，刀锋自下而上划了个半弧，向$n的
$l挥去",
        "lvl" : 0,
        "skill_name" : "割肉饲鹰",
]),
([        "action" : "$N左掌虚托右肘，一招"MAG"「投身饿虎」"NOR"，手中$w笔直划向$n的$l",
        "lvl" : 10,
        "skill_name" : "投身饿虎",
]),
([        "action" : "$N一招"BLU"「斫头谢天」"NOR"，$w绕颈而过，刷地一声自上而下向$n猛劈",
        "lvl" : 20,
        "skill_name" : "斫头谢天",
]),
([        "action" : "$N右手反执刀柄，一招"HIW"「折骨出髓」"NOR"，猛一挫身，$w直向$n的颈中斩
去",
        "lvl" : 30,
        "skill_name" : "折骨出髓",
]),
([        "action" : "$N一招"GRN"「挑身千灯」"NOR"，无数刀尖化作点点繁星，向$n的$l挑去",
        "lvl" : 40,
        "skill_name" : "挑身千灯",
]),
([        "action" : "$N双手合执$w，一招"BLU"「挖眼布施」"NOR"，拧身急转，刀尖直刺向$n的双眼
",
        "lvl" : 50,
        "skill_name" : "挖眼布施",
]),
([        "action" : "$N一招"CYN"「剥皮书经」"NOR"，手中$w划出一个大平十字，向$n纵横劈去",
        "lvl" : 60,
        "skill_name" : "剥皮书经",
]),
([        "action" : "$N反转刀尖对准自己，一招"RED"「剜心决志」"NOR"，全身一个翻滚，$w向$n拦
腰斩去",
        "lvl" : 70,
        "skill_name" : "剜心决志",
]),
([        "action" : "$N一招"HIB"「烧身供佛」"NOR"，$w的刀光仿佛化成一簇簇烈焰，将$n团团围绕
",
        "lvl" : 80,
        "skill_name" : "烧身供佛",
]),
([        "action" : "$N刀尖平指，一招"HIR"「刺血满地」"NOR"，一片片切骨刀气如飓风般裹向$n的
全身",
        "lvl" : 90,
        "skill_name" : "刺血满地",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
        if( query("max_neili", me)<100 )
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("xiuluo-dao", 1))
                return notify_fail("你的基本刀法水平有限，无法领会更高深的修罗刀法。\n");

        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon=query_temp("weapon", me) )
                 || query("skill_type", weapon) != "blade" )
                return notify_fail("你使用的武器不对。\n");
        if( query("qi", me)<50 )
                return notify_fail("你的体力不够练修罗刀。\n");
        me->receive_damage("qi", 35);
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
        int d_e1 = 40;
        int d_e2 = 20;
        int p_e1 = -10;
        int p_e2 = -30;
        int f_e1 = 100;
        int f_e2 = 150;
        int m_e1 = 130;
        int m_e2 = 240;
        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int)me->query_skill("xiuluo-dao", 1);
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
                "damage_type" : random(2) ? "割伤" : "擦伤",
        ]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
        return __DIR__"xiuluo-dao/" + action;
}

int help(object me)
{
        write(HIC"\n修罗刀："NOR"\n");
        write(@HELP

    修罗刀为少林七十二绝技之一。

        学习要求：
                混元一气功10级
                内力50
HELP
        );
        return 1;
}
