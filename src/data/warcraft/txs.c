// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "朱[2;37;0m
它是钛享受的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "txs");
        set("owner_name", "钛享受");
        set_temp("owner", "txs");
        set_temp("owner_name", "钛享受");
        ::setup();
}
