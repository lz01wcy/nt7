// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m傻龙[2;37;0m[2;37;0m", ({"shalong"}));        
        set("gender", "男性");                
        set("long", "傻呼呼的龙[2;37;0m
它是读者无聊的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "reader");
        set("owner_name", "读者无聊");
        set_temp("owner", "reader");
        set_temp("owner_name", "读者无聊");
        ::setup();
}
