// tufei1.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("盘龙花纹", ({ "picture"}) );
        set("gender", "男性" );
        set("age", 34);
        set("long",
                "他就是凶狠的蒙面大盗，作案从来不留活口。\n");
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("max_neili", 5000);
        set("jiali", 500);
        set("combat_exp", 4000000);
        set("attitude", "friendly");
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set_skill("dodge", 500);
        set_skill("unarmed",500);
        set_skill("parry", 500);
        set_skill("force",500);
        set_skill("blade", 500);
        set_skill("hand", 500);
        set_skill("cuff", 500);
        set_skill("yunlong-shengong", 500);
        set_skill("wuhu-duanmendao", 500);
        set_skill("changquan", 500);
        set_skill("sanshou", 500);
        set_skill("shenxing-baibian", 500);

        set("no_see", 1);
        set_weight(5);
        map_skill("force", "yunlong-shengong");
        map_skill("dodge", "shenxing-baibian");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("parry", "wuhu-duanmendao");
        map_skill("hand", "sanshou");
        map_skill("cuff", "changquan");
        prepare_skill("hand", "sanshou");
        prepare_skill("cuff", "changquan");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "blade.duan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );
        setup();
}
int do_look(string arg)
{
        if( arg == "picture" && query("id", this_object()) == "picture" )
    {
            write("这是一张官府的"+query("name", this_object())+"。\n");
            destruct(this_object());
      return 1;
    }
  return 0;
}
void init()
{
        object ob,obj;
        mapping skl;
        string *skillname;
        int maxskill,j;
  ob = this_player();
        obj = this_object();
  add_action("do_look","look");
        if( !query_temp("bt_inited") && interactive(ob) && query("id", ob) == query_temp("bt_ownname", obj) )
        {
                
    maxskill=query("maxskill");
    if (!maxskill)
    {
                   skl = ob->query_skills();
                   maxskill =10;
                  if (sizeof(skl))
                  { 
                    skillname = sort_array( keys(skl), (: strcmp :) );
                          for (j=0; j<sizeof(skl); j++)
                          {
                                  if (maxskill < skl[skillname[j]])
                                          maxskill = skl[skillname[j]];
                          }
                  }
          }
                addn_temp("bt_inited", 1, obj);
                set_skill("dodge", maxskill*2/3);
                set_skill("unarmed", maxskill*2/3);
                set_skill("force", maxskill*2/3);
                set_skill("cuff", maxskill*2/3);
                set_skill("parry", maxskill*2/3);
                set_skill("blade", maxskill*2/3);
                set_skill("hand", maxskill*2/3);
                set_skill("wuhu-duanmendao", maxskill*2/3);
                set_skill("changquan", maxskill*2/3);
                set_skill("sanshou", maxskill*2/3);
                set_skill("shenxing-baibian", maxskill*2/3);
                set_skill("yunlong-shengong", maxskill*2/3);
                if (!present("blade",obj))
                        carry_object("/clone/weapon/gangdao")->wield();
                set("title", "杀人如麻", obj);
                obj->set_weight(500000);
                set_name("蒙面大盗", ({ "mengmian dadao","md"}) );
                remove_call_out ("destroy_npc");
                call_out ("destroy_npc", 900); // 15 min
        }
        if( query("id", ob) == query_temp("bt_ownname", obj) )
        obj->kill_ob(ob);
}
void destroy_npc()
{
        message_vision(query("name", this_object())+"忽然打了个哆嗦，不由心生惧意，身形一晃，顿时混入莽莽人海之中。\n",environment(this_object()));
        destruct(this_object());
}
void die()
{
        object ob,me;
        string own;
        message_vision("$N倒在地上，死了！\n", this_object());
        ob = this_object();
        own=query_temp("bt_ownname", ob);
        if(own) me = find_player(own);
        if( me && query_temp("last_damage_from", ob) == me
         && (!query_temp("faint_by", ob) || query_temp("faint_by", ob) == me )
         && query_temp("bt_npc", ob) == query_temp("bt/npc", me) )
                        set_temp("bt/finish", 1, me);
        destruct(this_object());
}
varargs int receive_damage(string type, int damage, mixed from)
{
  if (query_leader())
   set_leader(0);
        return ::receive_damage(type,damage,from);
}