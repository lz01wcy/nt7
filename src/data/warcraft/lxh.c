// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m输出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是胡家放开的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lxh");
        set("owner_name", "胡家放开");
        set_temp("owner", "lxh");
        set_temp("owner_name", "胡家放开");
        ::setup();
}
