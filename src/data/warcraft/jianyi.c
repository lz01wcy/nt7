// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m奥妮克希亚[2;37;0m[2;37;0m", ({"jyi"}));        
        set("gender", "女性");                
        set("long", "奥妮克希亚[2;37;0m
它是剑一的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "jianyi");
        set("owner_name", "剑一");
        set_temp("owner", "jianyi");
        set_temp("owner_name", "剑一");
        ::setup();
}
