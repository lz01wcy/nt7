// Room: /d/kunlun/xsxiepo2.c
// Last Modified by Lonely on Jun. 29 2001

inherit ROOM;

void create()
{
        set("short", "雪山斜坡");
        set("long", @LONG
你手脚着地，沿着雪山斜坡，一步一步向着有阳沅之处爬去，但此
峭壁本就极陡，加上冻结冰雪，更是滑溜无比，一不小心则会滑跌。
LONG);
        set("exits",([
                "east" : __DIR__"pingtai",
        ]));
        set("outdoors", "hongmei");
        set("no_clean_up", 0);
        set("coor/x", -100010);
        set("coor/y", 20010);
        set("coor/z", 40);
        setup();
}
void init()
{
        add_action("do_pa","pa");
}
int do_pa(string arg)
{
        object me;
        me=this_player();
        if (!(arg||arg=="east"||arg=="west")) return 0;
        if (arg=="west")
        {
                message("vision",me->name()+"向西边爬去。\n",environment(me),me);
                write("你向西面爬去。\n");
                me->move(__DIR__"xsxiepo1");
                message("vision",me->name()+"爬了过来。\n",environment(me),me);
                return 1;
        }
        return 1;
}
