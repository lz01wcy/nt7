// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qlin"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是大咪咪的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "emsy");
        set("owner_name", "大咪咪");
        set_temp("owner", "emsy");
        set_temp("owner_name", "大咪咪");
        ::setup();
}
