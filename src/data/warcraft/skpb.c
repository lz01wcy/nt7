// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是庞雨的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "skpb");
        set("owner_name", "庞雨");
        set_temp("owner", "skpb");
        set_temp("owner_name", "庞雨");
        ::setup();
}
