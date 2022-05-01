// Room: /d/baihuagu/baihuagu.c
// Last Modified by Lonely on Mar. 5 2001

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"百花谷内"NOR);
        set("long", 
HIG"只见姹紫嫣红，满山锦绣，彩蝶纷飞，群蜂轻舞。纵是宇外琼地，
世外桃源，也不过如此。\n"NOR);
        set("outdoors", "baihuagu");
        set("exits", ([
                "out"   : __DIR__"huagu7",
                "south" : __DIR__"baihuagu1",
                "north" : __FILE__,
                "west"  : __FILE__,
                "east"  : __FILE__,
        ]));
        set("objects", ([
        ]));
        set("no_clean_up", 0);
        set("coor/x", -430);
        set("coor/y", -360);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}