// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "睡袋[2;37;0m
它是雷军的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ucdos");
        set("owner_name", "雷军");
        set_temp("owner", "ucdos");
        set_temp("owner_name", "雷军");
        ::setup();
}
