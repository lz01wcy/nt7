// xiaotan.c

inherit ROOM;

void create()
{
        set("short", "小摊");
        set("long", @LONG
这是一临时搭成的小摊，生意却非常兴隆。路人都爱在这里落脚，
你可以在这里打听到京城的奇闻逸趣。小二匆匆忙忙地接待着南来北
往的客人。树荫下摆着几张小木桌，桌旁坐满了各种各样的游人。
LONG );
        set("no_sleep_room",1);
        set("objects", ([
                "/d/beijing/npc/xiaoer" : 1,
                "/d/huashan/npc/youke" :2,
        ]));
        set("exits", ([
                "east" : "/d/beijing/road8",
        ]));
	set("coor/x", -2780);
	set("coor/y", 7570);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "east") && present("mian", this_player()) &&
            objectp(present("xiao er", environment(me))))
                return notify_fail("\n小二追出来说道：这位客官，吃面还想连碗端走啊？\n");

        return ::valid_leave(me,dir);
}