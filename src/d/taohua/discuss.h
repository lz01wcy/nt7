// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

int in_ask, answer;
int bCheckingRobot;


void say_question(object me, object ob)
{
        // object ob = this_player();
        int a, b, c;
        string oper;

        // if( in_ask || random(20) > 10 ) return;
        if( !ob || !userp(ob) || !me || !userp(me) )
        {
                bCheckingRobot = 0;
                return;
        }

        delete_temp("wrong");
        a = random(19) + 2;
        b = random(19) + 2;
        switch(random(5)) {
                case 0:
                        answer = a + b;
                        oper = chinese_number(a) + "加" + chinese_number(b)+ "等于多少？";
                        break;
                case 1:
                        if (a < b) { c = b; b = a; a = c;}
                        answer = a - b;
                        oper = chinese_number(a) + "减去" + chinese_number(b)+ "等于多少？";
                        break;
                case 2:
                        if( a * b < 200 ) {
                                answer = a * b;
                                oper = chinese_number(a) + "乘" + chinese_number(b)+ "等于多少？";
                        } else {
                                answer = (a * b) % 10;
                                oper = chinese_number(a) + "乘" + chinese_number(b)+ "，个位数等於多少？";
                        }
                        break;
                case 3:
                        answer = a % b;
                        oper = chinese_number(a) + "除以" + chinese_number(b)+ "的余数是多少？";
                        break;
                case 4:
                        oper = chinese_number(a) + "和" + chinese_number(b)+ "的最大公因数是多少？";
                        if( b < a ) { c = b; b = a; a = c; }
                        while( a > 1 && b%a > 1 ) {
                                c = a;
                                a = b%a;
                                b = c;
                        }
                        answer = b%a == 1 ? 1 : a;
                        break;
        }
        message_vision("$N对$n提问道："+oper + "，请在三十秒内作答(da <number>))。\n",me,ob);
        in_ask = 1;
        remove_call_out("say_answer");
        call_out("say_answer", 30, me,ob);
}

void say_answer(object me, object ob)
{
        object env, *inv;
        int i;

        if( !ob || !userp(ob) || !me || !userp(me) )
        {
                bCheckingRobot = 0;
                return;
        }

        addn("robot_check_wrong", 1, ob);
        call_out("ans_wrong", 1, me, ob);

        message_vision("$N说道：这么简单都不会？答案等于" + chinese_number(answer) + "。\n",me);
        in_ask = 0;
        remove_call_out("say_question");
        call_out("say_question", 1, me, ob);
}


