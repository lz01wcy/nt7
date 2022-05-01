// This program is a part of NITAN MudLIB
// linghu.c 令狐冲

#include <ansi.h>
#include "qizong.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_me();
string ask_ylj1();
string ask_ylj2();
string ask_ylj3();
mixed learn_chongling();

void create()
{
        set_name("令狐冲", ({ "linghu chong", "linghu", "chong" }));
        set("nickname", "大师兄");
        set("long", "他身材较瘦，长的浓眉阔眼，气宇暄昂，在同门中排行老大，\n"
                    "是华山派年轻一代中的顶尖好手。\n");
        set("gender", "男性");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);

        set("qi", 4800);
        set("max_qi", 4800);
        set("jing", 2400);
        set("max_jing", 2400);
        set("neili", 5700);
        set("max_neili", 5700);
        set("jiali", 60);
        set("level", 30);
        set("combat_exp", 2200000);
        set("score", 150000);

        set_skill("blade", 200);
        set_skill("cuff", 200);
        set_skill("feiyan-huixiang", 200);
        set_skill("strike", 200);
        set_skill("hunyuan-zhang", 200);
        set_skill("cuff",200);
        set_skill("poyu-quan", 200);
        set_skill("force", 200);
        set_skill("yijinjing", 200);
        set_skill("huashan-neigong", 200);
        set_skill("zixia-shengong", 200);
        set_skill("dodge", 200);
        set_skill("parry", 220);
        set_skill("sword", 240);
        set_skill("huashan-sword", 240);
        set_skill("chongling-jian", 240);
        set_skill("lonely-sword", 240);
        set_skill("huashan-quan", 240);
        set_skill("huashan-zhang", 240);
        set_skill("literate", 240);
        set_skill("tanqin-jifa", 400);
        set_skill("xiaoao-jianghu", 400);
        set_skill("qingxin-pushan", 400);
        set_skill("martial-cognize", 230);

        map_skill("force", "yijinjing");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "huashan-zhangfa");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "lonely-sword");
        map_skill("sword", "lonely-sword");
        map_skill("tanqin-jifa", "xiaoao-jianghu");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "poyu-quan");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.poqi" :),
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.yi" :),
                (: exert_function, "recover" :),
        }) );

        create_family("华山派", 14, "弟子");

        set("inquiry", ([
                "风清扬" : "唉，已经很久没有见到他老人家了。你问这干嘛？",
                "任盈盈" : "你真有她的消息吗，说罢，以见他神情激动，好象眼睛红红的！\n",
                "清心普善咒" : "这可是盈盈交给我的...",
                "笑傲江湖"   : "这是曲洋长老和刘正风师叔留下来的...唉！",
                "琴谱"       : (: ask_me :),
                "冲灵剑法"   : (: learn_chongling :),
                "宝剑"       : (: ask_ylj3 :),
                // "墨纹玄铁"   : (: ask_ylj2 :),
                // "遇见尼姑，逢赌必输" : (: ask_ylj1 :),
        ]));

        set("no_teach", ([
                "yijinjing"    : "此乃少林秘传，蒙方正大师传授，我不能擅自教你。",
                "lonely-sword" : "风老先生传我九剑的时候我立下誓言不得私"
                                 "自传授，你还是学习其他武功吧！",
        ]));

        set("music_book", 1);
        set("master_ob",3);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/heimuya/npc/obj/card2");
}

int recognize_apprentice(object me, string skill)
{
        if (skill != "tanqin-jifa" &&
            skill != "xiaoao-jianghu" &&
            skill != "qingxin-pushan")
        {
                command("say 对不起...我不能传授你这些，你要是想学点操琴技术还差不多。");
                return -1;
        }

        if( query_temp("can_learn/linghu/"+skill, me) )
                return 1;

        set_temp("can_learn/linghu/"+skill, 1, me);
        command("say 好吧，你既然对" + to_chinese(skill) +
                "有兴趣，我就教你一点。");

        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if( query("family/family_name", ob) == "华山剑宗" )
        {
                command("say 你是剑宗的啊？我可不好收你，我师傅不同意的！");
                return;
        }

        if( query("shen", ob)<0 )
        {
                command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }

        if ((int)ob->query_int() < 25)
        {
                command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我华山派武功？");
                return;
        }

        command("say 好吧，我就收下你了。");
        command("recruit "+query("id", ob));
        if( query("class", ob) != "swordsman" )
                set("class", "swordsman", ob);

        return;
}

