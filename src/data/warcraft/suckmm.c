// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m保时捷[2;37;0m[2;37;0m", ({"porche"}));        
        set("gender", "女性");                
        set("long", "运输工具[2;37;0m
它是西门夫人的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "suckmm");
        set("owner_name", "西门夫人");
        set_temp("owner", "suckmm");
        set_temp("owner_name", "西门夫人");
        ::setup();
}
