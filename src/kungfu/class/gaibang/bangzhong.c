// bangzhong.c

#include <ansi.h>;
inherit NPC;
#include "fight.h"

string *duo = ({ "仁", "义", "礼", "智", "信", "勇" });
void create()
{
        int level;
        level = random(7)+1;
        NPC_D->generate_cn_name(this_object());
        set("long", "这是位衣着破烂的丐帮弟子，眉目间透出股英气。\n");
        set("title", "丐帮"+chinese_number(level)+"袋弟子");
        set("gender", "男性");
        set("age", 15+level*5);
        set("attitude", "peaceful");
        set("class", "beggar");
         set("beggarlvl", 7);
        set("str", 23);
        set("int", 22);
        set("con", 18);
        set("dex", 25);

        set("max_qi", 200*level);
        set("qi", 200*level);
        set("max_jing", 100*level);
        set("jing", 100*level);
        set("neili", 150*level);
        set("max_neili", 150*level);
        set("jiali", 10*level);

        set("combat_exp", 3000 * level * level);

        set_skill("force", level*10);
        set_skill("huntian-qigong", level*10);
        set_skill("hand", level*10);
        set_skill("suohou-hand", level*10);
        set_skill("blade", level*10);
        set_skill("liuhe-dao", level*10);
        set_skill("dodge", level*10);
        set_skill("xiaoyaoyou", level*10);
        set_skill("parry", 70);
        set_skill("begging", 70);

        map_skill("force", "huntian-qigong");
        map_skill("blade", "liuhe-dao");
        map_skill("hand", "suohou-hand");
        map_skill("parry", "suohou-hand");
        map_skill("dodge", "xiaoyaoyou");
        prepare_skill("hand", "suohou-hand");

        //set("party/party_name", HIC"丐帮"NOR);
        //set("party/rank", GRN+"大"+duo[random(6)]+"分舵"HIY+chinese_number(level)+"袋弟子"NOR);
        //set("party/level", level);
        create_family("丐帮", 20, "弟子");

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(WEAPON_DIR"gangdao")->wield();
}
