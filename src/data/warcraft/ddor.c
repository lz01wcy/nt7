// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m冥火[2;37;0m[2;37;0m", ({"qilin_ddor"}));        
        set("gender", "女性");                
        set("long", "冥火[2;37;0m
它是偷天的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ddor");
        set("owner_name", "偷天");
        set_temp("owner", "ddor");
        set_temp("owner_name", "偷天");
        ::setup();
}
