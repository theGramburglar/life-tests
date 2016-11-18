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

using namespace std;

// ----
// test
// ----


#include <cassert>   // assert
#include <iostream> //endl, cin, cout
#include <sstream> //stringstream
#include <string> // strings
#include <utility> // pair
#include <algorithm> // swap
#include <vector>


#include "Life.h"

#include "gtest/gtest.h"
using namespace std;

//
// CONWAY constructor test
//

TEST(TestLife, conwaycell_construction_1) {
	ConwayCell cc = ConwayCell(true, '*');
	ASSERT_TRUE(cc.is_alive());
	ASSERT_EQ(cc.symbol, '*');
}

TEST(TestLife, conwaycell_construction_2) {
	ConwayCell cc = ConwayCell(false, '*');
	ASSERT_FALSE(cc.is_alive());
}

TEST(TestLife, conwaycell_construction_3) {
	ConwayCell cc = ConwayCell(true, '*');
	ASSERT_TRUE(cc.is_alive());
	cc.kill();
	ASSERT_FALSE(cc.is_alive());
}

TEST(TestLife, conwaycell_construction_4) {
	ConwayCell cc = ConwayCell(true, '*');
	ASSERT_TRUE(cc.is_alive());
	ASSERT_EQ(cc.symbol, '*');
}

// conway evolve test

TEST(TestLife, conway_evolve_1) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.evolve(0);
	ASSERT_FALSE(cc.is_alive());
}

TEST(TestLife, conway_evolve_2) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.evolve(3);
	ASSERT_TRUE(cc.is_alive());
}

TEST(TestLife, conway_evolve_3) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.evolve(4);
	ASSERT_FALSE(cc.is_alive());
}

TEST(TestLife, conway_evolve_4) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.evolve(8);
	ASSERT_FALSE(cc.is_alive());
}

TEST(TestLife, conway_evolve_5) {
	ConwayCell cc = ConwayCell(false, '*');
	cc.evolve(0);
	ASSERT_FALSE(cc.is_alive());
}

TEST(TestLife, conway_evolve_6) {
	ConwayCell cc = ConwayCell(false, '*');
	cc.evolve(3);
	ASSERT_TRUE(cc.is_alive());
}

TEST(TestLife, conway_evolve_7) {
	ConwayCell cc = ConwayCell(false, '*');
	cc.evolve(4);
	ASSERT_FALSE(cc.is_alive());
}

TEST(TestLife, conway_evolve_8) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.evolve(1);
	ASSERT_FALSE(cc.is_alive());
	ASSERT_EQ(cc.symbol, '.');
}

TEST(TestLife, conway_evolve_9) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.evolve(2);
	ASSERT_TRUE(cc.is_alive());
	ASSERT_EQ(cc.symbol, '*');
}

TEST(TestLife, conway_evolve_10) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.evolve(3);
	ASSERT_TRUE(cc.is_alive());
	ASSERT_EQ(cc.symbol, '*');
}

TEST(TestLife, conway_evolve_11) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.evolve(4);
	ASSERT_FALSE(cc.is_alive());
	ASSERT_EQ(cc.symbol, '.');
}

// conway kill test

TEST(TestLife, conway_kill_1) {
	ConwayCell cc = ConwayCell(false, '*');
	cc.kill();
	ASSERT_TRUE(!cc.is_alive());
}

TEST(TestLife, conway_kill_2) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.kill();
	ASSERT_FALSE(cc.is_alive());
}

TEST(TestLife, conway_kill_3) {
	ConwayCell cc = ConwayCell(false, '*');
	cc.kill();
	ASSERT_FALSE(cc.is_alive());
}

// conway revive

TEST(TestLife, conway_revive_1) {
	ConwayCell cc = ConwayCell(false, '*');
	cc.revive();
	ASSERT_TRUE(cc.is_alive());
}

TEST(TestLife, conway_revive_2) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.revive();
	ASSERT_TRUE(cc.is_alive());
}

TEST(TestLife, conway_revive_3) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.kill();
	ASSERT_FALSE(cc.is_alive());
	cc.revive();
	ASSERT_TRUE(cc.is_alive());
}

