// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m影子[2;37;0m[2;37;0m", ({"yinzi"}));        
        set("gender", "男性");                
        set("long", "影子[2;37;0m
它是影舞的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ywu");
        set("owner_name", "影舞");
        set_temp("owner", "ywu");
        set_temp("owner_name", "影舞");
        ::setup();
}
