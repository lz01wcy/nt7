// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m关关[2;37;0m[2;37;0m", ({"kwankwan"}));        
        set("gender", "男性");                
        set("long", "这是一只关关[2;37;0m
它是奴才五号的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "kwanfive");
        set("owner_name", "奴才五号");
        set_temp("owner", "kwanfive");
        set_temp("owner_name", "奴才五号");
        ::setup();
}
