// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m东方天八[2;37;0m[2;37;0m", ({"easthh"}));        
        set("gender", "女性");                
        set("long", "$HIW$东方天八[2;37;0m
它是东方八的魔幻兽。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "easth");
        set("owner_name", "东方八");
        set_temp("owner", "easth");
        set_temp("owner_name", "东方八");
        ::setup();
}
