// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Life.h"
#include <fstream> //ifstream

using namespace std;
using std::ifstream;

// ----
// test
// ----

/////////////////////////////////////////////////////////--Conway Cell--///////////////////////////////////

//DefulatConstruct
TEST(LifeFixture, ConwayDefaultConstruct_1)
{
	Conway_cell cc;
}

TEST(LifeFixture, ConwayDefaultConstruct_2)
{
	Conway_cell cc;
	Conway_cell cc1;
}

TEST(LifeFixture, ConwayDefaultConstruct_3)
{
	Conway_cell cc;
	Conway_cell cc1;
	Conway_cell cc2;
}

//ConwayCellCopyConstruct
TEST(LifeFixture, copy_construct_Conway_cell_1)
{
	Conway_cell cc;
	Conway_cell cc2(cc);
}


TEST(LifeFixture, copy_construct_Conway_cell_2)
{
	Conway_cell cc;
	Conway_cell cc3;
	Conway_cell cc4(cc3);
	Conway_cell cc2(cc);
}

TEST(LifeFixture, copy_construct_Conway_cell_3)
{
	Conway_cell cc;
	Conway_cell cc2;
	Conway_cell cc3;
	Conway_cell cc_1(cc);
	Conway_cell cc_2(cc2);
	Conway_cell cc_3(cc3);
}


//PrintSelfFunction
TEST(LifeFixture, Conway_cell_print_self_1) {
	Conway_cell cc;
	Abstract_cell* ac_ptr = &cc;

	ac_ptr->print_self();

	ASSERT_TRUE(true);
	}

	TEST(LifeFixture, Conway_cell_print_self_2) {
		Conway_cell cc;
		Abstract_cell* ac_ptr = &cc;
		pair<int,int> p1 = {3,3};
		ac_ptr->update_status(p1);
		ac_ptr->print_self();

		ASSERT_TRUE(true);
	}

	TEST(LifeFixture, Conway_cell_print_self_3) {
		Conway_cell cc;
		Conway_cell cc1;

		Abstract_cell* ac_ptr = &cc;
		Abstract_cell* ac_ptr2= &cc1;

		pair<int,int> p1 = {3,3};
		ac_ptr->update_status(p1);
		ac_ptr->print_self();

		pair<int,int> p2 = {0,0};
		ac_ptr2->update_status(p2);
		ac_ptr2->print_self();

		ASSERT_TRUE(true);
	}

//UpdateStatusFunction
TEST(LifeFixture, Conway_cell_update_status_1)
{
	Conway_cell cc;
	Abstract_cell* ac_ptr = &cc;
	ac_ptr->set_is_alive()= false;
	const pair<int,int> all_cross_neighbors(3,-1);
	ac_ptr->update_status(all_cross_neighbors);
	ASSERT_TRUE(ac_ptr->get_is_alive());

}

TEST(LifeFixture, Conway_cell_update_status_2)
{
	Conway_cell cc;
	Abstract_cell* ac_ptr = &cc;
	ac_ptr->set_is_alive()= false;
	ASSERT_TRUE(!ac_ptr->get_is_alive());

}

TEST(LifeFixture, Conway_cell_update_status_3)
{
	Conway_cell cc;
	Abstract_cell* ac_ptr = &cc;
	ac_ptr->set_is_alive()= false;
	const pair<int,int> all_cross_neighbors(1,-1);
	ac_ptr->update_status(all_cross_neighbors);
	ASSERT_TRUE(!ac_ptr->get_is_alive());
}

//Clone
TEST(LifeFixture, clone_Conway_cell_1)
{
	Conway_cell cc;
	Conway_cell *cc_clone_ptr = dynamic_cast<Conway_cell*>(cc.clone());
	delete cc_clone_ptr;
}

TEST(LifeFixture, clone_Conway_cell_2)
{
	Conway_cell cc;
	Conway_cell *cc_clone_ptr = dynamic_cast<Conway_cell*>(cc.clone());
	delete cc_clone_ptr;
}

TEST(LifeFixture, clone_Conway_cell_3)
{
	Conway_cell cc;
	Conway_cell *cc_clone_ptr = dynamic_cast<Conway_cell*>(cc.clone());
	delete cc_clone_ptr;
}

