// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幻灵[2;37;0m[2;37;0m", ({"mvm"}));        
        set("gender", "女性");                
        set("long", "卓越幻灵[2;37;0m
它是澄叶的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "elayken");
        set("owner_name", "澄叶");
        set_temp("owner", "elayken");
        set_temp("owner_name", "澄叶");
        ::setup();
}
