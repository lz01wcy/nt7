// Room: /d/xiangyang/wallw2.c
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
                "southup"   : __DIR__"wallw4",
                "northdown" : __DIR__"westgate1",
        ]));
        set("coor/x", -7860);
	set("coor/y", -780);
	set("coor/z", 10);
	setup();
}