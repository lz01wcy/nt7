// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "鸟[2;37;0m
它是长小媚的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "gongem");
        set("owner_name", "长小媚");
        set_temp("owner", "gongem");
        set_temp("owner_name", "长小媚");
        ::setup();
}
