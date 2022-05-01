//  Room:  /d/lanzhou/caoyuan1.c

inherit  ROOM;

void  create  ()
{        
        int dir1,dir2,dir3/*,dir4*/;
        dir1=random(5)+1;
        dir2=random(5)+1;
        dir3=random(5)+1;
        while (dir1!=2 && dir2!=2 && dir3!=2)        
        {        
                dir1=random(5)+1;
                dir2=random(5)+1;
                dir3=random(5)+1;                
        }
        set("short",  "大草原");
        set("long",  @LONG
西北平原上的大草原，较之蒙古草原毫不逊色。绿油油的牧草直连
天边。西北的蓝天绿地，比起东北的黑山白水来，别有一番风趣。
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "south" : "/d/changan/road9",
                "north" : __DIR__"caoyuan"+dir1,
                "east"  : __DIR__"caoyuan"+dir2,
                "west"  : __DIR__"caoyuan"+dir3,
        ]));
        set("objects",  ([
                "/d/xingxiu/npc/herdsman" : random(2),
        ]));
        set("outdoors", "lanzhou");
        set("no_clean_up", 0);
	set("coor/x", -15740);
	set("coor/y", 3770);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}