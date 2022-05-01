// skill.c
// Rewritten by Lonely@XYZX (16/05/2009)

// #pragma save_binary
#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;
mapping skill_prepare;
mapping wprepare;

mapping query_SKILL()
{
        mapping data = ([]);
        data["skills"] = skills;
        data["learned"] = learned;
        data["skill_map"] = skill_map;
        data["skill_prepare"] = skill_prepare;
        data["wprepare"] = wprepare;
        return data;
}

int set_SKILL(mapping data)
{
        if( !mapp(data) ) return 0;
        skills = data["skills"];
        learned = data["learned"];
        skill_map = data["skill_map"];
        skill_prepare = data["skill_prepare"];
        wprepare = data["wprepare"];
        return 1;
}

mapping query_skillc() { return skills; }
mapping query_skills()
{
        int i, n, l;
        mapping askills;
        string *sk;

        n = this_object()->query_all_buff("add_skill");
        if( !n ) return skills;

        askills = ([]);
        if( mapp(skills) )
                sk = keys(skills);
        if( arrayp(sk) && sizeof(sk) ) {
                for( i = 0; i<sizeof(sk); i++ ) {
                        l = skills[sk[i]] + n;
                        askills += ([ sk[i] : l ]);
                }
        }
        return askills;
}

mapping query_learned() { return learned; }
varargs void map_skill(string skill, string mapped_to);

string *query_skills_name()
{
        if( mapp(skills) )
                return keys(skills);
        else
                return 0;
}

void set_skill(string skill, int val)
{
        object ob, me, pob;

        if( !find_object(SKILL_D(skill)) &&
            !load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        me = this_player();
        ob = this_object();
        pob= previous_object();

        if( ob && userp(ob) && objectp(me) && objectp(pob) &&
            base_name(pob) != "/cmds/skill/abandon" &&
            base_name(pob) != "/cmds/skill/study" &&
            base_name(pob) != "/cmds/skill/learn" &&
            base_name(pob) != "/adm/daemons/mygiftd" )
                log_file("static/setskill",
                        sprintf("%s setskill %s %s to level %d use %s at %s.\n",
                                me->query_idname(), ob->query_idname(), skill, val, base_name(pob), ctime(time())) );

        if( !mapp(skills) ) skills = ([ skill: val ]);
        else skills[skill] = val;
}

void add_skill(string skill, int val)
{
        if( !find_object(SKILL_D(skill)) &&
            !load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) ) skills = ([ skill: val ]);
        else {
                if( undefinedp(skills[skill]) )
                        skills[skill] = val;
                else
                        skills[skill] += val;
        }
}

int delete_skill(string skill)
{
        int i;
        string *sk;

        if( mapp(skill_map) ) {
                map_delete(skill_map, skill);
                sk = keys(skill_map);
                for( i = 0; i < sizeof(sk); i++ ) {
                        if( skill_map[sk[i]] == skill )
                                map_skill(sk[i], 0);
                }
        }
        if( mapp(skills) ) {
                map_delete(skills, skill);
                if( mapp(learned) ) {
                        map_delete(learned, skill);
                        return undefinedp(learned[skill]);
                }
                return undefinedp(skills[skill]);
        }
        return 0;
}

varargs int delete_learn(string skill)
{
        if( !stringp(skill) ) {
                learned = ([]);
                return 1;
        }
        if( mapp(learned) ) {
                map_delete(learned, skill);
                return undefinedp(learned[skill]);
        }
        return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
        if( !mapped_to && mapp(skill_map) ) {
                if(  skill_prepare ) map_delete(skill_prepare, skill);
                map_delete(skill_map, skill);
                // check skill mix effect
                SKILLS_D->check_skillmix(this_object(), 1);

                return;
        }

        if( !find_object(SKILL_D(skill)) &&
            !load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) || undefinedp(skills[mapped_to]) )
                return;

        if( skill_prepare ) map_delete(skill_prepare, skill);
        if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
        else skill_map[skill] = mapped_to;

        SKILLS_D->check_skillmix(this_object(), 2);
}

