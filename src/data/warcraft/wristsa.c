// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿龙[2;37;0m[2;37;0m", ({"along"}));        
        set("gender", "男性");                
        set("long", "万恶[2;37;0m
它是大腕的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "wristsa");
        set("owner_name", "大腕");
        set_temp("owner", "wristsa");
        set_temp("owner_name", "大腕");
        ::setup();
}
