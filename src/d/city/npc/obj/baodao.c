// blade.c
// Last Modified by Lonely on May. 25 2001

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
         set_name(HIW"宝刀"NOR, ({"bao dao", "dao" }) );
         set_weight(4000);
         /*if( clonep() )
                 set_default_object(__FILE__);
         else*/ {
                 set("unit", "柄");
                 set("value", 500);
                 set("material", "iron");
                 set("long", "这似乎是一把不同寻常的宝刀，透着一股杀气。\n");
                 set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
                 set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
         }
         init_blade(25);
         setup();
}