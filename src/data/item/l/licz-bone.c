// ITEM Made by player(王五:licz) /data/item/l/licz-bone.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan  8 15:07:15 2019
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m可怜河边骨[2;37;0m", ({ "bone" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m无名之物[2;37;0m炼制而成的一柄剑。
");
	set("makeinfo", "[1;31m
王五(licz)[1;31m 出品
[2;37;0m");
	set("value", 35600000);
	set("point", 1775);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 2);
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if( !check_clone() ) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }
