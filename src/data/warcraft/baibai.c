// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是白胖胖的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "baibai");
        set("owner_name", "白胖胖");
        set_temp("owner", "baibai");
        set_temp("owner_name", "白胖胖");
        ::setup();
}
