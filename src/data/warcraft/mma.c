// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m兔八哥[2;37;0m[2;37;0m", ({"mymm"}));        
        set("gender", "女性");                
        set("long", "傻乎乎的兔八哥。[2;37;0m
它是米客一的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mma");
        set("owner_name", "米客一");
        set_temp("owner", "mma");
        set_temp("owner_name", "米客一");
        ::setup();
}
