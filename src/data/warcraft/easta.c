// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m东方天一[2;37;0m[2;37;0m", ({"eastaa"}));        
        set("gender", "女性");                
        set("long", "$HIR$东方天一[2;37;0m
它是东方一的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "easta");
        set("owner_name", "东方一");
        set_temp("owner", "easta");
        set_temp("owner_name", "东方一");
        ::setup();
}
