// gongnu.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("宫女", ({ "gong nu", "nu", "girl" }) );
        set("gender", "女性");
        set("age", 25);
        set("long", "这是伺侯娘娘的宫女。\n");
        set("combat_exp", 1000);
        set("shen_type", 0);
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 22);
        set("int", 20);
        set("dex", 24);

        set("max_qi", 400);
        set("eff_qi", 400);
        set("qi", 400);
        set("max_jing", 500);
        set("jing", 500);

        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);

        setup();

        carry_object("/d/city/obj/pink_cloth")->wear();
}
