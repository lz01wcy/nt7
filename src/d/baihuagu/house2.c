// Room: /d/baihuagu/house2.c
// Last Modified by Lonely on Mar. 5 2001

inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", HIY"周伯通居"NOR);
        set("long", 
"这是间很简陋的屋子，陈设简单，由此可见老顽童极于玩而不
极于物。\n");
        set("exits", ([
                "west"  : __DIR__"house1",
                "north" : __DIR__"shanpo1",
        ]));
        set("objects", ([           
        ]));
        set("no_clean_up", 0);
        set("coor/x", -410);
        set("coor/y", -370);
        set("coor/z", 10);
        setup();
        replace_program(ROOM);
}