// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大马[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "大马[2;37;0m
它是踢脚的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "kicker");
        set("owner_name", "踢脚");
        set_temp("owner", "kicker");
        set_temp("owner_name", "踢脚");
        ::setup();
}
