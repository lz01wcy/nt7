// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行车[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行车[2;37;0m
它是甄润奋的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "cymshialw");
        set("owner_name", "甄润奋");
        set_temp("owner", "cymshialw");
        set_temp("owner_name", "甄润奋");
        ::setup();
}
