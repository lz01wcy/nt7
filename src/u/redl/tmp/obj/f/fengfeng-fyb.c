// ITEM Made by player(风风:fengfeng) /data/item/f/fengfeng-fyb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct  4 11:26:42 2014
#include <ansi.h>
#include <armor.h>

inherit FINGER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[41;1m[1;33m福源指套[2;37;0m", ({ "fyb" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
");
	set("makeinfo", "[1;31m
风风(fengfeng)[1;31m 出品
[2;37;0m");
	set("value", 2100000);
	set("point", 500);
	set("max_consistence", 100);
	set("material", "magic stone");
	set("material_file", "/d/item/obj/butian");
	set("quality_level", 5);
	set("wear_msg", "[33m$N[33m装备[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/kar", 3);
	set("armor_prop/double_damage", 2.000000);
	set("armor_prop/leech_neili", 2.000000);

	setup();
}

string long() { return short() + query("makeinfo") + query("long") + item_long(); }
