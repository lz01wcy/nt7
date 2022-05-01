// help.c

// This include file is included by the help command (/cmds/usr/help).
// If you changed the structure of help docs, remember to update this file.
#include <ansi.h>

#define DEFAULT_EFUN_PATHS ({\
        "/doc/help/",\
        "/doc/skill/",\
        "/doc/efuns/",\
        "/doc/applies/",\
        })

#define DEFAULT_HELP_PATHS ({\
        "/help/", \
        })

inherit F_CLEAN_UP;

string *efun_search = DEFAULT_EFUN_PATHS;
string *help_search = DEFAULT_HELP_PATHS;
mapping here_map = ([
        "baituo":       "map_bts",
        "changan":      "map_ca",
        "city":         "map_yz",
        "city3":        "map_cd",
        "emei":         "map_em",
        "foshan":       "map_fs",
        "fuzhou":       "map_fz",
        "guanwai":      "map_gw",
        "guiyun":       "map_gyz",
        "gumu":         "map_gm",
        "hangzhou":     "map_hz",
        "heimuya":      "map_hmy",
        "hengshan":     "map_ns",
        "henshan":      "map_ss",
        "huanghe":      "map_hh",
        "huashan":      "map_ws",
        "jingzhou":     "map_jz",
        "jueqing":      "map_jqg",
        "kaifeng":      "map_kf",
        "kunlun":       "map_kl",
        "kunming":      "map_km",
        "lingzhou":     "map_lz",
        "lanzhou":      "map_la",
        "lingjiu":      "map_ljg",
        "lingxiao":     "map_lxg",
        "luoyang":      "map_ly",
        "meizhuang":    "map_mz",
        "mingjiao":     "map_mj",
        "motianya":     "map_mty",
        "pk":           "map_trc",
        "qingcheng":    "map_qc",
        "quanzhen":     "map_zn",
        "quanzhou":     "map_qz",
        "shaolin":      "map_sl",
        "shenlong":     "map_sld",
        "songshan":     "map_cs",
        "suzhou":       "map_sz",
        "taishan":      "map_es",
        "taohua":       "map_thd",
        "tangmen":      "map_tm",
        "tianlongsi":   "map_tls",
        "village":      "map_hsc",
        "wanjiegu":     "map_wjg",
        "wudang":       "map_wd",
        "xiakedao":     "map_xkd",
        "xiangyang":    "map_xi",
        "xiaoyao":      "map_xyl",
        "xingxiu":      "map_xxh",
        "beijing":      "map_bje",
        "dali":         "map_dl",
        "xuedao":       "map_xdm",
        "xueshan":      "map_xss",
        "xuanminggu":   "map_xmg",
        "yanziwu":      "map_yzw",
        "zhongzhou":    "map_zz",
]);

mapping here_map2 = ([
        "xingxiu":     ({"map_xxh", "map_xy"}),
        "beijing":     ({"map_bje", "map_bjw"}),
        "dali":        ({"map_dl","map_dalie","map_dalis","map_daliw","map_dalie"}),
]);

int help(object me);

int main(object me, string arg)
{
        int i;
        string file, str;

        // If no topic specified, give the topics.
        if( !arg ) {
                if (file_size(HELP_DIR + "/topics") > 0)
                {
                        write(color_filter(read_file(HELP_DIR + "/topics")));
                        // me->start_more(color_filter(read_file(HELP_DIR + "/topics")));
                } else
                {
                        write("没能找到帮助主题。\n");
                }
                return 1;
        }

        seteuid(getuid());

        if (arg == "here")
        {
                object here;
                string here_name,the_file,*mixed_file;

                me->start_more(color_filter(MAP_D->show_map(environment(me))));
                return 1;
                //return notify_fail("请您使用 map 指令察看地图。\n");
                if (!objectp(here = environment(me)))
                {
                        help(me);
                        return 1;
                }

                here_name = base_name(here);
                if (sscanf(here_name,"/d/%s/",here_name) != 1)
                {
                        write("没有关于这里的帮助信息。\n");
                        return 1;
                }

                if (mixed_file = here_map2[here_name])
                {
                        for (i = 0;i < sizeof(mixed_file);i ++)
                        {
                                the_file = "/help/" + mixed_file[i];
                                if (file_size(the_file) <= 0) continue;
                                str = read_file(the_file);
                                if (strsrch(str,filter_color(here->short())) != -1)
                                {
                                        str = replace_string(str, filter_color(here->short()), "$BLINK$" + filter_color(here->short()) + "$NOR$");
                                        me->start_more(color_filter(str));
                                        return 1;
                                }
                        }

                }

                if (!(the_file = here_map[here_name]))
                {
                        write("没有关于这里的帮助信息。\n");
                        return 1;
                }

                the_file = "/help/" + the_file;

                if (file_size(the_file) <= 0)
                {
                        write("没有关于这里的帮助信息。\n");
                        return 1;
                }

                str = read_file(the_file);
                str = replace_string(str, filter_color(here->short()), "$BLINK$" + filter_color(here->short()) + "$NOR$");
                me->start_more(color_filter(str));

                return 1;
        }

        // Search the individual search path first.
        if( pointerp(help_search) ) {
                MYGIFT_D->check_mygift(me, "newbie_mygift/help");
                i = sizeof(help_search);
                while(i--) if( file_size(help_search[i] + arg)>0 ) {
                        me->start_more(color_filter(read_file(help_search[i] + arg)));
                        return 1;
                }
        }

        // Else, try if a command name is specified.
        if( stringp(file = me->find_command(arg)) ) {
                notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
                return file->help(me);
        }

        // Support efun/lfun help with same name as other topics such as
        // ed() and ed command.
        sscanf(arg, "%s()", arg);

        // Finally, search the default search paths.
        if( pointerp(efun_search) ) {
                i = sizeof(efun_search);
                while(i--) if( file_size(efun_search[i] + arg)>0 ) {
                        me->start_more(color_filter(read_file(efun_search[i] + arg)));
                        return 1;
                }
        }

// 武功帮助文件
        sscanf(arg, "%s.%s", arg, str);
        if( file_size(SKILL_D(arg)+".c") < 1 )
                return notify_fail("没有针对这项主题的说明文件。\n");

// 武功绝招帮助文件
        if( stringp(str) )
        {
                string exert;

                if( stringp(exert = SKILL_D(arg)->exert_function_file(str)) &&
                        file_size(exert +".c") > 0)
                {
                        notify_fail("对不起，"+to_chinese(arg)+"内功方面的「"+str+"」功能没有详细的说明。\n");
                        return exert->help(me);
                }
                else
                if( stringp(exert = SKILL_D(arg)->perform_action_file(str)) &&
                        file_size(exert +".c") > 0)
                {
                        notify_fail("对不起，"+to_chinese(arg)+"外功方面的「"+str+"」功能没有详细的说明。\n");
                        return exert->help(me);
                }
                return notify_fail("对不起，"+to_chinese(arg)+"没有「"+str+"」这项功能。\n");
        }
        if( !SKILL_D(arg)->help(me) )
        {
                write(HIY"\n指定武技没有详细帮助说明。\n"NOR);
        }
        return notify_fail("没有针对这项主题的说明文件。\n");
}

int help(object me)
{
        write(@HELP
指令格式：help <主题>              例如：> help cmds
          help <函数名称>()        例如：> help call_out()

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。
玩家如果需要查看所在地的地图，可以尝试help here。 如果能搜索到地图，将
显示该玩家所在房间所属区域的地图。如果该房间在地图中有标记，则会自动将
其闪烁显示。
HELP
        );
        return 1;
}

