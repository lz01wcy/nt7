// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是筑梦者的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dreamer");
        set("owner_name", "筑梦者");
        set_temp("owner", "dreamer");
        set_temp("owner_name", "筑梦者");
        ::setup();
}
