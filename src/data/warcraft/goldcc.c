// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("狐[2;37;0m[2;37;0m", ({"goldccc"}));        
        set("gender", "男性");                
        set("long", "狐[2;37;0m
它是金狐的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "goldcc");
        set("owner_name", "金狐");
        set_temp("owner", "goldcc");
        set_temp("owner_name", "金狐");
        ::setup();
}
