// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小香猪[2;37;0m[2;37;0m", ({"xxz"}));        
        set("gender", "男性");                
        set("long", "小香猪[2;37;0m
它是不通侍刀的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "btblade");
        set("owner_name", "不通侍刀");
        set_temp("owner", "btblade");
        set_temp("owner_name", "不通侍刀");
        ::setup();
}
