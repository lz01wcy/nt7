inherit ROOM;

void create()
{
        set("short", "小土屋");
        set("long", @LONG
这是一间小土屋，看样子是一户农家的房子。屋里简单地摆着些
家具，墙角里堆着些农具。炕上坐着一个老婆婆和一个小孩，见有人
冲进来，都神色紧张地望着你。
LONG );
        set("exits", ([
                "north" : __DIR__"wdroad6",
        ]));
        set("objects", ([
                "/d/village/npc/oldwoman" : 1,
                "/d/village/npc/kid" : 1,
        ]));
        set("coor/x", -300);
        set("coor/y", -160);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}

