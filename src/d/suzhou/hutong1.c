// Room: /d/suzhou/hutong1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
        set("short", "胡同");
        set("long", @LONG
这是一条黑暗、肮脏的小巷，空气中仿佛飘扬着一股罪恶的气息，
东北边通向小巷深处，正人君子当然是不会往那边走去的。往南走就会
回到城中大路了。
LONG );
        set("outdoors", "suzhou");
        set("no_clean_up", 0);
        set("exits", ([
                "south"     : __DIR__"dongdajie1",
                "northeast" : __DIR__"hutong2",
        ]));
        set("objects", ([
                "/d/city/npc/liumang" : 2,
        ]));
	set("coor/x", 1120);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}