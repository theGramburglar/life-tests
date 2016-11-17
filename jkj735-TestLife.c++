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
#include <vector>
#include <iostream>
#include <sstream>
#include "Life.h"

using namespace std;

// ----
// LIFE
// ----

// Life Constructor Tests
TEST(LifeFixture, life_constructor_test_1) {
	stringstream in("2 2\n..\n..");
	Life<ConwayCell> l(in);
	ASSERT_EQ(l.board.size(), 2);
	ASSERT_EQ(l.board[0].size(), 2);
}

TEST(LifeFixture, life_constructor_test_2) {
	stringstream in("2 2\n..\n.*");
	Life<ConwayCell> l(in);
	ASSERT_FALSE(l.board[0][0].isAlive());
	ASSERT_TRUE(l.board[1][1].isAlive());
}

TEST(LifeFixture, life_constructor_test_3) {
	stringstream in("2 2\n..\n.*");
	Life<ConwayCell> l(in);
	stringstream out;	
	out << l;
	ASSERT_EQ(out.str(), "Generation = 0, Population = 1.\n..\n.*\n\n");
}

TEST(LifeFixture, life_constructor_test_4) {
	stringstream in("2 2\n--\n--");
	Life<FredkinCell> l(in);
	ASSERT_EQ(l.board.size(), 2);
	ASSERT_EQ(l.board[0].size(), 2);
}

TEST(LifeFixture, life_constructor_test_5) {
	stringstream in("2 2\n--\n-1");
	Life<FredkinCell> l(in);
	stringstream out;	
	out << l;
	ASSERT_EQ(out.str(), "Generation = 0, Population = 1.\n--\n-1\n\n");
}

TEST(LifeFixture, life_constructor_test_6) {
// 	stringstream in("2 2\n--\n-1");
// 	Life<Cell> l(in);
// 	stringstream out;
// 	out << l;
// 	ASSERT_EQ(out.str(), "Generation = 0, Population = 1.\n--\n-1\n\n");
}

// Life Run Tests
TEST(LifeFixture, run_life_test_1) {
	stringstream in("3 3\n...\n***\n...");
	Life<ConwayCell> l(in);
	stringstream out;	
	out << l;
	ASSERT_EQ(out.str(), "Generation = 0, Population = 3.\n...\n***\n...\n\n");
	l.run();
	out.str("");
	out << l;
	ASSERT_EQ(out.str(), "Generation = 1, Population = 3.\n.*.\n.*.\n.*.\n\n");
}

TEST(LifeFixture, run_life_test_2) {
	stringstream in("3 3\n---\n121\n---");
	Life<FredkinCell> l(in);
	stringstream out;	
	out << l;
	ASSERT_EQ(out.str(), "Generation = 0, Population = 3.\n---\n121\n---\n\n");
	l.run();
	l.run();
	out.str("");
	out << l;
	ASSERT_EQ(out.str(), "Generation = 2, Population = 0.\n---\n---\n---\n\n");
}

TEST(LifeFixture, run_life_test_3) {
// 	stringstream in("3 3\n---\n-1-\n---");
// 	Life<Cell> l(in);
// 	l.run();
}

TEST(LifeFixture, run_life_test_4) {
	stringstream in("3 3\n***\n***\n***");
	Life<ConwayCell> l(in);
	stringstream out;	
	out << l;
	ASSERT_EQ(out.str(), "Generation = 0, Population = 9.\n***\n***\n***\n\n");
	l.run();
	out.str("");
	out << l;
	ASSERT_EQ(out.str(), "Generation = 1, Population = 4.\n*.*\n...\n*.*\n\n");
}




// -----------
// CONWAY CELL
// -----------

// Conway Cell Constructor Tests
TEST(LifeFixture, conway_cell_constr_test_1) {
	ConwayCell c('.');
	ASSERT_EQ(c.neighbor_count, 0);
}

TEST(LifeFixture, conway_cell_constr_test_2) {
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, conway_cell_constr_test_3) {
	ConwayCell c('.');
	ASSERT_TRUE(!c.isAlive());
}

// Conway Cell Update Neighbor Tests
TEST(LifeFixture, cc_update_neighbor_test_1) {
	ConwayCell c('*');
	c.updateNeighborCount(1,1);
	ASSERT_EQ(c.neighbor_count, 1);
}

TEST(LifeFixture, cc_update_neighbor_test_2) {
	ConwayCell c('*');
	c.updateNeighborCount(0,0);
	ASSERT_EQ(c.neighbor_count, 0);
}

TEST(LifeFixture, cc_update_neighbor_test_3) {
	ConwayCell c('*');
	c.updateNeighborCount(-1,0);
	ASSERT_EQ(c.neighbor_count, 1);
}