TEST(TestLife, conway_revive_4) {
	ConwayCell cc = ConwayCell(true, '*');
	cc.kill();
	ASSERT_FALSE(cc.is_alive());
	cc.revive();
	ASSERT_TRUE(cc.is_alive());
	cc.revive();
	ASSERT_TRUE(cc.is_alive());
}

// Conway time to mutate test

TEST(TestLife, conway_time_to_mutate_1) {
	ConwayCell cc = ConwayCell(false, '*');
	ASSERT_FALSE(cc.time_to_mutate());
}

TEST(TestLife, conway_time_to_mutate_2) {
	ConwayCell cc = ConwayCell(false, '3');
	cc.revive();
	cc.kill();
	ASSERT_FALSE(cc.time_to_mutate());
}

TEST(TestLife, conway_time_to_mutate_3) {
	ConwayCell cc = ConwayCell(true, '*');
	ASSERT_FALSE(cc.time_to_mutate());
}

// conway neighbor_coordinates

TEST(TestLife, conway_neighbor_coordinates_1) {
	ConwayCell cc = ConwayCell(true, '*');
	vector<pair<int,int>> directions = cc.neighbor_coordinates();
	pair<int,int> coord = directions[0];
	ASSERT_EQ(coord.first, -1);
	ASSERT_EQ(coord.second, 0);
}

TEST(TestLife, conway_neighbor_coordinates_2) {
	ConwayCell cc = ConwayCell(true, '*');
	vector<pair<int,int>> directions = cc.neighbor_coordinates();
	pair<int,int> coord = directions[1];
	ASSERT_EQ(coord.first, -1);
	ASSERT_EQ(coord.second, 1);
}

TEST(TestLife, conway_neighbor_coordinates_3) {
	ConwayCell cc = ConwayCell(true, '*');
	vector<pair<int,int>> directions = cc.neighbor_coordinates();
	pair<int,int> coord = directions[2];
	ASSERT_EQ(coord.first, 0);
	ASSERT_EQ(coord.second, 1);
}

TEST(TestLife, conway_neighbor_coordinates_4) {
	ConwayCell cc = ConwayCell(true, '*');
	vector<pair<int,int>> directions = cc.neighbor_coordinates();
	pair<int,int> coord = directions[3];
	ASSERT_EQ(coord.first, 1);
	ASSERT_EQ(coord.second, 1);
}

TEST(TestLife, conway_neighbor_coordinates_5) {
	ConwayCell cc = ConwayCell(true, '*');
	vector<pair<int,int>> directions = cc.neighbor_coordinates();
	pair<int,int> coord = directions[4];
	ASSERT_EQ(coord.first, 1);
	ASSERT_EQ(coord.second, 0);
}

TEST(TestLife, conway_neighbor_coordinates_6) {
	ConwayCell cc = ConwayCell(true, '*');
	vector<pair<int,int>> directions = cc.neighbor_coordinates();
	pair<int,int> coord = directions[5];
	ASSERT_EQ(coord.first, 1);
	ASSERT_EQ(coord.second, -1);
}

TEST(TestLife, conway_neighbor_coordinates_7) {
	ConwayCell cc = ConwayCell(true, '*');
	vector<pair<int,int>> directions = cc.neighbor_coordinates();
	pair<int,int> coord = directions[6];
	ASSERT_EQ(coord.first, 0);
	ASSERT_EQ(coord.second, -1);
}

TEST(TestLife, conway_neighbor_coordinates_8) {
	ConwayCell cc = ConwayCell(true, '*');
	vector<pair<int,int>> directions = cc.neighbor_coordinates();
	pair<int,int> coord = directions[7];
	ASSERT_EQ(coord.first, -1);
	ASSERT_EQ(coord.second, -1);
}


//
// FREDKIN CELL TEST
//

// fredkin constructor

TEST(TestLife, fredkincell_construction_1) {
	FredkinCell cc = FredkinCell(true, '*');
	ASSERT_TRUE(cc.is_alive());
}

