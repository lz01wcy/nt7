//Room: /d/dali/langan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","杆栏中层");
        set("long",@LONG
这里是杆栏的中层，从楼梯一上来就是祭所。南诏蛮夷大多信奉
自己部族特有的神明，家家户户都居中室设案供奉。中层的其余房间
则为寝所。
LONG);
        set("objects", ([
           __DIR__"npc/kid": 1,
        ]));
        set("exits",([ /* sizeof() == 1 */
            "down"      : __DIR__"langan1",
        ]));
	set("coor/x", -19060);
	set("coor/y", -6880);
	set("coor/z", 20);
	setup();
}
void init()
{
        object me = this_player();
        if( query_temp("xuncheng", me) )
        {
                set_temp("dali_xc/lg2", 1, me);
        }
}