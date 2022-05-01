// Last Modified by Sir on May. 22 2001
// xian.c
inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#include <ansi.h>;
#include "hengshan.h";

string ask_me();
string ask_yao();
void create()
{
        set_name("定闲师太", ({ "dingxian shitai", "shitai", "dingxian" }) );
        set("long", "她就是恒山派的定闲师太，她身材瘦高，慈眉善目，\n"
                "是现任恒山派掌门人。\n");
        set("gender", "女性");
        set("title", HIB"恒山派第十三代掌门"NOR);
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
        set("inquiry",([
                "剃度"  : "贫尼不剃度弟子。",
                "出家"  : "贫尼不剃度弟子。",
                "还俗"  : "恒山弟子，不能还俗。",
                "白云熊胆丸" : (: ask_yao :),
                "秘籍"         : (: ask_me :),
                "天长掌法谱" : (: ask_me :),
        ]));
        set("no_get",1);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.yuyin" :),
                (: perform_action, "sword.yuyin" :),
                (: perform_action, "sword.yuyin" :),
                (: perform_action, "sword.liuyun" :),
                (: perform_action, "sword.liuyun" :),
                (: perform_action, "sword.liuyun" :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("wield changjian") :),
                (: command("wield changjian") :),
                (: command("wield chacngjian") :),
                (: command("wield changjian") :),
                (: perform_action, "hand.break" :),
                (: perform_action, "hand.break" :),
                (: perform_action, "hand.break" :),
                (: perform_action, "strike.diezhang" :),
                (: perform_action, "strike.diezhang" :),
                (: perform_action, "strike.diezhang" :),
        }));


        set("max_qi", 4000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali",100);
        set("jingli", 1500);
        set("max_jingli", 1500);
        set("combat_exp", 3000000);
        set("score", 1000);
        set("book_count", 1);
        set("yao_count", 1);

        set_skill("unarmed", 600);
        set_skill("sword", 600);
        set_skill("force", 600);
        set_skill("parry", 600);
        set_skill("dodge", 600);
        set_skill("strike", 600);
        set_skill("hand", 600);
        set_skill("buddhism", 600);
        set_skill("baiyun-xinfa",600);
        set_skill("hengshan-jian", 600);
        set_skill("chuanyun-shou",600);
        set_skill("tianchang-zhang",600);
        set_skill("lingxu-bu", 600);
        set_skill("literate", 600);

        map_skill("force","baiyun-xinfa");
        map_skill("sword", "hengshan-jian");
        map_skill("strike","tianchang-zhang");
        map_skill("hand","chuanyun-shou");
        map_skill("parry", "hengshan-jian");
        map_skill("dodge", "lingxu-bu");

        prepare_skill("hand", "chuanyun-shou");
        prepare_skill("strike", "tianchang-zhang");

        create_family("恒山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
void attempt_apprentice(object ob)
{
        string name, new_name;

        if (! permit_recruit(ob))
                return;

        if( query("class", ob) != "bonze" )
        {
                command ("say 阿弥陀佛！贫尼不收俗家弟子。");
                return;
        }

        if ((int)ob->query_skill("baiyun-xinfa",1) < 90 )
        {
                command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
                return;
        }
        if( query("shen", ob)<100000 )
        {
                command( "say 你若能多为侠义之举，当能承我衣钵。\n");
                return;
        }
        command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
        command("say 希望你能努力行善，济度众生，以光大我恒山派。");
        command("recruit "+query("id", ob));
        name=query("name", ob);
        new_name = "仪" + name[1..1];
        command("say 从今以后你的法名叫做" + new_name + "。");
        set("name", new_name, ob);
}


string ask_me()
{
        object ob;

        if( query("family/family_name", this_player()) != "恒山派" )
                return RANK_D->query_respect(this_player()) +
                "与本派毫无瓜葛，我派的武功典籍可不能交给你。";
        if (query("book_count") < 1)
                return "你来晚了，本派的秘籍不在此处。";
        addn("book_count", -1);
        ob = new("/clone/book/tianchang-zhangpu");
        ob->move(this_player());
        command("rumor"+query("name", this_player())+"拿到天长掌法谱啦。\n");
        return "好吧，这本「天长掌法谱」你拿回去好好钻研。";
}
string ask_yao()
{
        object ob;

        if( query("family/master_id", this_player()) != "dingxianshitai" )
                return RANK_D->query_respect(this_player()) +
                "非我弟子，不知此话从何谈起？";
        if (query("yao_count") < 1 || random(3) > 0)
                return "你来晚了，白云熊胆丸刚巧给人了。";
        addn("yao_count", -1);
        ob = new("/clone/medicine/nostrum/baiyunwan");
        ob->move(this_player());
        return "好吧，这粒白云熊胆丸就先给你吧。";
}
