// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("百事可乐[2;37;0m[2;37;0m", ({"keco"}));        
        set("gender", "男性");                
        set("long", "百事可乐[2;37;0m
它是可口的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "coke");
        set("owner_name", "可口");
        set_temp("owner", "coke");
        set_temp("owner_name", "可口");
        ::setup();
}
