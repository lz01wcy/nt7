// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m可口可乐[2;37;0m[2;37;0m", ({"pesif"}));        
        set("gender", "男性");                
        set("long", "可口可乐[2;37;0m
它是阿尔八的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "aliversh");
        set("owner_name", "阿尔八");
        set_temp("owner", "aliversh");
        set_temp("owner_name", "阿尔八");
        ::setup();
}
