// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是端木睿的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jlfd");
        set("owner_name", "端木睿");
        set_temp("owner", "jlfd");
        set_temp("owner_name", "端木睿");
        ::setup();
}
