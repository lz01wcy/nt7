inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",RED"西厂"NOR);
        set("long", @LONG
这里就是京城的特务机构——西厂。大厅内很是宽阔，这里警备
深严，穿着制服的西厂官兵和太监在这里来回走动。看来这里不宜久
留，赶快离开为妙。[2；37；0m
LONG );
        set("exits", ([
                "north" : "/d/beijing/xichang_men",
        ]));
        set("objects", ([
                "/d/beijing/npc/bing3" : 4,
                "/d/beijing/npc/taijian" : 1,
        ]));
        set("no_fight", 0);
	set("coor/x", -2810);
	set("coor/y", 7690);
	set("coor/z", 0);
	setup();
}