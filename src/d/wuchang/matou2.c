//Edited by fandog, 02/15/2000

#include <ansi.h>
inherit RIVER;

void create()
{
        set("short", "武昌码头");
        set("long", @LONG
武昌也是武汉的一个重镇。渡船在这里停下，走在石板搭砌的江岸，
仍然能感觉到大江的奔流。略带腥味的江边气息随风飘来。南边可见江
中一柱擎天石壁。
LONG );

        set("exits", ([
                "south" : __DIR__"chibi",
        ]));

        set("outdoors", "wuchang");
        set("no_clean_up", 0);
        set("coor/x", -1400);
        set("coor/y", -2200);
        set("coor/z", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "江");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("come_msg_out",   "一只木船缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n");
  set("busy_msg",       "只听得江面上隐隐传来：“别急嘛，这儿正忙着呐……”\n");
  set("wait_msg",       "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n");
  set("leave_msg_out",  "艄公把踏脚板收了起来，竹篙一点，木船向江心驶去。\n");
  set("leave_msg_in",   "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，木船向江心驶去。\n");
  set("come_msg_in",    "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n");
  set("item_desc/river", HIC "\n只见近岸处有几只渡船，也许大声喊("
                         HIY "yell" HIC ")一声船家(" HIY "boat" HIC
                        ")就\n能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏江而过。\n" NOR);
  set("boat_short", "渡船");    
  set("boat_desc",  @LONG
    一叶小舟，最多也就能载七、八个人。一名年轻力壮的艄公手持长
竹篙，正在船尾用力地撑着船，一边还吆喝着船歌：走四方～路迢迢～
水长长……
LONG );
  set("to",         __DIR__"matou1");  // 船的终点 /*   必选   */
        setup();
}
