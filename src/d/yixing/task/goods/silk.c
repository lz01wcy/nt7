// /d/yixing/task/goods/silk.c
// Last Modified by Lonely on Jul. 12 2002

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(CYN"绸缎"NOR, ({ "silk" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一匹做工极其考究的绸缎。\n");
                set("unit", "匹");
                set("value", 1000);
                set("material", "silk");
        }
        setup();
}