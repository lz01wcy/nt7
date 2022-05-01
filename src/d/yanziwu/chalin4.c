// Room: /d/yanziwu/chalin4.c
// Date: Jan.28 2000 by Lonely

inherit ROOM;

void create()
{
        set("short", "茶花林");
        set("long", @LONG
你在花林中跌跌撞撞地蹒跚而行，不知道那里是出口，来时所留神
的只是茶花，忘了记忆路径，眼见小路东一条、西一条，也不知那一条
才是来路，要回到小船停泊处却有点儿难了，于是你心想：“先走到水
边再说。”
LONG );
        set("outdoors", "mantuo");
        set("no_clean_up", 0);
        set("exits", ([
                "west"  : __DIR__"chalin1",
                "east"  : __DIR__"chalin3",
                "south" : __DIR__"chalin5",
                "north" : __DIR__"chalin2",
        ]));
        set("coor/x", 1200);
        set("coor/y", -1290);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}