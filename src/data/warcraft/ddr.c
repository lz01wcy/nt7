// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ddrr"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是堂日的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ddr");
        set("owner_name", "堂日");
        set_temp("owner", "ddr");
        set_temp("owner_name", "堂日");
        ::setup();
}
