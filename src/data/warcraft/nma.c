// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("泥煤[2;37;0m[2;37;0m", ({"nmride"}));        
        set("gender", "女性");                
        set("long", "坐骑[2;37;0m
它是鱼清的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nma");
        set("owner_name", "鱼清");
        set_temp("owner", "nma");
        set_temp("owner_name", "鱼清");
        ::setup();
}
