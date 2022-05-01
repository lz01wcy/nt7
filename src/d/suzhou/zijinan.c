// Room: /d/suzhou/zijinan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
        set("short", "紫金庵");
        set("long", @LONG
这是一座苏州城里有名的寺庵，庵中正面是释加摩尼佛眼，似乎在
注视前来礼佛之人；右壁一尊诸天用三个手指托起一块轻柔的绣花经盖
和后壁观音菩萨头上的一顶刻着牡丹花的紫红色华盖。左壁的每尊罗汉
塑像造型生动，各具特征，到达了以神人话、精神超忽、呼之欲活的艺
术境界，令人叹为观止。
LONG );
        set("objects", ([
                __DIR__"obj/box" : 1,
                __DIR__"npc/nigu1" : 1,
                __DIR__"npc/nigu2" : 1,
        ]));
        set("outdoors", "suzhou");
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("exits", ([
                "east"      : __DIR__"beidajie2",
        ]));
	set("coor/x", 1100);
	set("coor/y", -1030);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}