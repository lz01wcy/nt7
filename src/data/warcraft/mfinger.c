// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m制式巨龙[2;37;0m[2;37;0m", ({"mfinger_dragon"}));        
        set("gender", "男性");                
        set("long", "一头军用制式巨龙。[2;37;0m
它是指套仓库的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "mfinger");
        set("owner_name", "指套仓库");
        set_temp("owner", "mfinger");
        set_temp("owner_name", "指套仓库");
        ::setup();
}
