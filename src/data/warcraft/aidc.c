// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"idc"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是孙梦的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "aidc");
        set("owner_name", "孙梦");
        set_temp("owner", "aidc");
        set_temp("owner_name", "孙梦");
        ::setup();
}
