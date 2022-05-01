// roar.c 佛门狮子吼
// Last Modified by Lonely on May. 29 2001

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

  if ( userp(me) && !wizardp(me) && 
  !query("perform/roar", me) && 
  !query("can_perform/zhanzhuang-gong/roar", me) && 
  !query_temp("murong/xingyi", me) )
   return notify_fail("你所使用的内功中没有这种功能。");
        if( (query("neili", me)<600) || 
                (query("max_neili", me)<600) || 
                ((int)me->query_skill("zhanzhuang-gong",1) < 100) )
                return notify_fail("你鼓足真气＂喵＂的吼了一声, 结果吓走了几只老鼠。\n");
        if( query("no_fight", environment(me)) )
                return notify_fail("在这里不能攻击他人。\n");

        skill = me->query_skill("force");
        addn("neili", -150, me);
        me->receive_damage("qi", 10);

        me->start_busy(5);
        message_combatd(HIY"$N深深地吸一囗气，真力迸发，发出一声惊天动地的巨吼！\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)
        {
                if( !living(ob[i]) || query_temp("noliving", ob[i]) || ob[i] == me)continue;

                if( skill/2+random(skill/2)<query("con", ob[i])*2)continue;

                if (!userp(ob[i]) && !ob[i]->accept_hit(me)) continue;

                damage=skill-(query("max_neili", ob[i])/10);

                if( damage > 0 )
                {
                        ob[i]->receive_damage("jing", damage * 2 );
                        if( query("neili", ob[i])<skill*2 )
                                ob[i]->receive_wound("jing", damage);
                tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！\n");
                }

                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
        }

        return 1;
}

int help(object me)
{
        write(WHT"\n站桩功之佛门狮子吼："NOR"\n");
        write(@HELP

        使用功效：
                伤害自己周围的所有生物的精气

        出手要求：
                站桩功100级
                内力600
HELP
        );
        return 1;
}