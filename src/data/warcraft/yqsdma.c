// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行车[2;37;0m[2;37;0m", ({"zixc"}));        
        set("gender", "男性");                
        set("long", "自行车[2;37;0m
它是绝代风华的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yqsdma");
        set("owner_name", "绝代风华");
        set_temp("owner", "yqsdma");
        set_temp("owner_name", "绝代风华");
        ::setup();
}
