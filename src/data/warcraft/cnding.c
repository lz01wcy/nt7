// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qiling"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是菜农丁的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cnding");
        set("owner_name", "菜农丁");
        set_temp("owner", "cnding");
        set_temp("owner_name", "菜农丁");
        ::setup();
}
