// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m青玉麒麟[2;37;0m[2;37;0m", ({"qi_linb"}));        
        set("gender", "女性");                
        set("long", "青玉麒麟[2;37;0m
它是星宿老魔的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "smjb");
        set("owner_name", "星宿老魔");
        set_temp("owner", "smjb");
        set_temp("owner_name", "星宿老魔");
        ::setup();
}
