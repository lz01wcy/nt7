// /kaifeng/tonanyang.c
// Last modified by Lonely 2003.10.20

inherit ROOM;

void create()
{
        set("short", "官道");
        set("long", @LONG
这是条连接开封府与南阳府的官道，由于这条路治安较好
行人也不少。西面通向开封，东面通向南阳。
LONG
        );
        set("exits", ([
                "west" : __DIR__"tokaifeng",
                "east" : "/d/nanyang/yidao3",
        ]));
        set("outdoors", "kaifeng");
        set("no_clean_up", 0);

	set("coor/x", -4990);
	set("coor/y", 2220);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}