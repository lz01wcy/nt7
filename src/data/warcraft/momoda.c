// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小龙女[2;37;0m[2;37;0m", ({"longnv"}));        
        set("gender", "女性");                
        set("long", "摸摸大的小龙女[2;37;0m
它是摸摸大的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "momoda");
        set("owner_name", "摸摸大");
        set_temp("owner", "momoda");
        set_temp("owner_name", "摸摸大");
        ::setup();
}
