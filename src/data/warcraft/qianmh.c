// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老马[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老马[2;37;0m
它是聆耳倾听的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qianmh");
        set("owner_name", "聆耳倾听");
        set_temp("owner", "qianmh");
        set_temp("owner_name", "聆耳倾听");
        ::setup();
}
