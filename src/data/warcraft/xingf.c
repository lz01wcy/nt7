// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是星血一的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xingf");
        set("owner_name", "星血一");
        set_temp("owner", "xingf");
        set_temp("owner_name", "星血一");
        ::setup();
}
