// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"tgimm"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是阳顶天的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "tgimj");
        set("owner_name", "阳顶天");
        set_temp("owner", "tgimj");
        set_temp("owner_name", "阳顶天");
        ::setup();
}
