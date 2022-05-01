// Room: /d/songshan/eastwuchang.c
// Last Modified by Lonely on Jul. 15 2001

inherit ROOM;
void create()
{
        set("short", "东武场");
        set("long", @LONG
这里是嵩山派的练武场。地面是用黄泥土拌杂砂石砸实的，看起来
很结实的样子。练武场中间安着些器械，看来是练功用的。一些嵩山弟
子正满头臭汗地刻苦练功。
LONG );
        set("outdoors", "songshan");
        set("exits", ([
                "west"  : __DIR__"eastpath3",
                "south" : __DIR__"eastpath2",
        ]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 5,
        ]));
        set("coor/x", 0);
        set("coor/y", 920);
        set("coor/z", 90);
        setup();
        replace_program(ROOM);
}