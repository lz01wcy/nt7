// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ddww"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是堂学的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ddx");
        set("owner_name", "堂学");
        set_temp("owner", "ddx");
        set_temp("owner_name", "堂学");
        ::setup();
}
