// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m八小月份[2;37;0m[2;37;0m", ({"auga"}));        
        set("gender", "男性");                
        set("long", "阿[2;37;0m
它是八月份的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "aug");
        set("owner_name", "八月份");
        set_temp("owner", "aug");
        set_temp("owner_name", "八月份");
        ::setup();
}
