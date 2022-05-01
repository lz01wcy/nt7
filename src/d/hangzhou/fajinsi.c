// fajinsi.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "法净寺");
        set("long", @LONG
法净寺依山而立，寺前小溪流水。进香的游客不时的进进出出。
南上往上天竺。朝北是下山的路。
LONG);
        set("exits", ([
                "southup"   : __DIR__"shanlu3",
                "northdown" : __DIR__"shanlu2",
        ]));
        set("objects", ([
           __DIR__"npc/shami" : 1,
           __DIR__"npc/guest" : 1,
        ]));
        set("outdoors", "hangzhou");
	set("coor/x", 750);
	set("coor/y", -2090);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}