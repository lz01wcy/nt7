// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m子弹[2;37;0m[2;37;0m", ({"sudu"}));        
        set("gender", "男性");                
        set("long", "速度无止尽[2;37;0m
它是火云邪神的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "speed");
        set("owner_name", "火云邪神");
        set_temp("owner", "speed");
        set_temp("owner_name", "火云邪神");
        ::setup();
}
