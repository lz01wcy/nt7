// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龙[2;37;0m[2;37;0m", ({"xdragon"}));        
        set("gender", "男性");                
        set("long", "小龙[2;37;0m
它是大米的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "ylonga");
        set("owner_name", "大米");
        set_temp("owner", "ylonga");
        set_temp("owner_name", "大米");
        ::setup();
}
