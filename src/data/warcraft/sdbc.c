// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白光虎[2;37;0m[2;37;0m", ({"sdbca"}));        
        set("gender", "女性");                
        set("long", "相当神秘[2;37;0m
它是天空三号的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "sdbc");
        set("owner_name", "天空三号");
        set_temp("owner", "sdbc");
        set_temp("owner_name", "天空三号");
        ::setup();
}
