// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m玄武[2;37;0m[2;37;0m", ({"wwww"}));        
        set("gender", "男性");                
        set("long", "玄武[2;37;0m
它是成全的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "chenqa");
        set("owner_name", "成全");
        set_temp("owner", "chenqa");
        set_temp("owner_name", "成全");
        ::setup();
}
