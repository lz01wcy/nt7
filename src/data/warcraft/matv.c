// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m贰黄[2;37;0m[2;37;0m", ({"matvpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是黄贰的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matv");
        set("owner_name", "黄贰");
        set_temp("owner", "matv");
        set_temp("owner_name", "黄贰");
        ::setup();
}
