// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m壹雪[2;37;0m[2;37;0m", ({"matopet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是啦呱的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kos");
        set("owner_name", "啦呱");
        set_temp("owner", "kos");
        set_temp("owner_name", "啦呱");
        ::setup();
}
