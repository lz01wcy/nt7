// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行车[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行车[2;37;0m
它是贝晖思的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "nzuiubefh");
        set("owner_name", "贝晖思");
        set_temp("owner", "nzuiubefh");
        set_temp("owner_name", "贝晖思");
        ::setup();
}
