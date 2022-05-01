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
                "east"  : __DIR__"maze28",
                "south" : __DIR__"maze21",
                "west"  : __DIR__"maze58",
                "north" : __DIR__"maze25",
        ]));

        set("item_desc", ([
                "shibei" : "
　　随：元亨利贞，无咎。
　　初九：官有渝，贞吉。 出门交有功。
　　六二：系小子，失丈夫。
　　六三：系丈夫，失小子。 随有求得，利居贞。
　　九四：随有获，贞凶。有孚在道，以明，何咎。 
　　九五：孚于嘉，吉。
　　上六：拘系之，乃从维之。 王用亨于西山。
\n",
        ]));

        setup();
}

void init()
{
        object me;
        me = this_player();
        
        addn_temp("taohua/count", 17, me);
        check_count(me, 17);
        return;
}