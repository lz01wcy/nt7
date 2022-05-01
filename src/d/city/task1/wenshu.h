// Room: /d/city/wenshu.h


void init()
{
  call_out("dest", 1800);
  add_action("do_guankan", ({"guankan","kan"}));
  add_action("do_wancheng", ({"wancheng"}));
}

int do_guankan(string arg)
{
        int now_time, time;
        object me;

        me = this_player();
        now_time = me->query_condition("guanfu_task");
        time=query_temp("guanfu_time", me);

        if(!arg) return 0;
        if( arg=="wenshu" )
        {
                write("\n这是一张扬州知府悬赏捉拿江洋大盗的文书，上面栩栩如生的画着一个\n人的头像，下面有一行小字，上面写着：\n“江洋大盗「"+query_temp("guanfu_targetnm", me)+"」，悬赏捉拿”。\n据飞鸽传书，该犯目前出没于「"+query_temp("ch_weizhi", me)+"」附近。\n");
                if(now_time>time*3/4) write("你现在有充足的时间去寻找目标。\n");
                if(now_time>time/2 && now_time<=time*3/4 ) write("已经过去一小半时间了。\n");
                if(now_time>time/4 && now_time<=time/2 ) write("你还有一半的时间去追踪目标。\n");
                if(now_time>time/8 && now_time<=time/4 ) write("你的时间已经不多了。\n");
                if(now_time>0 && now_time<=time/8) write("官府好象已经快有新的目标了，你要抓紧时间了！\n");
                return 1;
        }
}

int do_wancheng(string arg)
{
        object me, target;
        int exp,pot,score,gfjob_times,now_time;

        if(!arg) return notify_fail("你要干什么？\n");
        me = this_player();
        target = present(arg, environment(me));
        now_time = me->query_condition("guanfu_task");

        if(!target) return notify_fail("找不到这个东西。\n");
        if( query("id", target) != "corpse")return notify_fail("你并没有完成任务。\n");
        if( query("victim_id", target) != query_temp("guanfu_target", me) )
                return notify_fail("那个并不是目标！\n");
        if( query("victim_user", target) )
                return notify_fail("嘿嘿，想作弊？！\n");
        if( query("kill_by", target) != me )
                return notify_fail("你晚了一步，目标已经被人杀了。\n");
  if( query_temp("mark/dune1", target) )
                return notify_fail("那已经是一具已经被人杀过的尸体了。\n");

        addn("gf_job", 1, me);
        gfjob_times=query("gf_job", me);
        if (gfjob_times < 1) gfjob_times = 1;
        message_vision(HIW "$N冷笑一声，从怀中掏出文书看了看，微运内劲将文书向空中飞射出去。\n但见文书化做片片雪片，飞落在$n身上。\n"NOR, me, target);
        write(WHT "很好！你成功地完成了任务。目前你已经为官府做了"+chinese_number(gfjob_times)+"次贡献。\n"NOR);
        set("long",query("long",  target)+"上面飞落着许多纸片。\n", target);
  set_temp("mark/dune1", 1, target);
        delete_temp("guanfu_time", me);
        me->clear_condition("guanfu_task");
        delete_temp("guanfu_target", me);
        delete_temp("guanfu_targetnm", me);
        delete_temp("ch_weizhi", me);
        delete_temp("path_rooms", me);
        delete_temp("gstart_rooms", me);
        delete_temp("mark/gkill3", me);

//调高一些奖励
        exp=800+random(400);
        if (exp > 1000) exp = 1000;
        pot=250+random(100);
        if (pot > 300) pot = 300;
        score=250+random(100);
        if (score > 300) score = 300;
        addn("potential", pot, me);
        addn("combat_exp", exp, me);
        addn("score", score, me);
        write(HIW"你被奖励了：\n" +
               chinese_number(exp) + "点实战经验\n" +
               chinese_number(pot) + "点潜能\n"+
               chinese_number(score) + "点江湖阅历\n"NOR);
        destruct(this_object());
        return 1;

}

void dest()
{
        object me = this_player();
        write("文书已经被你揉的模糊不清了，看来已经没什麽用了，你只好随手丢掉。\n", me);
        destruct(this_object());
}
