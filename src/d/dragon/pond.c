inherit ROOM; 
#include <ansi.h> 
void create()
{
   set("short", "池塘");
   set("long",
"[1;32m这是从三清湖引来的一个小小的池塘，一座小拱桥横跨在池\n"
"塘上。塘水碧绿，上面有几朵盛开的睡莲，粉红，洁白，鹅黄，衬托着碧\n"
"绿的叶子，漂浮在小池塘上，煞是惹人喜爱。一棵垂柳半横在塘边，柳丝\n"
"随风飘舞。几块太湖石(stone)散落地放在池塘边。\n"
);
   set("exits", ([ /* sizeof() == 4 */
      "southeast" : __DIR__"lake1",
   ]));
   
   set("item_desc", ([
      "太湖石": "几块玲珑的太湖石，散落地放在池塘边，石头的一部分被埋在了土下。\n",
      "stone": "几块玲珑的太湖石，散落地放在池塘边，石头的一部分被埋在了土下，看起来埋得不深，应该能够推(push)得动。\n",
      "垂柳": "垂柳在不远处的池塘边，整个柳树横在池塘上。\n",
      "tree": "垂柳在不远处的池塘边，整个柳树横在池塘上。\n",
      "睡莲": "半开的睡莲象睡梦之中的美人，漂浮在碧绿的池塘上。\n",
      "flower": "半开的睡莲象睡梦之中的美人，漂浮在碧绿的池塘上。\n",
   ]) );
      set("no_magic", 1);
        setup();
}

void init()
{
   add_action("do_push", "push");
}

int do_push(string arg)
{
   object me, qiuyin, where;
  
   me = this_player();
        where=environment(me); 
   if( query_temp("marks/moved", where))return notify_fail("石头似乎被人推过，已经松动了。\n");
   if (!arg || arg != "stone" && arg != "石头") 
      return notify_fail("你要推什么 ? \n");
   message("vision",me->name()+"伸手推了推太湖石，石边的土松动了，露出了一条胖胖的蚯蚓。\n", me);
   qiuyin = new("/quest/tulong/obj/qiuyin");
   qiuyin->move(where);
   set_temp("marks/moved", 1, where);
   return 1;

}
