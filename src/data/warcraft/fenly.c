// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蓝色忧郁[2;37;0m[2;37;0m", ({"food"}));        
        set("gender", "男性");                
        set("long", "蓝色忧郁[2;37;0m
它是唐宁的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "fenly");
        set("owner_name", "唐宁");
        set_temp("owner", "fenly");
        set_temp("owner_name", "唐宁");
        ::setup();
}
