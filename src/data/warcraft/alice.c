// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是爱丽丝的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "alice");
        set("owner_name", "爱丽丝");
        set_temp("owner", "alice");
        set_temp("owner_name", "爱丽丝");
        ::setup();
}
