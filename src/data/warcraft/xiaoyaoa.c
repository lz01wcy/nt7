// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("第一青龙[2;37;0m[2;37;0m", ({"sleepbaga"}));        
        set("gender", "男性");                
        set("long", "第一青龙[2;37;0m
它是小妖一号的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "xiaoyaoa");
        set("owner_name", "小妖一号");
        set_temp("owner", "xiaoyaoa");
        set_temp("owner_name", "小妖一号");
        ::setup();
}
