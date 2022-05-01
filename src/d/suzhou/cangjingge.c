// Room: /d/suzhou/cangjingge.c
// Last Modified by Lonely on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "藏经阁");
        set("long",@long
中间排列着五排大书架。四周则陈列矮几，以供阅读。几位老僧手
执经卷，正在闭目凝思。
long);
        set("exits",([
                "south" : __DIR__"dxbdian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 1119);
	set("coor/y", -1151);
	set("coor/z", 29);
	setup();
        replace_program(ROOM);
}