// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是书书的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "kkya");
        set("owner_name", "书书");
        set_temp("owner", "kkya");
        set_temp("owner_name", "书书");
        ::setup();
}
