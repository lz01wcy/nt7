// lin.c
// Last Modified by Lonely on May. 29 2001

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("林少宁", ({ "lin shaoning", "lin" }));
        set("long", "林少宁是泉州武馆馆长。\n");
        set("gender", "男性");
        set("age", 35);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("claw", 80);
        set_skill("hand", 80);
        set_skill("strike", 80);
        set_skill("finger", 80);
        set_skill("cuff", 80);
        set_skill("blade", 80);
        set_skill("stick", 80);
        set_skill("club", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("throwing", 80);
        set_skill("changquan", 40);
        set_skill("sanshou", 40);
        map_skill("cuff", "changquan");
        map_skill("hand", "sanshou");
        prepare_skill("cuff", "changquan");
        prepare_skill("hand", "sanshou");

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

}
int accept_object(object who, object ob)
{
        if( query("combat_exp", who) >= 3500 )
        {
                message_vision("林少宁望着$N说：你的武功应该历练江湖才能再长进，不能埋没在这里了。\n", who);
                return 0;
        }
        if( query("money_id", ob) && ob->value() >= 500 )
        {
                set_temp("marks/quanzhou_paied", 1, who);
                message_vision("林少宁对$N说：好！这位" + RANK_D->query_respect(who) + "想学什么呢？\n" , who);
                return 1;
        }
        else
                message_vision("林少宁皱眉对$N说：钱我不在乎。可你也给的也太少了点儿吧？\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if( !query_temp("marks/quanzhou_paied", ob) == 1)return 0;
        return 1;
}

