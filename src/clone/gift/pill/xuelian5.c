#include <ansi.h>
inherit __DIR__"pill";

void create()
{//5. 百年雪莲膏        HIC        39000                20000        100                由百年雪莲混合数种珍贵药材所炼制的灵药。

        set_name(HIC "百年雪莲膏" NOR, ({ "bainian xueliangao", "xuelian", "gao" }));
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                                                                set("long", HIC "由百年雪莲混合数种珍贵药材所炼制的灵药。\n" NOR);
                                                                set("unit", "盒");
                set("value", 20000);
                set("weight", 300);
                set("pill_skill", "dodge");
                set("pill_point", 39000);
                set("force_point", 100);
                set("pill_msg1", HIW "你只感到清凉之意散布全身，说不出的舒服受用。\n" NOR);
                set("pill_msg2", HIC "你只觉灵台处清欣无比，精力得到了完全的补充。\n" NOR);
        }
        setup();
}