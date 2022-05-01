inherit ROOM;

void create()
{
        set("short", "西厢走廊");
        set("long", @LONG
你走在一条走廊上，东边是大殿，北边是一座楼阁。西面楼上传
来阵阵打斗声。
LONG );
        set("exits", ([
                "northup" : __DIR__"cangjingge",
                "east"    : __DIR__"sanqingdian",
                "westup"  : __DIR__"caolianfang",
        ]));
        set("coor/x", -380);
        set("coor/y", -300);
        set("coor/z", 90);
        setup();
        replace_program(ROOM);
}