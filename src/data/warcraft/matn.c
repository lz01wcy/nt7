// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m柒雪[2;37;0m[2;37;0m", ({"matnpet"}));        
        set("gender", "男性");                
        set("long", "美丽中国梦[2;37;0m
它是雪柒的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matn");
        set("owner_name", "雪柒");
        set_temp("owner", "matn");
        set_temp("owner_name", "雪柒");
        ::setup();
}
