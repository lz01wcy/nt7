// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("巧[2;37;0m[2;37;0m", ({"qiao"}));        
        set("gender", "女性");                
        set("long", "巧[2;37;0m
它是吖什的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "gggc");
        set("owner_name", "吖什");
        set_temp("owner", "gggc");
        set_temp("owner_name", "吖什");
        ::setup();
}
