// qingduanao.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"青缎袄"NOR, ({"qingduan ao", "ao", "cloth"}));
        set_weight(3000);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "件");
                set("value", 250);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}