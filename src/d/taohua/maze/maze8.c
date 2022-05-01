// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit ROOM;

#include "maze.h"

void create()
{
        set("short", "石阵");
        set("long", @LONG
这是一座由约莫两人多高的大石块构成的乱石阵，规模似乎不大，但
抬眼望去，四周尽是重重叠叠的嶙峋怪石，完全看不出有路通向石阵之外，
加之阵中常年雾气弥漫，更让人摸不清头绪。石块下有一块斜倒的石碑(s
hibei)，半埋在浮土中。
LONG );

        set("exits", ([
                "east"  : __DIR__"maze39",
                "south" : __DIR__"maze23",
                "west"  : __DIR__"maze5",
                "north" : __DIR__"maze20",
        ]));

        set("item_desc", ([
                "shibei" : "
　　比：吉。 原筮元永贞，无咎。 不宁方来，后夫凶。
　　初六：有孚比之，无咎。 有孚盈缶，终来有他，吉。
　　六二：比之自内，贞吉。
　　六三：比之匪人。
　　六四：外比之，贞吉。
　　九五：显比，王用三驱，失前禽。 邑人不诫，吉。
　　上六：比之无首，凶。
\n",
        ]));

        setup();
}

void init()
{
        object me;
        me = this_player();
        
        addn_temp("taohua/count", 8, me);
        check_count(me, 8);
        return;
}