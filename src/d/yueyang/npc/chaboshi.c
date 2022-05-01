// chaboshi.c 茶博士?

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("茶博士", ({ "cha boshi", "chaboshi", "boshi" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这位茶博士一手提着大茶壶，一手拎着抹布，笑咪咪地忙着。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("no_get", "1");
        set("vendor_goods", ({
                __DIR__"obj/dongtingchun",
                __DIR__"obj/yinzhencha",
                __DIR__"obj/xianglian",
        }));
        setup();
        carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

void init()
{
        object ob;
        mapping myfam;

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
                if( (myfam=query("family", ob) )
                && myfam["family_name"] == "丐帮"
                && ob->query_skill("begging",1) > 10 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else
                {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob) + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob) + "，请进请进。\n");
                        break;
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        say("\n店小二大喝一声：你这臭要饭的进来干什麽？给我滚出去！\n\n");
        remove_call_out("kicking");
        call_out("kicking", 1, ob);

}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/yueyang/nanjie");
        message("vision","只听“乒”地一声，"+query("name", ob)+"被人从洞宾楼里一脚踢了出来，狼狈万状的逃开了。\n",environment(ob),ob);
}