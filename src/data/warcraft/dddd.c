// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ddddd"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是堂到的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dddd");
        set("owner_name", "堂到");
        set_temp("owner", "dddd");
        set_temp("owner_name", "堂到");
        ::setup();
}
