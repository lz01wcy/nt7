// zhanmao.c

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIR"红缨毡帽"NOR, ({ "hongying zhanmao", "head" }) );
        set_weight(100);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "顶");
                set("value",700);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}