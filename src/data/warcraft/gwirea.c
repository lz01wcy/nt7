// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"gdragon"}));        
        set("gender", "女性");                
        set("long", "青龙[2;37;0m
它是赵大的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "gwirea");
        set("owner_name", "赵大");
        set_temp("owner", "gwirea");
        set_temp("owner_name", "赵大");
        ::setup();
}
