// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("锄头[2;37;0m[2;37;0m", ({"qiankun_bag"}));        
        set("gender", "男性");                
        set("long", "出头[2;37;0m
它是迷惘的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "miwang");
        set("owner_name", "迷惘");
        set_temp("owner", "miwang");
        set_temp("owner_name", "迷惘");
        ::setup();
}
