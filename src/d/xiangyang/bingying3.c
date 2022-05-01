// Room: /d/xiangyang/bingying3.c
// Date: Jan. 8 1999 by Lonely

inherit ROOM;

void create()
{
        set("short", "兵营");
        set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队
操练，有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，
不动声色地巡视着四周。看到你进来，他们全都瞪大眼睛盯着你。
LONG );
        set("item_desc", ([
                "dong" : "\n",
        ]));

        set("exits", ([
                "east" : __DIR__"southjie3",
        ]));
        set("objects", ([
                __DIR__"npc/pian" : 1,
                __DIR__"npc/zuo"  : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("coor/x", -7830);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}