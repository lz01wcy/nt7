//room: shoushe.c
inherit ROOM;

void create()
{
        set("short","兽舍");
        set("long", @LONG
这里是白驼山庄的兽舍。白驼山驭兽术天下知名，这里也豢养了
各种猛兽，以供下山的白驼弟子使用。兽舍里猛兽长声嘶嚎，老远都
听得见。尤其是夜晚听来，更有是撕心裂肺的惨烈。
LONG );
        set("exits",([
                "east"  : __DIR__"tuyuan",
        ]));
        set("outdoors", "baituo");
        set("objects",([
                __DIR__"npc/fox" :1,
                __DIR__"npc/wolf" :1,
                __DIR__"npc/tiger" :1,
                __DIR__"npc/lion" :1,
        ]));
        set("coor/x", -49980);
        set("coor/y", 20070);
        set("coor/z", 30);
        setup();
        replace_program(ROOM);
}
