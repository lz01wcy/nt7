// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"zod"}));        
        set("gender", "女性");                
        set("long", "麒麟~麒麟[2;37;0m
它是成龙的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "chena");
        set("owner_name", "成龙");
        set_temp("owner", "chena");
        set_temp("owner_name", "成龙");
        ::setup();
}
