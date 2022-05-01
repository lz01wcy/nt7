// pine_forest0.c 松林
// Last Modified by Lonely on Aug. 18 2002

inherit ROOM;


void create()
{
        set("short", "松林");
        set("long", @LONG
这是松林深处，暗无天日，朦胧中只感觉到左右前后到处都是树影。
地上有一两个死人骷髅，发着绿荧荧的磷光。你惊骇之间，一脚踩在钢
针般的松针上！
LONG
        );
        
        if (random(2)) 
                set("objects", ([ __DIR__"obj/pine" : 1]));
        else                                         
                set("objects", ([ __DIR__"obj/songguo" : 1]));
        
        set("exits", ([
                "south" : __DIR__"pine_road1",
                "north" : __DIR__"pine_forest"+(2+random(4)),
        ]));
        set("outdoors", "wudang");
        setup();
}


void init()
{
        object me = this_player();
        
        if( !objectp(query_temp("armor/boots", me)) )
                me->receive_damage("qi", 10, "被松针扎死了");  
}
