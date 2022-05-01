//
// zhou.c 周伯通

#include <ansi.h>;

inherit NPC;
void create()
{
        set_name("周伯通", ({ "zhou botong", "zhou", "bo tong" }));
        set("gender", "男性");
        set("nickname", CYN "老顽童" NOR ) ;
        set("title", "全真教第一代弟子") ;
        set("age", 45);
        set("long",
                "他就是人称「老顽童」的周伯通。\n"
                "他一副仙风道骨的样子，看起来好象才四十来岁。很难想象他其实已经年逾古稀了。\n"
        );

        set("combat_exp", 5000000);
        set("shen_type", 1);
        set("max_neili", 10000);
        set("neili", 10000);
//        set("jiali", 0);
        set("per",39);

        set_skill("force", 180);
        set_skill("xiantian-gong", 180);    //先天气功
        set_skill("sword", 180);
        set_skill("quanzhen-jian", 180);  //全真剑
        set_skill("dodge", 180);
        set_skill("jinyan-gong", 180);   //金雁功
        set_skill("strike", 180);
        set_skill("haotian-zhang", 180);    //昊天掌
        set_skill("cuff", 180);
        set_skill("chunyang-quan", 180);    //纯阳拳
        set_skill("unarmed", 200);
        set_skill("kongming-quan", 200);     //空明泉
        set_skill("zuoyou-hubo", 100);
        set_skill("parry", 180);
        set_skill("literate", 80);
        set_skill("taoism", 100);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        map_skill("unarmed","kongming-quan");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        set("inquiry", ([
                "九阴真经" : "你再提这劳什子，我就不跟你玩了。\n",
                "瑛姑"     : "你知道她在哪儿吗？快，快告诉我。",
                "蛇"       : "不要吓我，我最怕蛇了！\n",
                "拜把兄弟" : "提起我的拜把兄弟郭靖，他可是个大英雄。不过比起我来，嘻嘻。",
                "郭靖"     : "提起我的拜把兄弟郭靖，他可是个大英雄。不过比起我来，嘻嘻。",
                "黄蓉"     : "这小丫头鬼机灵，我比不过她。",
        ]) );
        create_family("全真教", 1, "弟子");
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 15);
        setup();

        carry_object("/clone/cloth/cloth")->wear();
}
int accept_object(object who, object ob)
{
        if( query("id", ob) == "du she" )
        {
                message_vision("$N拿出一条毒蛇在老顽童的眼前晃了晃．．．．．．
老顽童吓得跳了起来，冲出洞外！边跑边喊：糟糕透了，老玩童这番死定了！\n\n
声音渐渐远去，终于不复耳闻。\n" ,who);
                destruct(this_object());
                return 0;
        }
        if( query("id", ob) == "mi" )
        {
                if( query_temp("marks/mihave", who) && query("marks/mi_age", who) <= 121 )
                {
                        message_vision("老顽童接过蜂蜜，高兴地说道：好，好，好。\n\n",who);
                        if( query("combat_exp", who)<100000 )
                        {
                                tell_object(who,HIW"你的经验上升了！\n你的潜能上升了！\n" NOR);
                                addn("combat_exp", 100+random(50), who);
                                addn("potential", 20+random(30), who);
                        }
                        set_temp("marks/mihave", 0, who);
                        addn("marks/mi", 1, who);
                        if( query("age", who)>39 )
                        {
                                tell_object(who, HIG "由於勤养玉蜂，你显得更发年轻了！\n" NOR);
                                addn("mud_age", -86400, who);
                                delete("last_slp", who);
                                delete("jingzuo_time", who);
                                addn("marks/mi_age", 1, who);
                                set("marks/mi", 0, who);
                        }
                }

                else
                {
                        message_vision( HIY"老顽童接过蜂蜜，对$N扮了个鬼脸，笑道：反正这蜜也不是你做的，不吃白不吃。\n\n"NOR,who);
                }
                call_out("delmi",2);
                return 1;
        }
        return 0;
}
int delmi()
{
        object obj2;
        obj2=present("mi", this_object());
        destruct(obj2);
        return 1;      
}