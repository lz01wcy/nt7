// Room: /yixing/shulin5.c
// Date: Nov.18 1998 by Lonely

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶尔从茂
密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身后传来野
兽的啸声使人不觉犹豫了前进的脚步。
LONG );
        set("outdoors", "yixing");
        set("no_clean_up", 0);
        set("exits", ([
                "southwest" : __DIR__"tiandi",
                "east"      : __DIR__"shulin2",
        ]));
        set("coor/x", 250);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}