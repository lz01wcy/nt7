// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小香猪[2;37;0m[2;37;0m", ({"xxz"}));        
        set("gender", "男性");                
        set("long", "小香猪[2;37;0m
它是不通鞋仔的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "btboots");
        set("owner_name", "不通鞋仔");
        set_temp("owner", "btboots");
        set_temp("owner_name", "不通鞋仔");
        ::setup();
}
