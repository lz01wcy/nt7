// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("西欧[2;37;0m[2;37;0m", ({"benz"}));        
        set("gender", "男性");                
        set("long", "           [2;37;0m
它是三品武士的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wupin");
        set("owner_name", "三品武士");
        set_temp("owner", "wupin");
        set_temp("owner_name", "三品武士");
        ::setup();
}
