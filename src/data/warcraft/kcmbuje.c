// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小青蛇[2;37;0m[2;37;0m", ({"qingshe"}));        
        set("gender", "男性");                
        set("long", "小青蛇[2;37;0m
它是好名好的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "kcmbuje");
        set("owner_name", "好名好");
        set_temp("owner", "kcmbuje");
        set_temp("owner_name", "好名好");
        ::setup();
}
