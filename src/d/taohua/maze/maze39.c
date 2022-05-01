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
                "east"  : __DIR__"maze60",
                "south" : __DIR__"maze52",
                "west"  : __DIR__"maze8",
                "north" : __DIR__"maze53",
        ]));

        set("item_desc", ([
                "shibei" : "
　　蹇：利西南，不利东北；利见大人，贞吉。
　　初六：往蹇，来誉。
　　六二：王臣蹇蹇，匪躬之故。
　　九三：往蹇来反。
　　六四：往蹇来连。
　　九五：大蹇朋来。
　　上六：往蹇来硕，吉；利见大人。
\n",
        ]));

        setup();
}

void init()
{
        object me;
        me = this_player();
        
        addn_temp("taohua/count", 39, me);
        check_count(me, 39);
        return;
}