TEST(TestLife, fredkincell_construction_2) {
	FredkinCell cc = FredkinCell(false, '*');
	ASSERT_FALSE(cc.is_alive());
}

TEST(TestLife, fredkincell_construction_3) {
	FredkinCell cc = FredkinCell(true, '*');
	ASSERT_TRUE(cc.is_alive());
	cc.kill();
	ASSERT_FALSE(cc.is_alive());
}

// fredkin neighbor directions
// N S E W

TEST(TestLife, fredkin_neighbor_directions_1) {
	FredkinCell fc = FredkinCell(true, '0');
	vector<pair<int,int>> d = fc.neighbor_coordinates();
	ASSERT_EQ(d[0].first, -1);
	ASSERT_EQ(d[0].second, 0);
}

TEST(TestLife, fredkin_neighbor_directions_2) {
	FredkinCell fc = FredkinCell(true, '0');
	vector<pair<int,int>> d = fc.neighbor_coordinates();
	ASSERT_EQ(d[1].first, 1);
	ASSERT_EQ(d[1].second, 0);
}

TEST(TestLife, fredkin_neighbor_directions_3) {
	FredkinCell fc = FredkinCell(true, '0');
	vector<pair<int,int>> d = fc.neighbor_coordinates();
	ASSERT_EQ(d[2].first, 0);
	ASSERT_EQ(d[2].second, 1);
}

TEST(TestLife, fredkin_neighbor_directions_4) {
	FredkinCell fc = FredkinCell(true, '0');
	vector<pair<int,int>> d = fc.neighbor_coordinates();
	ASSERT_EQ(d[3].first, 0);
	ASSERT_EQ(d[3].second, -1);
}

// Fredkin is alive

TEST(TestLife, fredkin_is_alive_1) {
	FredkinCell fc = FredkinCell(true, '0');
	ASSERT_TRUE(fc.is_alive());
}

TEST(TestLife, fredkin_is_alive_2) {
	FredkinCell fc = FredkinCell(false, '-');
	ASSERT_FALSE(fc.is_alive());
}

// Fredkin evolve

TEST(TestLife, fredkincell_evolve_1) {
	FredkinCell fc = FredkinCell(true, '0');
	fc.evolve(0);
	ASSERT_FALSE(fc.is_alive());
}

TEST(TestLife, fredkincell_evolve_2) {
	FredkinCell fc = FredkinCell(true, '0');
	fc.evolve(1);
	ASSERT_TRUE(fc.is_alive());
}

TEST(TestLife, fredkincell_evolve_3) {
	FredkinCell fc = FredkinCell(true, '0');
	fc.evolve(2);
	ASSERT_FALSE(fc.is_alive());
}

TEST(TestLife, fredkincell_evolve_4) {
	FredkinCell fc = FredkinCell(true, '0');
	fc.evolve(3);
	ASSERT_TRUE(fc.is_alive());
}

TEST(TestLife, fredkincell_evolve_5) {
	FredkinCell fc = FredkinCell(true, '0');
	fc.evolve(4);
	ASSERT_FALSE(fc.is_alive());
}

TEST(TestLife, fredkincell_evolve_6) {
	FredkinCell fc = FredkinCell(false, '-');
	fc.evolve(0);
	ASSERT_FALSE(fc.is_alive());
	ASSERT_EQ(fc.symbol, '-');
}

TEST(TestLife, fredkincell_evolve_7) {
	FredkinCell fc = FredkinCell(false, '-');
	fc.evolve(1);
	ASSERT_TRUE(fc.is_alive());
	ASSERT_EQ(fc.symbol, '0');
}

TEST(TestLife, fredkincell_evolve_8) {
	FredkinCell fc = FredkinCell(false, '-');
	fc.evolve(2);
	ASSERT_FALSE(fc.is_alive());
}

TEST(TestLife, fredkincell_evolve_9) {
	FredkinCell fc = FredkinCell(false, '-');
	fc.evolve(3);
	ASSERT_TRUE(fc.is_alive());
	ASSERT_EQ(fc.symbol, '0');
}

