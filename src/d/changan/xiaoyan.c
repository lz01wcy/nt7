// /d/changan/xiaoyan.c

inherit  ROOM;

void  create  ()
{
        set  ("short",  "小雁塔");
        set  ("long",  @LONG
小雁塔建于景龙年间，因比大雁塔小，故称小雁塔。塔高十五级，
双塔连理为一塔，形体秀丽美观。
LONG);
        set("exits",  ([  //sizeof()  ==  4
                "northeast"  :  __DIR__"road5",
        ]));
        set("outdoors",  "changan");
        set("coor/x", -10730);
	set("coor/y", 1860);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}