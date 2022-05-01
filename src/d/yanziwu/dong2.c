// Room: /d/yanziwu/dong2.c
// Date: Jan.28 2000 by Lonely

inherit ROOM;

void create()
{
        set("short", "潮声洞");
        set("long", @LONG
洞里伸手不见五指。隐隐听到湖浪冲击巨岩，延绵不绝。你在洞里
摸索前行，听着潮声引导，试图找到出洞的方向。
LONG );
        set("exits", ([
                "out"    : __DIR__"chaosheng",
                "south"  : __DIR__"dong1",
                "north"  : __DIR__"dong3",
                "east"   : __DIR__"dong4",
                "west"   : __DIR__"dong2",
        ]));
        set("no_clean_up", 0);
        set("coor/x", 1200);
        set("coor/y", -1280);
        set("coor/z", 0);
        setup();
        replace_program(ROOM);
}