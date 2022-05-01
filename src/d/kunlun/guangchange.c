// Room: /d/kunlun/guangchange.c
// Last Modified by Lonely on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "广场东");
        set("long",@long
这里是一个平平开阔的大广场，广场上有昆仑派的弟子在习武，西
面是仍然是广场，东面过去就是悬崖了，南面是下山的路。
long);
        set("exits",([
                "southwest" : __DIR__"shanlu04",
                "west"      : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("kunlun")+"/yulingzi" :  1,
                __DIR__"npc/kl-dizi3" :  2,
        ]));
        set("outdoors", "kunlun");
        set("coor/x", -119980);
        set("coor/y", 40040);
        set("coor/z", 90);
        setup();
        replace_program(ROOM);
}