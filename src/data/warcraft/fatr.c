// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻兽十[2;37;0m[2;37;0m", ({"aar"}));        
        set("gender", "女性");                
        set("long", "我的魔幻兽[2;37;0m
它是由药的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatr");
        set("owner_name", "由药");
        set_temp("owner", "fatr");
        set_temp("owner_name", "由药");
        ::setup();
}
