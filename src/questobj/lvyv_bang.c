// bamboo_stick.c

#include <ansi.h>;
#include <weapon.h>;
inherit STICK;

void create()
{
        set_name(HIG"绿玉棒"NOR, ({"lvyv bang", "zhu", "stick"}));
        set_weight(5000);
        set("taskobj", 1);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "根");
                set("long", "一根泛着淡淡青光的竹棒。\n");
                set("value", 0);
                set("material", "bamboo");
                set("wield_msg", "$N抽出一根青光闪闪的$N抓在手中。\n");
                set("unwield_msg", "$N把手中的$n插回腰中。\n");
        }
        setup();
}        