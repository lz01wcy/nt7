//girl.c

inherit BUNCHER; 
inherit F_DEALER;

void create()
{
        set_name("卖花姑娘", ({"maihua guniang", "girl", "guniang"}));
        set("shop_title", "花店老板");
        set("gender", "女性");
        set("combat_exp", 4000);
        set("age", 17);
        set("per", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("vendor_goods", ({
                "/d/changan/npc/obj/zi-luolan",
                "/d/changan/npc/obj/hong-meigui",
                "/d/changan/npc/obj/huang-meigui",
                "/d/changan/npc/obj/lan-tiane",
                "/d/changan/npc/obj/bai-chahua",
                "/d/changan/npc/obj/hei-mudan",
        }));

        setup();
          carry_object("/d/changan/npc/obj/skirt")->wear();
          add_money("silver", 30);
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");         
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        switch( random(2) ) 
        {
        case 0:
                message_vision("$N笑着说道：各种新"
                               "鲜花朵，买些回去给你的心上人吧。\n",
                               this_object(), ob);
                break;
        case 1:
                message_vision("$N笑咪咪地说道：这位" +
                               RANK_D->query_respect(ob) +
                               "要买什么花儿？\n",
                               this_object(), ob);

                break;
        }
}
