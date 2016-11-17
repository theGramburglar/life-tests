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
#include <iostream>

using namespace std;

// ----
// test
// ----

// TEST(LifeFixture, life) {
//     ASSERT_EQ(true, true);
// }

TEST(LifeFixture, life_1) {
    istringstream input( "...\n"
                         "***\n"
                         "...\n");
    istringstream results("Generation = 0, Population = 3.\n"
                          "...\n"
                          "***\n"
                          "...\n");
    ostringstream output;
    Life<ConwayCell> l(input, 3, 3);
    l.print_grid(output);
    ASSERT_EQ(results.str(), output.str());
}

TEST(LifeFixture, life_2) {
    istringstream input( "...\n"
                         "...\n"
                         "...\n");
    istringstream results("Generation = 0, Population = 0.\n"
                          "...\n"
                          "...\n"
                          "...\n");
    ostringstream output;
    Life<Cell> l(input, 3, 3);
    l.print_grid(output);
    ASSERT_EQ(results.str(), output.str());
}

TEST(LifeFixture, life_3) {
    istringstream input( "---\n"
                         "111\n"
                         "---\n");
    istringstream results("Generation = 0, Population = 3.\n"
                          "---\n"
                          "111\n"
                          "---\n");
    ostringstream output;
    Life<FredkinCell> l(input, 3, 3);
    l.print_grid(output);
    ASSERT_EQ(results.str(), output.str());
}

TEST(LifeFixture, life_4) {
    istringstream input("*..\n"
                        "...\n"
                        "...\n");
    vector<vector<int>> results{{0, 1, 0},
                                {1, 1, 0},
                                {0, 0, 0}};
    Life<ConwayCell> l(input, 3, 3);
    vector<vector<int>> neighbors = l.check_neighbors();
    ASSERT_EQ(results, neighbors);
}

