// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是开先的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mkd");
        set("owner_name", "开先");
        set_temp("owner", "mkd");
        set_temp("owner_name", "开先");
        ::setup();
}
