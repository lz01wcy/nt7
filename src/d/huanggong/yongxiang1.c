// Room: /d/huanggong/yongxiang1.c

inherit ROOM;

void create()
{
        set("short", "永巷");
        set("long", @LONG
这里是三大殿周围的通道。宫禁森严，天威莫测，来来往往的宫女
太监虽然很多，可是谁也不敢带出一点声来。
LONG
        );
        set("outdoors", "huanggong");
        set("exits", ([ /* sizeof() == 3 */
                "south" : __DIR__"yongxiang2",
                "north" : __DIR__"longzongmen",
                "east"  : __DIR__"baohedian",
        ]));
        set("no_clean_up", 0);

	set("coor/x", -2820);
	set("coor/y", 7721);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}