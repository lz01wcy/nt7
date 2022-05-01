// ownsword.c 宝剑
#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit SWORD;

void create()
{
        int i;
        object me = this_player();
        i=me->query_skill("sword", 1)/2+20;
        if (i>=120)
        i=120;
        set_name("剑", ({ "ownsword" }));
        set_weight(5000);
        set("no_drop","剑在人在,剑亡人亡！\n\n");
        set("no_get",1);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "口");
                set("long", "一代名铸剑师欧冶子亲手为你锻铸的宝剑。\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一口$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(i);
        setup();
}

void init()
{
        add_action("do_put","put");
}

int do_put(string arg)
{
        object me = this_player();
        if(arg!="ownsword in corpse")
        return 0;
        else
        {
            tell_object(me,"剑在人在,剑亡人亡！你不想活了？\n");
       }
}

void owner_is_killed()
{
        object me = this_player();
        write(HIY"只见眼前金光一闪...好象是.....\n"NOR);
        write("人在剑在,人亡剑亡。\n");
        query_temp("done_s", me);
        delete_temp("done_s", me);
        destruct(this_object());
}

string query_autoload()
{
        object *list, me;
        string target,swordname;
        int i;
        list = all_inventory(this_player());
        i = sizeof(list);
        while (i--) {
              if( (query("id", list[i])) == "ownsword" )
                swordname=query("name", list[i]);
        }

//        sscanf(swordname,"%s",target);
//        return target;
        return swordname;
}
void autoload(string arg)
{
        object me = this_player();
        query_temp("done_s", me);
        set_temp("done_s", 1, me);
        set("name",arg);
}