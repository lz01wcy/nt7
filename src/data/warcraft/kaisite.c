// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("避水金晴售[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "白鹿苍狼的坐骑[2;37;0m
它是白鹿苍狼的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kaisite");
        set("owner_name", "白鹿苍狼");
        set_temp("owner", "kaisite");
        set_temp("owner_name", "白鹿苍狼");
        ::setup();
}
