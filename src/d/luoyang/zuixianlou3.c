inherit ROOM;

void create()
{
        set("short", "望星楼三层");
        set("long", @LONG
这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里边吃
喝边作交易。这里也是城里举办喜宴的最佳场所。你站在楼上眺望，只觉
得心旷神怡。东面是一池湖水，碧波荡漾，北面则是崇山峻岭，气势雄浑，
巍峨壮观。
LONG);

        set("no_clean_up", 0);
        set("exits", ([
                  "up" : __DIR__"zuixianlou4",
                  "down" : __DIR__"zuixianlou2",
        ]));
        set("objects", ([
                "/d/zhongzhou/npc/fushang" : 2,
        ]));
	set("coor/x", -6980);
	set("coor/y", 2190);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}