// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "青龙[2;37;0m
它是段烟雨的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "xyfe");
        set("owner_name", "段烟雨");
        set_temp("owner", "xyfe");
        set_temp("owner_name", "段烟雨");
        ::setup();
}
