//Room: /d/dali/yulin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","榕树雨林");
        set("long",@LONG
这是一片湿润的雨林，脚下水汪汪的无路可行，十数丈高的巨大
榕树盘根错节，树干粗得几个人合抱也围不住。榕树的树枝下垂到泥
水中反过来扎根，成为特意的景致。雨林虽然少有走兽，却是飞禽聚
居的乐土，身手灵活的台夷猎人攀越在大榕树浮露的根枝上，用短弩
射猎飞鸟。
LONG);
        set("objects", ([
           __DIR__"npc/lieshou": 1,
        ]));
        set("outdoors", "dalis");
        set("exits",([ /* sizeof() == 1 */
            "west"      : __DIR__"luwang",
        ]));
	set("coor/x", -19110);
	set("coor/y", -6960);
	set("coor/z", 0);
	setup();
}

void init()
{
        object me = this_player();
        if( query_temp("xuncheng", me) )
        {
                set_temp("dali_xc/yl", 1, me);
        }
}