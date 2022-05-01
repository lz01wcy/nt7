// dao-cloth.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit CLOTH;

string* clothname = ({
        HIB"青色道袍"NOR,
        HIC"灰色道袍"NOR,
        HIW"白色道袍"NOR,
        HIY"黄色道袍"NOR,
});
string* clothid = ({
        "dao pao",
        "dao pao",
        "dao pao",
        "dao pao",
});
string* clothlong = ({
        "这是一件普普通通的青布道袍。\n",
        "这是一件略有皱摺的灰色布道袍。\n",
        "这是一件洗得很干净的白布道袍。\n",
        "这是一件洗得很褪色的黄布道袍。\n",
});

void create()
{
        int i = random(sizeof(clothname));
        set_name(clothname[i], ({ clothid[i], "cloth" }));
        set_weight(3000);
        set("long", clothlong[i]);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "件");
                set("value", 0);
//                set("long", clothlong[i]);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}