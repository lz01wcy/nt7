// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小猪[2;37;0m[2;37;0m", ({"kok"}));        
        set("gender", "男性");                
        set("long", ",,,[2;37;0m
它是狐肆的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "kkkn");
        set("owner_name", "狐肆");
        set_temp("owner", "kkkn");
        set_temp("owner_name", "狐肆");
        ::setup();
}
