// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地图精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "1324f[2;37;0m
它是小兵壬的魔幻兽。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xbj");
        set("owner_name", "小兵壬");
        set_temp("owner", "xbj");
        set_temp("owner_name", "小兵壬");
        ::setup();
}
