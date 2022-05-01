// Feb. 6, 1999 by Lonely
inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG
你走在一条长长的走廊上，上面雕梁画柱，飞檐琉璃，穿行其
间，心情舒畅。往西是有个厨房，往东是后院。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ 
            "southeast" : __DIR__"houyuan",
            "northeast" : __DIR__"zoulang4",
            "south"     : __DIR__"zoulang2",
            "west"      : __DIR__"chufang",
        ]));
        set("coor/x", 1600);
        set("coor/y", -1920);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}