inherit ROOM;

void create()
{
        set("short", "断魂崖");
        set("long", @LONG
这是通向灵鹫宫的必经之路，一条小道蜿蜒曲折地通向缥缈峰顶。
路的右侧是一条陡峭的山崖，一阵山风吹过，你似乎听见从下面传来
几声惨号，你心中一凛，不禁加快脚步赶紧离开这里。
LONG );
        set("outdoors", "lingjiu");
        set("exits",([
                "westup"   : __DIR__"yan",
                "eastdown" : __DIR__"shanjiao",
        ]));
        setup();
        replace_program(ROOM);
}