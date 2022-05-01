#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "大海");
        set("long",@LONG
你正处在茫茫大海之中。你极目远望，只见海天一线，周围连个黑点
都没有。耳边只有海浪的拍打声。
LONG);   
        set("outdoors", "taohua");
        set("no_clean_up", 0);
        set("coor/x", 5000);
        set("coor/y", -2000);
        set("coor/z", 0);
        setup();
        replace_program(ROOM) ;
}