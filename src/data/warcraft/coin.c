// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("战争狂龙[2;37;0m[2;37;0m", ({"war"}));        
        set("gender", "男性");                
        set("long", "来摸摸[2;37;0m
它是澄铜的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "coin");
        set("owner_name", "澄铜");
        set_temp("owner", "coin");
        set_temp("owner_name", "澄铜");
        ::setup();
}
