// Room: /d/yanziwu/chalin7.c
// Date: Jan.28 2000 by Lonely
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "茶花林");
        set("long", @LONG
你在花林中跌跌撞撞地蹒跚而行，不知道那里是出口，来时所留神
的只是茶花，忘了记忆路径，眼见小路东一条、西一条，也不知那一条
才是来路，要回到小船停泊处却有点儿难了，于是你心想：“先走到水
边再说。”
LONG );
        set("outdoors", "mantuo");
        set("no_clean_up", 0);
        set("exits", ([
                "west"  : __DIR__"chalin7",
                "east"  : __DIR__"chalin7",
                "north" : __DIR__"dukou",
                "south" : __DIR__"chalin7",
        ]));
        set("coor/x", 1200);
        set("coor/y", -1310);
        set("coor/z", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north")
                tell_object(me,HIY"你总算出了茶花林。\n"NOR);
        return ::valid_leave(me, dir);
}