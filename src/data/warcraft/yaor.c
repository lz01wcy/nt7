// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m拉土车[33m[2;37;0m[2;37;0m", ({"yaors"}));        
        set("gender", "女性");                
        set("long", "我的坐骑[2;37;0m
它是菜么的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yaor");
        set("owner_name", "菜么");
        set_temp("owner", "yaor");
        set_temp("owner_name", "菜么");
        ::setup();
}
