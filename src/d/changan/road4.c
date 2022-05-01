//  Room:  /d/changan/road4.c

inherit  ROOM;

void  create  ()
{
        set("short",  "大官道");
        set("long",  @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东南通向函谷
关，往西则直达长安城。
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "north"      :  __DIR__"boshulin1",
                "west"      :  __DIR__"baqiao",
                "southeast" :  __DIR__"road3",
        ]));
        set("outdoors", "guanzhong");
        set("no_clean_up", 0);
        set("coor/x", -10650);
	set("coor/y", 1930);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}