TEST(LifeFixture, life_5) {
    istringstream input("...\n"
                        "...\n"
                        "...\n");
    vector<vector<int>> results{{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};
    Life<ConwayCell> l(input, 3, 3);
    vector<vector<int>> neighbors = l.check_neighbors();
    ASSERT_EQ(results, neighbors);
}

TEST(LifeFixture, life_6) {
    istringstream input("...\n"
                        ".*.\n"
                        "...\n");
    vector<vector<int>> results{{1, 1, 1},
                                {1, 0, 1},
                                {1, 1, 1}};
    Life<ConwayCell> l(input, 3, 3);
    vector<vector<int>> neighbors = l.check_neighbors();
    ASSERT_EQ(results, neighbors);
}

TEST(LifeFixture, life_7) {
    istringstream input("...\n"
                        ".*.\n"
                        "...\n");
    istringstream results("Generation = 1, Population = 0.\n"
                          "...\n"
                          "...\n"
                          "...\n");
    ostringstream output;
    Life<ConwayCell> l(input, 3, 3);
    l.run_once();
    l.print_grid(output);
    ASSERT_EQ(results.str(), output.str());
}

TEST(LifeFixture, life_8) {
    istringstream input("...\n"
                        "***\n"
                        "...\n");
    istringstream results("Generation = 1, Population = 3.\n"
                          ".*.\n"
                          ".*.\n"
                          ".*.\n");
    ostringstream output;
    Life<ConwayCell> l(input, 3, 3);
    l.run_once();
    l.print_grid(output);
    ASSERT_EQ(results.str(), output.str());
}

TEST(LifeFixture, life_9) {
    istringstream input("---\n"
                        "-9-\n"
                        "---\n");
    istringstream results("Generation = 1, Population = 4.\n"
                          "-0-\n"
                          "0-0\n"
                          "-0-\n");
    ostringstream output;
    Life<FredkinCell> l(input, 3, 3);
    l.run_once();
    l.print_grid(output);
    ASSERT_EQ(results.str(), output.str());
}

// ----
// Cell
// ----

TEST(CellFixture, cell_1) {
    Cell c('.');
    ASSERT_EQ(c.print(), '.');
}

TEST(CellFixture, cell_2) {
    Cell c('0');
    ASSERT_EQ(c.print(), '0');
}

TEST(CellFixture, cell_3) {
    Cell c('0');
    Cell c1('*');
    ASSERT_EQ(c.print(), '0');
    ASSERT_EQ(c1.print(), '*');
    ASSERT_FALSE(c1.print() == c.print());
}

TEST(CellFixture, cell_4) {
    Cell c('a');
    ASSERT_EQ(c.print(), '0');
}

TEST(CellFixture, cell_5) {
    Cell c('.');
    Cell c1('0');
    c = c1;
    ASSERT_EQ(c.print(), '0');
}

TEST(CellFixture, cell_6) {
    Cell c('.');
    Cell c1('0');
    c1 = c;
    ASSERT_EQ(c1.print(), '.');
    Cell c2('.');
    c = c2;
    ASSERT_EQ(c.print(), c2.print());
}

TEST(CellFixture, cell_7) {
    Cell c('*');
    Cell c1('0');
    c = c1;
    ASSERT_EQ(c.print(), '0');
    Cell c2('.');
    c = c2;
    ASSERT_EQ(c2.print(), c.print());
}

TEST(CellFixture, cell_8) {
    Cell c1('*');
    Cell c2(c1);
    ASSERT_EQ(c1.print(), c2.print());
}

TEST(CellFixture, cell_9) {
    Cell c1('0');
    Cell c2(c1);
    ASSERT_EQ(c1.print(), c2.print());
}

TEST(CellFixture, cell_10) {
    Cell c1('*');
    Cell c2(c1);
    ASSERT_EQ(c1.print(), c2.print());
    Cell c3('0');
    ASSERT_FALSE(c3.print() == c2.print());
}

TEST(CellFixture, cell_11) {
    Cell c('*');
    ConwayCell c1('*');
    ASSERT_EQ(c.print(), '*');
    ASSERT_EQ(c1.print(), '*');
    ASSERT_EQ(c1.print(), c.print());
    FredkinCell f('0');
    c = Cell('0');
    ASSERT_EQ(c.print(), f.print());
}

TEST(CellFixture, cell_12) {
    istringstream input("---"
                        "00-"
                        "---");
    Life<Cell> l(input, 3, 3);
    FredkinCell f('0');
    ASSERT_EQ(l.board[1][0].print(), f.print());

    l.run_once();
    ASSERT_EQ(l.board[1][0].print(), '1');
    l.run_once();

    ConwayCell c('*');
    ASSERT_EQ(l.board[1][0].print(), c.print());
}

TEST(CellFixture, cell_13) {
    Cell c('.');
    ASSERT_EQ(c.check_alive(c.print()), false);
    c.evolve(3);
    ASSERT_EQ(c.check_alive(c.print()), true);
}

TEST(CellFixture, cell_14) {
    Cell c('0');
    ASSERT_EQ(c.check_alive(c.print()), true);
    c.evolve(3);
    ASSERT_EQ(c.check_alive(c.print()), true);
    ASSERT_EQ(c.print(), '1');
}

TEST(CellFixture, cell_15) {
    Cell c('0');
    ASSERT_EQ(c.check_alive(c.print()), true);
    c.evolve(3);
    ASSERT_EQ(c.check_alive(c.print()), true);
    c.evolve(0);
    ASSERT_EQ(c.print(), '-');
    c.evolve(2);
    ASSERT_EQ(c.print(), '-');
    c.evolve(1);
    ASSERT_EQ(c.print(), '1');
}

TEST(CellFixture, cell_16) {
    Cell c('.');
    ASSERT_EQ(c.check_alive('.'), false);
    ASSERT_EQ(c.check_alive('*'), true);
}

TEST(CellFixture, cell_17) {
    Cell c('0');
    ASSERT_EQ(c.check_alive('-'), false);
    ASSERT_EQ(c.check_alive('0'), true);
    ASSERT_EQ(c.check_alive('5'), true);
    ASSERT_EQ(c.check_alive(c.print()), true);
}

TEST(CellFixture, cell_18) {
    Cell c('.');
    Cell c1('*');
    ASSERT_EQ(c.check_alive('.'), c1.check_alive('.'));
    ASSERT_FALSE(c.check_alive(c.print()) == c1.check_alive(c1.print()));
}

// ----------
// ConwayCell
// ----------

TEST(ConwayCell, C_1) {
	ConwayCell c('.');
	ASSERT_EQ(c.is_alive, false);	 
}

TEST(ConwayCell, C_2) {
	ConwayCell c('*');
	ASSERT_EQ(c.is_alive, true);	 
}

TEST(ConwayCell, C_3) {
	ConwayCell c('.');
	char d = c.print();
	ASSERT_EQ(d, '.');	 
}

TEST(ConwayCell, C_4) {
	ConwayCell c('*');
	char d = c.print();
	ASSERT_EQ(d, '*');	 
}

TEST(ConwayCell, C_4_1) {
	ConwayCell c('*');
	ConwayCell c1('.');
	ConwayCell c2('.');
	char d = c.print();
	ASSERT_EQ(d, '*');	 
	ASSERT_EQ(c1.print(), c2.print());	 
}

TEST(ConwayCell, C_4_2) {
	ConwayCell c('*');
	ConwayCell c1('*');
	ConwayCell c2('*');
	ASSERT_EQ(c.print(), c1.print());	 
	ASSERT_EQ(c.print(), c2.print());	 
}

TEST(ConwayCell, C_5) {
	ConwayCell c('.');
	bool d = c.check_alive('.');
	ASSERT_EQ(d, false);	 
}

TEST(ConwayCell, C_6) {
	ConwayCell c('*');
	bool d = c.check_alive('*');
	ASSERT_EQ(d, true);	 
}

TEST(ConwayCell, C_6_1) {
	ConwayCell c('*');
	ConwayCell c1('*');
	ASSERT_EQ(c.check_alive(c.print()), c1.check_alive(c1.print()));	 
}

TEST(ConwayCell, C_6_2) {
	ConwayCell c('*');
	ConwayCell c1('*');
	ASSERT_EQ(c.check_alive('*'), c1.check_alive('*'));	 
}

TEST(ConwayCell, C_7) {
	ConwayCell c('.');
	c.evolve(3);
	ASSERT_EQ(c.is_alive, true);	 
}

TEST(ConwayCell, C_8) {
	ConwayCell c('*');
	c.evolve(1);
	ASSERT_EQ(c.is_alive, false);	 
}

TEST(ConwayCell, C_9) {
	ConwayCell c('*');
	c.evolve(4);
	ASSERT_EQ(c.is_alive, false);	 
}

TEST(ConwayCell, C_10) {
	ConwayCell c('*');
	c.evolve(5);
	ASSERT_EQ(c.is_alive, false);	 
}

TEST(ConwayCell, C_11) {
	ConwayCell c('.');
	AbstractCell* c1 = c.clone();
	delete c1;
	ASSERT_TRUE(c1 != nullptr);
}

TEST(ConwayCell, C_12) {
	ConwayCell c('*');
	AbstractCell* c1 = c.clone();
	delete c1;
	ASSERT_TRUE(c1 != nullptr);	 
}

// -----------------
// FredkinCell Tests
// -----------------

TEST(FredkinCell, F_1) {
	FredkinCell f('-');
	ASSERT_EQ(f.is_alive, false);	 
}

TEST(FredkinCell, F_2) {
	FredkinCell f('0');
	ASSERT_EQ(f.is_alive, true);	 
}

TEST(FredkinCell, F_2_1) {
	FredkinCell f('5');
	ASSERT_EQ(f.is_alive, true);	 
}

TEST(FredkinCell, F_2_2) {
	FredkinCell f('+');
	ASSERT_EQ(f.is_alive, true);	 
}

TEST(FredkinCell, F_3) {
	FredkinCell f('-');
	ASSERT_EQ(f.age, 0);	 
}

TEST(FredkinCell, F_4) {
	FredkinCell f('0');
	ASSERT_EQ(f.age, 0);	 
}

TEST(FredkinCell, F_4_1) {
	FredkinCell f('9');
	ASSERT_EQ(f.age, 0);	 
}

TEST(FredkinCell, F_5) {
	FredkinCell f('-');
	char d = f.print();
	ASSERT_EQ(d, '-');	 
}

TEST(FredkinCell, F_6) {
	FredkinCell f('0');
	char d = f.print();
	ASSERT_EQ(d, '0');	 
}

TEST(FredkinCell, F_6_1) {
	FredkinCell f('-');
	FredkinCell f1('0');
	ASSERT_FALSE(f.print() == f1.print());	 
}

TEST(FredkinCell, F_6_2) {
	FredkinCell f('0');
	FredkinCell f1('8');
	FredkinCell f2('-');
	ASSERT_EQ(f.print(), f1.print());	 
	ASSERT_FALSE(f1.print() == f2.print());	 
}

TEST(FredkinCell, F_7) {
	FredkinCell f('-');
	bool d = f.check_alive('-');
	ASSERT_EQ(d, false);	 
}

TEST(FredkinCell, F_8) {
	FredkinCell f('0');
	bool d = f.check_alive('0');
	ASSERT_EQ(d, true);	 
}

TEST(FredkinCell, F_8_1) {
	FredkinCell f('+');
    ASSERT_EQ(f.check_alive('-'), false);
    ASSERT_FALSE(f.check_alive('+') == false);
}

TEST(FredkinCell, F_9) {
	FredkinCell f('-');
	AbstractCell* f1 = f.clone();
	delete f1;
	ASSERT_TRUE(f1 != nullptr);	 

}

TEST(FredkinCell, F_10) {
	FredkinCell f('0');
	AbstractCell* f1 = f.clone();
	delete f1;
	ASSERT_TRUE(f1 != nullptr);	 
}

TEST(FredkinCell, F_11) {
	FredkinCell f('-');
	f.evolve(3);
	ASSERT_EQ(f.is_alive, true);	 
}

TEST(FredkinCell, F_12) {
	FredkinCell f('0');
	f.evolve(1);
	ASSERT_EQ(f.is_alive, true);	 
}

TEST(FredkinCell, F_13) {
	FredkinCell f('0');
	f.evolve(0);
	ASSERT_EQ(f.is_alive, false);	 
}

TEST(FredkinCell, F_14) {
	FredkinCell f('2');
	f.evolve(2);
	ASSERT_EQ(f.is_alive, false);	 
}

TEST(FredkinCell, F_15) {
	FredkinCell f('4');
	f.evolve(4);
	ASSERT_EQ(f.is_alive, false);	 
}

