// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "清风[2;37;0m
它是夏商风的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "skyp");
        set("owner_name", "夏商风");
        set_temp("owner", "skyp");
        set_temp("owner_name", "夏商风");
        ::setup();
}
