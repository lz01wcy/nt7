//Room: /d/dali/xiaodao2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","林间小道");
        set("long", @LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密密的
树林这里人迹罕至，惟闻足底叩击路面，微风吹拂树叶，沙沙作响。
LONG );
        set("outdoors", "dalic");
        set("exits",([ /* sizeof() == 1 */
            "northeast" : "/d/dali/heilongling",
            "west"      : "/d/dali/southgate",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -19120);
	set("coor/y", -6910);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}