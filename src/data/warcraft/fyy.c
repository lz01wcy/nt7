// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("考拉[2;37;0m[2;37;0m", ({"myfy"}));        
        set("gender", "男性");                
        set("long", "考拉[2;37;0m
它是菜比杨的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "fyy");
        set("owner_name", "菜比杨");
        set_temp("owner", "fyy");
        set_temp("owner_name", "菜比杨");
        ::setup();
}
