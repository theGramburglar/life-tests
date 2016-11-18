// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "Life.h"
#include "gtest/gtest.h"
#include <sstream>

using namespace std;

// ----
// test
// ----

// ----------
// Life Tests
// ----------


// Constructors
TEST(LifeFixture, life_constructor_1) {
	stringstream i("");
    Life<Cell> x(i, 0, 0);
    ASSERT_EQ(x.population, 0);
    ASSERT_EQ(x.turn, 0);
    ASSERT_EQ((int) x._board.size(), 0);
    ASSERT_EQ((int) x._neighbor_counts.size(), 0);
}


TEST(LifeFixture, life_constructor_2) {
	stringstream i("...\n.*.\n...");
    Life<ConwayCell> x(i, 3, 3);
    ASSERT_EQ(x.population, 1);
    ASSERT_EQ(x.turn, 0);
    ASSERT_EQ((int) x._board.size(), 3);
    ASSERT_EQ((int) x._neighbor_counts.size(), 3);
    ASSERT_TRUE(x._board[1][1].isAlive());
}

TEST(LifeFixture, life_constructor_3) {
	stringstream i("-0-\n0-0\n-0-");
    Life<FredkinCell> x(i, 3, 3);
    ASSERT_EQ(x.population, 4);
    ASSERT_EQ(x.turn, 0);
    ASSERT_EQ((int) x._board.size(), 3);
    ASSERT_EQ((int) x._neighbor_counts.size(), 3);
    ASSERT_TRUE(!x._board[1][1].isAlive());
    ASSERT_TRUE(x._board[0][1].isAlive());
}

TEST(LifeFixture, life_constructor_4) {
	stringstream i("***\n0-0\n***");
    Life<Cell> x(i, 3, 3);
    ASSERT_EQ(x.population, 8);
    ASSERT_EQ(x.turn, 0);
    ASSERT_EQ((int) x._board.size(), 3);
    ASSERT_EQ((int) x._neighbor_counts.size(), 3);
    ASSERT_TRUE(!x._board[1][1].isAlive());
    ASSERT_TRUE(x._board[0][1].isAlive());
}

// Output/print operator
TEST(LifeFixture, life_print_1) {
	stringstream out;
	stringstream s("...\n...\n...");
	stringstream s2("Generation = 0, Population = 0.\n...\n...\n...\n");

	Life<ConwayCell> l(s, 3, 3);

	out << l;

	ASSERT_EQ(out.str(), s2.str());
}

TEST(LifeFixture, life_print_2) {
	stringstream out;
	stringstream s("...\n.*.\n...");
	stringstream s2("Generation = 0, Population = 1.\n...\n.*.\n...\n");

	Life<ConwayCell> l(s, 3, 3);

	out << l;

	ASSERT_EQ(out.str(), s2.str());
}

TEST(LifeFixture, life_print_3) {
	stringstream out;
	stringstream s("*..\n.*.\n..*\n");
	stringstream s2("Generation = 0, Population = 3.\n*..\n.*.\n..*\n");

	Life<ConwayCell> l(s, 3, 3);

	out << l;

	ASSERT_EQ(out.str(), s2.str());
}

// Simulate method
TEST(LifeFixture, life_simulate_1) {
	stringstream out;
	stringstream s(".*.\n***\n.*.");
	stringstream s2("Generation = 1, Population = 8.\n***\n*.*\n***\n");

	Life<ConwayCell> l(s, 3, 3);
	l.simulate();

	out << l;

	ASSERT_EQ(out.str(), s2.str());
}

TEST(LifeFixture, life_simulate_2) {
	stringstream out;
	stringstream s("-0-\n000\n-0-");
	stringstream s2("Generation = 1, Population = 4.\n-1-\n1-1\n-1-\n");

	Life<FredkinCell> l(s, 3, 3);
	l.simulate();

	out << l;

	ASSERT_EQ(out.str(), s2.str());
}

TEST(LifeFixture, life_simulate_3) {
	stringstream out;
	stringstream s("---\n-0-\n---");
	stringstream s2("Generation = 1, Population = 4.\n-0-\n0-0\n-0-\n");

	Life<FredkinCell> l(s, 3, 3);
	l.simulate();

	out << l;

	ASSERT_EQ(out.str(), s2.str());
}

