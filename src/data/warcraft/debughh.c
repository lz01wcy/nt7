// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuquehh"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是姓名八米的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "debughh");
        set("owner_name", "姓名八米");
        set_temp("owner", "debughh");
        set_temp("owner_name", "姓名八米");
        ::setup();
}
