// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"lop"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是恒七的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "zzhf");
        set("owner_name", "恒七");
        set_temp("owner", "zzhf");
        set_temp("owner_name", "恒七");
        ::setup();
}
