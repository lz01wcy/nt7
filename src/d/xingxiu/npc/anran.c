// Room: /d/xingxiu/npc/anran.c
// Last Modified by Lonely on Apr. 25 2001

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

mapping *quest = ({
  (["name":                "yilihe",
    "start" :              "/d/xingxiu/yilihe",
    "place" :              "伊犁河", ]),    
  (["name":                "jiayuguan",
    "start" :              "/d/xingxiu/jiayuguan",
    "place" :              "嘉峪关",]), 
  (["name":                "silk1",
    "start" :              "/d/xingxiu/silk1",
    "place" :              "嘉峪关以西的丝绸之路",]),
  (["name":                "xianrenya",
    "start" :              "/d/xingxiu/xianrenya",
    "place" :              "仙人崖",]),
  (["name":                "yili",
    "start" :              "/d/xingxiu/yili",
    "place" :              "伊犁城",]),
  (["name":                "shanjiao",
    "start" :              "/d/xingxiu/shanjiao",
    "place" :              "天山脚下",]),
  (["name":                "xinglongshan",
    "start" :              "/d/xingxiu/xinglongshan",
    "place" :              "兴隆山",]),  
  (["name":                "shanshan",
    "start" :              "/d/xingxiu/shanshan",
    "place" :              "鸣沙山",]), 
  (["name":                "tugu",
    "start" :              "/d/xingxiu/tugu",
    "place" :              "吐谷浑伏俟城",]), 
});    
string ask_job();

