// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m四不象[2;37;0m[2;37;0m", ({"sibuxiang"}));        
        set("gender", "男性");                
        set("long", "  [2;37;0m
它是净秃的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tuzi");
        set("owner_name", "净秃");
        set_temp("owner", "tuzi");
        set_temp("owner_name", "净秃");
        ::setup();
}
