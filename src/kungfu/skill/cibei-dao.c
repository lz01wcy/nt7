// cibei-dao.c 慈悲刀

#include <ansi.h>;
inherit SHAOLIN_SKILL;
string type() { return "martial"; }
int is_pbsk() { return 1; }
string martialtype() { return "skill"; }

mapping *action = ({
([        "action" : "$N手中$w斜指，一招"GRN"「停车问路」"NOR"，反身一顿，一刀向$n的$l撩去",
        "lvl"    : 0,
        "skill_name" : "停车问路",
]),
([        "action" : "$N一招"MAG"「童子挂画」"NOR"，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
        "lvl"    : 8,
        "skill_name" : "童子挂画",
]),
([        "action" : "$N展身虚步，提腰跃落，一招"HIW"「推窗望月」"NOR"，刀锋一卷，拦腰斩向$n",
        "lvl"    : 16,
        "skill_name" : "推窗望月",
]),
([        "action" : "$N一招"YEL"「开门见山」"NOR"，$w大开大阖，自上而下划出一个大弧，笔直劈
向$n",
        "lvl"    : 24,
        "skill_name" : "开门见山",
]),
([        "action" : "$N手中$w一沉，一招"BLU"「临溪观鱼」"NOR"，双手持刃拦腰反切，砍向$n的胸
口",
        "lvl"    : 33,
        "skill_name" : "临溪观鱼",
]),
([        "action" : "$N挥舞$w，使出一招"HIC"「张弓望的」"NOR"，上劈下撩，左挡右开，齐齐罩向
$n",
        "lvl"    : 42,
        "skill_name" : "张弓望的",
]),
([        "action" : "$N一招"HIC"「风送轻舟」"NOR"，左脚跃步落地，$w顺势往前，挟风声劈向$n的
$l",
        "lvl"    : 51,
        "skill_name" : "风送轻舟",
]),
([        "action" : "$N盘身驻地，一招"HIB"「川流不息」"NOR"，挥出一片流光般的刀影，向$n的全
身涌去",
        "lvl"    : 60,
        "skill_name" : "川流不息",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
//int valid_combine(string combo) { return combo=="fumo-jian"; }

int valid_learn(object me)
{
        if( query("max_neili", me)<100 )
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 30)
                return notify_fail("你的内功火候不够。\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("cibei-dao", 1))
                return notify_fail("你的基本刀法水平有限，无法领会更高深的慈悲刀法。\n");

        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon=query_temp("weapon", me)) ||
                query("skill_type", weapon) != "blade" )
                return notify_fail("你使用的武器不对。\n");
        if( query("qi", me)<50 )
                return notify_fail("你的体力不够练慈悲刀。\n");
        me->receive_damage("qi", 25);
        return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
        if(level >= action[i]["lvl"])
                return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
        int d_e1 = 60;
        int d_e2 = 40;
        int p_e1 = 10;
        int p_e2 = -10;
        int f_e1 = 50;
        int f_e2 = 100;
        int m_e1 = 10;
        int m_e2 = 120;
        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int)me->query_skill("cibei-dao", 1);
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
                "damage_type" : "割伤",
        ]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
        return __DIR__"cibei-dao/" + action;
}

int help(object me)
{
        write(HIC"\n慈悲刀："NOR"\n");
        write(@HELP

    慈悲刀为少林七十二绝技之一。

        学习要求：
                混元一气功10级
                内力50
HELP
        );
        return 1;
}
