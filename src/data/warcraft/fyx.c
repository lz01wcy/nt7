// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("考拉[2;37;0m[2;37;0m", ({"myfy"}));        
        set("gender", "男性");                
        set("long", "考拉[2;37;0m
它是菜比韩的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "fyx");
        set("owner_name", "菜比韩");
        set_temp("owner", "fyx");
        set_temp("owner_name", "菜比韩");
        ::setup();
}
