// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("第二青龙[2;37;0m[2;37;0m", ({"sleepbagb"}));        
        set("gender", "男性");                
        set("long", "第二青龙[2;37;0m
它是小妖二号的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "xiaoyaob");
        set("owner_name", "小妖二号");
        set_temp("owner", "xiaoyaob");
        set_temp("owner_name", "小妖二号");
        ::setup();
}
