// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ccqq"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是学钱的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ccq");
        set("owner_name", "学钱");
        set_temp("owner", "ccq");
        set_temp("owner_name", "学钱");
        ::setup();
}
