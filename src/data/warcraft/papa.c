// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("欧蕾欧[2;37;0m[2;37;0m", ({"oio"}));        
        set("gender", "男性");                
        set("long", "漂亮的[2;37;0m
它是怕怕的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "papa");
        set("owner_name", "怕怕");
        set_temp("owner", "papa");
        set_temp("owner_name", "怕怕");
        ::setup();
}
