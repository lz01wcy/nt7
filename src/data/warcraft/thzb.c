// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m驴[1;33m车[2;37;0m[2;37;0m", ({"lvche"}));        
        set("gender", "男性");                
        set("long", "这是长工们的坐骑[2;37;0m
它是长工乙的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "thzb");
        set("owner_name", "长工乙");
        set_temp("owner", "thzb");
        set_temp("owner_name", "长工乙");
        ::setup();
}
