// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("日久生情[2;37;0m[2;37;0m", ({"rii"}));        
        set("gender", "男性");                
        set("long", "日久生情[2;37;0m
它是一次陆天的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "skyf");
        set("owner_name", "一次陆天");
        set_temp("owner", "skyf");
        set_temp("owner_name", "一次陆天");
        ::setup();
}
