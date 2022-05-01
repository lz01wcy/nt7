inherit ROOM;

void create()
{
        set("short", "大驿道");
        set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行
商的、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不
时还有两三骑快马从身边飞驰而过，扬起一路尘埃。马上的人个个身
着劲装，衣甲鲜明，有的还随身佩带着刀剑。看来都是些习武的江湖
人。道路两旁是整整齐齐的杨树林。
LONG );
        set("exits", ([
                "north" : "/d/beijing/road8",
                "south" : "/d/beijing/road10",
        ]));
        set("objects",([
                "/d/taishan/npc/tangzi" : 2,
        ]));
        set("outdoors", "beijing");
	set("coor/x", -2770);
	set("coor/y", 7560);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}