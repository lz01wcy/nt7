// Code of ShenZhou
// Room: didao_e_2.c 地道东
// Zhangchi 7/00

inherit ROOM;
#include "didao.h"

void create()
{
        set("short", "地道");
        set("long", @LONG
这是一条刚刚挖成的地道，看样子是往东延伸。
LONG );
        set("exits", ([
                "west": "/d/mingjiao/didao/didao_e_1",
]));
        
        set("cost", 1);
        set("valid_dig","east");

        setup();
//        replace_program(ROOM);
}

void init()
{
        int num=get_room("east");
        if (num >= 3)
                set("exits/east","/d/mingjiao/didao/didao_e_3");
        else
                delete("exits/east");

        add_action("do_dig","wa");
        add_action("do_dig","dig");
}