// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小坏蛋[2;37;0m[2;37;0m", ({"qll"}));        
        set("gender", "男性");                
        set("long", "小坏蛋[2;37;0m
它是独孤二的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "bqb");
        set("owner_name", "独孤二");
        set_temp("owner", "bqb");
        set_temp("owner_name", "独孤二");
        ::setup();
}
