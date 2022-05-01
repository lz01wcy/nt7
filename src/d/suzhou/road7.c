// Room: /d/suzhou/road7.c
// Last Modified by Lonely on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "湖畔大道");
        set("long",@long
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。大道两旁有一些小货摊，似乎是一处集市。北边通向灵岩山。
南边的青石大道通向湖边。
long);
        set("outdoors", "suzhou");
        set("exits",([
                "north" : __DIR__"lingyanshan",
                "south" : __DIR__"road6",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 1110);
	set("coor/y", -1150);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}