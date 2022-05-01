//room: /d/mingjiao/eastdian.c
inherit ROOM;

void init();

void create()
{
        set("short","明教东侧殿");
        set("long", @LONG
这里是东侧殿，是接待来宾的地方。殿内摆着几张桌子，桌旁围
放数把椅子。墙上悬着几幅字画，墙边一排书架，架上摆满书籍。窗
外是茫茫昆仑雪山，雪峰延绵。
LONG );
       set("exits",([
           "west"     : __DIR__"qiandian",
       ]));
       set("no_clean_up", 0);
       setup();
       replace_program(ROOM);
}