//Time To Mutate
TEST(LifeFixture, time_to_mutate_1)
{
	Conway_cell cc;
	Conway_cell *cc_ptr = dynamic_cast<Conway_cell*>(cc.clone());
	bool mutated = cc_ptr->time_to_mutate();
	delete cc_ptr;
	ASSERT_TRUE(!mutated);
}

TEST(LifeFixture, time_to_mutate_2)
{
	Conway_cell cc;
	Conway_cell *cc_ptr = dynamic_cast<Conway_cell*>(cc.clone());
	bool mutated = cc_ptr->time_to_mutate();
	delete cc_ptr;
	ASSERT_FALSE(mutated);
}

TEST(LifeFixture, time_to_mutate_3)
{
	Conway_cell cc;
	Abstract_cell* abs = cc.clone();
	Conway_cell *cc_ptr = dynamic_cast<Conway_cell*>(abs);
	bool mutated = cc_ptr->time_to_mutate();
	delete cc_ptr;
	ASSERT_TRUE(!mutated);
}




/////////////////////////////////////////////////////////--Fredkin_cell--///////////////////////////////////


//FredkinDefaultConstruct
TEST(LifeFixture, FredkinDefaultContruct_1)
{
	Fredkin_cell fc;
}

TEST(LifeFixture, FredkinDefaultContruct_2)
{
	Fredkin_cell fc;
	Fredkin_cell fc1;
}

TEST(LifeFixture, FredkinDefaultContruct_3)
{
	Fredkin_cell fc;
	Fredkin_cell fc1;
	Fredkin_cell fc2;
}

//CopyConstructor
TEST(LifeFixture, copy_construct_Fredkin_cell_1)
{
	Fredkin_cell fc;
	Fredkin_cell fc2(fc);
}

TEST(LifeFixture, copy_construct_Fredkin_cell_2)
{
	Fredkin_cell fc;
	Fredkin_cell fc3;
	Fredkin_cell fc4(fc3);
	Fredkin_cell fc2(fc);
}

TEST(LifeFixture, copy_construct_Fredkin_cell_3)
{
	Fredkin_cell fc;
	Fredkin_cell fc2;
	Fredkin_cell fc3;
	Fredkin_cell fc_1(fc);
	Fredkin_cell fc_2(fc2);
	Fredkin_cell fc_3(fc3);
}

//Clone
TEST(LifeFixture, clone_Fredkin_cell_1)
{
	Fredkin_cell fc;
	Fredkin_cell *fc_clone_ptr = dynamic_cast<Fredkin_cell*>(fc.clone());
	delete fc_clone_ptr;
}

TEST(LifeFixture, clone_Fredkin_cell_2)
{
	Fredkin_cell fc;
	Fredkin_cell *fc_clone_ptr = dynamic_cast<Fredkin_cell*>(fc.clone());
	delete fc_clone_ptr;
}

TEST(LifeFixture, clone_Fredkin_cell_3)
{
	Fredkin_cell fc;
	Fredkin_cell *fc_clone_ptr = dynamic_cast<Fredkin_cell*>(fc.clone());
	delete fc_clone_ptr;
}

//UpdateStatusFunction
TEST(LifeFixture, Fredkin_cell_Update_status_1)
{
	Fredkin_cell cc;
	Abstract_cell* ac_ptr = &cc;
	ac_ptr->set_is_alive()= false;
	const pair<int,int> all_cross_neighbors(3,3);
	ac_ptr->update_status(all_cross_neighbors);
	ASSERT_TRUE(ac_ptr->get_is_alive());

}

TEST(LifeFixture, Fredkin_cell_Update_status_2)
{
	Fredkin_cell cc;
	Abstract_cell* ac_ptr = &cc;
	ac_ptr->set_is_alive()= false;
	ASSERT_TRUE(!ac_ptr->get_is_alive());
}


TEST(LifeFixture, Fredkin_cell_Update_status_3)
{
	Fredkin_cell cc;
	Abstract_cell* ac_ptr = &cc;
	ac_ptr->set_is_alive()= false;
	const pair<int,int> all_cross_neighbors(1,-1);
	ac_ptr->update_status(all_cross_neighbors);
	ASSERT_TRUE(!ac_ptr->get_is_alive());
}

