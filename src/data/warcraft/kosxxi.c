// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m玖学[2;37;0m[2;37;0m", ({"kosxxipet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是学玖的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosxxi");
        set("owner_name", "学玖");
        set_temp("owner", "kosxxi");
        set_temp("owner_name", "学玖");
        ::setup();
}
