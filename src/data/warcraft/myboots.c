// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m一片云彩[1;37m[2;37;0m[2;37;0m", ({"myid"}));        
        set("gender", "女性");                
        set("long", "$HIW$一片云彩$HIW$[2;37;0m
它是家传靴子的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "myboots");
        set("owner_name", "家传靴子");
        set_temp("owner", "myboots");
        set_temp("owner_name", "家传靴子");
        ::setup();
}
