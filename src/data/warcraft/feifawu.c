// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "老虎[2;37;0m
它是牛气牛的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "feifawu");
        set("owner_name", "牛气牛");
        set_temp("owner", "feifawu");
        set_temp("owner_name", "牛气牛");
        ::setup();
}
