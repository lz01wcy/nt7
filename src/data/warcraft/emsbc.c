// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是男神来了的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "emsbc");
        set("owner_name", "男神来了");
        set_temp("owner", "emsbc");
        set_temp("owner_name", "男神来了");
        ::setup();
}
