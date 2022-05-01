// Room: /d/huanggong/dao7.c

inherit ROOM;

void create()
{
        set("short", "宫道");
        set("long", @LONG
这是紫禁内外城间的宫道. 平日里一些人物出入内宫, 就是走这路
的. 这宫道上每日都有大内侍卫来回巡逻, 出入可要小心. 宫道两边高
高的红墙, 正是为了拦阻入侵高手的.
LONG
        );
        set("outdoors", "huanggong");
        set("exits", ([ /* sizeof() == 2 */
                "north" : __DIR__"jiao3",
                "south" : __DIR__"dao8",
        ]));
        set("no_clean_up", 0);

	set("coor/x", -2840);
	set("coor/y", 7741);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}