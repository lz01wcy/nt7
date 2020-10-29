//Room: dgtsheshenya.c 睹光台舍身崖
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
        set("short", "睹光台舍身崖");
        set("long", @LONG
从卧云庵出来，这里是看日出、云海、佛光、神灯之地。台下深
崖万丈，陡彻无底，云遮雾掩。极目四望，数百里外的大小雪山皆历
历在目。因为这里至高至洁，至险至奇，又至美至幻，常有人在这里
投身云海，舍此肉身尘世。　　金顶云海，迷迷茫茫，笼罩四野，远
接天际。云海轻荡时，你在金顶，脚踏白云，大有飘飘欲仙之感；当
云涛迅猛涌来时，整个金顶都似在向前浮动，令人有乘舟欲风之意。
LONG );
        set("outdoors", "emei");
        set("exits",([ /* sizeof() == 1 */
                "north"     : __DIR__"duguangtai", 
/*
                "enter"    : __DIR__"woyunan",
                "east"     : __DIR__"duguangtai", 
*/
        ]));
        
        set("coor/x", -570);
        set("coor/y", -340);
        set("coor/z", 220);
        
        setup();
}

void init()
{
        object me;

        if (interactive(me = this_player()))
        {
                remove_call_out("clone_ji");
                call_out("clone_ji", 2,me);
        }
        add_action("do_sheshen","sheshen");
}

void clone_ji(object me)
{
        object *ob, obj;
        int i;

        if (! objectp(me) || environment(me) != this_object())
                return;

        ob = all_inventory(environment(me));
        for (i = 0; i < sizeof(ob); i++)
        {
                if( query("id", ob[i]) == "jixiaofu" )
                return;
        }

        if( query("marks/ji", me) )
        {
                obj = new("/kungfu/class/emei/ji.c");
                obj->move(environment(me));
        }
}

int do_sheshen(object me)
{
        me = this_player();
        message_vision("$N觉得活着太没意思了，决定舍身成仁。\n", me);
        message_vision("$N毅然跳出舍身崖，长声尖叫，凄厉的声音响彻山谷，随着$N的的下落也急剧向下拉长。\n", me);
        if (me->query_skill("dodge", 1) >= 220)
        {
                me->move(__DIR__"st0");
                me->unconcious();
        } else
        {
                command("chat 有人跳下舍身崖自杀了。\n\n");
                me->move(__DIR__"st0");
                me->die();
        }
        return 1;
}