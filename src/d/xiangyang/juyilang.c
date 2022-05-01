// Room: /d/xiangyang/juyilang.c
// Date: Jan. 8 1999 by Lonely

inherit ROOM;

void create()
{
        set("short", "水上走廊");
        set("long", @LONG
这时一条笔直的走廊，廊下是一湖池水。湖水映着长长垂柳，碧
绿清澈，你能看见一些鱼在游来游去。南面就是一个大花园，圆内东
西两侧各有一排厢房。
LONG );
        set("outdoors", "xiangyang");
        set("no_clean_up", 0);

        set("exits", ([
                "south" : __DIR__"juyihuayuan",
                "north" : __DIR__"juyiyuan",
        ]));
        set("coor/x", -7840);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}