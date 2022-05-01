// Code of ShenZhou
// Room: didao_e.c 地道东
// Zhangchi 3/00

inherit ROOM;
#include "didao.h"

void create()
{
        set("short", "地道");
        set("long", @LONG
这是一条刚刚挖成的地道，看样子是往东延伸。
LONG );
        set("exits", ([
                "west": "/d/mingjiao/didao/didao_e",
]));
        
        set("cost", 1);
        set("valid_dig","east");

        setup();
//        replace_program(ROOM);
}

void init()
{
        int num=get_room("east");
        if (num >= 2)
                set("exits/east","/d/mingjiao/didao/didao_e_2");
        else
                delete("exits/east");

        add_action("do_dig","wa");
        add_action("do_dig","dig");
}
