// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("竹笛[2;37;0m[2;37;0m", ({"ggg"}));        
        set("gender", "男性");                
        set("long", "懒[2;37;0m
它是梦醉的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gxh");
        set("owner_name", "梦醉");
        set_temp("owner", "gxh");
        set_temp("owner_name", "梦醉");
        ::setup();
}
