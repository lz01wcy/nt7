//Room: /d/dali/yuhuayuan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","御花园");
        set("long", @LONG
这里是大理国皇宫的御花园，两旁的花开得争奇斗艳，边上有一
个小水池，山上流下来的泉水就会集在那里，几只仙鹤在水边抓鱼，
一副旁若无人的样子，往北是花廊，往南是前殿。
LONG );
        set("objects", ([
           "/d/dali/npc/xianhe": 1,
        ]));
        set("outdoors", "daligong");
        set("exits",([ /* sizeof() == 1 */
            "north"  : "/d/dali/hualang",
            "south"  : "/d/dali/qiandian",
        ]));
	set("coor/x", -19140);
	set("coor/y", -6840);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}