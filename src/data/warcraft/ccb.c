// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ccbb"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是学并的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ccb");
        set("owner_name", "学并");
        set_temp("owner", "ccb");
        set_temp("owner_name", "学并");
        ::setup();
}
