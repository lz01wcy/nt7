// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小马[2;37;0m[2;37;0m", ({"xiaoma"}));        
        set("gender", "女性");                
        set("long", "小马[2;37;0m
它是华清散的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "hxxsan");
        set("owner_name", "华清散");
        set_temp("owner", "hxxsan");
        set_temp("owner_name", "华清散");
        ::setup();
}
