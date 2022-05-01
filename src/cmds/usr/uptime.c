// uptime.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
#include <mudlib.h>
#include <getconfig.h>

#define AUTOBOOT_D     "/adm/daemons/autobootd.c"
inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
        int t, d, h, m, s, r;
        string time, rtime;

        t = uptime();
        s = t % 60;                t /= 60;
        m = t % 60;                t /= 60;
        h = t % 24;                t /= 24;
        d = t;

        if (d) time = chinese_number(d) + "天";
        else time = "";

        if (h) time += chinese_number(h) + "小时";
        if (m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

/*
        r = time() + AUTOBOOT_D->query_time() * 60;
        rtime = TIME_D->replace_ctime(r);
*/

        //write(HIC + LOCAL_MUD_NAME() + "已经执行了" + time + "，将在 " + rtime + " 重启。\n\n" NOR);
        write(LOCAL_MUD_NAME() + "已经执行了" + time + "。\n\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : uptime
 
这个指令告诉您这个泥巴游戏已经连续执行了多久。
 
HELP
    );
    return 1;
}