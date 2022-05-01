// Room: /d/lingzhou/chaifang.c

inherit ROOM;
#include "room.h"
void create()
{
        set("short", "柴房");
        set("long", @LONG
这里是间不小的柴房，整齐的码着两人高的上好木柴，散发着木头
特有的清香，宫里的柴火一向都是每月一次从城外的落日林运来。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"yushanfang",
                "east"  : __DIR__"biangate",
        ]));
        create_door("east","木门","west",DOOR_CLOSED);
        set("coor/x", -6265);
        set("coor/y", 2985);
        set("coor/z", 0);
        setup();
}
