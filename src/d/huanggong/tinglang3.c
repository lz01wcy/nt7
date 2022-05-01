// Room: /d/huanggong/tinglang3.c

inherit ROOM;

void create()
{
        set("short", "厅廊");
        set("long", @LONG
飞檐雕栏的厅廊. 两边是喜人的花草, 站在这儿, 隐约听得到后宫
里嫔妃宫女们嬉笑的声音, 宫里的人来来往往的, 显得井井有条, 看来
宫里的规矩挺严的.
LONG
        );
        set("outdoors", "huanggong");
        set("exits", ([ /* sizeof() == 4 */
                "west"  : __DIR__"gong5",
                "east"  : __DIR__"gong6",
                "north" : __DIR__"tinglang2",
        ]));
        set("objects", ([ /* sizeof() == 3 */
                __DIR__"npc/pingwei" :1,
        ]));

	set("coor/x", -2830);
	set("coor/y", 7761);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}