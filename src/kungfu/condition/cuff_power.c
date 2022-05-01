// cuff_power.c

#include <condition.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if (me->is_ghost()) return 1;
                tell_object(me, HIR"你只觉得胸口一股暗劲爆发，哇的吐出一口鲜血！\n" NOR );
        message("vision", HIR"只听哇~的一声,"+me->name() + "突然吐出一口鲜血！\n"NOR, environment(me), me);
   
        me->receive_wound("qi",1000 + random(duration));
        me->receive_wound("jing", 1000+ random(duration/5));
        if( query("eff_jing", me)<0 || query("eff_qi", me)<0)
        {
                set_temp("die_reason", "体内拳劲爆发死亡", me);
                return 0;
        }
        me->apply_condition("cuff_power", 0);
        return 0;
}

string query_type(object me)
{
        return "hurt";
}