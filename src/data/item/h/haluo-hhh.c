// ITEM Made by player(肯克哈洛:haluo) /data/item/h/haluo-hhh.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jan  7 21:48:15 2019
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m深藏[1;33m身与[1;35m名[2;37;0m", ({ "hhh" }));
	set_weight(8000);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;35m无名之物[2;37;0m炼制而成的一条腰带。
");
	set("makeinfo", "[1;31m
肯克哈洛(haluo)[1;31m 出品
[2;37;0m");
	set("value", 34640000);
	set("point", 690);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 2);
	set("wear_msg", "[33m$N[33m装备[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }
