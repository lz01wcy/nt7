// longsword.c 长剑

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIW"宝剑"NOR, ({"bao jian", "sword" }));
        set_weight(5000);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "柄");
                set("long", "这似乎是一把不同寻常的剑，刃口锋利无比。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(25);
        setup();
}