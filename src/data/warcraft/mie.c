// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m白虎[2;37;0m[2;37;0m", ({"youling"}));        
        set("gender", "女性");                
        set("long", "白虎[2;37;0m
它是明灭的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "mie");
        set("owner_name", "明灭");
        set_temp("owner", "mie");
        set_temp("owner_name", "明灭");
        ::setup();
}
