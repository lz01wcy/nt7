// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m云苓[2;37;0m[2;37;0m", ({"xxtestcc"}));        
        set("gender", "男性");                
        set("long", "阿[2;37;0m
它是星宿云苓的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xxtestc");
        set("owner_name", "星宿云苓");
        set_temp("owner", "xxtestc");
        set_temp("owner_name", "星宿云苓");
        ::setup();
}
