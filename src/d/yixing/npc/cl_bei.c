// /d/yixing/npc/cl_bei.c 贝海石
// Last Modified by Lonely on Jul. 12 2002

inherit NPC;

#include <ansi.h>
#include <localtime.h>

string ask_job();
string ask_cure();
string ask_salary();

void create()
{
        set_name("贝海石", ({ "bei haishi", "bei" }));
        set("nickname", "着手成春");
        set("party/party_name", HIC"长乐帮"NOR);
        set("party/rank", "总管");
        set("long", 
                "他是一个身穿黄衫的老人，看上去脸色苍白，说话有气无力，\n"
                "还不停的咳嗽着，便似身患重病一般。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 900);
        set("max_jing", 500);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 40);
        set("combat_exp", 200000);
        set("score", 8000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("cuff",  120);
/*
        set_skill("ding-force",  100);
        set_skill("wuxingbu",   100);
        set_skill("wuxing-quan", 120);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff",  "wuxing-quan");
        map_skill("parry", "wuxing-quan");

        prepare_skill("cuff", "wuxing-quan");
*/
        set("inquiry", ([
                "长乐帮" : "长乐帮的具体事务由我总管。",
                "入帮" : "你去问帮主吧。",
/*
                "帮务" : (: ask_job :),
                "job"   : (: ask_job :),
*/
                "武功" : "帮主老人家的武功比我强多了，你还是向帮主学吧。",
                "香主" : "各位香主的任命由帮主老人家说了算。",
                "司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
                "帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
/*
                "疗伤" : (: ask_cure :),
                "cure" : (: ask_cure :),
                "红包" : (: ask_salary :),
                "salary" : (: ask_salary :),
*/
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

string ask_cure()
{
        object ling, me = this_player();
        string myfam;

        myfam = (string)query("party/party_name");
        if( query("party/party_name", me) != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";  

        if( time()<query("bangs/curetime", me)+60 )
                return RANK_D->query_rude(me) + "不是刚问过我吗？";

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( query("owner", ling) != query("id", me) )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( query("score", ling)<10 )
                return RANK_D->query_rude(me) + "不为帮中出力，光知道捞好处。";

        if( query("eff_qi", me)*10>query("max_qi", me)*8 )
                return "伤不重的话，挨两天就自愈了。";

        command("nod");
        addn("score", -2, ling);
        set("bangs/curetime", time(), me);
        message_vision("$N将一一包金创药递给$n。\n", this_object(), me);
        message_vision("$N小心翼翼地把一包金创药敷在伤口上，只觉伤势大为好转，气色看起来好多了。\n", me);
        me->receive_curing("qi", 50);
        return "服一包金创药就没事了。";
}

string ask_salary()
{
        object wage, ling, me = this_player();
        string myfam;
        int amount;

        myfam = (string)query("party/party_name");
        if( query("party/party_name", me) != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";

//        if( me->query_temp("bangs/pos") )
        if( query("bangs/pos", me) )
                return RANK_D->query_respect(me) + "已是一堂之主了，帮主那儿定有重赏。";

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( query("owner", ling) != query("id", me) )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( time()<query("bangs/salarytime", me)+1800 )
                return RANK_D->query_rude(me) + "不是刚问过我吗？";

        if( (amount=query("score", ling))<30 )
                return RANK_D->query_rude(me) + "最近表现很差呀，你这些日子在干吗？";

        command("nod");
        set("bangs/salarytime", time(), me);

        wage = new("/clone/money/silver");
        wage->set_amount(amount);
        delete("score", ling);
        wage->move(me);
        message_vision("$N转身拿出一个红包递给$n。\n", this_object(), me);
        return "你最近表现不错，这份红包你拿去花吧。";
}

#include "guanjia.h";
