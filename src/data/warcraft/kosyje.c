// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m伍研[2;37;0m[2;37;0m", ({"kosyjepet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是研伍的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosyje");
        set("owner_name", "研伍");
        set_temp("owner", "kosyje");
        set_temp("owner_name", "研伍");
        ::setup();
}
