// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老马[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老马[2;37;0m
它是把酒迎风的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qianmn");
        set("owner_name", "把酒迎风");
        set_temp("owner", "qianmn");
        set_temp("owner_name", "把酒迎风");
        ::setup();
}
