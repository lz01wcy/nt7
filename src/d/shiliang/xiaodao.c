// Feb. 6, 1999 by Lonely
inherit ROOM;
void create()
{
        set("short", "湖心小岛");
        set("long", @LONG
你来到湖心的小岛上。这里鸟语花香，彩蝶纷飞，景色宜人，空
气中仿佛有种玉兰香的味道。
LONG
        );
        set("outdoors","shiliang");
        set("no_clean_up", 0);
        set("exits", ([ 
            "north" : __DIR__"xiaodao1",
        ]));
        set("coor/x", 1610);
        set("coor/y", -1800);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}