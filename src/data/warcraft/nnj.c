// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是阑额娘个的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nnj");
        set("owner_name", "阑额娘个");
        set_temp("owner", "nnj");
        set_temp("owner_name", "阑额娘个");
        ::setup();
}