TEST(LifeFixture, life_simulate_4) {
	stringstream out;
	stringstream s("--------\n--------\n---00---\n--0000--\n--------\n--------");
	stringstream s2("Generation = 20, Population = 22.\n11566511\n-1----1-\n2-3113-2\n--+--+--\n3------3\n1------1\n");

	Life<FredkinCell> l(s, 6, 8);
	for (int x = 0; x < 20; ++x){
        l.simulate();
    }

	out << l;

	ASSERT_EQ(out.str(), s2.str());
}

TEST(LifeFixture, life_simulate_5) {
	stringstream out;
	stringstream s("--------\n--------\n---00---\n--0000--\n--------\n--------");
	stringstream s2("Generation = 20, Population = 18.\n...**...\n.**..**.\n*..**..*\n.*....*.\n1.*..*.1\n...**...\n");

	Life<Cell> l(s, 6, 8);
	for (int x = 0; x < 20; ++x){
        l.simulate();
    }

	out << l;

	ASSERT_EQ(out.str(), s2.str());
}

// ----------------
// ConwayCell Tests
// ----------------

// Constructors

// Default
TEST(LifeFixture, conwayCell_default_constructor_1) {
	ConwayCell c = ConwayCell();
	ASSERT_TRUE(!c.isAlive());
}

// Char Constrcutors
TEST(LifeFixture, conwayCell_char_constructor_1) {
	ConwayCell c = ConwayCell('.');
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, conwayCell_char_constructor_2) {
	ConwayCell c = ConwayCell('*');
	ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, conwayCell_char_constructor_3) {
	ASSERT_ANY_THROW(ConwayCell('h'));
}

// CellState Constructors
TEST(LifeFixture, conwayCell_state_constructor_1) {
	ConwayCell c = ConwayCell(alive);
	ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, conwayCell_state_constructor_2) {
	ConwayCell c = ConwayCell(dead);
	ASSERT_TRUE(!c.isAlive());
}

// Copy Constrcutors
TEST(LifeFixture, conwayCell_copy_constructor_1) {
	ConwayCell c = ConwayCell(alive);
	ConwayCell b(c);
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_TRUE(&c != &b);
}

TEST(LifeFixture, conwayCell_copy_constructor_2) {
	ConwayCell c = ConwayCell(dead);
	ConwayCell b(c);
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_TRUE(&c != &b);
}

TEST(LifeFixture, conwayCell_copy_assignment_1) {
	ConwayCell c = ConwayCell(dead);
	ConwayCell b;
	b = c;
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_TRUE(&c != &b);
}

TEST(LifeFixture, conwayCell_copy_assignment_2) {
	ConwayCell c = ConwayCell(alive);
	ConwayCell b;
	b = c;
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_TRUE(&c != &b);
}

// Update method
TEST(LifeFixture, conwayCell_update_1) {
	ConwayCell c = ConwayCell(dead);
	c.update(0);
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, conwayCell_update_2) {
	ConwayCell c = ConwayCell(dead);
	for (int x = 0; x <= 8; ++x) {
		if (x != 3)
			c.update(x);
		ASSERT_TRUE(!c.isAlive());
	}
	c.update(3);
	ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, conwayCell_update_3) {
	ConwayCell c = ConwayCell(alive);
	for (int x = 2; x <= 3; ++x) {
		c.update(x);
		ASSERT_TRUE(c.isAlive());
	}
	c.update(1);
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, conwayCell_update_4) {
	ConwayCell c = ConwayCell(alive);
	for (int x = 2; x <= 3; ++x) {
		c.update(x);
		ASSERT_TRUE(c.isAlive());
	}
	c.update(1);
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, conwayCell_update_5) {
	ConwayCell c = ConwayCell(alive);
	ASSERT_EQ(c.update(0), -1);
}

TEST(LifeFixture, conwayCell_update_6) {
	ConwayCell c = ConwayCell(alive);
	ASSERT_EQ(c.update(3), 0);
}

// shouldUpdateForRelativeNeighbor method
TEST(LifeFixture, conwayCell_shouldUpdate_1) {
	ConwayCell c = ConwayCell();
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(0, 1));
}

TEST(LifeFixture, conwayCell_shouldUpdate_2) {
	ConwayCell c = ConwayCell();
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(1, 0));
}

TEST(LifeFixture, conwayCell_shouldUpdate_3) {
	ConwayCell c = ConwayCell();
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(-1, 1));
}

