// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白麒麟[2;37;0m[2;37;0m", ({"tntnt"}));        
        set("gender", "女性");                
        set("long", "give kuang dizang zhishi[2;37;0m
它是零零发的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tntc");
        set("owner_name", "零零发");
        set_temp("owner", "tntc");
        set_temp("owner_name", "零零发");
        ::setup();
}
