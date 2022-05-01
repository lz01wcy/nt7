// Room: /d/gaibang/undergb.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
        set("short","破庙密室");
        set("long", @LONG
这是丐帮重要密道之一。由此上往，可直达破庙。四周光线昏暗，
似乎有几个黑暗的洞口在你身边。脚下地上扔满了垃圾，踩上去悉悉
索索地响。
LONG );
        set("exits", ([
                "up" : __DIR__"pomiao",
                "southwest":__DIR__"zlandao2",
        ]));
        set("objects",([
                CLASS_D("gaibang") + "/xi" : 1,
                "/d/gaibang/npc/6dai" : 1 + random(2),
                "/d/gaibang/npc/7dai" : 1 + random(2),
        ]));
        set("no_clean_up", 0);
        set("coor/x", 70);
        set("coor/y", 60);
        set("coor/z", -20);
        setup();
        replace_program(ROOM);
}
