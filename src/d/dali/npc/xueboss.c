// xueboss.c

inherit BUNCHER;
inherit F_VENDOR;

void create()
{
        set_name("薛老板", ({ "xue laoban", "xue" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "这是一个经验老到的生意人，一双精明的眼睛不停的打量着你。\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/dali/npc/obj/shoes",
                "/d/dali/npc/obj/guazi",
                "/d/dali/npc/obj/kenao",
                "/d/dali/npc/obj/qun",
        }) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
