// /d/yixing/npc/bangzhong.c
// Last Modified by Lonely on Jul. 12 2002
// skills and exp are set up by message_bangzhu.h file

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>
inherit NPC;
inherit F_SSERVER;

int auto_check();
int do_destroy(object);

void create()
{
        set_name("帮众", ({ "bangzhong" }));
        set("gender", "男性");
        set("party/party_name", HIC"长乐帮"NOR);
        set("party/rank", "豹捷堂");
        set("age", 20 + random(10));
        set("long", "一名身材高大的壮汉，满脸杀气，一付凶神恶煞的模样。\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 24);
        set("int", 10);
        set("con", 24);
        set("dex", 24);

        set("combat_exp", 30000);

        set("chat_chance", 5);
        set("chat_msg", ({
                (: auto_check :),
        }) );

        setup();
}

void init()
{
        ::init();

        add_action("do_check", "exert");
        add_action("do_check", "yun");
}

int do_check(string arg)
{
        object ob;
        string what, who;

        if( !arg ) return notify_fail("");

        if( arg != "play" )
        {
                 if( sscanf(arg, "%s %s", what, who) != 2 )
                          return notify_fail("");
                 if( what != "play" ) return notify_fail("");
        }
        if( !(ob = query("owner")) ) return notify_fail("");
        if( environment(ob) != environment() ) return notify_fail("");
        return 1;
}

int auto_check()
{
        object me = this_object();
        object ob, dest, room, victim;

        if( !living(me) ) return 1;
        if( !(ob = query("owner")) ) return do_destroy(me);
        if( !(dest = environment(ob)) ) return do_destroy(me);

        room = environment();
        if( room != dest ) {
                message("vision", me->name() + "急急忙忙地离开了。\n", room, ({me}));
                me->move(dest);
                message("vision", me->name() + "走了过来。\n", dest, ({me}));

                me->set_leader(ob);
                message_vision("$N诚惶诚恐地说道：望帮主恕罪！\n", me);
                return 1;
        }

        if( !ob->is_fighting() ) return 1;
        if( !living(victim = offensive_target(ob)) ) return 1;
        if( !is_fighting(victim) ) kill_ob(victim);
        return 1;
}

int do_destroy(object ob)
{
        message("vision", ob->name() + "急急忙忙地离开了。\n", environment(ob), ({ob}));

        destruct(ob);
        return 1;
}

int accept_kill(object me)
{
        object ob;

        if( !(ob = query("owner")) ) return 1;

        if( environment(ob) != environment()
        || !living(ob)
        ||  ob->is_busy()
        ||  ob->is_killing() ) return 1;

        message_vision("$N对$n喝道：敢伤我弟兄，胆子不小！\n", ob, me);
        ob->kill_ob(me);
        return 1;
}

void die()
{       
        object ob, corpse, killer, obj;
        int bonus, record;

        if( !living(this_object()) ) revive(1);
//        clear_condition();

        if( objectp(killer = query_temp("last_damage_from")) ) {
        if( query_temp("bangs/victim", killer) == query("title")){
                delete_temp("bangs/victim", killer);
                bonus = (int)query("combat_exp");
                bonus=bonus*100/(bonus+query("combat_exp", killer));
                record = bonus + random(bonus);
                addn("combat_exp", record, killer);

                log_file("BangJob",sprintf("%s于%s时因杀人示威得%s经验点\n",query("name", killer),ctime(time()),chinese_number(record)));

                bonus /= 4;
                if( obj = present("bang ling", killer) ) {
                        if( query("owner", obj) == query("id", killer) )
                                addn("score", bonus, obj);
                                delete("job", obj);
                }
        }
        }

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        dismiss_team();
        destruct(this_object());
}

