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
                "east"  : __DIR__"maze41",
                "south" : __DIR__"maze15",
                "west"  : __DIR__"maze23",
                "north" : __DIR__"maze39",
        ]));

        set("item_desc", ([
                "shibei" : "
　　艮：艮其背，不获其身，行其庭，不见其人，无咎。
　　初六：艮其趾，无咎，利永贞。
　　六二：艮其腓，不拯其随，其心不快。
　　九三：艮其限，列其夤，厉薰心。
　　六四：艮其身，无咎。
　　六五：艮其辅，言有序，悔亡。
　　上九：敦艮，吉。
\n",
        ]));

        setup();
}

void init()
{
        object me;
        me = this_player();
        
        addn_temp("taohua/count", 52, me);
        check_count(me, 52);
        return;
}