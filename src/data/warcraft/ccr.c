// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ccrr"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是学日的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ccr");
        set("owner_name", "学日");
        set_temp("owner", "ccr");
        set_temp("owner_name", "学日");
        ::setup();
}
