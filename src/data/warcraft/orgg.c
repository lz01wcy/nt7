// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地图精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "34567[2;37;0m
它是小芒果的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "orgg");
        set("owner_name", "小芒果");
        set_temp("owner", "orgg");
        set_temp("owner_name", "小芒果");
        ::setup();
}
