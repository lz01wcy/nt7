//Room: /d/dali/chahua7.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","茶花园");
        set("long", @LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你站在茶花
园中，北面是一座小山，山上栽满了常青乔木。地上长草委地，密密
层层的。东面有一个小小庭院，西边望去仍是一片万紫千红。
LONG );
        set("outdoors", "daliwang");
        set("exits",([ /* sizeof() == 1 */
            "south"   : "/d/dali/chahua6",
            "northup" : "/d/dali/chahua9",
            "east"    : "/d/dali/chahua10",
            "west"    : "/d/dali/chahua8",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -19071);
	set("coor/y", -6821);
	set("coor/z", -1);
	setup();
        replace_program(ROOM);
}