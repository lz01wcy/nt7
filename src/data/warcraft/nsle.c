// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地图精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "1111[2;37;0m
它是天地的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "nsle");
        set("owner_name", "天地");
        set_temp("owner", "nsle");
        set_temp("owner_name", "天地");
        ::setup();
}
