// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m移动休息室[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "  [2;37;0m
它是打钱一的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wudanga");
        set("owner_name", "打钱一");
        set_temp("owner", "wudanga");
        set_temp("owner_name", "打钱一");
        ::setup();
}
