// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小星星[2;37;0m[2;37;0m", ({"goldxxx"}));        
        set("gender", "男性");                
        set("long", "小星星[2;37;0m
它是金叉的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "goldxx");
        set("owner_name", "金叉");
        set_temp("owner", "goldxx");
        set_temp("owner_name", "金叉");
        ::setup();
}
