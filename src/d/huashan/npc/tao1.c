// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tao1.c 桃根仙

inherit NPC;
string ask_me();

void create()
{
        set_name("桃根仙", ({ "tao genxian", "tao", "genxian" }));
        set("nickname", "桃谷六仙老大");
        set("long", 
"桃根仙张着一张长长的马脸，尊容是令人不敢恭维的。与其五兄\n"
"弟行影不离，号称「桃谷六仙」。\n");
        set("gender", "男性");
        set("age", 65);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 20);
        set("con", 29);
        set("dex", 30);
        set("shen", 0);
        
        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("level", 6);
        set("combat_exp", 300000);
        set("score", 5000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("ding-dodge", 100);
        set_skill("ding-force", 100);
        set_skill("ding-unarmed", 100);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");

        set("chat_chance", 5);

        set("chat_msg", ({
                "桃根仙得意扬扬地说道：咱们桃谷六仙在江湖上来头可大呢！令狐冲对咱们可是不胜佩服的。\n",
                "桃根仙牛逼地说道：当年咱们桃谷六仙攻打少林时说多神气便有多神气。\n",
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
