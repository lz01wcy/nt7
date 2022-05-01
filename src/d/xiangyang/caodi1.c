// Room: /d/xiangyang/caodi1.c
// Date: Jan. 8 1999 by Lonely

inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "草地");
        set("long", @LONG
这是襄阳城外的草地。蒙古兵进犯以来，这里的百姓全进城了，
蒙古兵驰骋来去，以为牧场，尘土飞扬，甚是嚣张。
LONG );
        set("outdoors", "xiangyang");

        set("exits", ([
                "west"  : __DIR__"northgate2",
                "northup"  : "/d/jueqing/shanjiao",
        ]));
        set("objects", ([
                __DIR__"npc/tuolei"   : 1,
                __DIR__"npc/menggubing" : 2,
        ]));
        set("coor/x", -7800);
	set("coor/y", -710);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}