// /d/yixing/obj/biaohuo.c
// Last Modified by Lonely on Jul. 12 2002

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"红镖"NOR, ({"hong biao", "biao"}));
        set("weight", 20);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
                set("long", "这是一份红镖，包装非常仔细，不知装着什么东西。\n");
                set("unit", "份");
                set("value", 30);
        }
        setup();
}