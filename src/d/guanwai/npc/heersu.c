#include <ansi.h>
inherit KNOWER;

string ask_me();

void create()
{
        set_name("赫尔苏", ({ "he ersu", "he", "ersu", "heersu" }));
        set("long", "他是一个老参客，可是一贫如洗。\n");
        set("title", WHT "参客" NOR);
        set("age", 65);
        set("combat_exp", 300);
        set("str", 30);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
        set("attitude", "friendly");
        set("inquiry", ([
                "人参" : (: ask_me :),
                "山参" : (: ask_me :),
        ]));

        if (random(10) > 5)
                set("count", 1);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/stick")->wield();
}

string ask_me()
{
        object me = this_player();

        if (query("count") < 1)
        {
                return "嘿嘿，你下次再来吧，现在我手里也没货。\n";
        } else
        if( query_temp("tmark/参", me) )
        {
                return "你到底打算罗嗦些什么？\n";
        } else
        {
                set_temp("tmark/参", 1, me);
                return "我这儿倒是留了棵老山参，不过得先交钱。\n";
        }
}

int accept_object(object who, object ob)
{
        object obj;

        if( !query("money_id", ob) )
        {
                write(CYN "赫尔苏诧异地说道：你给我这个干什么？\n" NOR);
                return 0;
        }

        if (query("count") < 1)
        {
                write(CYN "赫尔苏摇头道：你等下次吧，现在我手里也没货。\n" NOR);
                return 0;
        }

        if( !query_temp("tmark/参", who) )
        {
                write(CYN "赫尔苏疑惑道：我又不是乞丐，没事给我钱作甚？\n" NOR);
                return 0;
        }

        if (ob->value() < 100000)
        {
                write(CYN "赫尔苏冷笑道：嘿嘿，给我这么多钱哪？\n" NOR);
                return 0;
        }

        obj = new("/clone/fam/pill/renshen1");
        obj->move(this_object());

        addn("count", -1);
        command("givebainianrenshento"+query("id", who));
        write(CYN "赫尔苏说道：既然您出得起价，这株百年人参就给您吧。\n" NOR);
        return 1;
}
