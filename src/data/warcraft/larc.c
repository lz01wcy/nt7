// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m绿色螳螂[2;37;0m[2;37;0m", ({"larcs"}));        
        set("gender", "男性");                
        set("long", "我的宠物[2;37;0m
它是死缘的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "larc");
        set("owner_name", "死缘");
        set_temp("owner", "larc");
        set_temp("owner_name", "死缘");
        ::setup();
}