//Time To Mutate
TEST(LifeFixture, Fredkin_time_to_mutate_1)
{
	Fredkin_cell cc;
	Fredkin_cell *cc_ptr = dynamic_cast<Fredkin_cell*>(cc.clone());
	cc_ptr->set_age() = 2;
	bool mutated = cc_ptr->time_to_mutate();
	delete cc_ptr;
	ASSERT_TRUE(mutated);

}

TEST(LifeFixture, Fredkin_time_to_mutate_2)
{
	Fredkin_cell cc;
	Fredkin_cell *cc_ptr = dynamic_cast<Fredkin_cell*>(cc.clone());
	cc_ptr->set_age() = 0;
	bool mutated = cc_ptr->time_to_mutate();
	delete cc_ptr;
	ASSERT_TRUE(!mutated);
}

TEST(LifeFixture, Fredkin_time_to_mutate_3)
{
	Fredkin_cell cc;
	Abstract_cell* abs = cc.clone();
	Fredkin_cell *cc_ptr = dynamic_cast<Fredkin_cell*>(abs);
	cc_ptr->set_age() = 2;
	bool mutated = cc_ptr->time_to_mutate();
	delete cc_ptr;
	ASSERT_TRUE(mutated);
}


/////////////////////////////////////////////////////////--Abstract_cell--///////////////////////////////////

//Clone
TEST(LifeFixture, clone_Abstract_cell_1)
{
	Conway_cell cc;
	Abstract_cell *cc_clone_ptr = cc.clone();
	delete cc_clone_ptr;
}

TEST(LifeFixture, clone_Abstract_cell_2)
{
	Fredkin_cell fc;
	Abstract_cell* abs = fc.clone();
	Fredkin_cell *fc_clone_ptr = dynamic_cast<Fredkin_cell*>(abs);
	Abstract_cell* test = fc_clone_ptr;
	delete test;
}

TEST(LifeFixture, clone_Abstract_cell_3)
{
	Fredkin_cell cc;
	Abstract_cell *fc_clone_ptr = dynamic_cast<Fredkin_cell*>(cc.clone());
	delete fc_clone_ptr;
}

TEST(LifeFixture, Abstract_cell_become_alive_1)
{
	Conway_cell cc;
	cc.become_alive();
	ASSERT_TRUE(cc.get_is_alive());
}

TEST(LifeFixture, Abstract_cell_become_alive_2)
{
	Conway_cell cc;
	cc.become_alive();
	Conway_cell cc2 = cc;
	ASSERT_TRUE(cc2.get_is_alive());
}

TEST(LifeFixture, Abstract_cell_become_alive_3)
{
	Conway_cell cc;
	cc.become_alive();
	Conway_cell cc2;
	cc2 = cc;
	ASSERT_TRUE(cc2.get_is_alive());
}

TEST(LifeFixture, Abstract_cell_live_1)
{
	Conway_cell cc;
	cc.become_alive();
	ASSERT_TRUE(cc.live());
}

TEST(LifeFixture, Abstract_cell_live_2)
{
	Conway_cell cc;
	cc.become_alive();
	Conway_cell cc2 = cc;
	ASSERT_TRUE(cc2.live());
}

TEST(LifeFixture, Abstract_cell_live_3)
{
	Conway_cell cc;
	cc.become_alive();
	Conway_cell cc2;
	cc2 = cc;
	ASSERT_TRUE(cc2.live());
}

TEST(LifeFixture, Abstract_cell_print_self_1)
{
	Conway_cell c;
	c.print_self();
}

TEST(LifeFixture, Abstract_cell_print_self_2)
{
	Conway_cell c;
	c.print_self();
	Fredkin_cell fc;
	c.print_self();
}

TEST(LifeFixture, Abstract_cell_print_self_3)
{
	Fredkin_cell c;
	c.print_self();
}


//constructor
TEST(LifeFixture, Abstract_cell_construct_1)
{
	Fredkin_cell c;
	ASSERT_TRUE(!c.get_is_alive());
}

TEST(LifeFixture, Abstract_cell_construct_2)
{
	Conway_cell c;
	ASSERT_TRUE(!c.get_is_alive());
}

TEST(LifeFixture, Abstract_cell_construct_3)
{
	Fredkin_cell c;
	c.set_is_alive() = true;
	ASSERT_TRUE(c.get_is_alive());
}
/////////////////////////////////////////////////////////--Cell--/////////////////////////////////////////

