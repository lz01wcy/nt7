// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("五花马[2;37;0m[2;37;0m", ({"omo"}));        
        set("gender", "女性");                
        set("long", "五花马[2;37;0m
它是周仓八的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xpa");
        set("owner_name", "周仓八");
        set_temp("owner", "xpa");
        set_temp("owner_name", "周仓八");
        ::setup();
}
