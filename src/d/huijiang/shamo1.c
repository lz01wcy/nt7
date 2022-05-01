// Room: /d/huijiang/shamo1.c
// Last Modified by Lonely on Sep. 12 2001

inherit ROOM;

void create()
{
        set ("short", "沙漠");
        set ("long", @LONG
淡黄色的沙堆连绵，在这死寂一片的世界中，天上不见飞鸟，地上
不见走兽。只有沙漠中倒毙的骆驼尸骨提醒你，曾经有过生命的痕迹。
远处出现了一抹岗峦。
LONG);
        set("outdoors", "huijiang");
        set("exits", ([ /* sizeof() == 2 */
                "east"  : __FILE__,
                "west"  : __FILE__,
                "south" : __FILE__,
                "north" : __DIR__"shamo2",
        ]));
        set("no_clean_up", 0);
        set("coor/x", -50010);
        set("coor/y", 9000);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}