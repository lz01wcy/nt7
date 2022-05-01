//Room: /d/dali/kedian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","客店");
        set("long",@LONG
这是喜州城里唯一的一家客栈，专门接待过往客商，生意非常兴
隆。店小二里里外外忙得团团转。此间虽偏远，却不因势坑宰客人，
住店一宿只要五两银子。
LONG);
        set("objects", ([
                __DIR__"npc/puren": 1,
        ]));
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("exits",([ /* sizeof() == 1 */
                "west"    : __DIR__"xizhou",
                "up"      : __DIR__"kedian2",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer3" : 1,
        ]));
	set("coor/x", -19120);
	set("coor/y", -6950);
	set("coor/z", 0);
	setup();
        "/clone/board/kedian15_b"->foo();
}

int valid_leave(object me, string dir)
{

        if( !query_temp("rent_paid", me) && dir == "up" )
        return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

        if( query_temp("rent_paid", me) && dir == "west" )
        return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

        return ::valid_leave(me, dir);
}