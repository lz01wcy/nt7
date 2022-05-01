// liu-zhuzhuang.c

#include <ansi.h>;
inherit NPC;

#include "fight.h"

void create()
{
        set_name("刘竹庄", ({"liu zhuzhuang", "liu", "zhuzhuang"}));
        set("gender", "男性");
        set("age", 35);
        set("long", "这是位武艺精强的丐帮五袋弟子。\n");
        set("title", "丐帮五袋弟子");
        set("attitude", "peaceful");
        set("class", "beggar");
         set("beggarlvl", 7);
        set("str", 23);
        set("int", 22);
        set("con", 18);
        set("dex", 25);

        set("max_qi", 360);
        set("max_jing", 300);
        set("neili", 710);
        set("max_neili", 710);
        set("jiali", 36);

        set("combat_exp", 69000);

        set_skill("force", 60);
        set_skill("huntian-qigong", 60);
        set_skill("hand", 60);
        set_skill("suohou-hand", 60);
        set_skill("blade", 68);
        set_skill("liuhe-dao", 60);
        set_skill("dodge", 68);
        set_skill("xiaoyaoyou", 60);
        set_skill("parry", 60);
        set_skill("staff", 60);
        set_skill("begging", 60);
        set_skill("strike",60);

        set_skill("lianhua-zhang",60);
        set_skill("turu-qilai",60);
        map_skill("strike","turu-qilai");
        prepare_skill("strike", "turu-qilai");
        map_skill("force", "huntian-qigong");
        map_skill("blade", "liuhe-dao");
        map_skill("hand", "suohou-hand");
        map_skill("parry", "suohou-hand");
        map_skill("dodge", "xiaoyaoyou");

        //set("party/party_name", HIC"丐帮"NOR);
        //set("party/rank", GRN"大智分舵"HIY"五袋弟子"NOR);
        //set("party/level", 5);
        create_family("丐帮", 20, "弟子");
        setup();

        carry_object(WEAPON_DIR"gangdao")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}
