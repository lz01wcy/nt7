// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m瘸腿老叫驴[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "这头老叫驴又老又丑，浑身斑癣，芙蓉姐姐的性工具[2;37;0m
它是郭达的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaog");
        set("owner_name", "郭达");
        set_temp("owner", "xiaog");
        set_temp("owner_name", "郭达");
        ::setup();
}
