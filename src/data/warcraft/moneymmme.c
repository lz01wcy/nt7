// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("骡子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "男性");                
        set("long", "骡子[2;37;0m
它是钱无良的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "moneymmme");
        set("owner_name", "钱无良");
        set_temp("owner", "moneymmme");
        set_temp("owner_name", "钱无良");
        ::setup();
}
