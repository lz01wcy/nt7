// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"ddddd"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是答迷的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "femm");
        set("owner_name", "答迷");
        set_temp("owner", "femm");
        set_temp("owner_name", "答迷");
        ::setup();
}
