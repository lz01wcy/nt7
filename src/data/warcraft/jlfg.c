// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是百里门的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jlfg");
        set("owner_name", "百里门");
        set_temp("owner", "jlfg");
        set_temp("owner_name", "百里门");
        ::setup();
}
