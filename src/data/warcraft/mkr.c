// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"fkaa"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是曼投的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mkr");
        set("owner_name", "曼投");
        set_temp("owner", "mkr");
        set_temp("owner_name", "曼投");
        ::setup();
}
