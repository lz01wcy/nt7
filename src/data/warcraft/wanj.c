// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m平一指[2;37;0m[2;37;0m", ({"qwe"}));        
        set("gender", "男性");                
        set("long", "shit[2;37;0m
它是丸玖的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "wanj");
        set("owner_name", "丸玖");
        set_temp("owner", "wanj");
        set_temp("owner_name", "丸玖");
        ::setup();
}
