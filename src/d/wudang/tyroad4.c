// tyroad4.c 崎岖山路
// by Marz 

inherit ROOM;

#include "feng.h"

string* npcs = ({
        "guest",
        "tufei2",
        "guest",
        "xiao_tufei",
        "guest",
        "xiao_louluo",
});

void create()
{
        int i = random(sizeof(npcs));

        set("short", "崎岖山路");
        set("long", @LONG
你走在一条崎岖狭隘的山路上，一边是峭壁，一边是悬崖。高高
的天柱峰(feng)笼罩在云雾中，隐约可见。可是身旁的进香客和游人
都仔细地町着自己的脚下，不敢抬头望一眼，惟恐一不小心摔下去。
更有强人趁机打劫，行人无不噤声闭气，只求快点赶路。
LONG );
        set("outdoors", "wudang");
        set("exits", ([
                "westup" : "/d/wudang/tyroad3",
                "southdown" : "/d/wudang/tyroad5",
        ]));
        set("item_desc", ([
                "feng" : (:look_feng:),
        ]));
        set("objects", ([
                "/d/wudang/npc/"+npcs[i] : 1
        ]));
//        set("no_clean_up", 0);
        set("coor/x", -330);
        set("coor/y", -290);
        set("coor/z", 70);
        setup();
}

void init()
{
        add_action("look_feng", "look");
}