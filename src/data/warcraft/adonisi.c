// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m大肥猫[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "大肥猫[2;37;0m
它是阿多九的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "adonisi");
        set("owner_name", "阿多九");
        set_temp("owner", "adonisi");
        set_temp("owner_name", "阿多九");
        ::setup();
}
