// pine_forest6.c 松林
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
        
        switch(random(8)){
        case 1:
                set("objects", ([ __DIR__"obj/songguo" : 2]));
                break;
        case 2:
                set("objects", ([ __DIR__"npc/snake" : 1]));
                break;
        case 0:
                set("objects", ([
                        __DIR__"obj/songguo" : 1,
                        __DIR__"npc/snake" : 1]));
                break;
        case 3:
                set("objects", ([ __DIR__"npc/snake" : 2]));
                break;
        case 4:
                set("objects", ([ __DIR__"obj/pine" : 1]));
                break;
        }                          
        
        set("exits", ([
                "south" : __DIR__"pine_forest"+(4+random(6)),
                "north" : __DIR__"pine_forest"+(6+random(4)),
                "east" : __DIR__"pine_forest"+(random(6)),
                "west" : __DIR__"pine_forest"+(random(6)),
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
