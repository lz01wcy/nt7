// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"fkaa"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是曲涂的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qkt");
        set("owner_name", "曲涂");
        set_temp("owner", "qkt");
        set_temp("owner_name", "曲涂");
        ::setup();
}