//Default Constructor
TEST(LifeFixture, construct_cell_1)
{
	Cell c;

}

TEST(LifeFixture, construct_cell_2)
{
	Cell c;
	Cell c1;
	Cell c2;
}
TEST(LifeFixture, construct_cell_3)
{
	Cell c;
	Cell c1;
	Cell c2;
	Cell c3;
}

//Cell(Abstract_cell) Constructor
TEST(LifeFixture, abscell_construct_cell_1)
{
	Fredkin_cell fc;
	Cell c(fc);
}

TEST(LifeFixture, abscell_construct_cell_2)
{
	Conway_cell cc;
	Cell c(cc);
}

TEST(LifeFixture, abscell_construct_cell_3)
{
	Conway_cell cc;
	Fredkin_cell fc;
	Cell c(fc);
	Cell c_1(cc);
}

//Cell Copy Constructor
TEST(LifeFixture, copy_construct_1)
{
	Cell c;
	Cell c2(c);
}

TEST(LifeFixture, copy_construct_2)
{
	Cell c;
	Cell c1;
	Cell c_1(c);
	Cell c_2(c1);
}
TEST(LifeFixture, copy_construct_3)
{
	Cell c;
	Cell c1;
	Cell c3;
	Cell c_1(c);
	Cell c_2(c1);
	Cell c_3(c3);
}

//Cell Copy Assgnment
TEST(LifeFixture, copy_assignment_cell_1)
{
	Cell c;
	Cell c2;
	c = c2;
}

TEST(LifeFixture, copy_assignment_cell_2)
{
	Cell c;
	Cell c2;
	Cell c3;
	c = c2;
	c3 = c;

}

TEST(LifeFixture, copy_assignment_cell_3)
{
	Cell c;
	Cell c2;
	Cell c3;
	c3 = c2;
	c = c3;
	c2 = c3;

}


//Become_Alive
TEST(LifeFixture, cell_become_alive_1)
{
	Cell c;
	c.become_alive();

	ASSERT_TRUE(c.live());
}

TEST(LifeFixture, cell_become_alive_2)
{
	Cell c;
	Cell c2;
	c.become_alive();
	c2 = c;

	ASSERT_TRUE(c2.live());
}

TEST(LifeFixture, cell_become_alive_3)
{
	Cell c;
	c.become_alive();
	Cell c2 = c;

	ASSERT_TRUE(c2.live());
}

//Live
TEST(LifeFixture, cell_live_1)
{
	Cell c;
	ASSERT_FALSE(c.live());
}

TEST(LifeFixture, cell_live_2)
{
	Cell c;
	c.become_alive();
	ASSERT_TRUE(c.live());
}

TEST(LifeFixture, cell_live_3)
{
	Cell c;
	c.become_alive();
	c.update_status(pair<int,int>(0,0));
	ASSERT_FALSE(c.live());
}

//Print Self
TEST(LifeFixture, cell_print_self_1)
{
	Cell c;
	c.print_self();
}

TEST(LifeFixture, cell_print_self_2)
{
	Cell c;
	c.become_alive();
	c.print_self();
}

TEST(LifeFixture, cell_print_self_3)
{
	Cell c;
	c.become_alive();
	c.update_status(pair<int,int>(0,0));
	c.print_self();
}

//UpdateStatus
TEST(LifeFixture, cell_update_status_1)
{
	Cell c;
	c.become_alive();
	c.update_status(pair<int,int>(0,0));
	ASSERT_FALSE(c.live());
}

TEST(LifeFixture, cell_update_status_2)
{
	Cell c;
	c.update_status(pair<int,int>(0,1));
	ASSERT_TRUE(c.live());
}

TEST(LifeFixture, cell_update_status_3)
{
	Cell c;
	c.update_status(pair<int,int>(0, 1));
	c.update_status(pair<int,int>(0, 1));
	ASSERT_TRUE(c.live());
}

//Mutate
TEST(LifeFixture, cell_mutate_1)
{
	Cell c;
	c.mutate();
}

TEST(LifeFixture, cell_mutate_2)
{
	Cell c;
	c.mutate();
	c.mutate();
}

