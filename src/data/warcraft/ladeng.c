// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m奥粑马[2;37;0m[2;37;0m", ({"abm"}));        
        set("gender", "男性");                
        set("long", "asdf[2;37;0m
它是拉灯的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ladeng");
        set("owner_name", "拉灯");
        set_temp("owner", "ladeng");
        set_temp("owner_name", "拉灯");
        ::setup();
}
