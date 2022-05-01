// jumang.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(RED"赤冠巨蟒"NOR, ({ "ju man", "snake" }) );
        set("race", "爬蛇");
        set("age", 20);
        set("long", "一只庞然大物，它眼中喷火，朱冠厉齿，忠心守卫这个果园，
好象要一口把你吞下。\n");
        set("attitude", "aggressive");
        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 500);
        set("max_jing", 500);
        set("str", 86);
        set("cor", 80);
        set("combat_exp", 1000000);
        set_temp("apply/attack", 85);
        set_temp("apply/damage", 80);
        set_temp("apply/armor", 88);
        set_temp("apply/defence",80);

        setup();
}

int hit_ob(object me, object ob, int damage)
{
        if( random(damage)>query_temp("apply/armor", ob) && 
                (int)ob->query_condition("snake_poison") < 10 )
        {
                ob->apply_condition("snake_poison", 40);
                tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
        }
}