// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龙[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "小龙[2;37;0m
它是嘎嘎嘎的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "wwwxx");
        set("owner_name", "嘎嘎嘎");
        set_temp("owner", "wwwxx");
        set_temp("owner_name", "嘎嘎嘎");
        ::setup();
}