TEST(LifeFixture, cell_mutate_3)
{
	Cell c;
	Cell c2;
	c.mutate();
	c2.mutate();
}

/////////////////////////////////////////////////////////--Life--/////////////////////////////////////////

TEST(LifeFixture, life_simulate_generation_1)
{
	Life<Conway_cell> life(4, 4);
	pair<int,int> loc1(1, 0);
	pair<int,int> loc2(2, 0);
	pair<int,int> loc3(1, 1);
	pair<int,int> loc4(1, 2);
	vector< pair<int,int> > cordinates = {loc1, loc2, loc3};
	life.populate(cordinates);
	cordinates.push_back(loc4);
	life.simulate_generation(1, 10);
	Life<Conway_cell> life2(4, 4);
	life2.populate(cordinates);
	ASSERT_EQ(life.dimensions(), life2.dimensions());
	ASSERT_EQ(life.population(), life2.population());
}

TEST(LifeFixture, life_simulate_generation_2)
{
	Life<Conway_cell> life(2, 2);
	pair<int,int> loc1(0, 0);
	pair<int,int> loc2(1, 0);
	pair<int,int> loc3(1, 1);
	pair<int,int> loc4(0, 1);
	vector< pair<int,int> > cordinates = {loc1, loc2, loc3, loc4};
	life.populate(cordinates);
	life.simulate_generation(1, 1);
	Life<Conway_cell> life2(2, 2);
	life2.populate(cordinates);
	ASSERT_EQ(life.dimensions(), life2.dimensions());
	ASSERT_EQ(life.population(), life2.population());
}

TEST(LifeFixture, life_simulate_generation_3)
{
	Life<Conway_cell> life(2, 2);
	pair<int,int> loc1(0, 0);
	vector< pair<int,int> > cordinates = {loc1};
	life.populate(cordinates);
	life.simulate_generation(1, 1);
	Life<Conway_cell> life2(2, 2);
	ASSERT_EQ(life.dimensions(), life2.dimensions());
	ASSERT_EQ(life.population(), life2.population());
}

TEST(LifeFixture, life_population_1)
{
	Life<Conway_cell> life(1, 1);
	pair<int,int> loc(0, 0);
	vector< pair<int,int> > cordiantes = {loc};
	life.populate(cordiantes);
	ASSERT_EQ(1, life.population());
}

TEST(LifeFixture, life_population_2)
{
	Life<Conway_cell> life(2, 2);
	pair<int,int> loc1(0, 0);
	pair<int,int> loc2(1, 0);
	vector< pair<int,int> > cordiantes = {loc1, loc2};
	life.populate(cordiantes);
	ASSERT_EQ(2, life.population());
}

TEST(LifeFixture, life_population_3)
{
	Life<Conway_cell> life(2, 2);
	pair<int,int> loc1(0, 0);
	pair<int,int> loc2(1, 0);
	pair<int,int> loc3(1, 1);
	vector< pair<int,int> > cordiantes = {loc1, loc2, loc3};
	life.populate(cordiantes);
	ASSERT_EQ(3, life.population());
}

TEST(LifeFixture, life_populate_1)
{
	Life<Conway_cell> life(1, 1);
	pair<int,int> loc(0, 0);
	vector< pair<int,int> > cordiantes = {loc};
	life.populate(cordiantes);
	ASSERT_EQ(1, life.population());
}

TEST(LifeFixture, life_populate_2)
{
	Life<Conway_cell> life(2, 2);
	pair<int,int> loc1(0, 0);
	pair<int,int> loc2(1, 0);
	pair<int,int> loc3(0, 1);
	pair<int,int> loc4(1, 1);
	vector< pair<int,int> > cordiantes = {loc1, loc2, loc3, loc4};
	life.populate(cordiantes);
	ASSERT_EQ(4, life.population());
}

TEST(LifeFixture, life_populate_3)
{
	Life<Conway_cell> life(2, 2);
	pair<int,int> loc1(0, 0);
	pair<int,int> loc2(1, 0);
	pair<int,int> loc3(0, 1);
	pair<int,int> loc4(1, 1);
	vector< pair<int,int> > cordiantes = {loc1, loc2, loc3, loc4};
	life.populate(cordiantes);
	life.populate(cordiantes);
	ASSERT_EQ(4, life.population());
}

