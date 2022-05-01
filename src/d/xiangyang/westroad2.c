// Room: /d/xiangyang/westroad2.c
// Date: Jan. 8 1999 by Lonely

inherit ROOM;

void create()
{
        set("short", "西内大街");
        set("long", @LONG
这是一条青石铺就的大街。北面是十字街口。隐隐地能望见南面
是一座很高的彩楼，东面是一堵盖着红色琉璃瓦的高墙，里面是郭府
大院。西面是襄阳城内新开的一家书店，听说里面能买到很好的书。
LONG );
        set("outdoors", "xiangyang");

        set("no_clean_up", 0);
        set("exits", ([
                "west"  : __DIR__"shudian",
                "south" : __DIR__"westroad1",
                "north" : __DIR__"jiekou1",
        ]));
        set("coor/x", -7830);
	set("coor/y", -750);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}