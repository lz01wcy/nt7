// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("伙子[2;37;0m[2;37;0m", ({"headblong"}));        
        set("gender", "男性");                
        set("long", "万恶[2;37;0m
它是地方官员的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "headb");
        set("owner_name", "地方官员");
        set_temp("owner", "headb");
        set_temp("owner_name", "地方官员");
        ::setup();
}
