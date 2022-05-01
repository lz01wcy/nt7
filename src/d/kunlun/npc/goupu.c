// Npc: /d/kunlun/npc/goupu.c 狗仆
// Last Modified by Lonely on Jun. 29 2001

inherit NPC;

void create()
{
        set_name("狗仆", ({ "gou pu", "pu" }));
        set("gender", "男性");
        set("age", 35);

        set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("shen_type", -1);
        setup();
}
        
