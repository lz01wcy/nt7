// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuquedd"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是姓名四米的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "debugdd");
        set("owner_name", "姓名四米");
        set_temp("owner", "debugdd");
        set_temp("owner_name", "姓名四米");
        ::setup();
}
