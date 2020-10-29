// analectad.c
// Created by jjgod for hell. 2002/01/27.
// Optimized by jjgod. 2002/12/14.
// Optimized by jjgod. 2003/01/01.

// #pragma optimize
// #pragma save_binary

#include <ansi.h>
#include <mudlib.h>
#include <localtime.h>
#include <analecta.h>

nosave  mapping analecta_list;                                  // 文选列表

private void    collect_all_analecta();                         // 收集所有文选信息
private mapping parse_analecta(string file_name);               // 解析文选头信息
public  mapping query_analecta_list();                          // 查询文选列表
public  int     add_analecta(int year, mapping analecta);       // 添加一篇文选
public  int     delete_analecta(int year, int number);          // 删除一篇文选

void create()
{
        seteuid(ROOT_UID);

        CHANNEL_D->channel_broadcast("sys", "文选系统已经启动。");
        analecta_list = ([ ]);
        collect_all_analecta();
}

// 查询文选列表
mapping query_analecta_list()
{
        return analecta_list;
}

string *query_year_analecta(int year)
{
        string y;

        y = sprintf("%d", year);

        if (undefinedp(analecta_list[y]))
                return 0;
        return analecta_list[y];
}

// ANALECTA_D 启动收集所有的文选
void collect_all_analecta()
{
        string year, dir, file;
        string *analecta_year, *files;

        CHANNEL_D->channel_broadcast("sys", "正在收集文选信息。");

        analecta_year = get_dir(ANALECTA_DIR);

        if (! arrayp(analecta_year) || ! sizeof(analecta_year))
        {
                CHANNEL_D->channel_broadcast("sys", "无任何文选信息。");
                return;
        }

        foreach (year in analecta_year)
        {
                dir = ANALECTA_DIR + year + "/";

                if (file_size(dir) != -2)
                        continue;

                analecta_list[year] = ({ });
                files = get_dir(dir);

                if (! arrayp(files) || ! sizeof(files))
                        continue;

                foreach(file in files)
                {
                        reset_eval_cost();
                        if (file_size(dir + file) <= 0)
                                continue;
                        analecta_list[year] += ({ parse_analecta(dir + file) });
                }
        }
        CHANNEL_D->channel_broadcast("sys", "文选信息收集完成。");
}

// 解析文选头信息

// 格式示例：
// subject : 测试文选                      -> 文选标题
// author_name : 阿福                      -> 文选作者
// author_id : jjgod                       -> 文选作者ID
// time : 1012137565                       -> 创作时间
// board : 客店留言板                      -> 发表地点
// file : /data/analecta/2002/10000000.txt -> 保存文件
// add_time : 1012137565                   -> 添加时间
// content :
// 这里是内容。                            -> 文选内容
mapping parse_analecta(string file_name)
{
        mapping data;
        int len, start, i, n;
        string info;
        string *lines;
        mixed sub_info;

        info = read_file(file_name, 1, HEAD_LINES);
        if (! stringp(info))
                return ([ ]);

        info = replace_string(info, "\r", "");
        lines = explode(info, "\n");

        data = ([ "subject"     : "无题",
                  "author_name" : "无名",
                  "author_id"   : "NULL_ID",
                  "time"        : 0,
                  "board"       : "未知留言版",
                  "file"        : "未知文件",
                  "add_time"    : 0,
                  "lines"       : 0, ]);

        n = sizeof(lines);
        for (i = 0; i < n; i++)
        {
                // 分成 '项目 ' 和 ' 内容' 两部分
                sub_info = explode(lines[i], ":");

                // 若无法解析
                if (sizeof(sub_info) < 2)
                        sub_info += ({ "" });

                // 去掉项目名前后的空格
                len = strlen(sub_info[0]);
                start = 0;

                while (start < len && sub_info[0][start] == ' ')
                        start++;
                while (len-- && sub_info[0][len] == ' ');

                sub_info[0] = sub_info[0][start..len];

                // 去掉项目内容前后的空格
                if (sizeof(sub_info) > 1)
                {
                        len = strlen(sub_info[1]);
                        start = 0;

                        while (start < len && sub_info[1][start] == ' ')
                                start++;
                        while (len-- && sub_info[1][len] == ' ');

                        sub_info[1] = sub_info[1][start..len];
                }

                // 若此行开始为文章内容，则停止解析
                if (sub_info[0] == "content")
                        break;
                else
                {
                        if (undefinedp(data[sub_info[0]]))
                                continue;
                        // 若此项内容应为数字
                        if (intp(data[sub_info[0]]))
                                sub_info = ({ sub_info[0], atoi(sub_info[1]) });
                        // 最后以实际信息替换掉缺省的信息
                        data[sub_info[0]] = sub_info[1];
                }
        }

        data["file"] = file_name;
        data["lines"] = file_lines(file_name);
        return data;
}

