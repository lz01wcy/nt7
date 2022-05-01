// Room: /d/kunlun/shanlin6.c
// Last Modified by Lonely on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "云杉林");
        set("long",@long
这是一片蜿蜒无尽的翠绿的树林，密密的云杉像撑天的巨伞，重重
叠叠的枝丫，只漏下斑斑点点细碎的日影。林子十分幽静，连鸟雀也少
飞来，只偶尔能听到远处的几声鸟鸣。
long);
        set("exits",([
                "west"  : __DIR__"shanlin"+(random(5)+1),
                "east"  : __DIR__"kuhanlou",
                "north" : __DIR__"shanlin"+(random(5)+1),
                "south" : __DIR__"shanlin"+ (random(5)+1),
        ]));
        set("no_clean_up", 0);
        set("outdoors", "kunlun");
        set("coor/x", -119990);
        set("coor/y", 40140);
        set("coor/z", 90);
        setup();
        replace_program(ROOM);
}