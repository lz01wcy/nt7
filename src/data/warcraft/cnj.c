// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"qingix"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是菜农十的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "cnj");
        set("owner_name", "菜农十");
        set_temp("owner", "cnj");
        set_temp("owner_name", "菜农十");
        ::setup();
}
