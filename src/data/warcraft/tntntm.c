// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("柏芝[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "柏芝[2;37;0m
它是元十三限的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tntntm");
        set("owner_name", "元十三限");
        set_temp("owner", "tntntm");
        set_temp("owner_name", "元十三限");
        ::setup();
}
