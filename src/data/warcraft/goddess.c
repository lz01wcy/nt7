// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[34m太古[1;37m神圣[1;31m龙皇[2;37;0m[2;37;0m", ({"dragons"}));        
        set("gender", "女性");                
        set("long", "太古第一神龙皇[2;37;0m
它是紫霞仙子的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "goddess");
        set("owner_name", "紫霞仙子");
        set_temp("owner", "goddess");
        set_temp("owner_name", "紫霞仙子");
        ::setup();
}
