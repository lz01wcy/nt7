// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是丸呦呦的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wanuu");
        set("owner_name", "丸呦呦");
        set_temp("owner", "wanuu");
        set_temp("owner_name", "丸呦呦");
        ::setup();
}
