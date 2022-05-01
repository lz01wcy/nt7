//  Room:  /d/changan/baqiao.c

inherit  ROOM;

void  create  ()
{
        set("short",  "灞桥");
        set("long",  @LONG
灞桥又叫霸桥，横跨霸水。“始皇自送至灞上”、“沛公军霸上”
指的就是这里。唐人送客多到灞桥，折柳赠别，至此黯然，故又称“消
魂桥”。春夏之交，翠柳低垂，冬则雪霁风寒，沙明石露，人称“灞柳
风雪”，列为“关中八景”之一。
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "west" :  __DIR__"dong-chengmen",
                "east" :  __DIR__"road4",
        ]));
        set("outdoors", "guanzhong");
        set("no_clean_up", 0);
        set("coor/x", -10660);
	set("coor/y", 1930);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}