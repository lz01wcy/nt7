// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("翠花[2;37;0m[2;37;0m", ({"cuihua"}));        
        set("gender", "男性");                
        set("long", "该上酸菜了...[2;37;0m
它是阿虎的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ahu");
        set("owner_name", "阿虎");
        set_temp("owner", "ahu");
        set_temp("owner_name", "阿虎");
        ::setup();
}
