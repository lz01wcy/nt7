// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m废物[2;37;0m[2;37;0m", ({"jiji"}));        
        set("gender", "女性");                
        set("long", "a [2;37;0m
它是金卡的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "goldw");
        set("owner_name", "金卡");
        set_temp("owner", "goldw");
        set_temp("owner_name", "金卡");
        ::setup();
}
