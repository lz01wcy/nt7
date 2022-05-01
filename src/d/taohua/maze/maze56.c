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
                "east"  : __DIR__"maze38",
                "south" : __DIR__"maze62",
                "west"  : __DIR__"maze35",
                "north" : __DIR__"maze31",
        ]));

        set("item_desc", ([
                "shibei" : "
　　旅：小亨，旅贞吉。
　　初六：旅琐琐，斯其所取灾。
　　六二：旅即次，怀其资，得童仆贞。
　　九三：旅焚其次，丧其童仆，贞厉。
　　九四：旅于处，得其资斧，我心不快。
　　六五：射雉一矢亡，终以誉命。
　　上九：鸟焚其巢，旅人先笑后号啕。 丧牛于易，凶。
\n",
        ]));

        setup();
}

void init()
{
        object me;
        me = this_player();
        
        addn_temp("taohua/count", 56, me);
        check_count(me, 56);
        return;
}