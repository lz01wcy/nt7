// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小狗[2;37;0m[2;37;0m", ({"benz"}));        
        set("gender", "男性");                
        set("long", "           [2;37;0m
它是扶桑武士的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wushi");
        set("owner_name", "扶桑武士");
        set_temp("owner", "wushi");
        set_temp("owner_name", "扶桑武士");
        ::setup();
}
