// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"klktd"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是太窝窝的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "klkt");
        set("owner_name", "太窝窝");
        set_temp("owner", "klkt");
        set_temp("owner_name", "太窝窝");
        ::setup();
}
