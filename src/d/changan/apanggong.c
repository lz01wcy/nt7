// /d/changan/apanggong.c

inherit  ROOM;

void  create  ()
{
        set  ("short",  "阿房宫");
        set  ("long",  @LONG
这里便是阿房宫，四下便是黄土、乱石，哪里看得出有什么宫殿？
不远处立着块石碑(bei)。
LONG);
        set("exits",  ([  //sizeof()  ==  4
                "east" :  __DIR__"road7",
        ]));
        set("item_desc",  ([
                "bei" :  "

            始皇三十五年，使奴七十万众建造此宫
                 不念暴政苛刻，义师逐鹿。
               霸王入关，千里宫阙付之一炬。

                暴者必亡      仁者无敌
\n",
        ]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
        set("coor/x", -10790);
	set("coor/y", 1920);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}