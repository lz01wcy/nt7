// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龙[2;37;0m[2;37;0m", ({"dragon_f"}));        
        set("gender", "女性");                
        set("long", "龙[2;37;0m
它是龙王六的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dragonf");
        set("owner_name", "龙王六");
        set_temp("owner", "dragonf");
        set_temp("owner_name", "龙王六");
        ::setup();
}
