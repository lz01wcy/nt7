// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m梦麒麟[2;37;0m[2;37;0m", ({"meng"}));        
        set("gender", "男性");                
        set("long", "nod[2;37;0m
它是小旦的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "smalldan");
        set("owner_name", "小旦");
        set_temp("owner", "smalldan");
        set_temp("owner_name", "小旦");
        ::setup();
}
