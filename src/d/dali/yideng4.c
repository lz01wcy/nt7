//Cracked by Kafei
// yideng quest room 4

inherit ROOM;
void create()
{
        set("short", "山腰");
        set("long", @LONG
这里是山的半腰，眼前景色如画，清溪潺潺，水流平稳之极，几
似定住不动。那溪水宽约丈许，两旁垂柳拂水，绿柳之间夹植着无数
桃树，若在春日桃花盛开之时，想见一片锦绣，繁华耀眼。这时虽无
桃花，但水边生满一丛丛白色小花，芳香馥郁，绿柳丛间时有飞鸟鸣
啭。山边一条手臂粗细的长藤，沿峰而上。仰头上望，见山峰的上半
截隐入云雾之中，不知峰顶究有多高。
LONG );

    set("no_sleep_room",1);
    set("objects", ([
                CLASS_D("dali") + "/woodcutter" : 1,
        ]));

        set("exits", ([
                "up"  : __DIR__"yideng5",
                "out" : __DIR__"maze1",
        ]));

        set("invalid_startroom", 1);
        set("coor/x", -38000);
        set("coor/y", -80000);
        set("coor/z", 100);
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "up" && objectp(present("qiao fu", environment(me))))
        return notify_fail("樵夫一眼不发的挡在你身前。\n");
        return ::valid_leave(me, dir);
}
