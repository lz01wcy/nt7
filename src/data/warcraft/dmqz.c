// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("紫云兽[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "紫云兽[2;37;0m
它是小混蛋的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dmqz");
        set("owner_name", "小混蛋");
        set_temp("owner", "dmqz");
        set_temp("owner_name", "小混蛋");
        ::setup();
}
