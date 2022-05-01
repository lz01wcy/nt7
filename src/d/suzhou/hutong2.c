// Room: /d/suzhou/hutong2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
        set("short", "胡同");
        set("long", @LONG
这是一条黑暗、肮脏的小巷，空气中仿佛飘扬着一股罪恶的气息，
几个贼眉鼠眼地盯着你的腰包，看来会马上扑上来。北面是一条小巷，
名为“生死巷”。
LONG );
        set("outdoors", "suzhou");
        set("no_clean_up", 0);
        set("exits", ([
                "north"     : __DIR__"leitai",
                "east"      : __DIR__"hutong3",
                "southwest" : __DIR__"hutong1",
        ]));
        set("objects", ([
                "/d/city/npc/liumangtou" : 1,
                "/d/city/npc/liumang" : 2,
        ]));
	set("coor/x", 1130);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}