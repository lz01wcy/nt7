// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("考拉[2;37;0m[2;37;0m", ({"myfy"}));        
        set("gender", "男性");                
        set("long", "考拉[2;37;0m
它是仓储四的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cchd");
        set("owner_name", "仓储四");
        set_temp("owner", "cchd");
        set_temp("owner_name", "仓储四");
        ::setup();
}
