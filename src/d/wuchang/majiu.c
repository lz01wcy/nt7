//Edited by fandog, 02/15/2000
inherit ROOM;

void create()
{
      set("short","马厩");
      set("long",@LONG
这是客店后的马厩，常年供应新鲜草料。客人们在此歇息，马夫会
把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干干净净，一直伺
候到客人上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
        set("outdoors", "wuchang");
        set("no_fight", "1");
        set("no_beg", "1");
        set("no_clean_up", 0);
        set("objects", ([
                "/d/city/npc/zaohongma": 1,
                "/d/city/npc/huangbiaoma": 1,
                "/d/city/npc/ziliuma": 1,
                "/clone/misc/mafu": 1,
        ]));
        set("item_desc", ([
                "paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      扬州城:  rideyz

TEXT]));
        set("exits",([ /* sizeof() == 1 */
                "north" : __DIR__"kedian",
                "up"   : SHOP_DIR"wuchang_shop",
        ]));
	set("coor/x", -5100);
	set("coor/y", -1900);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}