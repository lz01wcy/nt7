// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飞龙[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "飞龙在天[2;37;0m
它是六脉无剑的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "kztguiji");
        set("owner_name", "六脉无剑");
        set_temp("owner", "kztguiji");
        set_temp("owner_name", "六脉无剑");
        ::setup();
}
