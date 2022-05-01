// taiji-quan.c 太极拳

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *taijin = ({ "「阴阳诀」", "「动静诀」", "「两仪诀」", "「刚柔诀」", "「沾黏诀」",  "「引字诀」","钻翻", "螺旋","静恒","开合","软手","虚灵"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
         "$p眼见$P$w攻到，当即使出一招「揽雀尾」，右脚实，左脚虚，运起“挤”字诀，粘连粘随，右掌已搭住$P左腕，横劲发出。$N身不由主的向前一冲，跨出两步，方始站定。\n",
         "不料$p双手一圈，如抱太极，一股雄浑无比的力道组成了一个旋涡，只带得$P在原地急转七八下。\n",
         "$p「双风贯耳」，连消带打，双手成圆形击出，随即左圈右圈，一个圆圈跟着一个圆圈，大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈发出，登时便套得$P跌跌撞撞，身不由主的立足不稳。\n",
         "$p使出一招「云手」，左手高，右手低，一个圆圈已将$P$w套住。\n",
         "$p觉气息微窒，当下一招「斜飞势」，将$P$w引偏。\n",
         "$p吸一口气，体内真气流转，右掌挥出，一拒一迎，将$P的力道尽行碰了回去。\n",
         "$p双掌一翻，使出一招「云手」，双掌柔到了极处，空明若虚，将$P$w的急劲尽数化去。\n",
        "$p当即双掌一扬，迎着$w接去，待得手掌与$P$w将触未触之际，施出「揽雀尾式」，将$w轻轻拢住，脚下“金鸡独立式”，左足关地，右足悬空，全身急转，宛似一枚陀螺。\n",
         "就在这电光石火的一瞬之间，$p身子一弓，正是「白鹤亮翅」的前半招，$P的劲力登时落空。\n",
});

