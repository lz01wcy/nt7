// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行车[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "alias m whistle zxcc[2;37;0m
它是黄金糖的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "golddmm");
        set("owner_name", "黄金糖");
        set_temp("owner", "golddmm");
        set_temp("owner_name", "黄金糖");
        ::setup();
}
