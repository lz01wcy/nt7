// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "一麒麟[2;37;0m
它是爱罗丽的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "emss");
        set("owner_name", "爱罗丽");
        set_temp("owner", "emss");
        set_temp("owner_name", "爱罗丽");
        ::setup();
}
