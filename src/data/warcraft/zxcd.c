// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m肆钱[2;37;0m[2;37;0m", ({"zxcdpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是钱肆的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxcd");
        set("owner_name", "钱肆");
        set_temp("owner", "zxcd");
        set_temp("owner_name", "钱肆");
        ::setup();
}
