// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"ddddd"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是怒天的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "feu");
        set("owner_name", "怒天");
        set_temp("owner", "feu");
        set_temp("owner_name", "怒天");
        ::setup();
}
