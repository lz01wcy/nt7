// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小猫[2;37;0m[2;37;0m", ({"xiaomao"}));        
        set("gender", "男性");                
        set("long", "这是一只小猫。[2;37;0m
它是阿猫的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "amao");
        set("owner_name", "阿猫");
        set_temp("owner", "amao");
        set_temp("owner_name", "阿猫");
        ::setup();
}
