// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m四小月份[2;37;0m[2;37;0m", ({"apra"}));        
        set("gender", "男性");                
        set("long", "阿[2;37;0m
它是四月份的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "apr");
        set("owner_name", "四月份");
        set_temp("owner", "apr");
        set_temp("owner_name", "四月份");
        ::setup();
}
