// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("的我[2;37;0m[2;37;0m", ({"lppp"}));        
        set("gender", "男性");                
        set("long", "的我[2;37;0m
它是恒一的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "zzha");
        set("owner_name", "恒一");
        set_temp("owner", "zzha");
        set_temp("owner_name", "恒一");
        ::setup();
}
