// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("的会话[2;37;0m[2;37;0m", ({"opop"}));        
        set("gender", "男性");                
        set("long", "家具家电[2;37;0m
它是毒打猫猫的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "duda");
        set("owner_name", "毒打猫猫");
        set_temp("owner", "duda");
        set_temp("owner_name", "毒打猫猫");
        ::setup();
}
