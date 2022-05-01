// ITEM Made by player(小球球:ovo) /data/item/o/ovo-nle.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr  4 21:39:12 2019
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m内内护腕[2;37;0m", ({ "nle" }));
	set_weight(5000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;37m寰宇天晶[2;37;0m炼制而成的一对护腕。
");
	set("makeinfo", "[1;31m
小球球(ovo)[1;31m 出品
[2;37;0m");
	set("value", 4100000);
	set("point", 111);
	set("max_consistence", 100);
	set("material", "tian jing");
	set("material_file", "/clone/goods/tianjing");
	set("quality_level", 3);
	set("wear_msg", "[33m$N[33m装备[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/practice_times", 15);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }
