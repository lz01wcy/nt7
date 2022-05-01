// shanlu5.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit BUILD_ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
走在小路上，只见漫山遍野都是绿油油的茶蓬。农家少女们在欢
笑声中采茶。山路延伸向东西两边，北边就是龙井，东北边有一条土
路。
LONG);
        set("exits", ([
                "westup"   : __DIR__"shanlu4",
                "northeast": __DIR__"tulu1",
                "north"    : __DIR__"longjing",
                "east"     : __DIR__"yanxiadong",
        ]));
        set("objects", ([
                __DIR__"npc/caichanu" :2,
        ]));
        set("outdoors", "hangzhou");
	set("coor/x", 770);
	set("coor/y", -2110);
	set("coor/z", 40);
	setup();
}
