// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大料三号兽[2;37;0m[2;37;0m", ({"pphomethree"}));        
        set("gender", "女性");                
        set("long", "大料三号兽[2;37;0m
它是大料三号的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "phomethree");
        set("owner_name", "大料三号");
        set_temp("owner", "phomethree");
        set_temp("owner_name", "大料三号");
        ::setup();
}
