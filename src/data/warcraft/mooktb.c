// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("远古青龙[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "远古青龙[2;37;0m
它是一偷的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "mooktb");
        set("owner_name", "一偷");
        set_temp("owner", "mooktb");
        set_temp("owner_name", "一偷");
        ::setup();
}
