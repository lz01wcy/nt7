// Code of ShenZhou
//lh_book.c
//wsky
#include <ansi.h>
inherit ITEM;

int do_start(object me);


void create()
{
        set_name("黄皮册子", ({ "ce zi", "book" }));
        set_weight(600);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
                set("unit", "本");
                set("long", YEL"这是一本黄皮册子，册子上写着《三连环》三个篆字，左下角署名写着全真长春子。\n"NOR);
                set("material", "paper");
                set("no_drop","这样东西不能离开你。\n");
                set("no_get","这样东西不能离开你。\n");
                set("no_steal", 1);
                set("no_sell", 1);
                set("value", 300000);
        }
}

void init()
{
        add_action("do_lingwu","lingwu");
  
}
int do_lingwu(string arg)
{
        object me;
        int cost;
        me=this_player();
         if (me->is_busy())
            return notify_fail("你正忙着呢!\n");
        
        if( arg != query("id", this_object()))return notify_fail("你要领悟什么?\n");
        
        if(me->query_skill("quanzhen-jian", 1) <100)
            return notify_fail("你的全真剑法不够娴熟，无法领悟要决中的奥妙。\n");
            
        if(me->query_skill("taoism",1)<100)
                return notify_fail("你的道学修为不够。\n");
                
        if(me->query_skill("literate",1)<100)
                return notify_fail("你文学水平太差，看不懂此册。\n");
        
        if( query("player_id", this_object()) != query("id", me) )
        {
                addn("max_neili", -10, me);
                return notify_fail(HIR"你一读之下只觉浑身燥热，内力不聚，说不出的难受。\n"NOR);

        }

        if( query("can_perform/quanzhen-jian/lian", me) == 1 )
                    return notify_fail("你已经领悟三连环精要。\n");
        
        if( query("neili", me)<1000 || query("jing", me)<200 )
                return notify_fail("你精神不佳，无法领悟心法中的奥妙。\n");
                
        cost=query("int", me);
        
        if(cost>=30)
                cost=5;
        else
                cost=35-cost;
        
        set_temp("lianhuan_cost", cost, me);
        
        message_vision(YEL"$N从怀中摸出一本小册子,全神灌注地阅读着，不时左手轻轻的比划。\n" NOR, me);
            me->start_busy((: do_start:));
        return 1;

}

int do_start(object me)
{

        if( query_temp("lianhuan_cost", me) <= 0 )
        {
                if( random(query("int", me))>15 || random(me->query_int())>35 )
                {
                        addn("lingwu_lianhuan", 1, me);
                        tell_object(me,HIY"你静坐良久，似乎对三连环的运用有一丝领悟。\n"NOR);
                        
                        if( query("lingwu_lianhuan", me) >= 20 )
                        {
                                tell_object  (me,HIG"恭喜，你终于领悟出〖三连环〗秘决的精要。\n"NOR);
                                set("can_perform/quanzhen-jian/lian", 1, me);
                                delete("lingwu_lianhuan", me);
                                
                        }
                        set("neili", 0, me);
                        set("jingli", 0, me);
        
                }
                else
                {
                        
                        tell_object  (me,HIR"你左思右想始终不能领悟，不用得心中大燥。\n"NOR);
                            addn("neili", -query("max_neili", me), me);
                            me->receive_damage("jing",query("max_jing", me));
                            
                            if( query("neili", me)<0 || query("jing", me)<0 )
                                    me->unconcious();
                                   
                }
        
                return 0;
        }
        addn_temp("lianhuan_cost", -1, me);
        
        return 1;
}