// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m一[1;31m日[5m[1;36m六天[2;37;0m[2;37;0m[2;37;0m", ({"sat"}));        
        set("gender", "女性");                
        set("long", "$HIG$一$HIR$日$BLINK$$HIC$六天$NOR$[2;37;0m
它是星期六的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "saturday");
        set("owner_name", "星期六");
        set_temp("owner", "saturday");
        set_temp("owner_name", "星期六");
        ::setup();
}
