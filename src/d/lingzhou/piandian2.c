// Room: /d/lingzhou/piandian2.c

inherit ROOM;

void create()
{
        set("short", "偏殿");
        set("long", @LONG
这里是皇上寝宫边的偏殿，是侍卫们值班时休息的地方, 同样也不
大，但摆了好几张桌子，椅子却不多。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"qingong.c",
                "south" : __DIR__"yushufang",
        ]));
        set("objects", ([
                __DIR__"npc/shiwei" : 3,
        ]));
        set("coor/x", -6285);
        set("coor/y", 2985);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}