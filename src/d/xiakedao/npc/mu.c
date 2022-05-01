//mu.c

#include <ansi.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
        set_name("木丹凤", ({ "mu", "wood" }));
        set("long", "他就是天下闻之色变的侠客岛岛主，号称“叶上秋露”。\n"
                   +"只见他长须稀稀落落，兀自黑多白少，但一张脸却满是皱纹。\n"
                   +"看不出他的实际年纪。\n"
                   );
        set("title", "侠客岛主");
        set("gender", "男性");
        set("age", 75);
        set("nickname", HIB "叶上秋露" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 29);
        set("con", 30);
        set("dex", 28);

        set("qi", 900);
        set("max_qi", 900);
        set("jing", 900);
        set("max_jing", 900);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);

        set("combat_exp", 1500000);
        set("score", 200000);
        set_skill("force", 170);
        set_skill("unarmed", 100);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("hand",170);
        set_skill("staff", 170);

//      set_skill("yanyangong", 200);
        set_skill("jinwu-blade", 150);
//      set_skill("xiake-zhangfa", 100);
        set_skill("lingxu-bu", 150);

//      map_skill("force", "yanyangong");
        map_skill("dodge", "lingbo-weibu");
//      map_skill("unarmed", "xiake-zhangfa");
//      map_skill("hand", "xiake-zhangfa");
        map_skill("parry", "jinwu-blade");
        map_skill("staff", "jinwu-blade");

        create_family("侠客岛",1, "岛主");
        set("inquiry",([
           "腊八粥" :   "腊八粥只赠有缘人，不知你是否满足条件。？\n",
           "铜牌"   :   "我这可没有这玩艺，你如想要的话，可找别人问一问。\n",
        ]) );
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("gold",2);
}

void attempt_apprentice(object ob)
{
        message_vision("木岛主拍拍$N的头，微微摇了摇头。\n",ob);
//        command("recruit " + ob->query("id"));
        return;
}

int accept_object(object who, object ob)
{
        object obn;
        object room;
        object key;

        if ( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");
             command("smile");
        if( query("name", ob) == "罚恶铜牌" )
        {
            if( query_temp("own", ob) != query("name", who) )
            {
                 message_vision("这不是你的东西。\n",who);
                 return 0;
            }
            command("say原来是"+query("name", who)+"大侠"+
                "欢迎光临本岛。");

            obn=new("/d/xiakedao/obj/labazhou");
            obn->move(who);
            command(" say  这是本岛特产腊八粥，外边可不易喝到，其中最主要的一味是<断肠蚀骨腐心草>，"
               + "瞧" +  RANK_D->query_respect(who) + "也是有缘之人，快乘热喝，这样效力方著。");
            message_vision("木岛主给了你一碗腊八粥",who);
            if( query_temp("zhou", who) == 1 )
            {
                 command(" say 看来居士福缘深厚，有机会一睹武林绝技，请进吧！");
                 message_vision("只听得一阵隆隆的响声由远及近。\n", this_player());
                 set_temp("zhou", 0, who);
                 message_vision("只见岛主身后的石板缓缓移了开来，露出一条长长的甬道。\n", this_player());
                 set("exits/enter", "/u/noz/test/mishi", environment(who));

                 room=environment(who);
                 remove_call_out("close");
                 key = new("/d/xiakedao/obj/key");
message_vision("这是我身后石门的钥匙，也是侠客岛上的凭证，希望你妥善保管，不可随意丢弃，" +
                    "更不可交付他人，离岛时应与归还。\n", who);
                 key->move(who);
                 call_out("close", 15, room);
                 return 1;
            }
            set_temp("zhou", 2, who);
            return 1;
        }
        else
        {
            message_vision("我不需要这东西。\n",who);
            return 0;
        }
}

void close(object room)
{
        message("vision","轰隆隆的响声响过之后，石板又合上了。\n", room);
        delete("exits/enter", room);
}