TEST(TestLife, fredkincell_evolve_10) {
	FredkinCell fc = FredkinCell(false, '-');
	fc.evolve(4);
	ASSERT_FALSE(fc.is_alive());
	ASSERT_EQ(fc.symbol, '-');
}

TEST(TestLife, fredkincell_evolve_11) {
	FredkinCell fc = FredkinCell(false, '0');
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	ASSERT_TRUE(fc.is_alive());
	ASSERT_EQ(fc.symbol, '6');
}

TEST(TestLife, fredkincell_evolve_12) {
	FredkinCell fc = FredkinCell(false, '0');
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	ASSERT_TRUE(fc.is_alive());
	ASSERT_EQ(fc.symbol, '9');
}

TEST(TestLife, fredkincell_evolve_13) {
	FredkinCell fc = FredkinCell(false, '0');
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	fc.evolve(1);
	ASSERT_TRUE(fc.is_alive());
	ASSERT_EQ(fc.symbol, '+');
}

// fredkin kill test

TEST(TestLife, fredkin_kill_1) {
	FredkinCell fc = FredkinCell(true, '0');
	fc.kill();
	ASSERT_EQ(fc.symbol, '-');
	ASSERT_EQ(fc.state, false);
}

TEST(TestLife, fredkin_kill_2) {
	FredkinCell fc = FredkinCell(false, '-');
	fc.kill();
	ASSERT_EQ(fc.symbol, '-');
	ASSERT_EQ(fc.state, false);
}

TEST(TestLife, fredkin_kill_3) {
	FredkinCell fc = FredkinCell(true, '2');
	fc.kill();
	ASSERT_EQ(fc.symbol, '-');
	ASSERT_EQ(fc.state, false);
}

// fredkin time_to_mutate

TEST(TestLife, fredkin_time_to_mutate_1) {
	FredkinCell fc = FredkinCell(true, '0');
	ASSERT_FALSE(fc.time_to_mutate());
}

TEST(TestLife, fredkin_time_to_mutate_2) {
	FredkinCell fc = FredkinCell(true, '1');
	ASSERT_FALSE(fc.time_to_mutate());
}

TEST(TestLife, fredkin_time_to_mutate_3) {
	FredkinCell fc = FredkinCell(true, '2');
	ASSERT_TRUE(fc.time_to_mutate());
}

// Fredkin revive test

TEST(TestLife, fredkin_revive_1) {
	FredkinCell fc = FredkinCell(false, '-');
	fc.revive();
	ASSERT_EQ(fc.symbol, '0');
	ASSERT_EQ(fc.state, true);
}

TEST(TestLife, fredkin_revive_2) {
	FredkinCell fc = FredkinCell(false, '-');
	fc.age = '3';
	fc.revive();
	ASSERT_EQ(fc.symbol, '3');
	ASSERT_EQ(fc.state, true);
}

TEST(TestLife, fredkin_revive_3) {
	FredkinCell fc = FredkinCell(false, '-');
	fc.age = '+';
	fc.revive();
	ASSERT_EQ(fc.symbol, '+');
	ASSERT_EQ(fc.state, true);
}

// cell construction

TEST(TestLife, cell_constructor_1) {
	Cell c = Cell(true, '*');
	ConwayCell cc = ConwayCell(true, '*');
	ASSERT_EQ(c.cell->symbol, cc.symbol);
}

TEST(TestLife, cell_constructor_2) {
	Cell c = Cell(true, '0');
	FredkinCell cc = FredkinCell(true, '0');
	ASSERT_EQ(c.cell->symbol, cc.symbol);
}

TEST(TestLife, cell_constructor_3) {
	Cell c = Cell(false, '.');
	ConwayCell cc = ConwayCell(false, '.');
	ASSERT_EQ(c.cell->symbol, cc.symbol);
}

TEST(TestLife, cell_constructor_4) {
	Cell c = Cell(false, '-');
	FredkinCell cc = FredkinCell(false, '-');
	ASSERT_EQ(c.cell->symbol, cc.symbol);
}