int do_answer(string arg)
{
        object ob = this_player();
        object partner;
        string s;
        int ans;

        if( !query_temp("partner", ob) || !query_temp("partner_id", ob) || !(partner=present(query_temp("partner_id", ob),environment(ob))) )
                return notify_fail("这里没有你想要与之讨论的人。\n");


        if( !in_ask ) return notify_fail("你必须等下一题。\n");
        if( !arg ) return notify_fail("请你回答一个数字。\n");

        message_vision( CYN "$N答道：" + arg + "\n" NOR, ob);

        if( sscanf(arg, "%d", ans)==1 ) {
                if( ans==answer ) {
                        addn("robot_check", 1, ob);
                        message_vision("$N说道：答对了！\n",partner);
                        partner->command("pat"+query("id", this_player()));

                        remove_call_out("say_answer");
                        in_ask = 0;
                        if( query("robot_check", this_player()) >= 3){
                                message_vision(HIG"$N说道：很好，你果然对算法颇有研究，佩服！佩服！我们继续讨论武功吧。\n\n"NOR,partner);
                                delete("robot_check", ob);
                                delete("robot_check_wrong", ob);
                                delete("robot_checking", ob);
                                delete("robot_check", partner);
                                delete("robot_check_wrong", partner);
                                delete("robot_checking", partner);
                                bCheckingRobot = 0;
                                return 1;
                        }
                        else
                        {
                                remove_call_out("say_question");
                                call_out("say_question", 1, partner,ob);
                        }

                } else {
                        message_vision("$N说道：错！\n",partner);
                        addn("robot_check_wrong", 1, this_player());
                        addn_temp("wrong/"+query("id", this_player()),1);
                        call_out("ans_wrong", 0, partner,ob);
                        if( query_temp("wrong/"+query("id", this_player()))>3){
                                message_vision(HIG"只见青光一闪，黄药师突然出现在$N的眼前。\n"NOR,ob);
                                message_vision(HIY"黄药师很生气地对$N喝道：你这不肖之徒，连这么简单问题都答不出，去死吧。\n"NOR,ob);
                                message_vision(HIR"黄药师弹指一弹，一股内劲破空而出，向$n袭来，$N只觉得透不过气来，扑的一声倒在地上。\n"NOR,ob,ob);
                                message_vision(HIC"黄药师袖袍一挥，把$N凌空卷起，走到屋外，对哑仆喊道：“你们把这不肖之徒扔到外岛去，越远越好！”\n\n黄药师气哼哼的走了。\n\n"NOR,ob);

                                this_player()->receive_wound("qi", 100, this_object());
                                set("jingli", -1, this_player());
                                set("qi", -1, this_player());
                                this_player()->move("/d/island/icefire_land");
                                delete("robot_checking", ob);
                                delete("robot_check", ob);
                                delete("robot_check_wrong", ob);
                                bCheckingRobot = 0;
                                in_ask = 0;
                                remove_call_out("say_question");
                                remove_call_out("say_answer");
                        }

                        //remove_call_out("say_question");
                        //call_out("say_question", 1, ob);
                }
        }
        return 1;
}

int ans_wrong(object partner,object ob)
{
        if( query("robot_check_wrong", ob)>5){
                message_vision(HIG"只见青光一闪，黄药师突然出现在$N的眼前。\n"NOR,ob);
                message_vision(HIY"黄药师很生气地对$N喝道：你这不肖之徒，连这么简单问题都答不出，去死吧。\n"NOR,ob);
                message_vision(HIR"黄药师弹指一弹，一股内劲破空而出，向$n袭来，$N只觉得透不过气来，扑的一声倒在地上。\n"NOR,ob,ob);
                message_vision(HIC"黄药师袖袍一挥，把$N凌空卷起，走到屋外，对哑仆喊道：“你们把这不肖之徒扔到外岛去，越远越好！”\n\n黄药师气哼哼的走了。\n\n"NOR,ob);

                ob->move("/d/island/icefire_land");
                delete("robot_check_wrong", ob);
                delete("robot_check", ob);
                delete("robot_checking", ob);
                delete("robot_check_wrong", partner);
                delete("robot_check", partner);
                delete("robot_checking", partner);
                bCheckingRobot = 0;
                in_ask = 0;
                remove_call_out("say_question");
                remove_call_out("say_answer");
        }
        return 1;
}


