// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啪啪啪[2;37;0m[2;37;0m", ({"papapa"}));        
        set("gender", "女性");                
        set("long", "啪啪啪[2;37;0m
它是海之蓝的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "hzlancao");
        set("owner_name", "海之蓝");
        set_temp("owner", "hzlancao");
        set_temp("owner_name", "海之蓝");
        ::setup();
}