mapping *action = ({
([      "action" : "$N使一招"+(order[random(13)])+"「揽雀尾」"NOR"，双手划了个半圈，按向$n的$l",
        "skill_name" : "揽雀尾",
        "lvl" : 0
]),
([      "action" : "$N使一招"+(order[random(13)])+"「单鞭」"NOR"，右手收置肋下，左手向外挥出，劈向$n的$l",
        "skill_name" : "单鞭",
        "lvl" : 5
]),
([      "action" : "$N左手回收，右手由钩变掌，由右向左，使一招"+(order[random(13)])+"「提手上式」"NOR"，向$n的$l打去",
        "skill_name" : "提手上式",
        "lvl" : 10
]),
([      "action" : "$N双手划弧，右手向上，左手向下，使一招"+(order[random(13)])+"「白鹤亮翅」"NOR"，分击$n的面门和$l",
        "skill_name" : "白鹤亮翅",
        "lvl" : 15
]),
([      "action" : "$N左手由胸前向下，身体微转，划了一个大圈，使一招"+(order[random(13)])+"「搂膝拗步」"NOR"，击向$n的$l",
        "skill_name" : "搂膝拗步",
        "lvl" : 20
]),
([      "action" : "$N左手由下上挑，右手内合，使一招"+(order[random(13)])+"「手挥琵琶」"NOR"，向$n的$l打去",
        "skill_name" : "手挥琵琶",
        "lvl" : 25
]),
([      "action" : "$N左手变掌横于胸前，右拳由肘下穿出，一招"+(order[random(13)])+"「肘底看锤」"NOR"，锤向$n的$l",
        "skill_name" : "肘底看锤",
        "lvl" : 30
]),
([      "action" : "$N左脚前踏半步，右手使一招"+(order[random(13)])+"「海底针」"NOR"，指由下向$n的$l戳去",
        "skill_name" : "海底针",
        "lvl" : 35
]),
([      "action" : "$N招"+(order[random(13)])+"「闪通臂」"NOR"，左脚一个弓箭步，右手上举向外撇出，向$n的$l挥去",
        "skill_name" : "闪通臂",
        "lvl" : 40
]),
([      "action" : "$N两手由相对，转而向左上右下分别挥出，右手使一招"+(order[random(13)])+"「斜飞式」"NOR"，挥向$n的$l",
        "skill_name" : "斜飞式",
        "lvl" : 45
]),
([      "action" : "$N左手虚按，右手使一招"+(order[random(13)])+"「白蛇吐信」"NOR"，向$n的$l插去",
        "skill_name" : "白蛇吐信",
        "lvl" : 50
]),
([      "action" : "$N双手握拳，向前向后划弧，一招"+(order[random(13)])+"「双峰贯耳」"NOR"打向$n的$l",
        "skill_name" : "双风贯耳",
        "lvl" : 55
]),
([      "action" : "$N左手虚划，右手一记"+(order[random(13)])+"「指裆锤」"NOR"击向$n的裆部",
        "skill_name" : "指裆锤",
        "lvl" : 60
]),
([      "action" : "$N施出"+(order[random(13)])+"「伏虎式」"NOR"，右手击向$n的$l，左手攻向$n的裆部",
        "skill_name" : "伏虎式",
        "lvl" : 65
]),
([      "action" : "$N由臂带手，在面前缓缓划过，使一招"+(order[random(13)])+"「云手」"NOR"，挥向$n的$l",
        "skill_name" : "云手",
        "lvl" : 70
]),
([      "action" : "$N左腿收起，右手使一招"+(order[random(13)])+"「金鸡独立」"NOR"，向$n的$l击去",
        "skill_name" : "金鸡独立",
        "lvl" : 75
]),
([      "action" : "$N右手由钩变掌，双手掌心向上，右掌向前推出一招"+(order[random(13)])+"「高探马」"NOR"",
        "skill_name" : "高探马",
        "lvl" : 80
]),
([      "action" : "$N右手使一式招"+(order[random(13)])+"「玉女穿梭」"NOR"，扑身向$n的$l插去",
        "skill_name" : "玉女穿梭",
        "lvl" : 85
]),
([      "action" : "$N右手经腹前经左肋向前撇出，使一招"+(order[random(13)])+"「反身撇锤」"NOR"，向$n的$l锤去",
        "skill_name" : "反身撇锤",
        "lvl" : 90
]),
([      "action" : "$N左手虚按，右腿使一招"+(order[random(13)])+"「转身蹬腿」"NOR"，向$n的$l踢去",
        "skill_name" : "反身蹬腿",
        "lvl" : 95
]),
([      "action" : "$N左手向上划弧拦出，右手使一招"+(order[random(13)])+"「搬拦锤」"NOR"，向$n的$l锤去",
        "skill_name" : "白蛇吐信",
        "lvl" : 100
]),
([      "action" : "$N使一招"+(order[random(13)])+"「栽锤」"NOR"，左手搂左膝，右手向下锤向$n的$l",
        "skill_name" : "栽锤",
        "lvl" : 120
]),
([      "action" : "$N双手先抱成球状，忽地分开右手上左手下，一招"+(order[random(13)])+"「野马分鬃」"NOR"，向$n的$l和面门打去",
        "skill_name" : "野马分鬃",
        "lvl" : 150
]),
([      "action" : "$N左手由胸前向下，右臂微曲，使一招"+(order[random(13)])+"「抱虎归山」"NOR"，向$n的$l推去",
        "skill_name" : "抱虎归山",
        "lvl" : 180
]),
([      "action" : "$N双手经下腹划弧交于胸前，成十字状，一式"+(order[random(13)])+"「十字手」"NOR"，向$n的$l打去",
        "skill_name" : "十字手",
        "lvl" : 210
]),
([      "action" : "$N左脚踏一个虚步，双手交叉成十字拳，一招"+(order[random(13)])+"「进步七星」"NOR"，向$n的$l锤去",
        "skill_name" : "进步七星",
        "lvl" : 240
]),
([      "action" : "$N身体向后腾出，左手略直，右臂微曲，使一招"+(order[random(13)])+"「倒撵猴」"NOR"，向$n的$l和面门打去",
        "skill_name" : "倒撵猴",
        "lvl" : 270
]),
([      "action" : "$N双手伸开，以腰为轴，整个上身划出一个大圆弧，\n一招"+(order[random(13)])+"「转身摆莲」"NOR"，将$n浑身上下都笼罩在重重掌影之中",
        "skill_name" : "转身摆莲",
        "lvl" : 300
]),
([      "action" : "$N双手握拳，右手缓缓收至耳际，左手缓缓向前推出，\n拳意如箭，一招"+(order[random(13)])+"「弯弓射虎」"NOR"，直奔$n心窝而去",
        "skill_name" : "弯弓射虎",
        "lvl" : 400
]),
([      "action" : "$N双手在胸前翻掌，由腹部向前向上推出，一招"+(order[random(13)])+"「如封似闭」"NOR"，一股劲风直逼$n",
        "skill_name" : "如封似闭",
        "lvl" : 500
]),
});

int valid_enable(string usage) { return usage == "cuff" || usage == "parry"; }
int valid_combine(string combo)
{
        return combo == "wudang-zhang" || combo == "paiyun-shou";
}

