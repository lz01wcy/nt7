// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"fkaa"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是若开的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "rkj");
        set("owner_name", "若开");
        set_temp("owner", "rkj");
        set_temp("owner_name", "若开");
        ::setup();
}
