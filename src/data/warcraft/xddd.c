// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是美豆豆的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xddd");
        set("owner_name", "美豆豆");
        set_temp("owner", "xddd");
        set_temp("owner_name", "美豆豆");
        ::setup();
}
