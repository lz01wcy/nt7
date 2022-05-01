// cypress.c 柏树 
// Last Modified by Lonely on Aug. 18 2002

#include <ansi.h>
inherit ITEM;

int start_collapse = 0;
int chop_times = 0; 

void create()
{
        set_name(HIG"青柏树"NOR,({"cypress"}));
        set_weight(900000);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("long", "这是一棵苍翠的青柏树。\n");
                set("unit", "棵");
                set("value", 8);
                set("no_get", 1);
            }
        
        setup();
}

void init()
{
        add_action("do_chop", "chop");
        add_action("do_chop", "砍");
}

int do_chop(string arg)
{
        object weapon, me = this_player();
        object piece;
        
        if( !arg || arg!="cypress" && arg != "树" )
                return notify_fail("你要砍甚么？\n");

        if( !objectp(weapon=query_temp("weapon", me)) )
        {
                message_vision(HIR"$N挥手朝柏树一阵猛砍，弄得双手鲜血淋淋。\n"NOR, me);
                me->receive_damage("qi", 50, "流血过多死了");
                return 1;
        }else if( query("skill_type", weapon) != "sword" && 
                        query("skill_type", weapon) != "blade" && 
                        query("skill_type", weapon) != "axe" )
                {
                        message_vision(HIW"$N挥起手中" + weapon->name() + HIW"朝柏树一阵猛砍。\n"NOR, me);
                        message_vision(HIW"结果「啪」地一声，$N手中的" + weapon->name() + HIW"已经断为两截！\n"NOR , me );

                        weapon->unequip();
                        seteuid(getuid());
                        piece = new("/clone/misc/piece");
                        piece->set_name("断掉的"+query("name", weapon),({query("id", weapon),"piece"}));
                        piece->move(environment(me));
                        destruct(weapon);
                        return 1;
                }

        message_vision(HIW"$N操起手中" + weapon->name() + HIW"，吭吃吭吃地砍树。\n"NOR, me);
        me->receive_damage("qi",5+random(35-query("str", me)),"砍树累死了");
        chop_times++;

        if ( !start_collapse && random(chop_times) ) 
        {
                start_collapse = 1;
                chop_times = 0;
                message_vision(HIC"柏树开始松动起来，吱吱呀呀发出响声。\n"NOR, this_object());
                call_out("collapse", 20, me);
        }                

        return 1;
}  

void collapse(object me)
{
        object ob, obn;
        object *inv;
        int i;
        
        ob = this_object();
        if ( !objectp(me) ) return;

        if ( chop_times <= 0 || random(chop_times) < 2)
        {
                message_vision(HIC"柏树摇摆了两下，又站住了。\n"NOR, ob);
                start_collapse = 0;        
                return;
        } 

        message_vision(RED"柏树轰的一声倒了下来…\n"NOR, ob);

        if ( random(chop_times) > 5 ) 
        if ( present(me, environment(ob)) )   
        {
                message_vision(HIR"正砸在$n头上！\n"NOR, ob, me);
                me->receive_damage("qi", 30*chop_times, "被柏树干砸死了");
                me->receive_wound("qi", 20*chop_times, "被柏树干砸死了");
        }
        else 
        {
                inv = all_inventory(environment(ob));
                
                for (i = 0; i < sizeof(inv); i++)
                if (userp(inv[i]))
                {
                        message_vision(HIR"正砸在$n头上！\n"NOR, ob, inv[i]);
                        inv[i]->receive_damage("qi",30*chop_times, "被柏树干砸死了");
                        inv[i]->receive_wound("qi", 20*chop_times, "被柏树干砸死了");
                }
        }
        if (chop_times >= 13) chop_times = 13;
        set("wdjob/wage", chop_times, me);
        
        if ( objectp(environment(ob)) )
        {
                obn = new(__DIR__"cypress_bole");
                obn->move(environment(ob));
        }
        destruct(ob);
}