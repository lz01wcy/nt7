// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m玄冰寒毒[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "sleep[2;37;0m
它是毒药的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "poison");
        set("owner_name", "毒药");
        set_temp("owner", "poison");
        set_temp("owner_name", "毒药");
        ::setup();
}
