// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"qinlong"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是天海老师的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "avnine");
        set("owner_name", "天海老师");
        set_temp("owner", "avnine");
        set_temp("owner_name", "天海老师");
        ::setup();
}
