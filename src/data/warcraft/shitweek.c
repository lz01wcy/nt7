// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("异形[2;37;0m[2;37;0m", ({"shit"}));        
        set("gender", "男性");                
        set("long", "异形[2;37;0m
它是周钰翔的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "shitweek");
        set("owner_name", "周钰翔");
        set_temp("owner", "shitweek");
        set_temp("owner_name", "周钰翔");
        ::setup();
}
