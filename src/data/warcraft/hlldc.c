// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("最爱白虎[2;37;0m[2;37;0m", ({"hlldcbh"}));        
        set("gender", "女性");                
        set("long", "最爱白虎[2;37;0m
它是文东三号的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hlldc");
        set("owner_name", "文东三号");
        set_temp("owner", "hlldc");
        set_temp("owner_name", "文东三号");
        ::setup();
}
