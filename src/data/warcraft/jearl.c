// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m小[1;36m雉[1;36m[2;37;0m[2;37;0m", ({"zhi"}));        
        set("gender", "男性");                
        set("long", "看起来像是传说中的龙[2;37;0m
它是小诛的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "jearl");
        set("owner_name", "小诛");
        set_temp("owner", "jearl");
        set_temp("owner_name", "小诛");
        ::setup();
}