TEST(LifeFixture, life_print_grid_1)
{
	Life<Conway_cell> life(1, 1);
	pair<int,int> loc(0, 0);
	vector< pair<int,int> > cordiantes = {loc};
	life.populate(cordiantes);
	life.print_grid();
}

TEST(LifeFixture, life_print_grid_2)
{
	Life<Conway_cell> life(2, 2);
	pair<int,int> loc1(0, 0);
	pair<int,int> loc2(1, 0);
	pair<int,int> loc3(0, 1);
	pair<int,int> loc4(1, 1);
	vector< pair<int,int> > cordiantes = {loc1, loc2, loc3, loc4};
	life.populate(cordiantes);
	life.print_grid();
}

TEST(LifeFixture, life_print_grid_3)
{
	Life<Conway_cell> life(2, 2);
	pair<int,int> loc1(0, 0);
	pair<int,int> loc2(1, 0);
	pair<int,int> loc3(0, 1);
	pair<int,int> loc4(1, 1);
	vector< pair<int,int> > cordiantes = {loc1, loc2, loc3, loc4};
	life.populate(cordiantes);
	life.populate(cordiantes);
	life.print_grid();
}

TEST(LifeFixture, life_all_neighbors_1)
{
	Life<Conway_cell> life(4, 4);
	pair<int,int> loc1(1, 1);
	pair<int,int> loc2(2, 1);
	pair<int,int> loc3(1, 2);
	pair<int,int> loc4(2, 2);
	vector< pair<int,int> > cordiantes = {loc1, loc2, loc3, loc4};
	life.populate(cordiantes);
	ASSERT_EQ(3, life.all_neighbors(get<0>(loc1), get<1>(loc1), life.get_universe()));
	ASSERT_EQ(3, life.all_neighbors(get<0>(loc2), get<1>(loc1), life.get_universe()));
	ASSERT_EQ(3, life.all_neighbors(get<0>(loc3), get<1>(loc1), life.get_universe()));
	ASSERT_EQ(3, life.all_neighbors(get<0>(loc4), get<1>(loc1), life.get_universe()));
}

TEST(LifeFixture, life_all_neighbors_2)
{
	Life<Conway_cell> life(4, 4);

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			ASSERT_EQ(0, life.all_neighbors(j, i, life.get_universe()));
		}
	}
}

TEST(LifeFixture, life_all_neighbors_3)
{
	Life<Conway_cell> life(4, 4);
	pair<int,int> loc1(1, 1);
	pair<int,int> loc2(2, 1);
	pair<int,int> loc3(1, 2);
	pair<int,int> loc4(2, 2);
	pair<int,int> loc5(0, 0);
	pair<int,int> loc6(1, 0);
	pair<int,int> loc7(2, 0);
	pair<int,int> loc8(0, 1);
	pair<int,int> loc9(0, 2);
	vector< pair<int,int> > cordiantes;
	cordiantes.push_back(loc1);
	cordiantes.push_back(loc2);
	cordiantes.push_back(loc3);
	cordiantes.push_back(loc4);
	cordiantes.push_back(loc5);
	cordiantes.push_back(loc6);
	cordiantes.push_back(loc7);
	cordiantes.push_back(loc8);
	cordiantes.push_back(loc9);
	life.populate(cordiantes);
	ASSERT_EQ(8, life.all_neighbors(get<0>(loc1), get<1>(loc1), life.get_universe()));
}

TEST(LifeFixture, life_cross_neighbors_1)
{
	Life<Conway_cell> life(4, 4);
	pair<int,int> loc1(1, 1);
	pair<int,int> loc2(2, 1);
	pair<int,int> loc3(1, 2);
	pair<int,int> loc4(2, 2);
	vector< pair<int,int> > cordiantes = {loc1, loc2, loc3, loc4};
	life.populate(cordiantes);
	ASSERT_EQ(2, life.cross_neighbors(get<0>(loc1), get<1>(loc1), life.get_universe()));
	ASSERT_EQ(2, life.cross_neighbors(get<0>(loc2), get<1>(loc1), life.get_universe()));
	ASSERT_EQ(2, life.cross_neighbors(get<0>(loc3), get<1>(loc1), life.get_universe()));
	ASSERT_EQ(2, life.cross_neighbors(get<0>(loc4), get<1>(loc1), life.get_universe()));
}

