// Code of ShenZhou
// Room: didao_s_3.c 地道南
// Zhangchi 7/00

inherit ROOM;
#include "didao.h"

void create()
{
        set("short", "地道");
        set("long", @LONG
这是一条刚刚挖成的地道，看样子是往南延伸。
LONG );
        set("exits", ([
                "north": "/d/mingjiao/didao/didao_s_2",
]));
        
        set("cost", 1);
        set("valid_dig","south");

        setup();
//        replace_program(ROOM);
}

void init()
{
        int num=get_room("south");
        if (num >= 4)
                set("exits/south","/d/mingjiao/didao/didao_s_4");
        else
                delete("exits/south");

        add_action("do_dig","wa");
        add_action("do_dig","dig");
}