//
// EVOLVING CELL
//

TEST(TestLife, cell_evolve_1) {
	Cell c = Cell(true, '0');
	ASSERT_EQ(c.cell->is_alive(), true); 	
}

TEST(TestLife, cell_evolve_2) {
	Cell c = Cell(true, '0');
	c.evolve(1);
	ASSERT_EQ(c.cell->symbol, '1');
}

TEST(TestLife, cell_evolve_3) {
	Cell c = Cell(true, '0');
	c.evolve(1);
	c.evolve(1);
	ASSERT_EQ(c.cell->symbol, '*');
}

TEST(TestLife, cell_evolve_4) {
	Cell c = Cell(true, '*');
	ASSERT_EQ(c.cell->is_alive(), true); 	
}

TEST(TestLife, cell_evolve_5) {
	Cell c = Cell(true, '*');
	c.evolve(2);
	ASSERT_EQ(c.cell->symbol, '*');
}

TEST(TestLife, cell_evolve_6) {
	Cell c = Cell(true, '*');
	c.evolve(3);
	c.evolve(3);
	ASSERT_EQ(c.cell->symbol, '*');
}

TEST(TestLife, cell_evolve_7) {
	Cell c = Cell(true, '*');
	c.evolve(2);
	c.evolve(2);
	c.evolve(1);
	ASSERT_EQ(c.cell->symbol, '.');
}

TEST(TestLife, cell_evolve_8) {
	Cell c = Cell(true, '0');
	c.evolve(1);
	ASSERT_EQ(c.cell->symbol, '1');
}

TEST(TestLife, cell_evolve_9) {
	Cell c = Cell(true, '0');
	c.evolve(1);
	c.evolve(4);
	ASSERT_EQ(c.cell->symbol, '-');
}

TEST(TestLife, cell_evolve_10) {
	Cell c = Cell(true, '0');
	c.evolve(1);
	c.evolve(4);
	c.evolve(1);
	ASSERT_EQ(c.cell->symbol, '1');
}

TEST(TestLife, cell_evolve_11) {
	Cell c = Cell(true, '0');
	c.evolve(1);
	c.evolve(4);
	c.evolve(1);
	c.evolve(1);
	ASSERT_EQ(c.cell->symbol, '*');
}

// Cell copy assignment

TEST(TestLife, cell_copy_assignment_1) {
	ConwayCell c1 = ConwayCell(true, '*');
	ConwayCell c2 = ConwayCell(false, '.');
	c1 = c2;
	ASSERT_FALSE(c1.is_alive());
	ASSERT_EQ(c1.symbol, c2.symbol);
}

TEST(TestLife, cell_copy_assignment_2) {
	Cell c1 = Cell(true, '*');
	Cell c2 = Cell(false, '.');
	c1 = c2;
	ASSERT_FALSE(c1.is_alive());
	ASSERT_EQ(c1.cell->symbol, c2.cell->symbol);
}

TEST(TestLife, cell_copy_assignment_3) {
	Cell c1 = Cell(true, '0');
	Cell c2 = Cell(false, '-');
	c1 = c2;
	ASSERT_FALSE(c1.is_alive());
	ASSERT_EQ(c1.cell->symbol, c2.cell->symbol);
}

TEST(TestLife, cell_copy_assignment_4) {
	ConwayCell c1 = ConwayCell(true, '*');
	ConwayCell c2 = ConwayCell(false, '.');
	ConwayCell c3 = ConwayCell(true, '*');
	c1 = c2;
	c1 = c3;
	ASSERT_TRUE(c1.is_alive());
	ASSERT_EQ(c1.symbol, c3.symbol);
}

TEST(TestLife, cell_copy_assignment_5) {
	Cell c1 = Cell(true, '*');
	Cell c2 = Cell(false, '.');
	Cell c3 = Cell(true, '*');
	c1 = c2;
	c1 = c3;
	ASSERT_TRUE(c1.is_alive());
	ASSERT_EQ(c1.cell->symbol, c3.cell->symbol);
}

