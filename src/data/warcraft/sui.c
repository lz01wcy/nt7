// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m火[2;37;0m[2;37;0m", ({"huo"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$HIR$火[2;37;0m
它是随性的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sui");
        set("owner_name", "随性");
        set_temp("owner", "sui");
        set_temp("owner_name", "随性");
        ::setup();
}
