// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("苍井已空[2;37;0m[2;37;0m", ({"along"}));        
        set("gender", "男性");                
        set("long", "喔唷[2;37;0m
它是狂三的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "kuangc");
        set("owner_name", "狂三");
        set_temp("owner", "kuangc");
        set_temp("owner_name", "狂三");
        ::setup();
}
