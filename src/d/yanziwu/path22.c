// Room: /d/yanziwu/path22.c
// Date: Jan.28 2000 by Lonely

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "青草路");
        set("long", @LONG
走在青草路上，脚下踩着软软的小草，满目的清亮透绿，鼻子里闻
着青青的春泥香味，你想：哦，这就是江南。
LONG );
        set("outdoors", "mantuo");
        set("no_clean_up", 0);
        set("exits", ([
                "northup"  : __DIR__"path23",
                "west"     : __DIR__"path21",
                "east"     : __DIR__"path25",
        ]));
        set("coor/x", 1210);
        set("coor/y", -1270);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}