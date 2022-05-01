//Room: /d/dali/shanlu4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","山路");
        set("long", @LONG
一条山路，两边是茂密的树林，西面是延绵不绝的大山，道路两
旁间或可见一些夷族的村镇。山路向南蜿蜒着。
LONG );
        set("objects", ([
           "/d/dali/npc/shennongdizi": 1,
        ]));
        set("outdoors", "dalis");
        set("exits",([ /* sizeof() == 1 */
            "north"      : "/d/dali/shanlu2",
            "southwest"  : "/d/dali/shanlu5",
            "westup"     : "/d/wuliang/shanlu1",
        ]));
	set("coor/x", -19160);
	set("coor/y", -6900);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}