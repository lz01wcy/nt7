// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("刚刚[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "过来[2;37;0m
它是输出的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "adc");
        set("owner_name", "输出");
        set_temp("owner", "adc");
        set_temp("owner_name", "输出");
        ::setup();
}
