// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"lianpet"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是练三的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lianc");
        set("owner_name", "练三");
        set_temp("owner", "lianc");
        set_temp("owner_name", "练三");
        ::setup();
}
