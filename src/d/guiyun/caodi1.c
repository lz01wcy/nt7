// Room: /d/guiyun/caodi1.c
// Last Modified by Lonely on Jun. 29 2001

inherit ROOM;

void create()
{
        set("short", "草地");
        set("long",@LONG
一片青翠的草地。绿草如荫，茂密地生长着，草丛间有一些不知名
的小虫在钻来钻去。远处有一片树林。
LONG
);
        set("exits",([
                "west"  : __DIR__"caodi2",
                "east"  : __DIR__"caodi3",
                "south" : __DIR__"road4",
                "north" : __DIR__"shulin1",
        ]) );
        set("no_clean_up",0);
        set("outdoors", "guiyun");
        set("coor/x", 290);
        set("coor/y", -830);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}
