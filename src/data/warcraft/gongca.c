// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[1;36m[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "save[2;37;0m
它是宫安的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gongca");
        set("owner_name", "宫安");
        set_temp("owner", "gongca");
        set_temp("owner_name", "宫安");
        ::setup();
}
