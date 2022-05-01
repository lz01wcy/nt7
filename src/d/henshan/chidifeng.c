inherit ROOM;

void create()
{
        set("short", "赤帝峰");
        set("long", @LONG
相传祝融能以火施化，是黄帝的火正官，并主管南方的事务，死
后葬于此，故名赤帝峰。
LONG );
        set("exits", ([
                "southdown"  : __DIR__"shanlu2",
                "eastdown"   : __DIR__"shanlu11",
                "northdown"  : __DIR__"shanlu3",
        ]));

        set("outdoors", "henshan");

        set("no_clean_up", 0);

	set("coor/x", -6900);
	set("coor/y", -5580);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}