// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m青龙[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "龙[2;37;0m
它是不知道的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "sim");
        set("owner_name", "不知道");
        set_temp("owner", "sim");
        set_temp("owner_name", "不知道");
        ::setup();
}
