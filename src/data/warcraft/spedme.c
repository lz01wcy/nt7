// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿娇[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "阿娇[2;37;0m
它是祖金殿的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "spedme");
        set("owner_name", "祖金殿");
        set_temp("owner", "spedme");
        set_temp("owner_name", "祖金殿");
        ::setup();
}