// Clone method
TEST(LifeFixture, conwayCell_clone_1) {
	ConwayCell c = ConwayCell(dead);
	AbstractCell *b = c.clone();
	ASSERT_TRUE(&c != b);
	ASSERT_EQ(c.isAlive(), b->isAlive());
	delete b;
}

TEST(LifeFixture, conwayCell_clone_2) {
	ConwayCell c = ConwayCell(alive);
	AbstractCell *b = c.clone();
	ASSERT_TRUE(&c != b);
	ASSERT_EQ(c.isAlive(), b->isAlive());
	delete b;
}

// Name method
TEST(LifeFixture, conwayCell_name_1) {
	ConwayCell c = ConwayCell(dead);
	ASSERT_EQ(c.name(), '.');
}

TEST(LifeFixture, conwayCell_name_2) {
	ConwayCell c = ConwayCell(alive);
	ASSERT_EQ(c.name(), '*');
}

// -----------------
// FredkinCell Tests
// -----------------

// Name method
TEST(LifeFixture, fredkinCell_name_1) {
	FredkinCell c = FredkinCell(alive);
	ASSERT_EQ(c.name(), '0');
}

TEST(LifeFixture, fredkinCell_name_2) {
	FredkinCell c = FredkinCell(dead);
	ASSERT_EQ(c.name(), '-');
}

TEST(LifeFixture, fredkinCell_name_3) {
	FredkinCell c = FredkinCell(alive);
	c.age = 1;
	ASSERT_EQ(c.name(), '1');
}

TEST(LifeFixture, fredkinCell_name_4) {
	FredkinCell c = FredkinCell(alive);
	c.age = 9;
	ASSERT_EQ(c.name(), '9');
}

TEST(LifeFixture, fredkinCell_name_5) {
	FredkinCell c = FredkinCell(alive);
	c.age = 10;
	ASSERT_EQ(c.name(), '+');
}

TEST(LifeFixture, fredkinCell_name_6) {
	FredkinCell c = FredkinCell(alive);
	c.age = 1000;
	ASSERT_EQ(c.name(), '+');
}

// Constructors

// Default
TEST(LifeFixture, fredkinCell_default_constructor_1) {
	FredkinCell c = FredkinCell();
	ASSERT_EQ(c.age, 0);
	ASSERT_TRUE(!c.isAlive());
}

// Char constructors
TEST(LifeFixture, fredkinCell_char_constructor_1) {
	FredkinCell c = FredkinCell('0');
	ASSERT_EQ(c.age, 0);
	ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, fredkinCell_char_constructor_2) {
	FredkinCell c = FredkinCell('-');
	ASSERT_EQ(c.age, 0);
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, fredkinCell_char_constructor_3) {
	ASSERT_ANY_THROW(FredkinCell('m'));
}

// CellState constructors
TEST(LifeFixture, fredkinCell_state_constructor_1) {
	FredkinCell c = FredkinCell(dead);
	ASSERT_EQ(c.age, 0);
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, fredkinCell_state_constructor_2) {
	FredkinCell c = FredkinCell(alive);
	ASSERT_EQ(c.age, 0);
	ASSERT_TRUE(c.isAlive());
}

// Copy constructors
TEST(LifeFixture, fredkinCell_copy_constructor_1) {
	FredkinCell c = FredkinCell(alive);
	FredkinCell b(c);
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_EQ(c.age, b.age);
	ASSERT_TRUE(&c != &b);
}

TEST(LifeFixture, fredkinCell_copy_constructor_2) {
	FredkinCell c = FredkinCell(dead);
	FredkinCell b(c);
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_EQ(c.age, b.age);
	ASSERT_TRUE(&c != &b);
}

TEST(LifeFixture, fredkinCell_copy_constructor_3) {
	FredkinCell c = FredkinCell(alive);
	c.age = 5;
	FredkinCell b(c);
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_EQ(c.age, b.age);
	ASSERT_TRUE(&c != &b);
}

// Copy assignment operators
TEST(LifeFixture, fredkinCell_copy_assignment_1) {
	FredkinCell c = FredkinCell(dead);
	FredkinCell b;
	b = c;
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_EQ(c.age, b.age);
	ASSERT_TRUE(&c != &b);
}

TEST(LifeFixture, fredkinCell_copy_assignment_2) {
	FredkinCell c = FredkinCell(alive);
	FredkinCell b;
	b = c;
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_EQ(c.age, b.age);
	ASSERT_TRUE(&c != &b);
}

