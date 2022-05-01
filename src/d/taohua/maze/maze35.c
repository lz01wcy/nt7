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
                "east"  : __DIR__"maze56",
                "south" : __DIR__"maze16",
                "west"  : __DIR__"maze14",
                "north" : __DIR__"maze45",
        ]));

        set("item_desc", ([
                "shibei" : "
　　晋：康侯用锡马蕃庶，昼日三接。
　　初六：晋如，摧如，贞吉。 罔孚，裕无咎。
　　六二：晋如，愁如，贞吉。 受兹介福，于其王母。
　　六三：众允，悔亡。
　　九四：晋如硕鼠，贞厉。
　　六五：悔亡，失得勿恤，往吉无不利。
　　上九：晋其角，维用伐邑，厉吉无咎，贞吝。
\n",
        ]));
        
        setup();
}

void init()
{
        object me;
        me = this_player();
        
        addn_temp("taohua/count", 35, me);
        check_count(me, 35);
        return;
}