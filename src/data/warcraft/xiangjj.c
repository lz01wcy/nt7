// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是大卵泡的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiangjj");
        set("owner_name", "大卵泡");
        set_temp("owner", "xiangjj");
        set_temp("owner_name", "大卵泡");
        ::setup();
}