TEST(LifeFixture, fredkinCell_copy_assignment_3) {
	FredkinCell c = FredkinCell(alive);
	FredkinCell b;
	c.age = 10;
	b.age = 2;
	b = c;
	ASSERT_EQ(c.isAlive(), b.isAlive());
	ASSERT_EQ(c.age, b.age);
	ASSERT_TRUE(&c != &b);
}

// Clone method
TEST(LifeFixture, fredkinCell_clone_1) {
	FredkinCell c = FredkinCell(dead);
	AbstractCell *b = c.clone();
	ASSERT_TRUE(&c != b);
	ASSERT_EQ(c.isAlive(), b->isAlive());

	if (FredkinCell *f = dynamic_cast<FredkinCell*>(b)) {
		ASSERT_EQ(c.age, f->age);
	} else {
		ASSERT_TRUE(false);
	}

	delete b;
}

TEST(LifeFixture, fredkinCell_clone_2) {
	FredkinCell c = FredkinCell(alive);
	AbstractCell *b = c.clone();
	ASSERT_TRUE(&c != b);
	ASSERT_EQ(c.isAlive(), b->isAlive());

	if (FredkinCell *f = dynamic_cast<FredkinCell*>(b)) {
		ASSERT_EQ(c.age, f->age);
	} else {
		ASSERT_TRUE(false);
	}

	delete b;
}

TEST(LifeFixture, fredkinCell_clone_3) {
	FredkinCell c = FredkinCell(alive);
	c.age = 5;
	AbstractCell *b = c.clone();
	ASSERT_TRUE(&c != b);
	ASSERT_EQ(c.isAlive(), b->isAlive());

	if (FredkinCell *f = dynamic_cast<FredkinCell*>(b)) {
		ASSERT_EQ(c.age, f->age);
	} else {
		ASSERT_TRUE(false);
	}

	delete b;
}

// Update method
TEST(LifeFixture, fredkinCell_update_1) {
	FredkinCell c = FredkinCell(dead);
	c.update(0);
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, fredkinCell_update_2) {
	FredkinCell c = FredkinCell(dead);
	c.update(1);
	ASSERT_TRUE(c.isAlive());
	c.update(3);
	ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, fredkinCell_update_3) {
	FredkinCell c = FredkinCell(alive);
	c.update(0);
	ASSERT_TRUE(!c.isAlive());
	c.update(2);
	ASSERT_TRUE(!c.isAlive());
	c.update(4);
	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, fredkinCell_update_4) {
	FredkinCell c = FredkinCell(dead);
	c.update(1);
	ASSERT_TRUE(c.isAlive());
	ASSERT_EQ(c.age, 0);
	c.update(1);
	ASSERT_TRUE(c.isAlive());
	ASSERT_EQ(c.age, 1);
}

TEST(LifeFixture, fredkinCell_update_5) {
	FredkinCell c = FredkinCell(alive);
	c.update(1);
	ASSERT_TRUE(c.isAlive());
	ASSERT_EQ(c.age, 1);

	c.update(0);
	ASSERT_TRUE(!c.isAlive());
	ASSERT_EQ(c.age, 1);

	c.update(1);
	ASSERT_TRUE(c.isAlive());
	ASSERT_EQ(c.age, 1);

	c.update(1);
	ASSERT_TRUE(c.isAlive());
	ASSERT_EQ(c.age, 2);
}

TEST(LifeFixture, fredkinCell_update_6) {
	FredkinCell c = FredkinCell(alive);
	ASSERT_EQ(c.update(1), c.age);
}

TEST(LifeFixture, fredkinCell_update_7) {
	FredkinCell c = FredkinCell(alive);
	ASSERT_EQ(c.update(0), -1);
}

// ShouldUpdateForRelativeNeighbor method
TEST(LifeFixture, fredkinCell_shouldUpdate_1) {
	FredkinCell c = FredkinCell();
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(0, 1));
}

TEST(LifeFixture, fredkinCell_shouldUpdate_2) {
	FredkinCell c = FredkinCell();
	ASSERT_TRUE(!c.shouldUpdateForRelativeNeighbor(1, 1));
}

TEST(LifeFixture, fredkinCell_shouldUpdate_3) {
	FredkinCell c = FredkinCell();
	ASSERT_TRUE(!c.shouldUpdateForRelativeNeighbor(-1, 1));
}

TEST(LifeFixture, fredkinCell_shouldUpdate_4) {
	FredkinCell c = FredkinCell();
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(-1, 0));
}

