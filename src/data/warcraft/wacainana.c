// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是挖菜男一的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wacainana");
        set("owner_name", "挖菜男一");
        set_temp("owner", "wacainana");
        set_temp("owner_name", "挖菜男一");
        ::setup();
}
