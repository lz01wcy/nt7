// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻兽七[2;37;0m[2;37;0m", ({"aao"}));        
        set("gender", "女性");                
        set("long", "我的魔幻兽[2;37;0m
它是姓药的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fato");
        set("owner_name", "姓药");
        set_temp("owner", "fato");
        set_temp("owner_name", "姓药");
        ::setup();
}
