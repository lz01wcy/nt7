// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m贰钱[2;37;0m[2;37;0m", ({"zxcbpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是钱贰的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxcb");
        set("owner_name", "钱贰");
        set_temp("owner", "zxcb");
        set_temp("owner_name", "钱贰");
        ::setup();
}
