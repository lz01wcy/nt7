// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("马[2;37;0m[2;37;0m", ({"goldggg"}));        
        set("gender", "男性");                
        set("long", "马[2;37;0m
它是金马的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "goldgg");
        set("owner_name", "金马");
        set_temp("owner", "goldgg");
        set_temp("owner_name", "金马");
        ::setup();
}
