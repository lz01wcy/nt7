// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zqxdfhgxc"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是克隆人的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cdcdk");
        set("owner_name", "克隆人");
        set_temp("owner", "cdcdk");
        set_temp("owner_name", "克隆人");
        ::setup();
}
