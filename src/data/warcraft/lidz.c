// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"lidxa"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是星真的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidz");
        set("owner_name", "星真");
        set_temp("owner", "lidz");
        set_temp("owner_name", "星真");
        ::setup();
}
