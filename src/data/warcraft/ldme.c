// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("猪雀[2;37;0m[2;37;0m", ({"zqqqq"}));        
        set("gender", "女性");                
        set("long", "猪[2;37;0m
它是联丹的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ldme");
        set("owner_name", "联丹");
        set_temp("owner", "ldme");
        set_temp("owner_name", "联丹");
        ::setup();
}
