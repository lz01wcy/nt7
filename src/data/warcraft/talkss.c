// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玄武[2;37;0m[2;37;0m", ({"help_nick"}));        
        set("gender", "男性");                
        set("long", "玄武[2;37;0m
它是燕赤霞的魔幻兽。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "talkss");
        set("owner_name", "燕赤霞");
        set_temp("owner", "talkss");
        set_temp("owner_name", "燕赤霞");
        ::setup();
}
