// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啾啾挤挤[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "啾啾挤挤[2;37;0m
它是格格瘪的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bbbg");
        set("owner_name", "格格瘪");
        set_temp("owner", "bbbg");
        set_temp("owner_name", "格格瘪");
        ::setup();
}
