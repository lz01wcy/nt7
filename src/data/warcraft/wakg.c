// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火麒麟[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "火麒麟[2;37;0m
它是罗贰的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wakg");
        set("owner_name", "罗贰");
        set_temp("owner", "wakg");
        set_temp("owner_name", "罗贰");
        ::setup();
}
