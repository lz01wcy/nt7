// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "牛[2;37;0m
它是长六安的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "changansl");
        set("owner_name", "长六安");
        set_temp("owner", "changansl");
        set_temp("owner_name", "长六安");
        ::setup();
}