void create()
{
        set_name("黯然子", ({ "anran zi", "anran", "zi" }) );
        set("gender", "男性" );
        set("nickname", "星宿派六师兄");
        set("age", 31);
        set("location", 1);
        set("unique", 1);
        set("long", "黯然子在星宿二代十弟子中排行第六，
但他对星宿派武功有些独创，功力不浅。\n");
        set("env/wimpy", 40);
        set("str", 29);
        set("dex", 26);
        set("con", 24);
        set("int", 22);
        set("per", 18);
        set("shen", -7500);

        set_skill("force", 105);
        set_skill("huagong-dafa", 115);
        set_skill("dodge", 110);
        set_skill("zhaixinggong", 110);
        set_skill("strike", 110);
        set_skill("chousui-zhang", 110);
        set_skill("poison", 110);
        set_skill("parry", 110);
        set_skill("staff", 110);
        set_skill("tianshan-zhang", 110);
        set_skill("literate", 70);
        set_skill("claw", 110);
        set_skill("sanyin-wugongzhao", 110);
        map_skill("claw", "sanyin-wugongzhao");
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "chousui-zhang");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("claw", "sanyin-wugongzhao");
        prepare_skill("strike", "chousui-zhang");

        set("max_qi", 2000);
        set("max_jing", 2000);
        set("eff_jingli", 1800);
        set("score", -14000);
        set("combat_exp", 750000);
        set("chat_chance_combat", 5);
        set("chat_msg_combat", ({
                (: exert_function, "huagong" :),
                (: perform_action, "strike.biyan" :),
        }));
        create_family("星宿派", 2, "弟子");
        set("attitude", "peaceful");
        set("inquiry", ([
                "星宿派" : "你想加入，就拜我为师。",
                "星宿海" : "去星宿海干什么？拜我为师就够你学的了。",
                "丁春秋" : "丁春秋是你叫的吗？没大没小的。以后叫老仙！",
                "截杀" : (: ask_job :),
                "抢劫" : (: ask_job :),
                "吹捧" : "小师妹最讨老仙喜欢，你去问她吧。",
        ]));        
        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/cloth/dao-cloth")->wear();
        add_money("silver", 10);
}
void attempt_apprentice(object ob)
{
        command("consider");
        command("say 星宿门中各人都有专职，要拜师你去找我师兄弟吧！");
        return;
}
int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("你没有这件东西。");        
   if(userp(obj)){
       command("consider "+query("id", me));
       command("say 你拿个快死的人来骗我？");
       return 0;
       }
   if(!me->query_condition("xx_task2")){
       command("shake "+query("id", me));
       command("say 这么久才回来，我还不如找别人来干！");
       return 0;
       }
   if( query("id", obj) == "prize" && query("owner", obj) == query("id", me)){
       command("nod "+query("id", me));
       command("say 好样的！这才象我们星宿派的作风！\n");
       message_vision(HIY"$N将$n"HIY"拆开，拿出了一大堆金银财宝。\n"NOR,ob, obj);
       remove_call_out("destroying");
       call_out("destroying", 5, obj, ob, me);                       
       return 1;
       }
   if( query("money_id", obj)){
       command("pat "+query("id", me));
       command("say 钱我有的是，你以后还是留给自己吧。");
       return 0;
       }
   if( query("owner", obj) != query("id", me)){
       command("hehe "+query("id", me));
       command("say 不错啊，但这活可不是你干的。");
       return 1;
       }
   else return 0;       
}
void destroying(object obj, object ob, object me)
{   
   object n_money;
   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat"+query("id", me));
   message_vision(HIY"$N对$n说道：你这次做得极为出色，这是你该得的部分，拿去吧！\n"NOR,ob, me);
   n_money = new("/clone/money/gold");
   n_money->move(me); 
   n_money->add_amount(1);
   set_temp("job2_exp", 150+(query_temp("biaoshi", me)*(random(50)+50)), me);
   addn("combat_exp",query_temp("job2_exp",  me), me);
   addn("potential",query_temp("biaoshi",  me)*20, me);
   tell_room(environment(me), me->name()+"数着钱袋里的金子，脸上的肌肉不住地颤动，眼睛散发着一种奇怪的光芒。\n" NOR, ({ me }));     
   tell_object(me, "嘿嘿，发了！\n");
   log_file("xx_job2",sprintf("%s(%s)做星宿任务2，杀了%i个镖师，得到：%i点EXP。\n",
      me->name(1),getuid(me),query_temp("biaoshi", me),query_temp("job2_exp", me)));
   delete_temp("job2_exp", me);
   delete_temp("biaoshi", me);
   return;      
}
string ask_job()
{
  object me, ob;
  mapping aquest;
  int exp, j;
  aquest = quest[random(sizeof(quest))];
  me = this_player();
  ob = this_object();
  exp=query("combat_exp", me);
 
    if(ob->is_busy() || ob->is_fighting()) return "没看见我正忙着吗？一边等着去！";
    if( !query("family", me))return "看得出你对老仙态度恭敬，何不加入我星宿派呢？";
    if( query("family/family_name", me) != "星宿派" && !query_temp("ding_flatter", me) )
            return "你对老仙的态度看上去不太恭敬啊！";
    if(me->query_condition("wait_xx_task"))
            return "上次把我师兄给的任务搞砸了，这次你就等等吧。";
    if(me->query_condition("xx_task2"))
            return "我现在还没有得到任何消息，你等会儿再来吧。";
    if(me->query_condition("job_busy"))
            return "你现在还有任务在身，等会儿再来吧。";       
    if( query_temp("job_asked", ob) == query("id", me) )
            return "不是叫你先去那里等我吗？怎么还赖在这里？";
    if( query_temp("job_asked", ob) )
            return "嘿嘿，你来晚了，等下一次吧。";
    if(exp<200000) return "哈哈哈，你再加把力练功吧。";
    if(exp>=750000) return "你的功力已经超过我了，还用跟我出去做事？";
    if( query("shen", me)>-10000)return "哼！看来你的心肠还不够黑啊，这种事你不问也罢。";
    if(exp>=600000) j=6;
    else if(exp>=500000) j=5;
    else if(exp>=400000) j=5;
    else if(exp>=300000) j=4;   
    else j=3;   
  
    set_temp("xx_job2", 1, me);
    delete_temp("biaoshi", me);
    message_vision(CYN"\n$N阴阴一笑，说道：这两天会有一队骆驼商队经过，你够胆就和我一起去看看吧。\n"NOR, ob, me);
    set_temp("job_asked",query("id",  me), ob);
    set_temp("dest", aquest["name"], ob);
    set_temp("start_place", aquest["start"], ob);
    set_temp("place", aquest["place"], ob);
    set_temp("j", j, me);
    me->apply_condition("xx_task2", 60+(j*20));
    me->start_busy(1);
    call_out("going", 30, ob); 
    return "我还有些事要办，你先去"+query_temp("place", ob)+"等我。\n";
}
void going(object me)
{
       message_vision("$N急急忙忙地走了出去。\n", me);       
       me->move(query_temp("start_place", me));
       message_vision("$N急急忙忙地走了过来。\n", me);       
}
void init()
{
   object ob, where, me;
   ::init();
   ob=this_object();
   where = environment(ob);
   if( query_temp("dest", ob)){
     if( interactive(me=this_player()) && query_temp("xx_job2", me )
         && query_temp("job_asked", ob) == query("id", me )
         && file_name(where) == query_temp("start_place", ob)){
           remove_call_out("waiting");
           call_out("do_back", 120, ob);
           call_out("waiting", 1, ob, me);
           }
     else{
         remove_call_out("do_back");
         call_out("do_back", 90, ob);
         }
     }
}
void waiting(object ob, object me)
{   
    if(!ob || !living(me)) return;
    command("nod"+query("id", me));
    command("say 好，我们就在这里等着他们来吧。");
    set_temp("wait_target", 1, ob);
    set_temp("wait_target", 1, me);
    remove_call_out("wait_target");
    call_out("wait_target", 30, ob, me);
    return; 
}
void do_back(object me)
{
        delete_temp("wait_target", me);
        delete_temp("start_place", me);
        delete_temp("place", me);
        delete_temp("dest", me);
        message_vision("$N转过山丘，几个起落就不见了。\n", me);
        me->move("/d/xingxiu/ryd1");  
        message_vision("$N急急忙忙地走了过来。\n", me);
        remove_call_out("del_temp");
        call_out("del_temp", 400, me);             
}
void del_temp(object me) {delete_temp("job_asked",me);}

int wait_target(object ob, object me)
{
        object obj;
        if(!objectp(present(me, environment(ob))))
        {
                message_vision("$N说道：耶？那家伙怎么不见了？\n", ob);
                remove_call_out("do_back");
                do_back(ob);
                return 1;
        }
        if(!objectp(ob = present("anran zi", environment(me))))
        {
                tell_object(me,"你发现黯然子不见了，只好灰溜溜地转身离开。\n");
                tell_room(environment(me),me->name()+"突然一脸茫然的表情，看来是想要离开了。\n", ({ me }));
                delete_temp("xx_job2", me);
                me->clear_condition("xx_task2");
                delete_temp("wait_target", me);
                return 1;
        }
        obj = new(__DIR__"shangdui");
        obj->move(environment(me)); 
        set("arg",query_temp("dest",  ob), obj);
        message_vision(HIY"\n只听一阵骆驼风铃声传来，一只骆驼商队出现在眼前！\n\n"NOR, ob);
        tell_object(me,"猎物终于出现了！\n"); 
        message_vision(HIY"$N对着$n大声命令道：你快抢(qiang)商队，我来对付其他人！\n"NOR, ob, me); 
        message_vision("说完$N就冲上前去，和几个护镖镖师打斗追逐开了。\n", ob);
        remove_call_out("do_back");
        do_back(ob);
        delete_temp("wait_target", me);
        set_temp("rob_start", 1, me);
}
