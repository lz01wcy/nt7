// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("米四麒麟[2;37;0m[2;37;0m", ({"miduoqilins"}));        
        set("gender", "男性");                
        set("long", "米四麒麟[2;37;0m
它是米多四的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "miduolind");
        set("owner_name", "米多四");
        set_temp("owner", "miduolind");
        set_temp("owner_name", "米多四");
        ::setup();
}
