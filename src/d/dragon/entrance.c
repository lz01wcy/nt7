inherit ROOM; 
#include <ansi.h> 

void create()
{
      set("short","青草坪");
      set("long",
"[1;32m松临雨过青，花向春来美。风中有淡淡的幽香。远远可见山\n"
"上祥云瑞瑞，彩霞如练虹。地上还有一个泉眼，但看起来似乎已经干涸了。\n"
);
      set("exits",([ 
           "north"  : __DIR__"spirit4",
      ]));
      set("objects",([
      ]));
      set("no_magic", 1);
        setup();
}
