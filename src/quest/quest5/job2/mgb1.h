void init()
{
        ::init();
        add_action("do_kill","kill");
        add_action("do_kill","hit");    
}

int do_kill(string arg)
{
        object who = this_player();
        object me = this_object();
        
        if(!arg || present(arg,environment(me))!=me) return 0;
        if( !(query("ygjg", me)) )
            return 1;
        if( query("ygjg", me) != who )
                return notify_fail(CYN"你还是各司其职，专心对付你的"HIR"蒙古兵"CYN"吧。\n"NOR);
                message_vision(CYN"$N加油！$N加油！\n"NOR,who);
        return 1;
} 