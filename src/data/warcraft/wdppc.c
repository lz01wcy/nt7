// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("偶的[2;37;0m[2;37;0m", ({"xwdppc"}));        
        set("gender", "女性");                
        set("long", "偶的[2;37;0m
它是武当师三的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdppc");
        set("owner_name", "武当师三");
        set_temp("owner", "wdppc");
        set_temp("owner_name", "武当师三");
        ::setup();
}