// This function 'prepare' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the prepared skill <skill>.
varargs void prepare_skill(string skill, string mapped_to)
{
        if( !mapped_to && mapp(skill_prepare) ) {
                map_delete(skill_prepare, skill);
                return;
        }
        if( !find_object(SKILL_D(skill)) &&
            !load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");
        if( !mapp(skills) || undefinedp(skills[mapped_to]) )
                return;
        if( !mapp(skill_prepare) ) skill_prepare = ([ skill: mapped_to ]);
        else skill_prepare[skill] = mapped_to;
}

varargs void prepare_wskill(string skill, string mapped_to)
{
        if( !mapped_to && mapp(wprepare) ) {
                map_delete(wprepare, skill);
                return;
        }

        if( !find_object(SKILL_D(skill)) &&
            !load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) || undefinedp(skills[mapped_to]) )
                return;

        if( !mapp(wprepare) ) wprepare = ([ skill: mapped_to ]);
        else wprepare[skill] = mapped_to;
}


string query_skill_mapped(string skill)
{
        if( mapp(skill_map ) && !undefinedp(skill_map[skill]))
                return skill_map[skill];
        return 0;
}

string query_skill_prepared(string skill)
{
        if( mapp(skill_prepare) && !undefinedp(skill_prepare[skill]) )
                return skill_prepare[skill];
        return 0;
}

string query_wprepared(string skill)
{
        if( mapp(wprepare) && !undefinedp(wprepare[skill]) )
                return wprepare[skill];
        return 0;
}

varargs int query_skillo(string skill, int raw)
{
        if( !raw ) {
                int n;

                n = this_object()->query_all_buff(skill);
                if( mapp(skills) ) {
                        n += skills[skill] / 2;
                        if( mapp(skill_map))
                                n += skills[skill_map[skill]];
                }
                return n;
        }
        if( mapp(skills) && !undefinedp(skills[skill]) ) {
                return skills[skill];
        }
        return 0;
}

varargs int query_skill(string skill, int raw)
{
        int n, l;

        if( !raw ){
                l = this_object()->query_all_buff(skill);
                n = this_object()->query_all_buff("add_skill");
                if( mapp(skills))
                {
                        l += (n + skills[skill]) / 2;
                        if( mapp(skill_map))
                                l += (n + skills[skill_map[skill]]);
                }
                return l;
        }
        if( mapp(skills) && !undefinedp(skills[skill]) ) {
                l = skills[skill];
                l += this_object()->query_all_buff("add_skill");
                return l;
        }
        return 0;
}

mapping query_skill_map()
{
        return skill_map;
}

mapping query_skill_prepare()
{
        return skill_prepare;
}

mapping query_wprepare()
{
        return wprepare;
}

