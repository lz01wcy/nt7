// Room: /guiyun/damen.c
// Date: Nov.18 1998 by Lonely

inherit ROOM;

void create()
{
        set("short", "大门");
        set("long", @LONG
面前是一座庄院，门楼不甚高大，青砖绿瓦，灰色底的匾上写着『
归云庄』三个大黑字。牌匾较为陈旧，边角处的漆皮已剥落，露出暗黄
色的木质。看来挂在那已不下二十个春秋了。
LONG );
        set("outdoors", "guiyun");
        set("exits", ([
                "enter" : __DIR__"dayuan",
                "south" : __DIR__"shiqiao",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 2,
        ]));
        set("coor/x", 280);
        set("coor/y", -830);
        set("coor/z", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=query("family", me);

        if ((!myfam || myfam["family_name"] != "桃花岛") &&
                !query_temp("marks/guiyun", me) && dir == "enter" && 
                objectp(present("jia ding", environment(me))))
                return notify_fail("家丁做了个揖，说道：尊驾与敝庄素无往来，庄主不见外客，还是请回吧。\n");

        return ::valid_leave(me, dir);
}