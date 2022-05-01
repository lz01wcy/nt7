// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这是桃花岛弟子的休息室。几张木床整整齐齐的排列于屋角，茶几花
瓶中插着几枝疏密相间的新开桃花，散发出阵阵花香。地下纤尘不染，看
来是常常打扫。
LONG );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits", ([
                "south" : __DIR__"changlang2",
        ]));
        set("coor/x", 8980);
        set("coor/y", -2940);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}