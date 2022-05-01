#include <ansi.h>
inherit NPC;

#define HEILONG    "/clone/lonely/heilongbian"
#define LING       "/clone/lonely/item/tongjiling"

void create()
{
        object ob;
        set_name("茅十八", ({ "mao shiba", "mao", "shiba" }));
        set("long", @LONG
他虬髯如乱草，满脸血污，好象曾受过很重的
伤，可以看得见他左腿上血迹未干。但他双目
炯炯，却又有着说不出的威风。
LONG);
        set("title", "官府通缉要犯");
        set("gender", "男性");
        set("age", 30);
        set("str", 25);
        set("dex", 16);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("force", 100);
        set_skill("bagua-xinfa", 100);
        set_skill("blade", 120);
        set_skill("wuhu-duanmendao", 120);
        set_skill("cuff", 120);
        set_skill("hua-quan", 120);
        set_skill("dodge", 100);
        set_skill("feiyan-zoubi", 100);
        set_skill("parry", 100);
        set_skill("literate", 60);
        set_skill("martial-cognize", 80);

        map_skill("blade", "wuhu-duanmendao");
        map_skill("parry", "wuhu-duanmendao");
        map_skill("force", "bagua-xinfa");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("cuff", "hua-quan");

        prepare_skill("cuff", "hua-quan");

        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 50);
        set_temp("apply/unarmed_damage", 50);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.juan" :),
                (: perform_action, "blade.duan" :),
                (: exert_function, "recover" :),
        }));

        set("inquiry", ([
                "史松"   : "谁杀了史松这奸贼，我可以帮他提高江湖威望。",
                // "断字诀" : "我总得留两手吧？",
        ]));

        set("chat_chance", 2);
        set("chat_msg", ({
                CYN "茅十八说道: 他奶奶的，我就不信鳌拜有这等厉害，我正要上北京去斗他一斗。\n" NOR,
                CYN "茅十八叹道: 我这五虎断门刀法对付盐枭可是绰绰有余，不知对付鳌拜行不行。\n" NOR,
                CYN "茅十八说道: 他奶奶的，要谁帮我杀了史松，兄弟我就谢谢了。\n" NOR,
                CYN "茅十八朗声说道：江湖有言为人不识陈近南，就称英雄也枉然。\n" NOR,
                (: random_move :)
        }) );
        setup();
        if (clonep())
        {
                ob = find_object(LING);
                if (! ob) ob = load_object(LING);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        set_temp("handing", ob);
                }
        }
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object me, object ob)
{
        int exp, pot, sc;

        exp = 500 + random(300);
        pot = 100 + random(50);
        sc = random(10);

        if (base_name(ob) != HEILONG)
        {
                command("say 你给我这种东西干什么？");
                return 0;
        }

        if( query("combat_exp", me)>10000 )
        {
        	if( !query("skybook/luding/mao", me) )
        	{
                addn("combat_exp", exp, 	me);
                addn("potential", pot, 	me);
                addn("score", sc, 	me);
                	tell_object(me, HIW "\n\n你成功的帮助茅十八弄到了黑龙鞭！\n" NOR +
                                        HIC "通过这次的历练，你获得了" + chinese_number(exp) +
                                        "点经验、" + chinese_number(pot) + "点潜能以及" +
                                	chinese_number(sc) + "点江湖阅历。\n\n" NOR);
                set("skybook/luding/mao", 1, 	me);
                set("can_learn/wuhu-duanmendao/mao", 1, 	me);
		}
                command("haha");
                command("say 多谢，多谢。那个狗腿子俺早就想除去了。");
                command("say 俺这有一套五虎断门刀，你如果有意，倒是可以看看。\n");
        } else
	{
                command("pat"+query("id", me));
                command("say 要不是你的江湖经验太浅，俺真想教你点东西。");
	}
        destruct(ob);
        return 1;
}

int recognize_apprentice(object me, string skill)
{
        if( !query("can_learn/wuhu-duanmendao/mao", me) )
        {
                command("say 干嘛？没拜师就想向俺学东西？");
                return -1;
        }

        if (skill != "wuhu-duanmendao")
        {
                command("say 俺就只有这一套刀法拿得出手。");
                return -1;
        }
        return 1;
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
                case "断字诀" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/wuhu-duanmendao/duan",
                           "name"    : "断字诀",
                           "sk1"     : "wuhu-duanmendao",
                           "lv1"     : 150,
                           "force"   : 140,
                           "neili"   : 1500,
                           "free"    : 1,
                           "shen"    : 5000, ]));
                break;
        default:
                return 0;
        }
}
