// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m骡子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "女性");                
        set("long", "$HIB$骡子[2;37;0m
它是苦工玖的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xyiii");
        set("owner_name", "苦工玖");
        set_temp("owner", "xyiii");
        set_temp("owner_name", "苦工玖");
        ::setup();
}
