// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是丸梅梅的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wanmm");
        set("owner_name", "丸梅梅");
        set_temp("owner", "wanmm");
        set_temp("owner_name", "丸梅梅");
        ::setup();
}
