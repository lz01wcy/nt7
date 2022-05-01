// Room: /xiakedao/lin1.c

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这是一片茂密的树林，好象被人设计了一种阵，一走进来，你仿佛迷失了方向。
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "east" : __FILE__,
                "west" : __FILE__,
                "south" : __DIR__"lin2",
                "north" : __DIR__"haitan",
        ]));
        set("objects", ([
                "/d/motianya/npc/qiaofu" : 1,
        ]));
        set("no_clean_up", 0);
        set("coor/x", -3000);
        set("coor/y", -21000);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}