int do_discuss(string arg)
{
        object me,partner;
        int exp1, exp2, pot1, pot2, times, i;
        string name1, name2, name3, name4, target;

        me = this_player();
                  if (me->is_busy()
                   || query_temp("pending/exercising", me )
                   || query_temp("exit_blocked", me) )
                                         return notify_fail("你现在正忙着呢。\n");

        if( !arg || arg == getuid(me))
                return notify_fail("没有你想要与之讨论的人。\n");

/*
        if (sscanf(arg, "%s %d", target ,times)!=2 ) {
                times = 1;
        if( !arg || arg == getuid(me))
                return notify_fail("没有你想要与之讨论的人。\n");
        }
*/
        if (sscanf(arg, "%s %d", target ,times)!=2 ) {
                times = 1;
            if (sscanf(arg, "%s", target )!=1 )
                return notify_fail("这里没有你想要与之讨论的人。\n");
        }
        
        if (times < 1) 
                return notify_fail("你要讨论多少次？\n");
        if( !(partner = present(target, environment(me))) || !partner->is_character() || me == partner)
                return notify_fail("这里没有你想要与之讨论的人。\n");


        exp1=query_temp("exp_gain", me);
        pot1=query_temp("pot_gain", me);
        name1 = me->name();
        name3=query_temp("partner", me);
        exp2=query_temp("exp_gain", partner);
        pot2=query_temp("pot_gain", partner);
        name2 = partner->name();
        name4=query_temp("partner", partner);

        set_temp("partner_id",query("id",  me), partner);
        set_temp("partner_id",query("id",  partner), me);
        if( query("th_discuss", me)>2000 )
                return notify_fail("你讨论了这麽多，应该实践一下本门武功的技巧了。\n");
        if( query("th_discuss", partner)>2000 )
                return notify_fail(name2+"已经讨论过很多本门武学，应该实践一下了。\n");

/*
        if( query("huang_called", me) )
                return notify_fail("黄药师要你去见他，身为弟子，该当先遵行师命才是，可不是切磋功夫的时候。\n");
        if( query("huang_called", partner) )
                return notify_fail("黄药师要"+name2+"去见他，身为弟子，该当先遵行师命才是，可不是切磋功夫的时候。\n");

        if( query("th_ask", me) )
                return notify_fail("你还没去找"+query("th_ask", me)+"呢。\n");
        if( query("th_ask", partner) )
                return notify_fail("对方还没处理完师父交代的事。\n");
        if( query("th_teach", me) )
                return notify_fail("你帮"+query("th_teach", me)+"练功夫，才帮到一半哪。\n");
        if( query("th_teach", partner) )
                return notify_fail("对方还没处理完师父交代的事。\n");
*/
        if( (exp1 < times || exp2 < times ) && times > 1)
                return notify_fail("怕你们讨论不了这么大范围。\n");

        if( query("jing", me)<20 || query("jingli", me)<20 )
                return notify_fail("你太累了，无法继续讨论下去。\n");
                  if( query("jing", partner)<20 || query("jingli", partner)<20 )
                                         return notify_fail("你的同伴一副昏昏欲睡的样子，看来无法继续讨论下去。\n");

        if( query("jing", me)<10+10*times || query("jingli", me)<10+10*times )
                return notify_fail("以你目前的精神状况，怕一次讨论不了这麽多东西。\n");
                  if( query("jing", partner)<10+10*times || query("jingli", partner)<10+10*times )
                                         return notify_fail("以对方目前的精神状况，怕一次讨论不了这麽多东西。\n");

        addn("jing", -10*times, me);
        addn("jing", -10*times, partner);
        addn("jingli", -10*times, me);
        addn("jingli", -10*times, partner);

        if( exp1 < 1 && exp2 < 1) {
                tell_object(me,CYN"你和"+name2+"穷聊了一阵，感觉脑袋空荡荡的，一无所得。\n"NOR);
                tell_object(partner,CYN"你和"+name1+"穷聊了一阵，感觉脑袋空荡荡的，一无所得。\n"NOR);
                message_vision(CYN"$N和$n正有一搭，没一搭的摆空龙门阵。\n"NOR,me,partner);
                delete_temp("exp_gain", me);
                delete_temp("exp_gain", partner);
                me->start_busy(random(3));
                partner->start_busy(random(3));
                return 1;
        }

        if( exp1 < 1 ) {
                tell_object(me,CYN"你想要和"+name2+"探讨一下武功心得，但却觉得没啥好说的...\n"NOR);
                tell_object(partner,CYN""+name1+"似乎想和你讨论点什麽的样子...\n"NOR);
                message_vision(CYN"$N对$n一副欲言又止的尴尬模样。\n"NOR,me,partner);
                delete_temp("exp_gain", me);
                return 1;
        }

                  if( exp2 < 1 ) {
                                         tell_object(me,CYN"你想要和"+name2+"探讨一下武功心得，但"+name2+"却一副心不在焉的样子...\n"NOR);
                                         tell_object(partner,CYN""+name1+"似乎想和你讨论点什麽的样子，但你却觉得没啥好说的...\n"NOR);
                                         message_vision(CYN"$n对$N一副欲言又止的尴尬模样。\n"NOR,me,partner);
                                         delete_temp("exp_gain", me);
                                         return 1;
                  }

  if( query("robot_checking", me) )
  {
        if(bCheckingRobot == 0)
        {
                bCheckingRobot = 1;
                call_out("say_question",1,partner,me);
        }
        return notify_fail("你还是先把问题答完再想别的吧! \n");
  }

  if( query("robot_checking", partner) )
  {
        if(bCheckingRobot == 0)
        {
                bCheckingRobot = 1;
                call_out("say_question",1,me,partner);
        }
        return notify_fail("还是等人家先把问题答完再说吧! \n");
  }

//discuss变成discuss xxx <次数>後，下指令机会减少，check robot机会减低太多，暂时取消

/*
  if( random( 150 ) == 1 && bCheckingRobot == 0)
  {
        message_vision(HIG"$N说道：本桃花岛派不但以武功称誉天下，而且师父对奇门八卦、诸子百家无所不精、无所不通。\n",me);
        message_vision("$N说道：我等弟子若能学到师父一成两成学问，就此生无憾了。\n",me);
        message_vision("$N说道：今天练功这么久，不如休息休息，让我们来探讨探讨一些算法问题。\n"NOR,me);
        set("robot_checking", 1, partner);
        bCheckingRobot = 1;
        call_out("say_question",1,me,partner);
        return 1;
  }

        if( query("th_discuss", me)>2000){
        message_vision("$N正欲讨论武学精要，一个哑仆走了过来，对$N咿咿呀呀地做了个手势，是黄药师有事要找$N，不知有何吩咐。\n",me,partner);
        message_vision("$N和$n对望一眼，停了下来。$N向哑仆挥挥手，示意知道，哑仆便即离去。\n",me,partner);
        set("huang_called", 1, me);
        delete("th_discuss", me);
        return 1;
        }
*/

        message_vision(CYN"$N和$n热烈的探讨着各自武功的得失，及其对武学的理解。\n"NOR,me,partner);
        tell_object(me,HIY"你一边和"+name2+"印证武学，一边回想着与"+name3+"的比武经过，对武学的认识又深了一层！\n"NOR);
                  tell_object(partner,HIY"你一边和"+name1+"印证武学，一边回想着与"+name4+"的比武经过，对武学的认识又深了一层！\n"NOR);
        //me->start_busy(1+random(2));
        //partner->start_busy(1+random(2));

        exp1 = exp1-times; pot1 = pot1-times;
        exp2 = exp2-times; pot2 = pot2-times;

        set_temp("exp_gain", exp1, me);
        set_temp("exp_gain", exp2, partner);

                    for (i=0; i<times; i++) {
        addn("combat_exp", (me->query_int()/30+1), me);
        addn("th_discuss", 1, me);
        addn("combat_exp", (partner->query_int()/30+1), partner);
        addn("th_discuss", 1, partner);
        }

        if (pot1>0) {
                set_temp("pot_gain", pot1, me);
                for (i=0; i<times; i++) {
                if( query("potential", me)<query("max_potential", me )
                && random(3) == 1) {
                addn("potential", (me->query_int()/20+1), me);
                }
                }
        }else delete_temp("pot_gain", me);

        if (pot2>0) {
                set_temp("pot_gain", pot2, partner);
                for (i=0; i<times; i++) {
                if( query("potential", partner)<query("max_potential", partner )
                && random(3) == 1) {
                addn("potential", (partner->query_int()/20+1), partner);
                }
                }
        }else delete_temp("pot_gain", partner);
                if( wizardp(me) )
        message_vision("exp1:"+exp1+" exp2:"+exp2+" pot1:"+pot1+" pot2:"+pot2+"\n",me,partner);

        return 1;
}