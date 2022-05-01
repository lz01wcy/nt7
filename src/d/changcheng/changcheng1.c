// Room: /d/changcheng/changcheng1.c
// Last Modified by Lonely on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长城");
        set("long", WHT@LONG
这里就是举世闻名的----长城。站在长城上，你可以看到四周群山
环绕，山上到处都是矮矮的灌木丛，举目望去，你脚下的长城顺着山脊
象一条巨龙般蜿蜒的向东、西延伸出去。
LONG
NOR );
        set("outdoors", "changcheng");
        set("exits", ([
                "west" :__DIR__"changcheng2",
                "east" :__DIR__"juyongguan",
        ]));
        set("no_clean_up", 0);
        set("coor/x", -500);
        set("coor/y", 5000);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}
