// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("金将军[2;37;0m[2;37;0m", ({"yaojjj"}));        
        set("gender", "男性");                
        set("long", "金将军[2;37;0m
它是药紧急的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaojj");
        set("owner_name", "药紧急");
        set_temp("owner", "yaojj");
        set_temp("owner_name", "药紧急");
        ::setup();
}
