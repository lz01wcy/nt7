// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("快[2;37;0m[2;37;0m", ({"kuai"}));        
        set("gender", "男性");                
        set("long", "快[2;37;0m
它是鬼谷的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ara");
        set("owner_name", "鬼谷");
        set_temp("owner", "ara");
        set_temp("owner_name", "鬼谷");
        ::setup();
}
