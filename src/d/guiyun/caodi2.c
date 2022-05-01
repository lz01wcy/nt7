// Room: /d/guiyun/caodi2.c
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
                "east"  : __DIR__"caodi1",
                "north" : __DIR__"shulin2",
        ]) );
        set("no_clean_up",0);
        set("outdoors", "guiyun");
        set("coor/x", 280);
        set("coor/y", -830);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}
