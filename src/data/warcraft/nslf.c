// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地图精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "女性");                
        set("long", "1111[2;37;0m
它是玄黄的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "nslf");
        set("owner_name", "玄黄");
        set_temp("owner", "nslf");
        set_temp("owner_name", "玄黄");
        ::setup();
}
