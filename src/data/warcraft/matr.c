// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m肆雪[2;37;0m[2;37;0m", ({"matrpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是雪肆的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matr");
        set("owner_name", "雪肆");
        set_temp("owner", "matr");
        set_temp("owner_name", "雪肆");
        ::setup();
}
