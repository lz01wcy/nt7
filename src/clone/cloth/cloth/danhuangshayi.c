// danhuangshayi.c 淡黄纱衣

#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( YEL "淡黄纱衣" NOR, ({ "danhuang shayi", "cloth" }) );
        set_weight(800);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "件");
                set("value", 600);
                set("armor_prop/armor", 1);
                set("material", "cloth");
                set("female_only", 1);
        }
        setup();
}