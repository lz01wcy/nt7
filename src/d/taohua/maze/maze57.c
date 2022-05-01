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
                "east"  : __DIR__"maze59",
                "south" : __DIR__"maze48",
                "west"  : __DIR__"maze42",
                "north" : __DIR__"maze32",
        ]));

        set("item_desc", ([
                "shibei" : "
　　巽：小亨，利攸往，利见大人。
　　初六：进退，利武人之贞。
　　九二：巽在□下，用史巫纷若，吉无咎。
　　九三：频巽，吝。
　　六四：悔亡，田获三品。
　　九五：贞吉悔亡，无不利。 无初有终，先庚三日，后庚三日，吉。
　　上九：巽在□下，丧其资斧，贞凶。
□  ＝ 爿 ＋ 木
\n",
        ]));
        
        setup();
}

void init()
{
        object me;
        me = this_player();
        
        addn_temp("taohua/count", 57, me);
        check_count(me, 57);
        return;
}