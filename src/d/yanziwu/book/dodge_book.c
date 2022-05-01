// dodge_book.c
#include <ansi.h>
inherit ITEM;
int do_study(string arg);
void init()
{
        add_action("do_study","kan");
}
void create()
{
        set_name(HIM"慕容世家"HIW"轻功篇"NOR, ({"dodge book","book"}));
        set_weight(500);
        set("unit", "册");
        set("long","这是慕容世家的藏书中的"HIW"轻功篇"NOR"，包含了普天下所有门派的轻功精要。\n想修绝世武功，就好好看(kan)吧。\n");
        set("value", 1);
        set("material", "paper");
        setup();
}
int do_study(string arg)
{
        object me = this_player();
        int level = me->query_skill("dodge",1);
        if (me->query_skill("shenyuan-gong",1) < 20)
                return notify_fail("你的神元功未入门，无法从书上学到什么。\n");
        if ( (arg != "book") && (arg != "dodge book"))
                return notify_fail("你要学什么？\n");
        if (level >= 150)
                return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
        if (level <= 50)
                return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太深奥了，毫无收获。\n");
        if( query("combat_exp", me)<(level*level*level/10) )
                return notify_fail("你的实战经验不足，再怎么读也没用。\n");
        if( query("jing", me)<25 )
                return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");
        me->receive_damage("jing", 25);
        me->improve_skill("dodge", (int)me->query_skill("literate",1)/5+1); 
        write("你研读了有关基本轻功的技巧，似乎有点心得。\n");
        return 1;
}