// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龙[2;37;0m
它是东郭贤的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "horc");
        set("owner_name", "东郭贤");
        set_temp("owner", "horc");
        set_temp("owner_name", "东郭贤");
        ::setup();
}
