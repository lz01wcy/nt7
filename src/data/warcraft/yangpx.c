// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"pxniao"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是杨日月的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yangpx");
        set("owner_name", "杨日月");
        set_temp("owner", "yangpx");
        set_temp("owner_name", "杨日月");
        ::setup();
}