// 添加一篇文选，以一随机八位数字为文件名
int add_analecta(int year, mapping analecta)
{
        int i;
        string file, info;
        int add_time;

        // 生成一个随机文件名
        i = random(99999999 - 10000000 + 1) + 10000000;
        file = ANALECTA_DIR + year + "/" + i + ".txt";

        assure_file(file);
        if (file_size(file) > 0)
                return add_analecta(year, analecta);

        add_time = time();
        info = sprintf("subject : %s\n"
                       "author_name : %s\n"
                       "author_id : %s\n"
                       "time : %d\n"
                       "board : %s\n"
                       "file : %s\n"
                       "add_time : %d\n"
                       "content :\n%s",
                       analecta["subject"], analecta["author_name"],
                       analecta["author_id"], analecta["time"],
                       analecta["board"], file,
                       add_time, analecta["content"]);

        analecta["file"] = file;
        analecta["add_time"] = add_time;

        write_file(file, info, 1);
        analecta["lines"] = file_lines(file);

        // 清除 content 信息，以免占用过多内存
        map_delete(analecta, "content");
        if (undefinedp(analecta_list[sprintf("%d", year)]))
                analecta_list[sprintf("%d", year)] = ({ analecta });
        else analecta_list[sprintf("%d", year)] += ({ analecta });
        return 1;
}

// 删除一篇文选
int delete_analecta(int year, int number)
{
        mapping *analecta;

        if (! arrayp(analecta = analecta_list[sprintf("%d", year)]) ||
            ! sizeof(analecta))
                return 0;

        if (sizeof(analecta) < number)
                return 0;

        if (number < 1)
                return 0;

        // 因为是按照时间排列的顺序指出的序号，
        // 所以删除的时候也要按照这个序号查找
        analecta = sort_array(analecta, (: sort_analectas :));

        number--;
        rm(analecta[number]["file"]);

        if (number == 0)
                analecta = ({ });

        analecta = analecta[0..number - 1] + analecta[number + 1..<1];
        analecta_list[sprintf("%d", year)] = analecta;

        return 1;
}

// 清除一年的文选列表
int clear_analecta_list(int year)
{
        if (undefinedp(analecta_list[sprintf("%d", year)]))
                return 0;

        map_delete(analecta_list, sprintf("%d", year));
        return 1;
}

// 提示用户
void prompt_user(object me)
{
        int num;
        int total;
        int year;
        mapping *analectas;
        int last_read_time;

        /*
        if (! VERSION_D->is_release_server())
                return;
        */

        year = localtime(time())[LT_YEAR];
        if( !sizeof(query("analecta_last_read", me)) )
        {
                tell_object(me, HIM "欢迎您进入" + LOCAL_MUD_NAME() + "，今后请使用" HIY " wenxuan " HIM
                                "命令查阅游戏的文章选集。\n" NOR);

                set("analecta_last_read/"+year, time(), me);
                return;
        }

        last_read_time=query("analecta_last_read/"+year, me);

        analectas = analecta_list[sprintf("%d", year)];

        if (! arrayp(analectas) || ! sizeof(analectas)) {
                tell_object(me, HIM "你目前没有未曾阅读过的文章选集。\n" NOR);
                return;
        }

        num = sizeof(analectas);
        total = 0;
        while (num--)
                if (analectas[num]["add_time"] > last_read_time)
                        total++;
                else
                        break;

        if (total)
                tell_object(me, sprintf(WHT "你目前一共有 " HIY "%d" NOR
                                        WHT " 篇文选还没有阅读，请使用 "
                                        HIY "wenxuan" NOR WHT " 命令阅读。\n" NOR, total));
        else
                tell_object(me, HIM "你目前没有未曾阅读过的文章选集。\n" NOR);
}

string query_name()
{
        return "文选精灵(ANALECTA_D)";
}