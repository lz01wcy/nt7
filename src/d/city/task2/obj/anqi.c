// anqi.c 暗器

#include <ansi.h>
#include <combat.h>
inherit ITEM;

#define tired_damage 20

int * max_damage = ({
        400,
        380,
        410,
        410,
        450,
        390,
});

int * fix_damage = ({
        20,
        20,
        20,
        20,
        25,
        22,
});

string * name_str = ({
        "穿云刺",
        "刺蒺藜",
        "飞燕梭",
        "蜂尾针",
        "梨花钉",
        "袖箭",
});

string * id = ({
        "chuanyun ci",
        "ci jili",
        "feiyan suo",
        "fengwei zhen",
        "lihua ding",
        "xiu jian",
});

string * short_id = ({
        "cc",
        "cj",
        "fs",
        "fz",
        "ld",
        "xj",
});

string * des_str = ({
        "这是一柄穿云刺，柄上系着一根细链，可以用于飞刺作暗器。\n",
        "这是一颗浑身都是倒刺的铁蒺藜，可以当作暗器使用。\n",
        "这是一条形似燕子的梭镖。\n",
        "这东西似乎是儿童玩耍的小弓一样，用青铜合金打造的弓柄，蛟筋做成的弓弦好象很结实。\n",
        "一个精致的白银打造的小盒子，正面好象有很多细若发丝的孔。\n顶部做着一个机钮，旁边用小纂刻着‘暗器之王’几个字。\n",
        "这是一柄袖箭，设计得极其精巧，可以装在袖筒里用以暗算别人。\n旁边有一个小机钮，一按机钮，袖箭就会发射(shot)出去了。\n",
});

string * shot_str = ({
        "$N一抖手中的铁链，穿云刺脱手向$n刺过去！\n",
        "$N从怀内摸出一双铁手套戴好，从身边摸出一颗刺蒺藜，掷向$n！\n",
        "$N手一翻，掌心暗藏的飞燕梭直射$n！\n",
        "$N拉开小弓的弓弦，搭上一支蜂尾针，向$n射去！\n",
        "$N将钉盒上的机钮一掀，只听得‘嗤嗤’破空声不断，数十细若发丝的梨花钉一
掠而过，直射$n！\n",
        "$N抬起手来按动了机钮，一支暗器从$N的袖筒里向$n射去！\n",
});

string * target_str = ({
        "结果$N一惊之下，没有躲开这一击！\n",
        "结果$N一惊之下，没有躲开这一击！\n",
        "$N惨叫一声，被射个正着！\n",
        "$N还没来得及避开，就被射中了！\n",
        "$N只觉得眼前白茫茫一片，避无可避，被暗器射个正着！\n",
        "只听$N惨叫一声，被暗器射个正着！\n",
});

string * escape_str = ({
        "结果中途似乎被什么东西碰了一下，暗器失去了准头，没有伤到$N。\n",
        "结果$N轻巧地往旁边一让，暗器落了空。\n",
        "结果$N一闪，暗器没有射中。\n",
        "$N侧身一让，暗器擦着$N的手臂掠过，仅仅是划破了$N的皮肉。\n",
        "结果$N一缩身，所有暗器都落了空。\n",
        "$N本能地往旁边一让，袖箭只是擦破了$N的皮肉，并没有造成多大伤害。\n",
});

int i; 
void init()
{
        add_action("do_shot","shot");
}

void create()
{
        i = random(sizeof(name_str));

        set_name(HIY+name_str[i]+NOR, ({ id[i],short_id[i] }) );
        set_weight(1500);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/
        {
                set("unit", "盒");
                set("value", 0);
                set("material", "steel");
                set("long", des_str[i]);
        }
        setup();
}

int do_shot(string arg)
{
        object obj,weapon;
        object me = this_player();
        int lv1,lv2,lv3,lv4,damage;
        string skill_type;
        int tired;

        if( query("no_fight", environment(me)) )
                return notify_fail("这里禁止战斗。\n");
        if( !arg)
                return notify_fail("你要射击谁？\n");
        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("这里没有这个人！\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        if (obj == me) return notify_fail("射自己？别想不开啊。\n");

        message_vision(HIR+shot_str[i]+NOR,me, obj);

        if( objectp(weapon=query_temp("weapon", obj)) )
                skill_type=query("skill_type", weapon);
        else skill_type = "unarmed";

        lv1 = COMBAT_D->skill_power(obj, skill_type, SKILL_USAGE_DEFENSE);
        lv2 = COMBAT_D->skill_power(obj, "dodge", SKILL_USAGE_DEFENSE);

        lv3 = (lv2 + (weapon? lv1: (lv1/10))) / 100 + 1;
        lv4=query_temp("apply/armor", obj);

        tired=query("total_tired", obj);
        damage = random(max_damage[i]) - random(lv3+lv4) + fix_damage[i] + random(tired_damage * tired);

        if (damage > 0 )
        {
                obj->receive_wound("qi",damage);
                message_vision(HIR+target_str[random(sizeof(target_str))]+NOR,obj);
        }
        else message_vision(HIW+escape_str[random(sizeof(escape_str))]+NOR,obj);

        destruct(this_object());
        return 1;
}