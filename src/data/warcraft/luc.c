// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m摇钱树[2;37;0m[2;37;0m", ({"qlong"}));        
        set("gender", "男性");                
        set("long", "摇钱树[2;37;0m
它是采花三的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "luc");
        set("owner_name", "采花三");
        set_temp("owner", "luc");
        set_temp("owner_name", "采花三");
        ::setup();
}
