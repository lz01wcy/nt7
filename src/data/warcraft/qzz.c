// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"mypet"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是保地的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "qzz");
        set("owner_name", "保地");
        set_temp("owner", "qzz");
        set_temp("owner_name", "保地");
        ::setup();
}
