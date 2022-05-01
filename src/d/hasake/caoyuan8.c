// caoyuan8.c 草原
inherit ROOM;
void create()
{
        set("short", "大草原");
        set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还真
不好走，看来买匹马来代步到是的好主意。
LONG);
        set("exits", ([
            "south" : __DIR__"caoyuan9",
            "west" : __DIR__"caoyuana",
            "east" : __DIR__"caoyuan7",
            "north" : __DIR__"room-che",
        ]));
        set("outdoors", "hasake");
        setup();
        replace_program(ROOM);
}