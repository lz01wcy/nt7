// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m贰学[2;37;0m[2;37;0m", ({"kosxxbpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是学贰的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosxxb");
        set("owner_name", "学贰");
        set_temp("owner", "kosxxb");
        set_temp("owner_name", "学贰");
        ::setup();
}
