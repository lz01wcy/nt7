// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37;41m滴滴[2;37;0m[2;37;0m", ({"zuesds"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是叶四的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zuesd");
        set("owner_name", "叶四");
        set_temp("owner", "zuesd");
        set_temp("owner_name", "叶四");
        ::setup();
}
