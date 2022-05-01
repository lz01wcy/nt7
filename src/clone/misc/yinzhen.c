// /clone/misc/yinzhen.c
// Last modified by Lonely 2003.9.2

#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIW "银针" NOR, ({ "yin zhen" , "yin", "zhen" }) );
        set_weight(200);

        if( clonep() ) set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", HIW"这是三寸长的银针，细而柔韧，多为医家刺穴疗伤之用。\n能运用这种银针的医者多为旷世神医，并有深厚的内功。\n你可以试着用它来针灸(zhenjiu)疗伤。\n" NOR);
                set("value", 0);
                set("yingdu", 50);
                set("base_unit", "枚");
                set("base_weight", 10);
                set("base_value", 0);
                set("material","crimsonsteel");
        }
        set_amount(1);
        init_throwing(30);
        setup();
}

void init()
{
        add_action("do_heal", "zhenjiu");
}

int do_heal(string arg)
{
        object ob, me = this_player();
        int damage, heals, i, exp, pot;
        string msg, s;

        if (me->query_skill("acupuncture", 1) < 1 )
                return notify_fail("你针灸术都没学，去杀人啊？\n");
        if( query("equipped", this_object()) != "wielded" )
                return notify_fail("你必须把银针拿在手里才能针灸。\n");
        if (! arg || ! objectp(ob = present(arg, environment(me))))
                return notify_fail("你想对谁施行针灸术？\n");
        if (! ob->is_character() )
                return notify_fail("看清楚了，那不是活人！\n"); 
        if( query_temp("noliving", ob) || !living(ob) )
                return notify_fail("你还是等他醒了之后再治疗吧。\n");
        if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
        if (me->is_fighting() || ob->is_fighting())
                return notify_fail("战斗中还想疗伤，你找死啊？\n");
        if( ob->is_killing(query("id", me)) )
                return notify_fail("人家不会给你这个机会的。\n");
        if( query("race", ob) != "人类" )
          return notify_fail("你要当兽医？\n");
        if (ob != me && userp(ob))
        {
                        tell_object(me, YEL "你不能为玩家针灸。\n" NOR);
                        return 1;
        }
        if( !userp(ob) && random(me->query_skill("acupuncture",1)+query("cor", me))<1 )
        {
                        message_vision( HIY "$N" HIY "正想给$n" HIY "疗伤，可$n" HIY "望着$N" HIY "那不停颤抖的双手，脸上露出害怕的神色。\n" NOR + CYN "$n" CYN "皱了皱眉头，对$N" CYN "说道：你那点手艺还是算了吧。\n"NOR, me, ob);
                        return 1;
        }
        if (me!=ob && ob->query_skill("force") >= 150)
                return notify_fail("人家内功深厚，不指望你替他疗伤。\n");
        if( (query("max_qi", ob)*5/100>query("eff_qi", ob)) )
                return notify_fail("现在此人受伤过重，施行针灸太危险了！\n");
        if( query("neili", me)<80 )
                return notify_fail("你的内力不足，无法使用针灸术为人疗伤！\n");
        if( query("jing", me)<50 )
                return notify_fail("你的精不足，无法集中精力！\n");
        if( time()-query_temp("last/zhenjiu", ob)<60 )
                return notify_fail("人家刚刚接收过针灸治疗，现在不需要你帮忙。\n");
        if( query("max_qi", ob) == query("eff_qi", ob) )
        {
                if(me != ob) return notify_fail("这人并没有受伤！\n");
                else
                        message_vision(HIW"$N"HIW"决定用自己来做试验，来提高自己针灸术的水平。\n" NOR, me);
        }
        set_temp("last/zhenjiu", time(), ob);
        addn("neili", -50, me);
        addn("jing", -30, me);
        me->start_busy(1 + random(1));
        me->improve_skill("acupuncture", 5 + random(me->query_skill("acupuncture",1)));
        tell_object(me, HIC "在实践过程中你的「针灸术」提高了！\n" NOR);
        if (me == ob) s = "$N";
                 else s = "$n";
        msg = HIW"$N"HIW"手捏银针，小心翼翼地向"+s+HIW"的穴道刺去，\n"NOR;
        if (random(120) > (int)me->query_skill("acupuncture", 1))
        {
                damage=1+random(query("max_qi", ob)/2);
                i=query("max_qi", ob)*10/damage;

                if (i > 100)
                        msg += CYN"可是$N"CYN"用力稍偏，没刺中穴道，"+s+CYN"脸上露出一丝难过的神情。"NOR;
                else
                {
                        if (i > 40)
                                msg += RED"但是$N"RED"用力过猛，竟然刺出了血，这可是针灸中的大忌！"NOR;
                        else
                                msg += RED"$N"RED"刺了下去才发现刺错了穴道，"+s+RED"「哇」的喷出了一口鲜血！"NOR;
                }

                ob->receive_wound("qi", damage);
                damage = i;
        }
        else
        {
                msg += HIW"$N"HIW"的银针准确无误地刺入穴道，随着银针的缓缓转动，"+s+HIW"长长地出了一口气，脸色好看多了。"NOR;
                damage = -1;
                if( me != ob/* && query("combat_exp", me)<200000*/ )
                {
                        exp = 20 + random(20);
                        pot = 5 + random(5);

                        addn("combat_exp", exp, me);
                        addn("potential", pot, me);

                        tell_object(me,HIC"你获得了"+chinese_number(exp)+"点经验和"+chinese_number(pot)+"点潜能。\n"NOR);
                }

                heals = me->query_skill("acupuncture", 1)+random(me->query_skill("acupuncture", 1));

                if( (query("eff_qi", ob)+heals/3)>query("max_qi", ob) )
                        set("eff_qi",query("max_qi",  ob), ob);
                else addn("eff_qi", heals / 3, ob);
        }

        msg += "\n";
        if (me == ob) message_vision(msg, me);
        else message_vision(msg, me, ob);

        if (damage > 0)
        {
                if( query("qi", ob)<0 )
                {
                        set("eff_qi", 1, ob);
                        set("qi", 1, ob);

                        if (userp(ob))
                        {
                                if (me == ob)
                                        message_vision(HIR"好险啊！$N"HIR"差一点把自己扎死。\n"NOR, me);
                                else
                                        message_vision(HIR"好险啊！$N"HIR"差一点把$n"HIR"扎死。\n"NOR, me, ob);
                        }
                }
                else
                {
                        if (me != ob)
                        {
                                if (random(damage) < 40)
                                {
                                        message_vision(HIR"$N"HIR"痛得「哇哇」大叫不止，怒道：居然敢下毒手，你想杀死我啊！\n" NOR, ob);
                                        ob->kill_ob(me);
                                        me->fight_ob(ob);
                                }
                                else
                                {
                                        message_vision(HIR"$N"HIR"「哇」的大叫一声，不满地道：好痛啊！下次你可千万当心点！\n"NOR,ob);
                                }
                        }
                }
                
        }

        return 1;
}