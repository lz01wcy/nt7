// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"longlong"}));        
        set("gender", "男性");                
        set("long", "女职工[2;37;0m
它是霍金的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "xueb");
        set("owner_name", "霍金");
        set_temp("owner", "xueb");
        set_temp("owner_name", "霍金");
        ::setup();
}
