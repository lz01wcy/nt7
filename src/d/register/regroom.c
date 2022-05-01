// Room:/d/welcome/regroom.c
// Updated by Lonely (08/11/2002)

#include <ansi.h>
inherit ROOM;
int do_register(string arg);

void create()
{
        set("short", "泥潭注册室");
        set("long", "\n这里是新玩家进行注册的地方，请您使用指令 " HIC "register " NOR "加上你的完\n"
                    "整及真实" HIC " email " NOR "地址进行注册。\n\n"
                    "    请务必认真注册你的电子邮件地址，" HIR "电子邮件地址是保障你一切\n"
                    "权益的依据" NOR "，包括你密码的丢失情况下，我们通过你注册的信箱来确\n"
                    "认你的身份和归还你的密码。\n\n"

                    "现在，请输入" HIW " reg 您的email地址\n\n" NOR);


        set("item_desc", ([
        "sign":
"\t     [1;33m有关电子邮件注册的几点说明[0m
[37m－－－－－－－－－－－－－－－－－－－－－－－－－－[0m
首先请你仔细检查注册命令里输入的电子邮件地址是否正确！

这个游戏的注册过程是由机器自动完成的，在你还没有离开
游戏的时候注册信就已经发出了。如果注册信未能正确发出
会提示你从新输入注册命令，只有正确发出以后才会将注册
玩家断线。
你收到的时间是有你的邮件服务提供者决定的，如果他们转
信的时间快，正常情况下你应当在[1;33m10[0m秒钟之内收到。也就是
你关上 zMud窗口打开邮件程序，就应当能收到了。最迟[1;33m1-2[0m
个小时也应当收到。
我们的游戏给玩家留了 [1;36m48[0m 个小时的收信时间应当是很充分
的。如果在这段时间内还未能收到我们发给你的信，建议你
换一个转信快的邮件服务提供者再次申请，或者向你的邮件
服务提供者进行咨询。

感谢你对这个游戏的关注。  (注：邮件注册制度暂缓实行)
[37m－－－－－－－－－－－－－－－－－－－－－－－－－－[0m
                               \t\t[1;36m" + MUD_NAME + "巫师组[0m\n"
        ]));


        set("no_fight", 1);
        set("no_magic", 1);
        set("no_steal", 1);
        set("no_beg", 1);   
        // set("valid_startroom", 1); 
     
        setup();
}

void init()
{
        add_action("do_register", "register");
        add_action("do_register", "reg");
        add_action("do_register", "zhuce");
}

int do_register(string arg)
{
        object me = this_player();
        string mail;
        string msg;
        
        if (! arg|| strsrch(arg, "@") == -1 
        || sscanf(arg, "%*s@%*s.%*s") != 3 
        || strsrch(arg, ",") != -1)
                return notify_fail("电子邮件地址必须是 "
                                   "player@me.com 格式。\n");
        else
        {
                mail = arg;
                set("email", mail, me);

                msg=query("name", me)+"（"+query("id", me)+"）：\n\n";

                msg += "    欢迎进入泥潭的世界，从这一刻起您将有机会体验到其他MUD 无\n" +
                       "法带给您的快乐。\n";
                msg += "    如果您是一个喜欢聊天的人，这里有更多，更有趣，也更全面的\n" +
                       "emote 可以让您尽情享乐，嬉笑怒骂，完全不必负责任。\n";
                msg += "    如果您是一个喜欢练功的人，这里的门派之间将达到最大限度的\n" +
                       "平衡，多样的任务系统可以让您比较顺利的成就一代宗师。\n";
                msg += "    如果很不巧的您是一个利欲熏心的人，这里的官职系统一定可以\n" +
                       "满足您担当兵马大将军的欲望。\n";
                msg += "    如果您是一个渴望生活的人，您可以在这里娶妻生子，买房钓鱼\n" +
                       "为乐，享受那一份世外高人的恬静与淡雅。\n";
                msg += "    如果您对MUD 游戏感到很陌生，我们的泥潭中有完善的新手指引\n" +
                       "系统，并设有专门的新人导师对各位新玩家进行指导。\n";
                msg += "    同时，这里严格贯彻“公平，公正，公开”六字真言，努力为各\n" +
                       "位玩家打造一片纯净的游戏天空。\n";
                msg += "    更多的游戏特色您可以访问我们的网站www.chinesemud.org，或\n" +
                       "者直接进入游戏内部用help命令进行查询。如果您对我们的游戏有任\n" +
                       "何意见，您可以在游戏内部的留言板上留言，或者直接登陆我们的论\n" +
                       "坛bbs.chinesemud.org。\n";
                msg += "    再次衷心感谢您参与我们的游戏，在此泥潭的巫师们将以最大的\n" +
                       "热情回报您对我们的支持。\n";
                msg += "    谢谢！\n\n";

                msg += "　　        　　　　　　　　　                泥潭巫师工作群\n";

                /*
                if (! MAIL_D->queue_mail(me, "nitan@chinesemud.org",
                        query("email", me),"感谢您光临泥潭网络游戏",msg) )
                {
                        tell_object(me, query_fail_msg());
                        tell_object(me, "发送注册邮件失败，请注册你正确的邮件地址！\n");
                        return 1;
                }
                */
                
                set("registered", 1, me);
                /*
                tell_object(me, "\n有一封邮件已根据您登记的地址发往\n\n" +
                                ""+HIW+query("email", me)+NOR+"\n\n请您"
                                HIG "二分钟" NOR "后检查您的电子邮件信箱。\n");
                */
                tell_object(me, HIR "\n祝您在泥潭玩的愉快！:)\n\n" NOR);
                message("vision", "只见白光一闪，"+me->name()+"消失了。\n", environment(me), ({me}) ); 
                // SMTP_D->send_mail(me,mail);
                me->move("/d/register/entry");
                message("vision", "你忽然发现前面多了一个人影。\n", environment(me), me);
                
                return 1;
        }
}
