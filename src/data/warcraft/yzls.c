// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m粉木耳[2;37;0m[2;37;0m", ({"fenmuer"}));        
        set("gender", "男性");                
        set("long", "粉木耳[2;37;0m
它是一指流沙的魔幻兽。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "yzls");
        set("owner_name", "一指流沙");
        set_temp("owner", "yzls");
        set_temp("owner_name", "一指流沙");
        ::setup();
}
