// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行车[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行车[2;37;0m
它是紫怨的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "moneydme");
        set("owner_name", "紫怨");
        set_temp("owner", "moneydme");
        set_temp("owner_name", "紫怨");
        ::setup();
}
