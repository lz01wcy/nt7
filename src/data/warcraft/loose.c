// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("冲锋号[2;37;0m[2;37;0m", ({"shoot"}));        
        set("gender", "女性");                
        set("long", "冲锋号[2;37;0m
它是集火的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "loose");
        set("owner_name", "集火");
        set_temp("owner", "loose");
        set_temp("owner_name", "集火");
        ::setup();
}
