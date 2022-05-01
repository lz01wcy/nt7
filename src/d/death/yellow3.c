// yellow3.c 黄泉大道

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", BLU "黄泉路" NOR);
        set("long",BLU @LONG
“人生自古谁无死”，从古至今，死一直是所有帝王将相，仁人义
士不能避免的结局。眼前就是著名的黄泉大道。就在你身边，一个个模
模糊糊的身影涌动着，耳边不乏一阵阵的啼哭之声可知韶华易逝，青春
难驻，人生在世多么的短暂，到了这个时候，却又是多么的留恋......
LONG NOR);
        set("exits", ([
                "north" : __DIR__"gate",
                "south" : __DIR__"yellow2",
        ]) );
        set("objects",([
                __DIR__"npc/mengpo" : 1,
        ]));
        set("no_fight", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        if( wizardp(me) || !userp(me) ) return 1;

        if (dir == "south")
        {
                return notify_fail("一个空洞的声音在你耳边响起....\n没有回头路了！\n");
        }
        else return 1;
}