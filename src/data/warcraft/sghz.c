// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙狗[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "女性");                
        set("long", "神仙狗[2;37;0m
它是龙仓库的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "sghz");
        set("owner_name", "龙仓库");
        set_temp("owner", "sghz");
        set_temp("owner_name", "龙仓库");
        ::setup();
}
