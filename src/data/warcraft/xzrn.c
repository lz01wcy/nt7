// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地图精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "13123[2;37;0m
它是出云申猴的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xzrn");
        set("owner_name", "出云申猴");
        set_temp("owner", "xzrn");
        set_temp("owner_name", "出云申猴");
        ::setup();
}