// Conway Cell Update State Tests
TEST(LifeFixture, cc_update_state_test_1) {
	ConwayCell c('*');
	c.neighbor_count = 4;
	ASSERT_TRUE(c.isAlive());
	int val = c.updateState();
	ASSERT_TRUE(val == 0 && !c.isAlive());
}

TEST(LifeFixture, cc_update_state_test_2) {
	ConwayCell c('*');
	c.updateNeighborCount(-1,0);
	c.updateNeighborCount(1,1);
	ASSERT_TRUE(c.isAlive());
	int val = c.updateState();
	ASSERT_TRUE(val == 0 && c.isAlive());
}

TEST(LifeFixture, cc_update_state_test_3) {
	ConwayCell c('.');
	c.updateNeighborCount(-1,0);
	c.updateNeighborCount(1,1);
	c.updateNeighborCount(0,0);
	c.updateNeighborCount(1,-1);
	ASSERT_TRUE(!c.isAlive());
	int val = c.updateState();
	ASSERT_TRUE(val == 0 && c.isAlive());
}

TEST(LifeFixture, cc_update_state_test_4) {
	ConwayCell c('.');
	c.updateNeighborCount(-1,0);
	c.updateNeighborCount(1,1);
	c.updateNeighborCount(0,0);
	ASSERT_TRUE(!c.isAlive());
	int val = c.updateState();
	ASSERT_TRUE(val == 0 && !c.isAlive());
}

TEST(LifeFixture, cc_update_state_test_5) {
	ConwayCell c('.');
	c.updateNeighborCount(-1,0);
	ASSERT_TRUE(!c.isAlive());
	int val = c.updateState();
	ASSERT_TRUE(val == 0 && !c.isAlive());
	ASSERT_EQ(c.neighbor_count, 0);
}

TEST(LifeFixture, cc_update_state_test_6) {
	ConwayCell c('*');
	ASSERT_EQ(c.neighbor_count, 0);
	c.updateState();
	ASSERT_EQ(c.neighbor_count, 0);
}

// Write Tests
TEST(LifeFixture, cc_write_test_1) {
	ConwayCell c('*');
	stringstream out;
	out << c;
	ASSERT_EQ("*", out.str());
}

TEST(LifeFixture, cc_write_test_2) {
	ConwayCell c('.');
	stringstream out;
	out << c;
	ASSERT_EQ(".", out.str());
}

TEST(LifeFixture, cc_write_test_3) {
	ConwayCell c('*');
	c.updateState();
	stringstream out;
	out << c;
	ASSERT_EQ(".", out.str());
}




// ------------
// FREDKIN CELL
// ------------

// Fredkin Cell Constructor Tests
TEST(LifeFixture, fredkin_cell_constr_test_1) {
	FredkinCell f('-');
	ASSERT_TRUE(!f.isAlive());
	ASSERT_EQ(f.age, 0);
}

TEST(LifeFixture, fredkin_cell_constr_test_2) {
	FredkinCell f('1');
	ASSERT_TRUE(f.isAlive());
	ASSERT_EQ(f.age, 1);
}

TEST(LifeFixture, fredkin_cell_constr_test_3) {
	FredkinCell f('3');
	ASSERT_TRUE(f.isAlive());
	ASSERT_EQ(f.age, 3);
}

// Fredkin Cell Update Neighbor Tests
TEST(LifeFixture, fc_update_neighbor_test_1) {
	FredkinCell f('1');
	f.updateNeighborCount(-1,0);
	ASSERT_EQ(f.neighbor_count, 1);
	f.updateNeighborCount(-1,1);
	ASSERT_EQ(f.neighbor_count, 1);
}

TEST(LifeFixture, fc_update_neighbor_test_2) {
	FredkinCell f('1');
	f.updateNeighborCount(0,0);
	ASSERT_EQ(f.neighbor_count, 0);
}

TEST(LifeFixture, fc_update_neighbor_test_3) {
	FredkinCell f('1');
	f.updateNeighborCount(-1,-1);
	ASSERT_EQ(f.neighbor_count, 0);
	f.updateNeighborCount(1,1);
	ASSERT_EQ(f.neighbor_count, 0);
	f.updateNeighborCount(0,1);
	ASSERT_EQ(f.neighbor_count, 1);
}

// Fredkin Cell Update State Tests
TEST(LifeFixture, fc_update_state_test_1) {
	FredkinCell f('-');
	f.neighbor_count = 3;
	int val = f.updateState();
	ASSERT_TRUE(val == 0 && f.isAlive());
}

