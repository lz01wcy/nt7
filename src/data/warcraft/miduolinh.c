// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("米多小子[2;37;0m[2;37;0m", ({"miduoshou"}));        
        set("gender", "男性");                
        set("long", "米多小子[2;37;0m
它是米多巴的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "miduolinh");
        set("owner_name", "米多巴");
        set_temp("owner", "miduolinh");
        set_temp("owner_name", "米多巴");
        ::setup();
}
