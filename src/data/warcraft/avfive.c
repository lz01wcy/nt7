// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是里美老师的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "avfive");
        set("owner_name", "里美老师");
        set_temp("owner", "avfive");
        set_temp("owner_name", "里美老师");
        ::setup();
}
