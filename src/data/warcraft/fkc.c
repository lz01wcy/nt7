// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"fkcc"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是福才的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fkc");
        set("owner_name", "福才");
        set_temp("owner", "fkc");
        set_temp("owner_name", "福才");
        ::setup();
}
