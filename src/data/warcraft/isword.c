// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龙[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "龙[2;37;0m
它是制剑师傅的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "isword");
        set("owner_name", "制剑师傅");
        set_temp("owner", "isword");
        set_temp("owner_name", "制剑师傅");
        ::setup();
}