TEST(LifeFixture, life_cross_neighbors_2)
{
		Life<Conway_cell> life(4, 4);

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			ASSERT_EQ(0, life.cross_neighbors(j, i, life.get_universe()));
		}
	}
}

TEST(LifeFixture, life_cross_neighbors_3)
{
	Life<Conway_cell> life(4, 4);
	pair<int,int> loc1(1, 1);
	pair<int,int> loc2(2, 1);
	pair<int,int> loc3(1, 2);
	pair<int,int> loc4(2, 2);
	pair<int,int> loc5(0, 0);
	pair<int,int> loc6(1, 0);
	pair<int,int> loc7(2, 0);
	pair<int,int> loc8(0, 1);
	pair<int,int> loc9(0, 2);
	vector< pair<int,int> > cordiantes;
	cordiantes.push_back(loc1);
	cordiantes.push_back(loc2);
	cordiantes.push_back(loc3);
	cordiantes.push_back(loc4);
	cordiantes.push_back(loc5);
	cordiantes.push_back(loc6);
	cordiantes.push_back(loc7);
	cordiantes.push_back(loc8);
	cordiantes.push_back(loc9);
	life.populate(cordiantes);
	ASSERT_EQ(4, life.cross_neighbors(get<0>(loc1), get<1>(loc1), life.get_universe()));
}

TEST(LifeFixture, life_check_bounds_1)
{
	Life<Conway_cell> life(4, 4);
	ASSERT_TRUE(life.check_bounds(0, 0));
}

TEST(LifeFixture, life_check_bounds_2)
{
	Life<Conway_cell> life(4, 4);
	ASSERT_TRUE(life.check_bounds(3, 3));
}

TEST(LifeFixture, life_check_bounds_3)
{
	Life<Conway_cell> life(4, 4);
	ASSERT_FALSE(life.check_bounds(4, 4));
}

TEST(LifeFixture, parse_data_1)
{
	ifstream ifs("RunLife.in", ifstream::in);
	tuple< int, int, vector< pair<int,int> > > t = parse_data(ifs);
	const int& x = get<0>(t);
    const int& y = get<1>(t);
    ASSERT_EQ(13, x);
    ASSERT_EQ(21, y);
}

TEST(LifeFixture, parse_data_2)
{
	ifstream ifs("RunLife.in", ifstream::in);
	tuple< int, int, vector< pair<int,int> > > t = parse_data(ifs);
	vector< pair<int,int> > cordinates = get<2>(t);

	pair<int,int> loc1(4, 8);
	pair<int,int> loc2(5, 8);
	pair<int,int> loc3(6, 8);
	pair<int,int> loc4(7, 8);
	pair<int,int> loc5(8, 8);
	pair<int,int> loc6(7, 9);
	pair<int,int> loc7(6, 10);
	pair<int,int> loc8(5, 11);
	pair<int,int> loc9(4, 12);
	pair<int,int> loc10(5, 12);
	pair<int,int> loc11(6, 12);
	pair<int,int> loc12(7, 12);
	pair<int,int> loc13(8, 12);

	vector< pair<int,int> > expected_cordinates;
	expected_cordinates.push_back(loc1);
	expected_cordinates.push_back(loc2);
	expected_cordinates.push_back(loc3);
	expected_cordinates.push_back(loc4);
	expected_cordinates.push_back(loc5);
	expected_cordinates.push_back(loc6);
	expected_cordinates.push_back(loc7);
	expected_cordinates.push_back(loc8);
	expected_cordinates.push_back(loc9);
	expected_cordinates.push_back(loc10);
	expected_cordinates.push_back(loc11);
	expected_cordinates.push_back(loc12);
	expected_cordinates.push_back(loc13);

	ASSERT_EQ(expected_cordinates, cordinates);
}

TEST(LifeFixture, parse_data_3)
{
	ifstream ifs("RunLife.in", ifstream::in);
	tuple< int, int, vector< pair<int,int> > > t = parse_data(ifs);
	const int& x = get<0>(t);
    const int& y = get<1>(t);
    const vector< pair<int,int> >& live_cordinates = get<2>(t);
    Life<Conway_cell> life(x, y);
    life.populate(live_cordinates);
    ASSERT_EQ(13, life.population());
}
