// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "蛇谷山道");
        set("long", @LONG
这是白驼山蛇谷中的山路，是一条人马踩出来的小道，随着地势
曲折起伏，蜿蜒难行。山路两旁林木葱郁，草丛中不时响起沙沙之声，
似乎有什麽在草里来回窜动。
LONG );

        set("exits", ([
                "southwest" : __DIR__"shegu3",
                "northwest" : __DIR__"shegu5",
        ]));

        set("objects", ([
                __DIR__"obj/branch"+(1+random(2)) : 1,
                __DIR__"obj/branch"+(3+random(2)) : 1,
                __DIR__"npc/yetu" : 1,
        ]));

        set("hide_snake", random(3));
        set("grass", 1);

        set("outdoors","baituo");
        set("shegu", 1);
        set("coor/x", -49970);
        set("coor/y", 20140);
        set("coor/z", 20);
        setup();
}

#include "snake_room.h"