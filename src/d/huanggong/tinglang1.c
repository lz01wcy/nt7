// Room: /d/huanggong/tinglang1.c

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
        set("exits", ([ /* sizeof() == 3 */
                "west"  : __DIR__"gong1",
                "east"  : __DIR__"gong2",
                "south" : __DIR__"tinglang2",
        ]));
        set("no_clean_up", 0);

	set("coor/x", -2830);
	set("coor/y", 7781);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}