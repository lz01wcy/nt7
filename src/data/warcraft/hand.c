// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "女性");                
        set("long", "白虎[2;37;0m
它是小手的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hand");
        set("owner_name", "小手");
        set_temp("owner", "hand");
        set_temp("owner_name", "小手");
        ::setup();
}
