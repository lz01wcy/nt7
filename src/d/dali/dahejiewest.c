//Room: /d/dali/dahejiewest.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","大和街");
        set("long", @LONG
这是一条青石板路，两边种了不少柏树，显得庄严肃穆。南面是
大理城的守军驻地，隐隐可以听到兵士们操练的号子声，向北是土司
府，是当今皇太妃刀氏一族的世袭衙门。
LONG );
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */
            "east"   : "/d/dali/shizilukou",
            "north"  : "/d/dali/tusifu",
            "south"  : "/d/dali/bingying",
            "west"   : "/d/dali/zsh_dldamen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -19140);
	set("coor/y", -6900);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}