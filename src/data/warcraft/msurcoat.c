// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m制式巨龙[2;37;0m[2;37;0m", ({"marmor_dragon"}));        
        set("gender", "男性");                
        set("long", "一头军用制式巨龙。[2;37;0m
它是披风仓库的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "msurcoat");
        set("owner_name", "披风仓库");
        set_temp("owner", "msurcoat");
        set_temp("owner_name", "披风仓库");
        ::setup();
}
