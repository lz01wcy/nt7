// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行车[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行车[2;37;0m
它是孙子帆的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "gagbmnrma");
        set("owner_name", "孙子帆");
        set_temp("owner", "gagbmnrma");
        set_temp("owner_name", "孙子帆");
        ::setup();
}
