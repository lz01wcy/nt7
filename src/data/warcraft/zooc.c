// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("牛蹄[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "牛蹄[2;37;0m
它是生肖牛的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zooc");
        set("owner_name", "生肖牛");
        set_temp("owner", "zooc");
        set_temp("owner_name", "生肖牛");
        ::setup();
}
