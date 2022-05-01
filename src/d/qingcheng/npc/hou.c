// hou.c

inherit NPC;

#include <ansi.h>;

void create()
{
        set_name("侯人英", ({ "hou renying", "hou", "renying" }));
        set("gender", "男性");
        set("nickname", HIC"青城四秀"NOR);
        set("age", 25);
        set("long", "他就是「英雄豪杰，青城四秀」之一，武功也远高同门。\n");

        set("combat_exp", 80000);
        set("shen_type", -1);

        set_skill("sword", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("strike", 80);
        set_skill("unarmed", 80);
        set_skill("force", 80);
        set_skill("bixie-sword", 80);
        set_skill("songfeng-jian", 80);
        set_skill("chuanhua", 80);
        set_skill("wuying-leg", 80);
        set_skill("cuixin-zhang", 80);
        set_skill("qingming-xuangong", 80);
        map_skill("force", "qingming-xuangong");
        map_skill("unarmed", "wuying-leg");
        map_skill("strike", "cuixin-zhang");
        map_skill("dodge", "chuanhua");
        map_skill("parry", "bixie-sword");
        map_skill("sword", "songfeng-jian");
        prepare_skill("unarmed", "wuying-leg");
        prepare_skill("strike", "cuixin-zhang");
        create_family("青城派", 6, "弟子");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}
