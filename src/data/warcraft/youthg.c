// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m不[1;35m帅[1;36m脸上[1;31m踹[2;37;0m[2;37;0m[2;37;0m", ({"guys"}));        
        set("gender", "男性");                
        set("long", "不帅脸上踹[2;37;0m
它是骚年的魔幻兽。
");
        set("race_type", "青龙");
        set("magic/type", "wood");
        set("owner", "youthg");
        set("owner_name", "骚年");
        set_temp("owner", "youthg");
        set_temp("owner_name", "骚年");
        ::setup();
}
