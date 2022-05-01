//Room: /d/quanzhou/westbridge.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","西门吊桥");
        set("long",@LONG
这是泉州西面的一座吊桥，从傍着晋江而建的城楼大门上以两
个滑轮维系。日出放下吊，日落绞起。过了桥向西南走可达岭南广
东。
LONG);
        set("outdoors", "quanzhou");
        set("exits",([ /* sizeof() == 1 */
            "west"  : "/d/foshan/road14",
            "east"  : __DIR__"westroad2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -930);
	set("coor/y", -7670);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}