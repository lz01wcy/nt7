// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"sdada"}));        
        set("gender", "女性");                
        set("long", "大厦[2;37;0m
它是鱼儿儿的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "yur");
        set("owner_name", "鱼儿儿");
        set_temp("owner", "yur");
        set_temp("owner_name", "鱼儿儿");
        ::setup();
}
