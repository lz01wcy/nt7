// qiaofu.c
// Last Modifyed by Ahda on Jan. 4 2002

inherit NPC;

void create()
{
        set_name("樵夫", ({ "qiao fu","qiao","fu" }) );
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个很健壮的樵夫。\n");
        set("shen_type", 1);
        set("combat_exp", 800);
        set("str", 22);
        set("dex", 18);
        set("con", 18);
        set("int", 18);
        set("attitude", "friendly");
        setup();
        carry_object(CLOTH_DIR"cloth")->wear();
        carry_object(__DIR__"obj/chai");
        carry_object(__DIR__"obj/chaidao")->wield();
}