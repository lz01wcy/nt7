// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m凤凰[1;36m涅[1;32m磐[2;37;0m[2;37;0m[2;37;0m", ({"niepan"}));        
        set("gender", "女性");                
        set("long", "涅磐重生[2;37;0m
它是夭天的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "enticing");
        set("owner_name", "夭天");
        set_temp("owner", "enticing");
        set_temp("owner_name", "夭天");
        ::setup();
}
