// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qiling"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是运镖乙的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "btyunbiao");
        set("owner_name", "运镖乙");
        set_temp("owner", "btyunbiao");
        set_temp("owner_name", "运镖乙");
        ::setup();
}
