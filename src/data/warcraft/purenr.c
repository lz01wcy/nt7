// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "鸟类的一种。[2;37;0m
它是仆人的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "purenr");
        set("owner_name", "仆人");
        set_temp("owner", "purenr");
        set_temp("owner_name", "仆人");
        ::setup();
}