int valid_learn(object me)
{
        if( query("int", me)<26 )
                return notify_fail("你先天悟性太差，难以领会太极拳的要诣。\n");

        if( !me->query_family() || me->query_family() != "武当派" )
                return notify_fail("你不是武当派，难以领会太极拳的要诣。\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("练太极拳必须空手。\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("你的内功火候不够，无法学太极拳。\n");

        if( query("max_neili", me)<1000 )
                return notify_fail("你的内力太弱，无法练太极拳。\n");

        if ((int)me->query_skill("cuff", 1) < 100)
                return notify_fail("你的基本拳法火候不够，无法学太极拳。\n");

        if ((int)me->query_skill("cuff", 1) < (int)me->query_skill("taiji-quan", 1))
                return notify_fail("你的基本拳法水平有限，无法领会更高深的太极拳。\n");

        return 1;
}
int practice_skill(object me)
{
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("你的必须空手才能练习。\n");
        if( query("qi", me)<70 )
                return notify_fail("你的体力太低了。\n");
        if( query("neili", me)<70 )
                return notify_fail("你的内力不够练太极拳。\n");
        me->receive_damage("qi", 60);
        addn("neili", -60, me);
        return 1;
}
string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
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
        int d_e1 = -60;
        int d_e2 = -50;
        int p_e1 = -70;
        int p_e2 = -60;
        int f_e1 = 400;
        int f_e2 = 600;
        int i, lvl, seq, ttl = sizeof(action);
        string msg;
        lvl = (int) me->query_skill("taiji-quan", 1);
/////////yun taiji/////////
        if( query_temp("taiji", me) && query("neili", me)>100 )
        {
                addn_temp("taiji_fight", 1, me);
                msg = random(2)==1?
                        HIW"只见$N虚灵顶劲、涵胸拔背、松腰垂臀、沉肩坠肘，双手抱了个太极式的圆圈，纯以意行太极，\n已达形神合一，心动气动的境界，结果使出了太极拳中的"NOR:
                        HIW"刹时间$N悟到了太极拳旨中“似松非松，将展未展，劲断意不断”的精微奥妙之处，\n使出一招犹如行云流水，潇洒无比。结果使出了太极拳中的"NOR;
                msg = msg + order[random(sizeof(order))] + taijin[random(sizeof(taijin))] + NOR;
        if ( lvl > 250
        && random(lvl) > 200
        && random(10)>3)
        {
                addn("neili", -10, me);
                return ([
                        "action" : msg,
                        "force" :  600,
                        "dodge":   -180,
                        "damage":   500,
                        "parry":   -180,
                        "damage_type" : random(2)==1?"瘀伤":"内伤",
                ]);
        }
  }
  //////普通出招////////
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

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("taiji-quan", 1) < 100 ||
            !living(me) || query_temp("weapon", me) )
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("taiji-quan", 1);

        if (ap / 3 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIC "$n" HIC "面含微笑，双手齐出，划出了"
                                            "一个圆圈，竟然让$N" +
                                            HIC "的攻击全不着力。\n" NOR]);
                        break;

                case 1:
                        result += (["msg" : HIC "$n" HIC "左右格档，使出四两拨千斤的手法，"
                                            "化解$N" HIC "的攻势于无形。\n" NOR]);
                        break;

                default:
                        result += (["msg" : HIC "$n" HIC "慢慢出拳"
                                            HIC "，动作虽然缓慢，却让$N"
                                            HIC "感到浑身粘滞，甚不舒畅。\n" NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(3))
                {
                case 0:
                        result = HIY "$n" HIY "面含微笑，双手齐出，划出了"
                                 "一个圆圈，然而$N" +
                                 HIY "理也不理，随手挥招直入，进袭$n"
                                 HIY "！\n" NOR;
                        break;

                case 1:
                        result = HIY "$n" HIY "左右格档，使出四两拨千斤的手法，"
                                 "可是$N" HIY "攻势却是变化无方，不遵循常理。\n" NOR;
                        break;

                default:
                        result = HIY "$n" HIY "慢慢出拳"
                                 HIY "，动作缓慢却让$N"
                                 HIY "感到粘滞，可是$N"
                                 HIY "立刻变化节奏，出奇招快速进击$n"
                                 HIY "！\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if( query_temp("weapon", me) )
                return 0;

        lvl = me->query_skill("taiji-quan", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
string perform_action_file(string action)
{
        return __DIR__"taiji-quan/" + action;
}
string query_description()
{
        return
        "太极拳，为宋末元初武当张三丰真人所创，合道家之说，冲虚自然，主以慢"
        "打快，以静制动，後发制人，无为至虚之念的上乘武学。拳出时双手圆转，"
        "每一招都含着太极式的阴阳变化，精微奥妙，实是开辟了武学中从所未有的"
        "新天地。诀窍为「虚灵顶劲、涵胸拔背、松腰垂臀、沉肩坠肘」十六个字，"
        "纯粹以意行，最忌用力。形神合一，是这路拳法的要旨。"
        "太极拳劲首要在于似松非松，将展未展，劲断意不断，其接力打力为武林一绝。";
}

int help(object me)
{
        write(WHT"\n太极拳："NOR"\n");
        write(@HELP

    太极拳，为宋末元初武当张三丰真人所创，合道家之说，冲虚
自然，讲究以柔克刚、四两拨千斤。主以慢打快，以静制动，后发
制人，无为至虚之念的上乘武学。拳出时双手圆转，每一招都含着
太极式的阴阳变化，精微奥妙，实是开辟了武学中从所未有的新天
地。诀窍为「虚灵顶劲、涵胸拔背、松腰垂臀、沉肩坠肘」十六个
字，纯以意行，最忌用力。形神合一，是这路拳法的要旨。
    太极拳劲首要在似松非松，将展未展，劲断意不断，其接力打
力为武林一绝。

        学习要求：
                太极神功20级
                内力100
HELP
        );
        return 1;
}
