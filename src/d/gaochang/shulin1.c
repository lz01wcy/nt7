// Room: /d/gaochang/shulin1.c
// Last Modified by Lonely on Jul. 15 2000

inherit ROOM;

void create()
{
        set("short", "高昌迷宫");
        set("long", @LONG
这是条黑沈沈的长甬道，甬道前出现了三条岔道。迷宫之内并无足
迹指引，你不知道要往哪条路走。俯身细看，见左首，右首和前方三条
路上都有淡淡的足迹。
LONG
        );

        set("outdoors", "gaochang");
        set("no_drop",1);
        set("exits", ([
                "west" : __DIR__"shulin"+(random(10)+2),
                "east" : __DIR__"shulin2",
                "south" :__DIR__ "road",
                "north" : __DIR__"shulin"+(random(10)+2),
        ]));
        set("objects",([
                __DIR__"obj/fake_map" : 1,
                __DIR__"npc/ghost" : 3,
        ]));
        set("coor/x", -38000);
        set("coor/y", 11000);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}