TEST(LifeFixture, fc_update_state_test_2) {
	FredkinCell f('-');
	f.updateNeighborCount(1,0);
	int val = f.updateState();
	ASSERT_TRUE(val == 0 && f.isAlive());
}

TEST(LifeFixture, fc_update_state_test_3) {
	FredkinCell f('1');
	f.updateNeighborCount(1,0);
	int val = f.updateState();
	ASSERT_TRUE(val == 2 && f.isAlive());
}

TEST(LifeFixture, fc_update_state_test_4) {
	FredkinCell f('1');
	f.updateNeighborCount(1,0);
	int val = f.updateState();
	ASSERT_TRUE(val == 2 && f.isAlive());
	f.updateNeighborCount(1,0);
	val = f.updateState();
	ASSERT_TRUE(val == 3 && f.isAlive());
}

TEST(LifeFixture, fc_update_state_test_5) {
	FredkinCell f('1');
	f.updateNeighborCount(1,0);
	f.updateNeighborCount(0,1);
	int val = f.updateState();
	ASSERT_TRUE(val == 1 && !f.isAlive());
	f.updateNeighborCount(1,0);
	val = f.updateState();
	ASSERT_TRUE(val == 1 && f.isAlive());
}


// -----------
// CELL HOLDER
// -----------

// Cell Constructor Tests
TEST(LifeFixture, cell_constr_test_1) {
	Cell c('*');
	ConwayCell* cc = dynamic_cast<ConwayCell*>(c.abs_cell);
	ASSERT_TRUE(cc != nullptr);
}

TEST(LifeFixture, cell_constr_test_2) {
	Cell c('.');
	ConwayCell* cc = dynamic_cast<ConwayCell*>(c.abs_cell);
	ASSERT_TRUE(cc != nullptr);
}

TEST(LifeFixture, cell_constr_test_3) {
	Cell c('1');
	FredkinCell* fc = dynamic_cast<FredkinCell*>(c.abs_cell);
	ASSERT_TRUE(fc != nullptr);
}

TEST(LifeFixture, cell_constr_test_4) {
	Cell c('-');
	FredkinCell* fc = dynamic_cast<FredkinCell*>(c.abs_cell);
	ASSERT_TRUE(fc != nullptr);
}
// Cell Update Neighbor Tests
TEST(LifeFixture, cell_update_neighbor_test_1) {
	Cell c('*');
	c.updateNeighborCount(-1,-1);
	ASSERT_EQ(c.abs_cell->neighbor_count, 1);
}

TEST(LifeFixture, cell_update_neighbor_test_2) {
	Cell c('*');
	c.updateNeighborCount(0,0);
	ASSERT_EQ(c.abs_cell->neighbor_count, 0);
}

TEST(LifeFixture, cell_update_neighbor_test_3) {
	Cell c('1');
	c.updateNeighborCount(-1,0);
	ASSERT_EQ(c.abs_cell->neighbor_count, 1);
}

TEST(LifeFixture, cell_update_neighbor_test_4) {
	Cell c('1');
	c.updateNeighborCount(1,1);
	ASSERT_EQ(c.abs_cell->neighbor_count, 0);
}
// Cell Update State Tests
TEST(LifeFixture, cell_update_state_test_1) {
	Cell c('*');
	c.updateNeighborCount(1,1);
	c.updateState();
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, cell_update_state_test_2) {
	Cell c('*');
	c.updateNeighborCount(1,1);
	c.updateNeighborCount(1,0);
	c.updateNeighborCount(0,0);
	c.updateState();
	ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, cell_update_state_test_3) {
	Cell c('1');
	c.updateNeighborCount(-1,0);
	c.updateNeighborCount(1,0);
	c.updateNeighborCount(0,0);
	c.updateState();
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, cell_update_state_test_4) {
	Cell c('-');
	c.updateNeighborCount(1,0);
	c.updateNeighborCount(0,0);
	c.updateState();
	ASSERT_TRUE(c.isAlive());
}

// Cell holder class print test
TEST(LifeFixture, cell_print_test_1) {
	Cell c('-');
	stringstream out;
	out << c;
	ASSERT_EQ("-", out.str());
}

TEST(LifeFixture, cell_print_test_2) {
	Cell c('*');
	stringstream out;
	out << c;
	ASSERT_EQ("*", out.str());
}

TEST(LifeFixture, cell_print_test_3) {
	Cell c('.');
	stringstream out;
	out << c;
	ASSERT_EQ(".", out.str());
}

TEST(LifeFixture, cell_print_test_4) {
	Cell c('5');
	stringstream out;
	out << c;
	ASSERT_EQ("5", out.str());
}