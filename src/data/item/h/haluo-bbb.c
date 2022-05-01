// ITEM Made by player(肯克哈洛:haluo) /data/item/h/haluo-bbb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jan  6 22:56:56 2019
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m吴钩[1;34m霜雪[1;35m明[2;37;0m", ({ "bbb" }));
	set_weight(20000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;35m无名之物[2;37;0m炼制而成的一件战衣。
");
	set("makeinfo", "[1;31m
肯克哈洛(haluo)[1;31m 出品
[2;37;0m");
	set("value", 35820000);
	set("point", 1786);
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
