// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ddooo"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是堂噢的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ddo");
        set("owner_name", "堂噢");
        set_temp("owner", "ddo");
        set_temp("owner_name", "堂噢");
        ::setup();
}