mixed ask_me()
{
        object me;
        object ob;

        me = this_player();
        if (query("music_book") < 1)
                return "我的琴谱已经借出去了。\n";

        ob = new("/clone/book/qin");
        ob->move(me, 1);
        message_vision("$n把琴谱给了$N，道：你拿去好好学习吧。\n",
                       me, this_object());
        set("music_book", 0);
        return 1;
}

void reset()
{
        set("music_book", 1);
}

/*
void unconcious()
{
        die();
}
*/

mixed learn_chongling()
{
        object me = this_player();
        int lv = me->query_skill("huashan-sword", 1);

        if (me->query_skill("chongling-jian"))
               return "你不是已经会了吗？\n";

        if( query("family/family_name", me) != "华山派" )
               return "你说什么，我不明白！\n";

        if (lv < 100)
               return "你冲灵剑法修为不够，我还不能传你这招！\n";
        message_vision(HIW "$N" HIW "说道：“这套剑法是我和小师妹练剑的时候突发奇想"
                       "创出来的，乃是从华山剑法中演化出来！你可看好了！”说完将「冲"
                       "灵剑法」冲头到尾地给$n" HIW "演示了一遍！\n" NOR,
                       this_object(), me);

        command("haha");
        tell_object(me, HIG "你学会了「冲灵剑法」！\n" NOR);

        if( !query("have_ask_chongling", me)){
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("huashan-sword"))
                me->improve_skill("huashan-sword", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        set("have_ask_chongling", 1, me);
        }

        command("say 领会了多少就看你华山剑法的修为了，剩下的就靠你自己下去练习！");

        me->set_skill("chongling-jian", lv / 10);

        return 1;
}

int accept_object(object who, object ob)
{
        object obn;
        int r;

        if (r = ::accept_object(who, ob))
                return r;

        if (! who || environment(who) != environment())
                return 0;

        if (! objectp(ob))
                return 0;

        if (! present(ob, who))
                return notify_fail("你没有这件东西。\n");

        if( query("name", ob) != "信" &&
            query("id", ob) != "qingxin" )
                return notify_fail("令狐冲不需要这件东西。\n");

        say("令狐冲双手捧着任盈盈的信，泪如雨下，这块白虎堂令牌你拿去还给盈盈，告诉她我就去找她!");
        obn = new("/d/heimuya/npc/obj/card2");
        obn->set_amount(1);
        obn->move(who);
        destruct(ob);
        return 1;
}

string ask_ylj1()
{
        object me;

        me = this_player();
        command("haha"+query("id", me));
        set_temp("ylj/step1", 1, me);

        return sort_string("兄台也知道这件事？这是当初兄弟我为救恒山派的仪琳师妹，向采"
                           "花大盗田伯光开的玩笑，事后恒山的定静师伯不但没怪我，还送我"
                           "了一块世间已绝迹的墨纹玄铁，要我用它铸成一把绝世宝剑，行侠"
                           "处恶，笑傲江湖.....\n", 64, 3);
}

string ask_ylj2()
{
        object me;

        me = this_player();
        if( !query_temp("ylj/step1", me) )
                return "这可是个天大的秘密。\n";

        set_temp("ylj/step2", 1, me);
        delete_temp("ylj/step1", me);

        return "说来这墨纹玄铁也是一个宝物，我一直找不到铸剑名师，不想浪费了这块玄铁...。\n";
}

string ask_ylj3()
{
        object me, obj;

        me = this_player();
        if( !query_temp("ylj/step2", me) )
                return "这可是个天大的秘密。\n";

        delete_temp("ylj/step2", me);
        command("look"+query("id", me));

        if( query("shen", me)>100000 )
        {
                obj = new(__DIR__"obj/xuantie");
                obj->move(me);
                // me->set_temp("ylj/step3", 1);
                return "看兄台一身正气，这块玄铁就送与兄台，望兄台能找到铸\n"
                       "剑名师，铸成宝剑，行侠江湖，也不枉费定静师伯的一翻苦心.....\n";
        }
        return "这可是个天大的秘密。\n";
}
