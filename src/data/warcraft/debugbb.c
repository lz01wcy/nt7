// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuquebb"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是姓名二米的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "debugbb");
        set("owner_name", "姓名二米");
        set_temp("owner", "debugbb");
        set_temp("owner_name", "姓名二米");
        ::setup();
}
