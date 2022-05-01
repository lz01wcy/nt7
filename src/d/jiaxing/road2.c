// Room: /d/jiaxing/road2.c
// Last Modified by Lonely on Nov. 17 2000

inherit ROOM;

void create()
{
        set("short", "土路");
        set("long", @LONG
这是一条郊外的土路，两边生长着蓬乱的茅草。路边是江南水乡到
处都可以见到的小河。远处似乎有座村落。
LONG
        );
        set("no_clean_up", 0);
        set("outdoors","jiaxing");

        set("exits", ([
                "north"    : __DIR__"road1",
                "southeast": __DIR__"njwest",
        ]) );

	set("coor/x", 1230);
	set("coor/y", -1810);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}