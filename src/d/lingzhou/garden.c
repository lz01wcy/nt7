// Room: /d/lingzhou/garden.c

inherit ROOM;

void create()
{
        set("short", "御花园");
        set("long", @LONG
这是皇宫里的御花园，花团锦簇，百草飘香，虽不比江南水乡般艳
丽，却也别有一般风味。北面是占园中一半面积的翠心湖，西面有条小
路通向一片紫竹林。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "south" : __DIR__"huilang2",
                "west" : __DIR__"zhulin",
                "east" : __DIR__"piandian",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xixiagong");

        set("coor/x", -6275);
        set("coor/y", 2995);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}