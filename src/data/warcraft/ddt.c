// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ddsss"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是堂堂的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ddt");
        set("owner_name", "堂堂");
        set_temp("owner", "ddt");
        set_temp("owner_name", "堂堂");
        ::setup();
}
