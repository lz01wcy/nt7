// midao3.c
// Modified by Lonely June.25 2000

inherit ROOM;

void create()
{
        set("short", "秘密通道");
        set("long", @LONG
这是一段又长又黑的秘密通道，隐约可以感觉到四周是冰冷而坚硬
的石壁，你什么了看不清楚，只可以靠摸索着前进。
LONG );
        set("exits", ([
                "south" : __DIR__"midao2",
                "out" : __DIR__"muwu1",
        ]));
        set("no_clean_up", 0);
        set("coor/x", -3000);
        set("coor/y", -1000);
        set("coor/z", -40);
        setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="out") 
         tell_object(me,"你走出了秘密通道，神秘地出现在一间木屋之中。\n");
         return ::valid_leave(me,dir);
}
