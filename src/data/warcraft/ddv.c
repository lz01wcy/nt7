// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ddvv"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是堂位的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ddv");
        set("owner_name", "堂位");
        set_temp("owner", "ddv");
        set_temp("owner_name", "堂位");
        ::setup();
}
