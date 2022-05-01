// ITEM Made by player(文哥:code) /data/item/c/code-ggg.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jan  6 08:26:37 2019
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m烈焰[2;37;0m", ({ "ggg" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m无名之物[2;37;0m炼制而成的一顶头盔。
");
	set("makeinfo", "[1;31m
文哥(code)[1;31m 出品
[2;37;0m");
	set("value", 35720000);
	set("point", 890);
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