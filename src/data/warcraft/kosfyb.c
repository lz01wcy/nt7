// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m贰福缘[2;37;0m[2;37;0m", ({"kosfybpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是福缘贰的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosfyb");
        set("owner_name", "福缘贰");
        set_temp("owner", "kosfyb");
        set_temp("owner_name", "福缘贰");
        ::setup();
}
