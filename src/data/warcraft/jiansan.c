// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m死亡之翼[2;37;0m[2;37;0m", ({"jsa"}));        
        set("gender", "男性");                
        set("long", "死亡之翼[2;37;0m
它是剑三的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "jiansan");
        set("owner_name", "剑三");
        set_temp("owner", "jiansan");
        set_temp("owner_name", "剑三");
        ::setup();
}
