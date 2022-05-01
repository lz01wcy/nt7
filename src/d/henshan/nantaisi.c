inherit ROOM;

void create()
{
        set("short", "南台寺");
        set("long", @LONG
南台寺为禅宗七祖怀让的弟子石头希迁的道场，寺下紫云峰上是
石头和尚墓。寺周林荫夹道，曲径通幽，泉流叮咚，蜂蝶纷飞，山风
吹过时万叶悉索，真好去处。
LONG );
        set("exits", ([
                "northdown"  : __DIR__"shanlu9",
        ]));

        set("objects", ([
                __DIR__"npc/xiangke" : 4,
        ]));                    

        set("outdoors", "henshan");

        set("no_clean_up", 0);

	set("coor/x", -6940);
	set("coor/y", -5590);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}