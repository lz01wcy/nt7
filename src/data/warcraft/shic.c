// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"shipet"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是石三的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "shic");
        set("owner_name", "石三");
        set_temp("owner", "shic");
        set_temp("owner_name", "石三");
        ::setup();
}
