// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "我有一头小毛驴我从来也不骑[2;37;0m
它是宇文成都的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lovelm");
        set("owner_name", "宇文成都");
        set_temp("owner", "lovelm");
        set_temp("owner_name", "宇文成都");
        ::setup();
}
