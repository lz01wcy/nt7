// Room: /d/suzhou/hanshidian.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
        set("short", "寒拾殿");
        set("long", @LONG
这里供奉着相传为“和合二仙”化身的寒山，拾得金身塑像，形态
生动，逗人喜爱。寒山寺每年除夕半夜，撞钟一百零八响，其含义是除
旧迎新和纪念佛门一百零八位高僧。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "out"   : __DIR__"fengqiao",
                "west"  : __DIR__"zhengdian",
        ]));
	set("coor/x", 1049);
	set("coor/y", -1051);
	set("coor/z", -1);
	setup();
        replace_program(ROOM);
}