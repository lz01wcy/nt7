// /d/quanzhen/shulin6.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这位于终南山间的一大片树林，生的颇为茂密。走在其间，只听
得脚下沙沙的落叶声，四周昏昏暗暗的，不时几道日光穿过浓密的枝
头，投射而下。偶尔远处几声兽吼声，更添了一份神秘感。往北、南
各有一条小径。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southup"   : __DIR__"shulin5",
                "northdown" : __DIR__"shandao3",
                "south" : __DIR__"milin",
        ]));
        set("objects", ([
                "/d/wudang/npc/monkey" : 1,
        ]));
        set("coor/x", -3190);
        set("coor/y", 160);
        set("coor/z", 100);
        setup();
        //replace_program(ROOM);
}

#include "caiyao.h"
