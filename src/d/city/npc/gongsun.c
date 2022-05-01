// gongsun.c

inherit NPC;

string apply_dancer(object me);
string answer_leaving(object me);
int do_yes(string arg);
void do_something();

void create()
{
        set_name("公孙大娘", ({"gongsun daniang", "gongsun", "daniang"}));
        set("age", 32);
        set("gender", "女性");
        set("per", 20);
        set("long","城内不知道公孙大娘的人恐怕没几个。\n特别是那些文人骚客，跟公孙大娘不熟简直就是没面子。\n");
        set("title", "老板娘");
        set("attitude", "friendly");

        set("combat_exp", 40000);
        set("max_force", 400);
        set("force", 400);
        set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 90);
        set_skill("yueying-wubu", 120);
        set_skill("parry", 60);
        set_skill("literate", 90);
        set_skill("sword", 90);
        map_skill("dodge", "yunying-wubu");

        set("inquiry", ([
                "name" : "嘻嘻...连老娘我公孙大娘你都不知道...\n",
                "here" : "嘿嘿...天下美景不胜数，长安此处最繁华。\n",
                "舞妓" : (: apply_dancer :),
                "舞女" : (: apply_dancer :),
                "歌妓" : (: apply_dancer :),
                "歌女" : (: apply_dancer :),
                "leave" : (: answer_leaving :),
                "离开" : (: answer_leaving :),
        ]) );

        setup();
        carry_object(CLOTH_DIR"skirt")->wear();
        carry_object(CLOTH_DIR"shoes")->wear();
        add_money("silver", 200);
}

void do_something()
{
        command(sprintf("bet %d silver", 1+random(5)));
        call_out ("do_something", 120);        
}

string apply_dancer(object me)
{
        me=this_player();
        if( query("gender", me) == "男性" )
        {
                return "这就要看阁下的本事了，我可帮不上多少忙。\n";
        }
        else
        {
                if( query("class", me) == "dancer" )
                        return "好好干吧，以后不愁嫁不上好人家。\n";

                if( query("age", me) >= 30 )
                        return "岁月不饶人，姑娘还是另寻它路吧。\n";

                message_vision("公孙大娘看了$N一眼叹道：这碗饭可不是容易吃的。\n", me);        
                set_temp("dancer_applied", 1, me);
                return "姑娘果真是下了决心？(yes)\n";
        }
}

string answer_leaving(object me)
{
        me=this_player();
        if( query("gender", me) == "男性" )
        {
                return "快滚，滚得远远的！老娘这地方还怕没人来吗？\n";
        }
        else
        {
                if( query("class", me) == "dancer" )
                        return "既入此门，大家都知道了，离不离开又有什么分别呢？\n";
                else return "快走吧，这里本来就不是女人玩的地方。\n";
        }
}

void init()
{
        ::init();

        remove_call_out("do_something");
        call_out ("do_something", 120);                

        add_action("do_yes", "yes");
}

int do_yes(string arg)
{
        object me;

        me=this_player();
        
        if( query_temp("dancer_applied", me) )
        {
                message_vision("$N答道：我都想清楚了！\n\n", me);
                message_vision("公孙大娘拍了拍$N的头道：好好干！只要能碰上好运气，荣华富贵垂手可得！\n", me);
                delete_temp("dancer_applied", me);
                set("class", "dancer", me);
                return 1;
        }

        return 0;
}
