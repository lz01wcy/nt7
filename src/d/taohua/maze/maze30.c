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
                "south" : __DIR__"maze55",
                "west"  : __DIR__"maze64",
                "north" : __DIR__"maze49",
        ]));

        set("item_desc", ([
                "shibei" : "
　　离：利贞，亨。 畜牝牛，吉。
　　初九：履错然，敬之无咎。
　　六二：黄离，元吉。
　　九三：日昃之离，不鼓缶而歌，则大耋之嗟，凶。
　　九四：突如其来如，焚如，死如，弃如。
　　六五：出涕沱若，戚嗟若，吉。
　　上九：王用出征，有嘉折首，获其匪丑，无咎。
\n",
        ]));

        setup();
}

void init()
{
        object me;
        me = this_player();
        
        addn_temp("taohua/count", 30, me);
        check_count(me, 30);
        return;
}