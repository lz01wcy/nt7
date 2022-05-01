// Room: /d/xiangyang/dingzi.c
// Date: Jan. 8 1999 by Lonely

inherit ROOM;

void create()
{
        set("short", "丁字街口");
        set("long", @LONG
这里是襄阳城北部的丁字街口。向北一直通向玄武门，东面和西
面是一条笔直的青石大街，通向城内。南面是一堵上盖红色琉璃瓦的
高墙，里面是襄阳安抚使吕文德的府邸。
LONG );
        set("outdoors", "xiangyang");
        set("no_clean_up", 0);

        set("exits", ([
                "east"  : __DIR__"northroad2",
                "west"  : __DIR__"northroad1",
                "north" : __DIR__"northjie",
        ]));
        set("objects", ([
                "/clone/npc/walker"  : 1,
        ]));
        set("coor/x", -7810);
	set("coor/y", -740);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}