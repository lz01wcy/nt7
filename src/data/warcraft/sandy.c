// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小麒麟[2;37;0m[2;37;0m", ({"little_hei"}));        
        set("gender", "女性");                
        set("long", "小麒麟一只[2;37;0m
它是欧阳问天的魔幻兽。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sandy");
        set("owner_name", "欧阳问天");
        set_temp("owner", "sandy");
        set_temp("owner_name", "欧阳问天");
        ::setup();
}
