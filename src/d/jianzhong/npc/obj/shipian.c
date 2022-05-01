#include <ansi.h>
inherit ITEM;
int do_study(string arg);
void init()
{
        add_action("do_study","yanxi");
}
void create()
{
        set_name(HIC"长石片"NOR, ({ "chang shipian", "stone", "shipian" }) );
        set_weight(5000);
        set("unit", "块");
        set("long",HIC@LONG
一块普普通通的长条石片，上面有些细细的纹路，看不出什么特别之处。
LONG
NOR
);
        set("value", 1);
        set("material", "stone");
        setup();
}
int do_study(string arg)
{
        object me = this_player();
        int dugulevel = me->query_skill("dugu-jiujian-sword",1);
        if ( (arg != "stone") && (arg != "shipian") && (arg != "chang shipian") )
                return notify_fail("你要学什么？\n");
        if ((dugulevel >= 150) && (dugulevel <= 250) )
        {
               if( query("combat_exp", me)<dugulevel*dugulevel*dugulevel/10 )
                        return notify_fail("你只觉得石头的纹理暗合「独孤九剑」的剑意，可是就是理不出\n头绪，看来是实战经验不够。\n");
               if( query("jing", me)<25 )
                        return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");
                me->receive_damage("jing", 25);
                me->improve_skill("dugu-jiujian-sword",(query("int", me))*(query("combat_exp", me)/20000));
                message("vision","你拿出长石条仔细研究，竟从石条的纹理上领悟出「独孤九剑」\n的剑意，「独孤九剑」大有长进。\n",me);
                message("vision",query("name", me)+"仔细研读一块石片。\n",environment(me),me);
                return 1;
        }
        return notify_fail("你对着石头看来看去，没看出什么道理出来。\n");
}