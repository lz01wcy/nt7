// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"sss"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是大力一号的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mana");
        set("owner_name", "大力一号");
        set_temp("owner", "mana");
        set_temp("owner_name", "大力一号");
        ::setup();
}
