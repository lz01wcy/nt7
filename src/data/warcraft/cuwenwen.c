// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龙[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "清[2;37;0m
它是醋闻闻的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "cuwenwen");
        set("owner_name", "醋闻闻");
        set_temp("owner", "cuwenwen");
        set_temp("owner_name", "醋闻闻");
        ::setup();
}
