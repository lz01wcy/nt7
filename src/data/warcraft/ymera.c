// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("笑话[2;37;0m[2;37;0m", ({"xiaohua"}));        
        set("gender", "男性");                
        set("long", "sadf[2;37;0m
它是新瘦的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "ymera");
        set("owner_name", "新瘦");
        set_temp("owner", "ymera");
        set_temp("owner_name", "新瘦");
        ::setup();
}
