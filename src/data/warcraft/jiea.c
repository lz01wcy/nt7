// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("狂[2;37;0m[2;37;0m", ({"kuangf"}));        
        set("gender", "女性");                
        set("long", "狂风[2;37;0m
它是杰一的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "jiea");
        set("owner_name", "杰一");
        set_temp("owner", "jiea");
        set_temp("owner_name", "杰一");
        ::setup();
}
