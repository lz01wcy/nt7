// wuxiang_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIB "无相神光" NOR, ({ "wu xiang", "wuxiang", "sword" }));
        set_weight(6000);
        set("taskobj", 1);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "柄");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        setup();
}