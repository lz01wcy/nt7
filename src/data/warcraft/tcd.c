// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"qingiii"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是菜农四的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "tcd");
        set("owner_name", "菜农四");
        set_temp("owner", "tcd");
        set_temp("owner_name", "菜农四");
        ::setup();
}
