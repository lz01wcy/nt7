// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m通天晓[2;37;0m[2;37;0m", ({"tongtian"}));        
        set("gender", "男性");                
        set("long", "$HIB$通天晓[2;37;0m
它是楚涯的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gbckr");
        set("owner_name", "楚涯");
        set_temp("owner", "gbckr");
        set_temp("owner_name", "楚涯");
        ::setup();
}
