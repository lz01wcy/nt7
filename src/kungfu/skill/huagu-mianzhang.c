// huagu-mianzhang 化骨绵掌

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([        "action" : "$N身形微晃，一招"HIB"「长恨深入骨」"NOR"，十指如戟，插向$n的双肩锁骨",
        "lvl"   : 0,
        "skill_name" : "长恨深入骨"
]),
([        "action" : "$N出手如风，十指微微抖动，一招"HIB"「素手裂红裳」"NOR"抓向$n的前胸",
        "lvl"   : 20,
        "skill_name" : "素手裂红裳"
]),
([        "action" : "$N双手忽隐忽现，一招"HIB"「长风吹落尘」"NOR"，鬼魅般地抓向$n的肩头",
        "lvl"   : 40,
        "skill_name" : "长风吹落尘"
]),
([        "action" : "$N左手当胸画弧，右手疾出，一招"HIB"「明月映流沙」"NOR"，猛地抓向$n的额
头",
        "lvl"   : 60,
        "skill_name" : "明月映流沙"
]),
([        "action" : "$N使一招"HIB"「森然动四方」"NOR"，激起漫天的劲风，撞向$n",
        "lvl"   : 80,
        "skill_name" : "森然动四方"
]),
([        "action" : "$N面无表情，双臂忽左忽右地疾挥，使出"HIB"「黯黯侵骨寒」"NOR"，十指\n忽伸忽缩，迅猛无比地袭向$n全身各处大穴",
        "lvl"   : 100,
        "skill_name" : "黯黯侵骨寒"
]),
([        "action" : "$N使出"HIB"「黄沙飘惊雨」"NOR"，蓦然游身而上，绕着$n疾转数圈，$n正眼花缭乱间，\n$N已悄然停在$n身后，右手划出一道光圈，接着右手冲出光圈猛抓$n的后背",
        "lvl"   : 120,
        "skill_name" : "黄沙飘惊雨"
]),
([        "action" : "$N突然双手平举，$n一呆，正在猜测间，便见$N嗖的一下将双手\n收回胸前，接着一招"HIB"「白骨无限寒」"NOR"，五指如钩，直抓向$n的腰间",
        "lvl"   : 140,
        "skill_name" : "白骨无限寒"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="shenlong-bashi"; }

int valid_learn(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("练化骨绵掌必须空手。\n");

        if ((int)me->query_skill("force") < 40)
                return notify_fail("你的内功心法火候不够，练化骨绵掌会走火入魔。\n");

        if( query("max_neili", me)<250 )
                return notify_fail("你的内力太弱，无法练化骨绵掌。\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("huagu-mianzhang", 1))
                return notify_fail("你的基本掌法火候有限，无法领会更高深的化骨绵掌。\n");

        return 1;
}

int practice_skill(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("你的必须空手才能练习。\n");
        if( query("qi", me)<60 )
                return notify_fail("你的体力太低了。\n");
        if( query("neili", me)<50 )
                return notify_fail("你的内力不够练化骨绵掌。\n");
        if (me->query_skill("huagu-mianzhang", 1) < 60)
                me->receive_damage("qi", 60);
        else
                me->receive_damage("qi", 40);
        addn("neili", -25, me);
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
        int d_e1 = -45;
        int d_e2 = -20;
        int p_e1 = 0;
        int p_e2 = 25;
        int f_e1 = 200;
        int f_e2 = 300;
        int i, lvl, seq, ttl = sizeof(action);

        lvl = (int) me->query_skill("huagu-mianzhang", 1);
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

string perform_action_file(string action)
{
        return __DIR__"huagu-mianzhang/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("huagu-mianzhang", 1);
        flvl=query("jiali", me);
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force"))
        {
                victim->receive_wound("qi", damage_bonus, me);
                victim->affect_by("huagu",
                              ([ "level" : lvl + random(lvl),
                                 "id":query("id", me),
                                 "duration" : lvl / 50 + random(lvl / 20) ]));

                return HIB"$n胸腹间气血翻涌，“哇”的一声，又是鲜血，又是清水，大口吐了出来。\n" NOR;
        }
}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int amount;

        if ((int)me->query_skill("huagu-mianzhang") > 100)
        {
                if (random(damage_bonus) > (int)victim->query_skill("force") / 10
                 && !query_temp("hgmz", victim) )
                {
                        set_temp("hgmz", 1, victim);
                        amount = 5 * damage_bonus/( 1 + victim->query_con()) + 1;
                        amount = amount / 100;
                        addn_temp("apply/str", -amount, victim);
                        victim->start_call_out( (: call_other, __FILE__, "remove_effect",
                                                victim, me, amount :),
                                                (int)me->query_skill("huagu-mianzhang", 1) / 20);

                        return HIB "\n$N登时头晕目眩，立时便欲呕吐，喉间“呃呃呃”的不住作声。\n" NOR;
                }
        }
}

void remove_effect(object victim, object me, int amount)
{
        delete_temp("hgmz", victim);
        addn_temp("apply/str", amount, victim);
        message_combatd(HIB"\n$N胸腹间气血翻涌，“哇”的一声，又是鲜血，又是清水，大口吐了出来。\n"NOR, victim);
        if( me )
                victim->receive_wound("qi", amount * 10 + random(amount * 10), me);
        else
                victim->receive_wound("qi", amount * 10 + random(amount * 10));
}
*/

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
        write(HIC"\n化骨绵掌："NOR"\n");
        write(@HELP

    化骨绵掌为蛇岛神龙教绝技。可与绝命腿互备。

        学习要求：
                毒龙大法级别不能低于化骨绵掌
                基本内功50
                内力300
HELP
        );
        return 1;
}
