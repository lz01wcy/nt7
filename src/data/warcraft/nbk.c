// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小蕾[2;37;0m[2;37;0m", ({"xiaolei"}));        
        set("gender", "男性");                
        set("long", "一日千里[2;37;0m
它是李煜的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "nbk");
        set("owner_name", "李煜");
        set_temp("owner", "nbk");
        set_temp("owner_name", "李煜");
        ::setup();
}
