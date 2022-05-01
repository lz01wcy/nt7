// this file does nothing if no shell's enabled.
// dual.c

int help(object me);

int main(object me, string arg)
{
        int flag;
        
        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if( !me->is_admin() )
                return notify_fail("你不能使用该命令。\n"); 

        if (! arg) return help(me);

        flag=query("env/dual_type", me);

        if (flag)
                return (int)me->evaluate_shell(arg, flag);

        printf("%O\n", me->evaluate_shell(arg, 0));

        return 1;

}

int help(object me)
{
        write(@HELP
指令格式 : dual [detail]

这个指令可以执行一段单独的LPC代码。
可以使用var命令定义的私有变量。

如果该段代码没有返回值，或者需要使用一个组合的代码段。
必须设置环境变量 dual_type

与Unix相同，您也可以使用 ` 符号的内嵌命令格式，
（需要设置 use_shell 环境变量）
但是该代码必须有返回值。
例如 chat I am `me->short()`, at `here->query("short")`
会先计算出 me->short() 和 here->query("short") 的值，然后再替换命令。
又： `here->query("exits")[random(sizeof(here->query("exits")))]`
会随机的选择当前房间的一个出口行走。

HELP
        );
        return 1;
}

