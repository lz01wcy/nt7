// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m拾研[2;37;0m[2;37;0m", ({"kosyjjpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是研拾的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosyjj");
        set("owner_name", "研拾");
        set_temp("owner", "kosyjj");
        set_temp("owner_name", "研拾");
        ::setup();
}
