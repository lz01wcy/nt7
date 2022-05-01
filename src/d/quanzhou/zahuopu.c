// Room: /d/quanzhou/zahuopu.c
// Last Modified by Lonely on May. 29 2001

inherit ROOM;

void create()
{
        set("short", "杂货铺");
        set("long", @LONG
这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。
杨掌柜懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖
一些贵重的东西。摊上立着一块招牌(zhaopai)。
LONG );
        set("item_desc", ([
                "zhaopai" : "请用 list 列出货物表，buy 向老板购物。\n",
        ]));
        set("exits", ([
                "south" : __DIR__"westroad1",
        ]));
        set("objects", ([
                __DIR__"npc/chen" : 1,
        ]));
	set("coor/x", -910);
	set("coor/y", -7660);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}