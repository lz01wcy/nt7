#include "herb.h"

void create()
{
        set_name(HIG "茯苓" NOR, ({"fu ling"}));
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ 
        {
                set("long","茯苓：草本植物，补气血，润五脏，是不可多得的上佳药材。\n");
                set("base_unit", "块");
                set("base_value", 4000);
                set("base_weight", 60);
                set("cure_s",40);
                set("cure_d",0);
                set("cure_n",53);
                
        }
        setup();
}