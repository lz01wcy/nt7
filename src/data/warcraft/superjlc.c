// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "finish[2;37;0m
它是不灭剑体的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "superjlc");
        set("owner_name", "不灭剑体");
        set_temp("owner", "superjlc");
        set_temp("owner_name", "不灭剑体");
        ::setup();
}
