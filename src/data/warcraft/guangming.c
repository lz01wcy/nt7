// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("瑞兽光明麒麟[2;37;0m[2;37;0m", ({"guangmingqilin"}));        
        set("gender", "男性");                
        set("long", "瑞兽光明麒麟[2;37;0m
它是张有悔的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "guangming");
        set("owner_name", "张有悔");
        set_temp("owner", "guangming");
        set_temp("owner_name", "张有悔");
        ::setup();
}
