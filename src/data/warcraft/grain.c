// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哼哈[2;37;0m[2;37;0m", ({"ggrain"}));        
        set("gender", "男性");                
        set("long", "哼哈[2;37;0m
它是飘渺云雨的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "grain");
        set("owner_name", "飘渺云雨");
        set_temp("owner", "grain");
        set_temp("owner_name", "飘渺云雨");
        ::setup();
}
