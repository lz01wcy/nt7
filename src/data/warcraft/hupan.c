// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("电眼飞狐[2;37;0m[2;37;0m", ({"feihu"}));        
        set("gender", "男性");                
        set("long", "电眼飞狐[2;37;0m
它是张湖畔的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hupan");
        set("owner_name", "张湖畔");
        set_temp("owner", "hupan");
        set_temp("owner_name", "张湖畔");
        ::setup();
}
