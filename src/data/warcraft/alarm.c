// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m饕餮[2;37;0m[2;37;0m", ({"greedy"}));        
        set("gender", "男性");                
        set("long", "有首无身，食人未咽，害及其身，以言报更也![2;37;0m
它是浮生若梦的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "alarm");
        set("owner_name", "浮生若梦");
        set_temp("owner", "alarm");
        set_temp("owner_name", "浮生若梦");
        ::setup();
}
