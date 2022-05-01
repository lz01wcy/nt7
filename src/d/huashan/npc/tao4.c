// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tao4.c 桃叶仙

inherit NPC;
string ask_me();

void create()
{
        set_name("桃叶仙", ({ "tao yexian", "tao", "yexian" }));
        set("nickname", "桃谷六仙不知是老四还是老三");
        set("long", 
"桃叶仙与桃枝仙不知谁是老三，谁是老四。但他常说自己是老三，\n"
"和桃枝仙常常为此争论。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 29);
        set("int", 20);
        set("con", 29);
        set("dex", 29);
        set("shen", 0);
        
        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 50);
        set("level", 6);
        set("combat_exp", 300000);
        set("score", 5000);

        set_skill("force", 95);
        set_skill("dodge", 100);
        set_skill("parry", 95);
        set_skill("unarmed", 100);
        set_skill("ding-dodge", 95);
        set_skill("ding-force", 95);
        set_skill("ding-unarmed", 95);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");

        set("chat_chance", 5);

        set("chat_msg", ({
                "桃叶仙对着桃枝仙吼道：我才是老三，你是老四。\n",
                "桃叶仙说道：我们父母本来记得谁是老三谁是老三，后来却忘了。\n",
        }) );

        set("inquiry", ([
                "令狐冲"     : "令狐兄是我的好朋友，常说咱们六兄弟是江湖中的英雄好汉。\n",
                "风清扬"     : (: ask_me :),
                "风前辈"     : (: ask_me :),
                "风清扬前辈" : (: ask_me :),
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

#include "tao.h"
