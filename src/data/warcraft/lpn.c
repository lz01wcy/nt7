// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m输出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是路旁野草的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lpn");
        set("owner_name", "路旁野草");
        set_temp("owner", "lpn");
        set_temp("owner_name", "路旁野草");
        ::setup();
}
