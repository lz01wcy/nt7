// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火麒麟[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "火麒麟[2;37;0m
它是罗十三的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wakt");
        set("owner_name", "罗十三");
        set_temp("owner", "wakt");
        set_temp("owner_name", "罗十三");
        ::setup();
}
