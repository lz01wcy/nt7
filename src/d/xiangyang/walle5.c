// Room: /d/xiangyang/walle5.c
// Date: Jan. 8 1999 by Lonely
// Modified by Zeratul Jan 15 2001,限制了疯狂爬城

inherit __DIR__"wall.c";

void create()
{
        set("short", "石阶");
        set("long", @LONG
这是登向城头的石阶，因为城墙很高，所以很陡。石阶两
侧有可供拉车上下的斜坡道。
LONG );
        set("outdoors", "xiangyang");
        set("no_clean_up", 0);

        set("exits", ([
                "southup"   : __DIR__"walle7",
                "northdown" : __DIR__"walle3",
        ]));
        set("coor/x", -7780);
	set("coor/y", -800);
	set("coor/z", 30);
	setup();
}