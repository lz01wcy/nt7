// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"iccc"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是张杨的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "icc");
        set("owner_name", "张杨");
        set_temp("owner", "icc");
        set_temp("owner_name", "张杨");
        ::setup();
}
