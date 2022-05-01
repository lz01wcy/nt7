// Room: /d/xiangyang/jiangjunyuan.c
// Date: Jan. 8 1999 by Lonely

inherit ROOM;

void create()
{
        set("short", "将军府大院");
        set("long", @LONG
这里是将军府的大院，只见大理石铺就的地面一尘不染，两个衣
着光鲜的小丫鬟认真的在擦洗两边的栏杆和柱子，不时有值班的卫士
走过来。向里望去，可以看到将军府的大堂。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"jiangjungate",
                "north" : __DIR__"jiangjuntang",
        ]));
        set("coor/x", -7810);
	set("coor/y", -750);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}