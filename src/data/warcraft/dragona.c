// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龙[2;37;0m[2;37;0m", ({"dragon_a"}));        
        set("gender", "男性");                
        set("long", "龙[2;37;0m
它是龙王一的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dragona");
        set("owner_name", "龙王一");
        set_temp("owner", "dragona");
        set_temp("owner_name", "龙王一");
        ::setup();
}
