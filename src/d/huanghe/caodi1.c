// Room: /huanghe/caodi1.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "草地");
        set("long", @LONG
这里是一片绿茵茵的草地，像是一方绿色的毯子铺在地上。草丛中
开着一些不知名的小花，有红的、黄的，还有紫的。花瓣上、草叶上的
露珠闪着晶莹的光。
LONG );
        set("exits", ([
                "east" : "/d/city/beimen",
                "west" : __DIR__"caodi2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huanghe");
        set("coor/x", -100);
        set("coor/y", 100);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}
