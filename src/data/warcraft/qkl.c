// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"fkaa"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是曲弩的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qkl");
        set("owner_name", "曲弩");
        set_temp("owner", "qkl");
        set_temp("owner_name", "曲弩");
        ::setup();
}