int skill_death_penalty()
{
        string *sk;
        int i;

        if( wizardp(this_object()) || !mapp(skills) ) return 0;

        sk = keys(skills);
        if( !mapp(learned) ) {
                for( i = 0; i<sizeof(sk); i++ ) {
                        // 门派技能不丢失
                        if( SKILL_D(sk[i])->is_fmsk() ) continue;
                        skills[sk[i]]--;
                        if( skills[sk[i]] < 1) map_delete(skills, sk[i]);
                }
        } else {
                for( i = 0; i<sizeof(sk); i++ ) {
                        // 门派技能不丢失
                        if( SKILL_D(sk[i])->is_fmsk() ) continue;
                        if( (int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2 )
                                map_delete(learned, sk[i]);
                        else {
                                skills[sk[i]]--;
                                if( skills[sk[i]] < 0 ) map_delete(skills, sk[i]);
                        }
                }
        }

        //skill_map = 0;
        //skill_prepare = 0;
        SKILLS_D->check_skillmix(this_object(), 0);

        return 1;
}

int skill_expell_penalty()
{
        int i;
        string *skname;
        int tsl = query("skill_expell_penalty_tsl");

        if( !mapp(skills) ) return 1;

        skname = keys(skills);
        for( i = 0; i < sizeof(skname); i++ ) {
                if( file_size(SKILL_D(skname[i]) + ".c") < 0 ) {
                        delete_skill(skname[i]);
                        continue;
                }

                // 自创的武功不降低
                if( SKILL_D(skname[i])->is_invent_skill() )
                        continue;

                if( SKILL_D(skname[i])->is_fmsk() )
                {
                        delete_skill(skname[i]);
                        continue;
                }

                if( !tsl && SKILL_D(skname[i])->is_spsk() )
                {
                        delete_skill(skname[i]);
                        continue;
                }

                if( tsl && SKILL_D(skname[i])->is_pbsk() )
                        continue;

                if( SKILL_D(skname[i])->is_ultimate_skill() )
                        continue;

                if( SKILL_D(skname[i])->type() != "martial" ||
                    skname[i] == "martial-cognize" )
                        continue;

                if( SKILL_D(skname[i])->valid_enable("parry") ||
                    SKILL_D(skname[i])->valid_enable("dodge") ||
                    SKILL_D(skname[i])->valid_enable("poison") ||
                    SKILL_D(skname[i])->valid_enable("throwing") ||
                    SKILL_D(skname[i])->valid_enable("force") ) {
                        delete("can_perform/"+skname[i]);
                        delete("can_exert/"+skname[i]);
                        delete_skill(skname[i]);
                        continue;
                }

                if( !tsl && (query_skillo(skname[i], 1) >= 100) )
                        set_skill(skname[i], 100);
        }

        if( tsl ) {
                addn("skill_expell_penalty_tsl", -1);
                tell_object(this_object(), HIY "你使用了一次无损脱师机会。\n" NOR);
        }
        skill_map = 0;
        skill_prepare = 0;
        SKILLS_D->check_skillmix(this_object(), 0);
}

int can_improve_skill(string skill)
{
        int lvl;
        mixed exp;

        if( !find_object(SKILL_D(skill)) &&
            !load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        switch( SKILL_D(skill)->type() ) {
        case "knowledge":
                // 知识类技能
                return 1;

        case "technic":
                // 技术类技能
                return 1;

        case "martial":
        case "poison":
                lvl = query_skillo(skill, 1);
                exp = query("combat_exp");
                if( lvl * lvl * lvl / 10 > exp )
                        return 0;
                return 1;

        default:
                return 1;
        }
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
        int spi;
        int lvl;
        int mlvl;
        int flag;
        int lucky;
        string type;

        if( !find_object(SKILL_D(skill)) &&
            !load_object(SKILL_D(skill)) )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) ) skills = ([]);
        if( undefinedp(skills[skill]) ) skills[skill] = 0;

        type = SKILL_D(skill)->type();
        switch( type ) {
        case "martial":
                if( intp(mlvl = skills["martial-cognize"]) &&
                    skill != "martial-cognize" )
                        // martial-cognize does extra bonus for martial skills
                        amount += amount * mlvl / 500;
                break;

        case "knowledge":
                if( intp(mlvl = skills["culture-cognize"]) &&
                    skill != "culture-cognize" )
                        // culture-cognize does extra bonus for culture skills
                        amount += amount * mlvl / 500;
                break;

        case "technic":
                if( intp(mlvl = skills["technic-cognize"]) &&
                    skill != "technic-cognize" )
                        // culture-cognize does extra bonus for culture skills
                        amount += amount * mlvl / 500;
                break;
        }

        // adjust the point improved
        lvl = skills[skill];
        amount = 1 + amount * 100 / (lvl + 100);

        if( !mapp(learned) ) learned = ([ skill : amount ]);
        else (int)learned[skill] += amount;

        /*
        if( (!weak_mode || !userp(this_object())) &&
            learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
                skills[skill]++;
                learned[skill] = 0;
                tell_object(this_object(), HIC "你的「" + to_chinese(skill) +
                            "」进步了！\n" NOR);
                SKILL_D(skill)->skill_improved(this_object());
                SKILLS_D->skill_summary(this_object(),skill,skills[skill]);
        }
        */
        if( !weak_mode || !userp(this_object()) ) {
                flag = 0;
                if( this_object()->query_all_buff("lucky2016") &&
                    (this_object()->query_viplevel() > 7 || random(100) > 96) ) lucky = 1;

                while( learned[skill]
                &&      learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
                        skills[skill]++;
                        learned[skill] -= skills[skill] * skills[skill];
                        if( flag++ < 10 )
                        tell_object(this_object(), HIC "你的「" + to_chinese(skill) +
                                    "」进步了！\n" NOR);
                        SKILL_D(skill)->skill_improved(this_object());
                        SKILLS_D->skill_summary(this_object(),skill,skills[skill]);
                        if( flag >= 1000 && !lucky ) { learned[skill] = 0; break; }
                }
        }
}

void delete_all_skills()
{
        skills = allocate_mapping(0);
        learned = allocate_mapping(0);
        wprepare = allocate_mapping(0);
        skill_map = allocate_mapping(0);
        skill_prepare = allocate_mapping(0);
}
