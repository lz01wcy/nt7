// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("及时雨[2;37;0m[2;37;0m", ({"lsjsy"}));        
        set("gender", "男性");                
        set("long", "及时雨[2;37;0m
它是打包五号的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bage");
        set("owner_name", "打包五号");
        set_temp("owner", "bage");
        set_temp("owner_name", "打包五号");
        ::setup();
}
