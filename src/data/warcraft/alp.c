// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哈哈哈[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "do l,hp[2;37;0m
它是玩单的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "alp");
        set("owner_name", "玩单");
        set_temp("owner", "alp");
        set_temp("owner_name", "玩单");
        ::setup();
}
