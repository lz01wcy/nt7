// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"shipet"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是石一的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "shia");
        set("owner_name", "石一");
        set_temp("owner", "shia");
        set_temp("owner_name", "石一");
        ::setup();
}
