// ITEM Made by player(魔虎:uuu) /data/item/u/uuu-uuui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 18 23:10:22 2019
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m虎王披风[2;37;0m", ({ "uuui" }));
	set_weight(1000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;35m无名之物[2;37;0m炼制而成的一件披风。
");
	set("makeinfo", "[1;31m
魔虎(uuu)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 750);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 5);
	set("wear_msg", "[33m$N[33m装备[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/avoid_blind", 1.500000);
	set("armor_prop/reduce_busy", 2.500000);
	set("armor_prop/learn_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }