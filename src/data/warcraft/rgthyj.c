// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老马[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老马[2;37;0m
它是赫连春水的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "rgthyj");
        set("owner_name", "赫连春水");
        set_temp("owner", "rgthyj");
        set_temp("owner_name", "赫连春水");
        ::setup();
}
