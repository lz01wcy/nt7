// Room: /d/changcheng/changcheng7.c
// Last Modified by Lonely on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长城");
        set("long", WHT @LONG
这里就是举世闻名的----长城。站在长城上，你可以看到四周群山
环绕，山上可以看见不少矮矮的灌木丛，但不少的树也被砍光了，很多
地方已经露出了一片片的黄土，举目望去，你脚下的长城顺着山脊象一
条巨龙般蜿蜒的向北，向东南延伸出去。北面山顶处是一个烽火台。
LONG
NOR );
        set("outdoors", "changcheng");
        set("exits", ([
                "northup"   :__DIR__"fenghuotai1-1",
                "southeast" :__DIR__"changcheng6",
        ]));
        set("no_clean_up", 0);
        set("coor/x", -6000);
        set("coor/y", 6000);
        set("coor/z", 80);
        setup();
        replace_program(ROOM);
}
