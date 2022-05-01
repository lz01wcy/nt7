//Room: /d/dali/shanlin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","山林");
        set("long",@LONG
你走在一片茂密的山林中，时而有飞禽走兽横过，百鸟在林间飞
鸣，南边乌夷部落里的村民经常来此狩猎。山林北面不远传来隆隆水
声，看来有大河流过，南边是一片低洼的河谷盆地，颇有人烟。
LONG);
        set("objects", ([
           __DIR__"npc/lieren": 1,
        ]));
        set("outdoors", "daliw");
        set("exits",([ /* sizeof() == 1 */
            "northdown"  : __DIR__"hebian",
            "southdown"  : __DIR__"gelucheng",
        ]));
	set("coor/x", -19210);
	set("coor/y", -6840);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}