// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m移动休息室[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "  [2;37;0m
它是打钱四的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wudangd");
        set("owner_name", "打钱四");
        set_temp("owner", "wudangd");
        set_temp("owner_name", "打钱四");
        ::setup();
}
