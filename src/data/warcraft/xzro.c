// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地图精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "23456[2;37;0m
它是出云酉鸡的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xzro");
        set("owner_name", "出云酉鸡");
        set_temp("owner", "xzro");
        set_temp("owner_name", "出云酉鸡");
        ::setup();
}
