// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("柏芝[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "柏芝[2;37;0m
它是曹国舅的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tntntg");
        set("owner_name", "曹国舅");
        set_temp("owner", "tntntg");
        set_temp("owner_name", "曹国舅");
        ::setup();
}
