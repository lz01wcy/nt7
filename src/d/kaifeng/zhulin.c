inherit ROOM;

void create()
{
          set ("short", "竹林");
        set("long", @LONG
一阵清凉从头顶碧绿的竹梢倾斜下来，几点金色的光斑透过竹叶
在地上跳动，风过处，刷刷的声响随风而远去，在竹林的中间被人开
出了一片空地，中央是一间小茅屋。
LONG );

          set("outdoors", "kaifeng");
          set("exits", ([
                  "enter" : __DIR__"zhulin1",
                  "west":__DIR__"fanta",
        ]));
	set("coor/x", -5020);
	set("coor/y", 2140);
	set("coor/z", 10);
	setup();
          replace_program(ROOM);
}