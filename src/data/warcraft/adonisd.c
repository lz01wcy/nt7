// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m大黄马[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "大黄马[2;37;0m
它是阿多四的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "adonisd");
        set("owner_name", "阿多四");
        set_temp("owner", "adonisd");
        set_temp("owner_name", "阿多四");
        ::setup();
}
