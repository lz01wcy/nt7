//Room: /d/dali/northgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
        set("short","北门");
        set("long", @LONG
阳苜咩城，或简称苜咩城，是大理国的都城。自南诏于初创，历
经陈氏『长大和国』、赵氏『大天兴国』、杨氏『大义宁国』诸代而
至当今的段氏的『大理国』，均以此城为都。此处乃是北城门，以梅
溪为护河，城墙建在溪南，由石块和土垒成，高二丈五，厚达二丈，
门上有重楼，驻有了哨。青石官道从城里直向北延伸，另有一条黄土
大路向西通去。
LONG );
        set("objects", ([
           "/d/dali/npc/bing": 4,
           "/d/dali/npc/jiang": 1,
                "/clone/npc/walker"  : 1,
        ]));
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */
            "south"     : "/d/dali/paifang",
            "north"     : "/d/dali/dalinorth",
            "east"      : "/d/dali/chahuashan1",
            "west"      : "/d/dali/shanlu3",
        ]));
	set("coor/x", -19160);
	set("coor/y", -6860);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}