TEST(TestLife, cell_copy_assignment_6) {
	Cell c1 = Cell(true, '0');
	Cell c2 = Cell(false, '-');
	Cell c3 = Cell(true , '0');
	c1 = c2;
	c1 = c3;
	ASSERT_TRUE(c1.is_alive());
	ASSERT_EQ(c1.cell->symbol, c3.cell->symbol);
}


// life is indexable with ASSERT_TRUE

TEST(TestLife, at_1) {
	stringstream ss;
	ss << "......*.*";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);
	ConwayCell cc = l.at(0,0);
	ASSERT_EQ(cc.is_alive(), false);
	ASSERT_EQ(cc.symbol, '.');
}

TEST(TestLife, at_2) {
	stringstream ss;
	ss << "......*.*";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);
	ConwayCell cc = l.at(2,2);
	ASSERT_EQ(cc.is_alive(), true);
	ASSERT_EQ(cc.symbol, '*');
}

TEST(TestLife, at_3) {
	stringstream ss;
	ss << "......*.*";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);
	ConwayCell cc = l.at(2,0);
	ASSERT_EQ(cc.is_alive(), true);
	ASSERT_EQ(cc.symbol, '*');
}

TEST(TestLife, in_bounds_1) {
	stringstream ss;
	ss << "*********";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);	
	ASSERT_TRUE(l.in_bounds(0,0));
}

TEST(TestLife, in_bounds_2) {
	stringstream ss;
	ss << "*********";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);	
	ASSERT_TRUE(l.in_bounds(0,2));
}
TEST(TestLife, in_bounds_3) {
	stringstream ss;
	ss << "*********";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);	
	ASSERT_TRUE(l.in_bounds(2,0));
}
TEST(TestLife, in_bounds_4) {
	stringstream ss;
	ss << "*********";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);	
	ASSERT_TRUE(l.in_bounds(2,2));
}
TEST(TestLife, in_bounds_5) {
	stringstream ss;
	ss << "*********";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);	
	ASSERT_FALSE(l.in_bounds(-1,0));
}
TEST(TestLife, in_bounds_6) {
	stringstream ss;
	ss << "*********";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);	
	ASSERT_FALSE(l.in_bounds(0,3));
}
TEST(TestLife, in_bounds_7) {
	stringstream ss;
	ss << "*********";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);	
	ASSERT_FALSE(l.in_bounds(3,0));
}
TEST(TestLife, in_bounds_8) {
	stringstream ss;
	ss << "*********";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);	
	ASSERT_FALSE(l.in_bounds(3,3));
}

//
// EVOLVING LIFE
//

TEST(TestLife, simulate_generation_1) {
	stringstream ss;
	ss << "*********";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);
	l.simulate_generation();
	ConwayCell cc = l.at(0,0);
	ASSERT_TRUE(cc.is_alive());
	cc = l.at(2,0);
	ASSERT_TRUE(cc.is_alive());
	cc = l.at(0, 2);
	ASSERT_TRUE(cc.is_alive());
	cc = l.at(2,2);
	ASSERT_TRUE(cc.is_alive());

}

TEST(TestLife, simulate_generation_2) {
	stringstream ss;
	ss << "....**.*.";
	Life<ConwayCell> l = Life<ConwayCell>(3,3, ss);
	ConwayCell cc = l.at(2,2);
	ASSERT_FALSE(cc.is_alive());
	l.simulate_generation();
	cc = l.at(2,2);
	ASSERT_TRUE(cc.is_alive());
	cc = l.at(1,1);
	ASSERT_TRUE(cc.is_alive());
}

TEST(TestLife, simulate_generation_3) {
	stringstream ss;
	ss << "000";
	Life<FredkinCell> l = Life<FredkinCell>(1,3, ss);
	l.simulate_generation();
	// 1 - 1
	FredkinCell fc = l.at(0,0);
	ASSERT_TRUE(fc.is_alive());
	ASSERT_EQ(fc.symbol, '1');
	l.simulate_generation();
	// - 1 -
	fc = l.at(0,0);
	ASSERT_EQ(fc.symbol, '-');
}


