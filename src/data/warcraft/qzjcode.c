// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[41m自行车[2;37;0m[2;37;0m", ({"zixingche"}));        
        set("gender", "男性");                
        set("long", "自行车[2;37;0m
它是先天功的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "qzjcode");
        set("owner_name", "先天功");
        set_temp("owner", "qzjcode");
        set_temp("owner_name", "先天功");
        ::setup();
}
