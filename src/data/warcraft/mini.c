// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飞机[2;37;0m[2;37;0m", ({"mymini"}));        
        set("gender", "女性");                
        set("long", "飞机[2;37;0m
它是米尼的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mini");
        set("owner_name", "米尼");
        set_temp("owner", "mini");
        set_temp("owner_name", "米尼");
        ::setup();
}
