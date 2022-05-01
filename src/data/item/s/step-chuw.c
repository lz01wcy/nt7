// ITEM Made by player(泡泡:step) /data/item/s/step-chuw.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Feb 10 16:52:53 2019
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("我的护手[2;37;0m", ({ "chuw" }));
	set_weight(400);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m无名之物[2;37;0m炼制而成的一双护手。
");
	set("makeinfo", "[1;31m
泡泡(step)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 1500);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 2);
	set("wear_msg", "[33m$N[33m装备[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }
