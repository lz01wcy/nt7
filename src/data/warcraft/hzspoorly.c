// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("结永[2;37;0m[2;37;0m", ({"feih"}));        
        set("gender", "男性");                
        set("long", "结永[2;37;0m
它是海风的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "hzspoorly");
        set("owner_name", "海风");
        set_temp("owner", "hzspoorly");
        set_temp("owner_name", "海风");
        ::setup();
}
