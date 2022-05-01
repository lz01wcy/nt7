// Room: /d/xiangyang/jiedao.c
// Date: Jan. 8 1999 by Lonely

inherit ROOM;

void create()
{
        set("short", "街道");
        set("long", @LONG
这里是襄阳城内有钱人的居住区。街道两旁是一些豪华的住宅，
虽然襄阳历经战乱，但还有许多有钱人没搬走，为坚守襄阳城出钱出
力。
LONG );
        set("outdoors", "xiangyang");

        set("exits", ([
                "east"  : __DIR__"minju1",
                "west"  : __DIR__"minju2",
                "north" : __DIR__"eastjie2",
        ]));
        set("objects", ([
                __DIR__"npc/poorman" : 2,
        ]));
        set("coor/x", -7800);
	set("coor/y", -780);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}