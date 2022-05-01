// yaogu-xinfa.c 药谷心法

inherit FORCE;

int valid_enable(string usage)
{
            return usage == "force";
}

int valid_force(string force)
{
        return force == "shennong-xinjing" ||
               force == "yaogu-xinfa" ||
               force == "lengyue-shengong" ||
               force == "hujia-neigong" ||
               force == "danyang-tunafa" ||
               force == "miaojia-neigong" ;
}

int valid_learn(object me)
{
            return ::valid_learn(me);
}

int practice_skill(object me)
{
            return notify_fail("药谷心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
            return __DIR__"yaogu-xinfa/" + func;
}