// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m青龙[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "$HIG$青龙[2;37;0m
它是笑三少的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "sanshao");
        set("owner_name", "笑三少");
        set_temp("owner", "sanshao");
        set_temp("owner_name", "笑三少");
        ::setup();
}
