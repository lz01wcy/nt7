#include "herb.h"

void create()
{
        set_name(HIY"金"HIW"银"HIC"花"NOR, ({"jinyin hua","hua"}));

        /*if (clonep())
                set_default_object(__FILE__);
        else*/ 
        {
                set("long","金银花：藤本植物，花分金银二色，可入药，败火剂。\n");
                set("base_unit", "朵");
                set("base_value", 4000);
                set("base_weight", 60);
                set("cure_s",0);
                set("cure_d",1);
                set("cure_n",0);
                
        }
        setup();
}