// -----------------
// Cell Constructors
// -----------------

// Default
TEST(LifeFixture, cell_default_constructor_1) {
	Cell c = Cell();
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
}

// Char constructor
TEST(LifeFixture, cell_char_constructor_1) {
	Cell c = Cell('.');
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(dynamic_cast<ConwayCell*>(c._abstractCell));
}

TEST(LifeFixture, cell_char_constructor_2) {
	Cell c = Cell('*');
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(dynamic_cast<ConwayCell*>(c._abstractCell));
}

TEST(LifeFixture, cell_char_constructor_3) {
	Cell c = Cell('-');
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
}

TEST(LifeFixture, cell_char_constructor_4) {
	Cell c = Cell('0');
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
}

TEST(LifeFixture, cell_char_constructor_5) {
	ASSERT_ANY_THROW(Cell('h'));
}

// Copy constructor
TEST(LifeFixture, cell_copy_constructor_1) {
	Cell c;
	Cell b(c);
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(b._abstractCell));
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
	ASSERT_TRUE(&c != &b);
	ASSERT_TRUE(c._abstractCell != b._abstractCell);
	ASSERT_EQ(c.isAlive(), b.isAlive());
}

TEST(LifeFixture, cell_copy_constructor_2) {
	Cell c('0');
	Cell b(c);

	if (FredkinCell *f1 = dynamic_cast<FredkinCell*>(b._abstractCell)) {
		if (FredkinCell *f2 = dynamic_cast<FredkinCell*>(c._abstractCell)) {
			ASSERT_EQ(f1->age, f2->age);
		} else {
			ASSERT_TRUE(false);
		}
	} else {
		ASSERT_TRUE(false);
	}

	ASSERT_TRUE(&c != &b);
	ASSERT_TRUE(c._abstractCell != b._abstractCell);
	ASSERT_EQ(c.isAlive(), b.isAlive());
}

TEST(LifeFixture, cell_copy_constructor_3) {
	Cell c('.');
	Cell b(c);

	ASSERT_TRUE(dynamic_cast<ConwayCell*>(b._abstractCell));
	ASSERT_TRUE(dynamic_cast<ConwayCell*>(c._abstractCell));
	ASSERT_TRUE(&c != &b);
	ASSERT_TRUE(c._abstractCell != b._abstractCell);
	ASSERT_EQ(c.isAlive(), b.isAlive());
}

// Copy assignment operator
TEST(LifeFixture, cell_copy_assignment_1) {
	Cell c('.');
	Cell b;

	b = c;

	ASSERT_TRUE(dynamic_cast<ConwayCell*>(b._abstractCell));
	ASSERT_TRUE(dynamic_cast<ConwayCell*>(c._abstractCell));
	ASSERT_TRUE(&c != &b);
	ASSERT_TRUE(c._abstractCell != b._abstractCell);
	ASSERT_EQ(c.isAlive(), b.isAlive());
}

TEST(LifeFixture, cell_copy_assignment_2) {
	Cell c('0');
	Cell b;

	b = c;

	ASSERT_TRUE(dynamic_cast<FredkinCell*>(b._abstractCell));
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
	ASSERT_TRUE(&c != &b);
	ASSERT_TRUE(c._abstractCell != b._abstractCell);
	ASSERT_EQ(c.isAlive(), b.isAlive());
}

// isAlive method
TEST(LifeFixture, cell_isAlive_1) {
	Cell c;
	c._abstractCell->state = alive;

	ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, cell_isAlive_2) {
	Cell c;
	c._abstractCell->state = dead;

	ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, cell_isAlive_3) {
	Cell c('.');
	c._abstractCell->state = alive;

	ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, cell_isAlive_4) {
	Cell c('.');
	c._abstractCell->state = dead;

	ASSERT_TRUE(!c.isAlive());
}

// Update method
TEST(LifeFixture, cell_update_1) {
	Cell c('.');
	ASSERT_TRUE(dynamic_cast<ConwayCell*>(c._abstractCell));
	ASSERT_TRUE(!c.isAlive());
	ASSERT_EQ(c.update(3), 0);
	ASSERT_TRUE(c.isAlive());
	ASSERT_EQ(c.update(3), 0);
	ASSERT_TRUE(c.isAlive());
	ASSERT_EQ(c.update(3), 0);
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(dynamic_cast<ConwayCell*>(c._abstractCell));
}

