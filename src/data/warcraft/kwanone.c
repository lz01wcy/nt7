// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m关关[2;37;0m[2;37;0m", ({"kwankwan"}));        
        set("gender", "男性");                
        set("long", "关关[2;37;0m
它是奴才一号的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kwanone");
        set("owner_name", "奴才一号");
        set_temp("owner", "kwanone");
        set_temp("owner_name", "奴才一号");
        ::setup();
}
