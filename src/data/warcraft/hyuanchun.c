// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("贾宝玉[2;37;0m[2;37;0m", ({"jbaoyu"}));        
        set("gender", "男性");                
        set("long", "贾宝玉[2;37;0m
它是元春的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hyuanchun");
        set("owner_name", "元春");
        set_temp("owner", "hyuanchun");
        set_temp("owner_name", "元春");
        ::setup();
}