TEST(LifeFixture, cell_update_2) {
	Cell c('-');
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
	ASSERT_TRUE(!c.isAlive());
	ASSERT_EQ(c.update(3), 0);
	ASSERT_TRUE(c.isAlive());
	ASSERT_EQ(c.update(3), 1);
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
}

TEST(LifeFixture, cell_update_3) {
	Cell c('-');
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
	ASSERT_TRUE(!c.isAlive());
	ASSERT_EQ(c.update(3), 0);
	ASSERT_TRUE(c.isAlive());
	ASSERT_EQ(c.update(3), 1);
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
	ASSERT_EQ(c.update(3), 0);
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(dynamic_cast<ConwayCell*>(c._abstractCell));
}

// shouldUpdateForRelativeNeighbor method
TEST(LifeFixture, cell_shouldUpdate_1) {
	Cell c('-');
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(1, 0));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(-1, 0));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(0, 1));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(0, -1));
}


TEST(LifeFixture, cell_shouldUpdate_2) {
	Cell c('-');
	ASSERT_TRUE(dynamic_cast<FredkinCell*>(c._abstractCell));
	ASSERT_TRUE(!c.shouldUpdateForRelativeNeighbor(1, 1));
	ASSERT_TRUE(!c.shouldUpdateForRelativeNeighbor(-1, 1));
	ASSERT_TRUE(!c.shouldUpdateForRelativeNeighbor(1, 1));
	ASSERT_TRUE(!c.shouldUpdateForRelativeNeighbor(1, -1));
	ASSERT_TRUE(!c.shouldUpdateForRelativeNeighbor(0, 0));
}

TEST(LifeFixture, cell_shouldUpdate_3) {
	Cell c('.');
	ASSERT_TRUE(dynamic_cast<ConwayCell*>(c._abstractCell));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(1, 1));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(-1, 1));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(1, 1));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(1, -1));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(0, 0));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(1, 0));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(-1, 0));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(0, 1));
	ASSERT_TRUE(c.shouldUpdateForRelativeNeighbor(0, -1));
}

// Output/print operator
TEST(LifeFixture, cell_print_1) {
	stringstream out;
	stringstream s("*");

	Cell c('*');

	out << c;

	ASSERT_EQ(out.str(), s.str());
}

TEST(LifeFixture, cell_print_2) {
	stringstream out;
	stringstream s(".");

	Cell c('.');

	out << c;

	ASSERT_EQ(out.str(), s.str());
}

TEST(LifeFixture, cell_print_3) {
	stringstream out;
	stringstream s("-");

	Cell c('-');

	out << c;

	ASSERT_EQ(out.str(), s.str());
}

// ------------------
// AbstractCell Tests
// ------------------

// isAlive method
TEST(LifeFixture, abstractCell_isAlive_1) {
    ConwayCell c(alive);

    ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, abstractCell_isAlive_2) {
    ConwayCell c(dead);

    ASSERT_TRUE(!c.isAlive());
}


TEST(LifeFixture, abstractCell_isAlive_3) {
    FredkinCell c(alive);

    ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, abstractCell_isAlive_4) {
    FredkinCell c(dead);

    ASSERT_TRUE(!c.isAlive());
}

// Output/print operator
TEST(LifeFixture, abstractCell_print_1) {
	stringstream out;
	stringstream s("*");

	ConwayCell c(alive);

	out << c;

	ASSERT_EQ(out.str(), s.str());
}

TEST(LifeFixture, abstractCell_print_2) {
	stringstream out;
	stringstream s(".");

	ConwayCell c(dead);

	out << c;

	ASSERT_EQ(out.str(), s.str());
}

TEST(LifeFixture, abstractCell_print_3) {
	stringstream out;
	stringstream s("0");

	FredkinCell c(alive);

	out << c;

	ASSERT_EQ(out.str(), s.str());
}

TEST(LifeFixture, abstractCell_print_4) {
	stringstream out;
	stringstream s("-");

	FredkinCell c(dead);

	out << c;

	ASSERT_EQ(out.str(), s.str());
}

TEST(LifeFixture, abstractCell_print_5) {
	stringstream out;
	stringstream s("+");

	FredkinCell c(alive);
	c.age = 10;

	out << c;

	ASSERT_EQ(out.str(), s.str());
}

TEST(LifeFixture, abstractCell_print_6) {
	stringstream out;
	stringstream s("5");

	FredkinCell c(alive);
	c.age = 5;

	out << c;

	ASSERT_EQ(out.str(), s.str());
}
