// magua.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("马褂", ({ "ma gua", "gua", "cloth"}));
        set_weight(3000);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("long", "一件淡青色的马褂．\n");
                set("unit", "件");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}