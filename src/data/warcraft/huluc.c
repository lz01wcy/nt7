// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m大白猪[2;37;0m[2;37;0m", ({"omo"}));        
        set("gender", "男性");                
        set("long", "$HIW$大白猪[2;37;0m
它是葫芦水娃的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "huluc");
        set("owner_name", "葫芦水娃");
        set_temp("owner", "huluc");
        set_temp("owner_name", "葫芦水娃");
        ::setup();
}
