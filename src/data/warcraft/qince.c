// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玄武[2;37;0m[2;37;0m", ({"asd"}));        
        set("gender", "男性");                
        set("long", "玄武[2;37;0m
它是秦策的魔幻兽。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "qince");
        set("owner_name", "秦策");
        set_temp("owner", "qince");
        set_temp("owner_name", "秦策");
        ::setup();
}
