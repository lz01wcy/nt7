// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻兽六[2;37;0m[2;37;0m", ({"aan"}));        
        set("gender", "女性");                
        set("long", "我的魔幻兽[2;37;0m
它是高药的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatn");
        set("owner_name", "高药");
        set_temp("owner", "fatn");
        set_temp("owner_name", "高药");
        ::setup();
}
