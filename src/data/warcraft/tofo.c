// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飞云[2;37;0m[2;37;0m", ({"flycloud"}));        
        set("gender", "男性");                
        set("long", "无[2;37;0m
它是谢闲的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tofo");
        set("owner_name", "谢闲");
        set_temp("owner", "tofo");
        set_temp("owner_name", "谢闲");
        ::setup();
}
