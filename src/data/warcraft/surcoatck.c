// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("追风兽[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "追风兽[2;37;0m
它是披风仓的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "surcoatck");
        set("owner_name", "披风仓");
        set_temp("owner", "surcoatck");
        set_temp("owner_name", "披风仓");
        ::setup();
}
