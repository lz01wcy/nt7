// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小头[2;37;0m[2;37;0m", ({"xstone"}));        
        set("gender", "男性");                
        set("long", "小头[2;37;0m
它是石头的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "stone");
        set("owner_name", "石头");
        set_temp("owner", "stone");
        set_temp("owner_name", "石头");
        ::setup();
}
