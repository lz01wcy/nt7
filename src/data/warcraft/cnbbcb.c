// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玄武[2;37;0m[2;37;0m", ({"neverfreea"}));        
        set("gender", "男性");                
        set("long", "玄武[2;37;0m
它是范统的魔幻兽。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "cnbbcb");
        set("owner_name", "范统");
        set_temp("owner", "cnbbcb");
        set_temp("owner_name", "范统");
        ::setup();
}
