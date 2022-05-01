// caoyuan.c 草原
inherit ROOM;
void create()
{
        set("short", "草原边缘");
        set("long", @LONG
这里是大草原和沙漠接壤之地，青草由稀至密，向西绵绵延伸而去。
地上有几行骆驼踏过的蹄印，看样子这里常常有商队来往。西南方好象有
些炊烟。
LONG);
        set("exits", ([
            "east" : __DIR__"caoyuana",
            "southwest" : __DIR__"caoyuan1",
            "northwest" : __DIR__"caoyuan2",
            "north" : __DIR__"caoyuan3",
 //           "north" : __DIR__"caoyuana",
            "south" : __DIR__"caoyuana",
        ]));
        set("objects", ([
                    __DIR__"npc/biaoshi" : 1,
        ])); 
        set("outdoors", "hasake");
        setup();
}
/*
int valid_leave(object me, string dir)
{
       if( dir == "north")addn_temp("mark/steps", 1, me);
       if( dir == "south")addn_temp("mark/steps", -1, me);
        
       if( query_temp("mark/steps", me) == 4){
            me->move(__DIR__"hswz");
            delete_temp("mark/steps", me);
            return notify_fail("唉。。。\n");
           }  
     if( query_temp("mark/steps", me) == -4){
           me->move(__DIR__"caoyuan1");
           delete_temp("mark/steps", me);
             return notify_fail("唉。。。\n");
        }  
        return ::valid_leave(me, dir);
}
*/