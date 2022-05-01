// Last Modified by Lonely on Nov. 17 2000

inherit NPC;

int ask_thd();
int ask_price();
int ask_qihang();

void create()
{
        set_name("船老大", ({ "laoda" , "chuanlaoda" }) );
        set("gender", "男性" );
        set("age", 42);
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "老大");
        set("inquiry", ([
                "name"  : "我就是这里的老大，他们都叫我小马哥。",
                "rumors": "听说以前有一艘红毛鬼子的船遇难后漂流到这里，唯一的船员就死在那边的小店里。",
                "here"  : "这里是附近唯一的出海渔港了。",
                "chuhai": "客官您要启航去哪里啊？难道是桃花...",
                "出海"  : "客官您要启航去哪里啊？难道是桃花...",
                "雇船"  : "客官您要启航去哪里啊？难道是桃花...",
                "桃花岛": (: ask_thd :),
                "taohuadao": (: ask_thd :),
                "价钱": (: ask_price :),
                "price": (: ask_price :),
                "启航": (: ask_qihang :),
                "qihang": (: ask_qihang :),
        ]) );
        setup();
}

int ask_thd()
{
        object ob=this_player();

        if( query("thd/x", ob) )
        {
                say("船老大瞪大了眼睛，吃惊地说：客官要去那个鬼地方么？听说以前去的人都没有回来过。\n如果您真的要去的话，这个价钱嘛...\n" );
                if( query("family/family_name", ob) != "桃花岛" )
                        set_temp("thd_temp", 1, ob);
                else
                {
                        message_vision("$N大喝一声：“我就是桃花岛弟子，你也敢要钱？！”\n", ob);
                        command("fear"+query("id", ob));
                        message_vision("船老大苦着脸对$N说：“客官息怒，小的这就找船家来。”\n", ob);
                        if (query_temp("busy",get_object("/d/taohua/boat")))
                         {
                                command("say 小船已经出海了，客官您先稍等一会儿。\n");
                                write("您可以随时要求启航(qihang)了。\n");
                                set_temp("thd_temp", 3, ob);
                        }
                        else {
                                say("船老大一招手，喊过一个艄公来：载这位客官去桃花岛。\n");
                                set_temp("thd_target", "thd", ob);
                                delete_temp("thd_temp", ob);
                                ob->move("/d/taohua/boat");
                        }
                }
        }
        else say("船老大摇摇头，说道：我们只听说过桃花岛，可谁也不知道在哪里。\n");
        return 1;
}

int ask_price()
{
        object ob=this_player();
        int money = 30000;

        if( query("age", ob)<16 )
                money=(query("age", ob)-13)*1000;
        if( query_temp("thd_temp", ob) )
        {
                say("船老大似笑非笑地说道：我看客官面善，就收您" + MONEY_D->price_str(money) + "吧。\n" );
                command("hehe laoda");
                set_temp("thd_temp", 2, ob);
        }
        else {
                command("?"+query("id", ob));
                command("dunno"+query("id", ob));
        }
        return 1;
}

int accept_object(object who, object ob)
{
        int money = 30000;

        if( query("age", who)<16 )
                money=(query("age", who)-13)*1000;
        if( query("money_id", ob) && ob->value() >= money){
                if( query_temp("thd_temp", who)<2 )
                        say("船老大乐了，说道：您老是有钱没处花么？\n");
                else {
                        if (query_temp("busy",get_object("/d/taohua/boat")))  {
                                command("say 小船已经出海了，客官您先稍等一会儿。\n");
                                write("您可以随时要求启航(qihang)了。\n");
                                set_temp("thd_temp", 3, who);
                        }
                        else {
                                command("say 船老大说道：好了您哪。\n");
                                say("船老大一招手，喊过一个艄公来：载这位客官去桃花岛。\n");
                                set_temp("thd_target", "thd", who);
                                delete_temp("thd_temp", who);
                                who->move("/d/taohua/boat");
                        }
                }
                return 1;
        }
        return 0;
}

int ask_qihang()
{
        object ob=this_player();

        if( query_temp("thd_temp", ob)<3 )
                say("船老大骂道：干什么？！想白坐啊？\n" );
        else {
                if (query_temp("busy",get_object("/d/taohua/boat")))  
                        command("say 小船已经出海了，客官您再等一会儿。\n");
                else {
                        command("say 船老大说道：好了您哪。\n");
                        say("船老大一招手，喊过一个艄公来：载这位客官去桃花岛。\n");
                        set_temp("thd_target", "thd", ob);
                        delete_temp("thd_temp", ob);
                        ob->move("/d/taohua/boat");
                }
        }
        return 1;
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        message_vision("船老大喝问$N：“在我的地盘你也敢撒野？！”\n", ob);
        message_vision("$N连忙赔笑道：“不敢，不敢。”\n", ob);
}
