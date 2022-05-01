inherit ROOM;

void create()
{
      set("short", "青石阶");
        set("long", @LONG
已经是峨嵋山脚下了。南面一条通往峨嵋的青石阶，两旁绿树荫
蔽，空气十分清新。西南方通向南诏的大理国。西边好象有人搭了个
小草棚。
LONG );
      set("outdoors", "emei");
      set("exits", ([
          "northeast" : __DIR__"qsjie1",
          "southwest" : "/d/dali/road1",
          "southup"   : __DIR__"bgsgate",
          "west"      : __DIR__"caopeng",
      ]));
      set("no_clean_up", 0);
        set("coor/x", -370);
        set("coor/y", -200);
        set("coor/z", 0);
        setup();
      replace_program(ROOM);
}