//Room: /d/dali/longkou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","龙口城");
        set("long",@LONG
这里已到大理南疆了，龙口城南临元江，属临江路。大理国南部
虽广有千多里，但大城镇较稀少，此地虽离大理中心不远，却也算南
部的重要关口之一了，是和南方临国通商的口岸。由此北去二十五里
即是喜州城，南边沿元江有不少台夷村庄。大理官府在此有些驻军。
LONG);
        set("objects", ([
           __DIR__"npc/bing": 2,
        ]));
        set("outdoors", "dalis");
        set("exits",([ /* sizeof() == 1 */
            "north"      : __DIR__"feilihueast",
        ]));
	set("coor/x", -19120);
	set("coor/y", -6980);
	set("coor/z", 0);
	setup();
}

void init()
{
        object me = this_player();
        if( query_temp("xuncheng", me) )
        {
                set_temp("dali_xc/lk", 1, me);
        }
}