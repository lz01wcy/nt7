// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龙[2;37;0m[2;37;0m", ({"oasispet"}));        
        set("gender", "男性");                
        set("long", "描述什么[2;37;0m
它是绿洲绿的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "oasis");
        set("owner_name", "绿洲绿");
        set_temp("owner", "oasis");
        set_temp("owner_name", "绿洲绿");
        ::setup();
}
