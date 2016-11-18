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

/* ConwayCellFixture */

TEST(ConwayCellFixture, default_constructor) {
  ConwayCell c;
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayCellFixture, bool_constructor_1) {
  ConwayCell c(false);
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayCellFixture, bool_constructor_2) {
  ConwayCell c(true);
  ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCellFixture, copy_constructor_1) {
  ConwayCell c;
  ConwayCell c2(c);
  ASSERT_TRUE(c.isAlive() == c2.isAlive());
}

TEST(ConwayCellFixture, copy_constructor_2) {
  ConwayCell c(false);
  ConwayCell c2(c);
  ASSERT_TRUE(c.isAlive() == c2.isAlive());
}

TEST(ConwayCellFixture, copy_assign_1) {
  ConwayCell c;
  ConwayCell c2 = c;
  ASSERT_TRUE(c.isAlive() == c2.isAlive());
}

TEST(ConwayCellFixture, copy_assign_2) {
  ConwayCell c(false);
  ConwayCell c2 = c;
  ASSERT_TRUE(c.isAlive() == c2.isAlive());
}

TEST(ConwayCellFixture, evolve_1) {
  ConwayCell c(true);
  ASSERT_EQ(nullptr, c.evolve(0));
}

TEST(ConwayCellFixture, evolve_2) {
  ConwayCell c(false);
  ASSERT_EQ(nullptr, c.evolve(3));
}

TEST(ConwayCellFixture, evolve_3) {
  ConwayCell c(false);
  ASSERT_EQ(nullptr, c.evolve(0));
}

TEST(ConwayCellFixture, evolve_4) {
  ConwayCell c(true);
  ASSERT_EQ(nullptr, c.evolve(1));
}

TEST(ConwayCellFixture, evolve_5) {
  ConwayCell c(true);
  ASSERT_EQ(nullptr, c.evolve(4));
}

TEST(ConwayCellFixture, evolve_6) {
  ConwayCell c(true);
  ASSERT_EQ(nullptr, c.evolve(2));
}

TEST(ConwayCellFixture, evolve_7) {
  ConwayCell c(true);
  c.evolve(0);
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayCellFixture, evolve_8) {
  ConwayCell c(false);
  c.evolve(3);
  ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCellFixture, evolve_9) {
  ConwayCell c(false);
  c.evolve(0);
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayCellFixture, evolve_10) {
  ConwayCell c(true);
  c.evolve(1);
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayCellFixture, evolve_11) {
  ConwayCell c(true);
  c.evolve(4);
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayCellFixture, evolve_12) {
  ConwayCell c(true);
  c.evolve(2);
  ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCellFixture, is_neighbor_1) {
  ConwayCell c;
  ASSERT_TRUE(c.isNeighbor(0));
}

TEST(ConwayCellFixture, is_neighbor_2) {
  ConwayCell c;
  ASSERT_TRUE(c.isNeighbor(1));
}

TEST(ConwayCellFixture, is_neighbor_3) {
  ConwayCell c;
  ASSERT_TRUE(c.isNeighbor(2));
}

TEST(ConwayCellFixture, is_neighbor_4) {
  ConwayCell c;
  ASSERT_TRUE(c.isNeighbor(3));
}

TEST(ConwayCellFixture, clone_1) {
  ConwayCell c;
  AbstractCell *c2 = c.clone();
  ASSERT_TRUE(&c != c2);
}

TEST(ConwayCellFixture, clone_2) {
  ConwayCell c(true);
  AbstractCell *c2 = c.clone();
  ASSERT_TRUE(c.isAlive() == c2->isAlive());
}

TEST(ConwayCellFixture, stream_1) {
  ostringstream w;
  ConwayCell c;
  w << c;
  ASSERT_EQ(".", w.str());
}

TEST(ConwayCellFixture, stream_2) {
  ostringstream w;
  ConwayCell c(true);
  w << c;
  ASSERT_EQ("*", w.str());
}

/* FredkinCellFixture */

TEST(FredkinCellFixture, default_constructor) {
  FredkinCell c;
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCellFixture, bool_constructor_1) {
  FredkinCell c(false);
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCellFixture, bool_constructor_2) {
  FredkinCell c(true);
  ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCellFixture, copy_constructor_1) {
  FredkinCell c;
  FredkinCell c2(c);
  ASSERT_TRUE(c.isAlive() == c2.isAlive());
}

TEST(FredkinCellFixture, copy_constructor_2) {
  FredkinCell c(false);
  FredkinCell c2(c);
  ASSERT_TRUE(c.isAlive() == c2.isAlive());
}

TEST(FredkinCellFixture, copy_constructor_3) {
	FredkinCell c(true);
	c.evolve(1);
	FredkinCell c2(c);
	ASSERT_TRUE(c._age == c2._age);
}

TEST(FredkinCellFixture, copy_assign_1) {
  FredkinCell c;
  FredkinCell c2 = c;
  ASSERT_TRUE(c.isAlive() == c2.isAlive());
}

TEST(FredkinCellFixture, copy_assign_2) {
  FredkinCell c(false);
  FredkinCell c2 = c;
  ASSERT_TRUE(c.isAlive() == c2.isAlive());
}

TEST(FredkinCellFixture, copy_assign_3) {
	FredkinCell c(true);
	c.evolve(1);
	FredkinCell c2 = c;
	ASSERT_TRUE(c._age == c2._age);
}

TEST(FredkinCellFixture, evolve_1) {
  FredkinCell c(true);
  ASSERT_EQ(nullptr, c.evolve(0));
}

TEST(FredkinCellFixture, evolve_2) {
  FredkinCell c(false);
  ASSERT_EQ(nullptr, c.evolve(3));
}

TEST(FredkinCellFixture, evolve_3) {
  FredkinCell c(false);
  ASSERT_EQ(nullptr, c.evolve(0));
}

TEST(FredkinCellFixture, evolve_4) {
  FredkinCell c(true);
  ASSERT_EQ(nullptr, c.evolve(1));
}

TEST(FredkinCellFixture, evolve_5) {
  FredkinCell c(true);
  ASSERT_EQ(nullptr, c.evolve(4));
}

TEST(FredkinCellFixture, evolve_6) {
  FredkinCell c(true);
  ASSERT_EQ(nullptr, c.evolve(2));
}

TEST(FredkinCellFixture, evolve_7) {
  FredkinCell c(true);
  c.evolve(0);
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCellFixture, evolve_8) {
  FredkinCell c(false);
  c.evolve(3);
  ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCellFixture, evolve_9) {
  FredkinCell c(false);
  c.evolve(0);
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCellFixture, evolve_10) {
  FredkinCell c(true);
  c.evolve(1);
  ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCellFixture, evolve_11) {
  FredkinCell c(true);
  c.evolve(4);
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCellFixture, evolve_12) {
  FredkinCell c(true);
  c.evolve(2);
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCellFixture, evolve_13) {
	FredkinCell c(true);
	c.evolve(1);
	ASSERT_EQ(1, c._age);
}

TEST(FredkinCellFixture, is_neighbor_1) {
  FredkinCell c;
  ASSERT_FALSE(c.isNeighbor(0));
}

TEST(FredkinCellFixture, is_neighbor_2) {
  FredkinCell c;
  ASSERT_TRUE(c.isNeighbor(1));
}

TEST(FredkinCellFixture, is_neighbor_3) {
  FredkinCell c;
  ASSERT_FALSE(c.isNeighbor(2));
}

TEST(FredkinCellFixture, is_neighbor_4) {
  FredkinCell c;
  ASSERT_TRUE(c.isNeighbor(3));
}

TEST(FredkinCellFixture, clone_1) {
  FredkinCell c;
  AbstractCell *c2 = c.clone();
  ASSERT_TRUE(&c != c2);
}

TEST(FredkinCellFixture, clone_2) {
  FredkinCell c(true);
  AbstractCell *c2 = c.clone();
  ASSERT_TRUE(c.isAlive() == c2->isAlive());
}

TEST(FredkinCellFixture, stream_1) {
  ostringstream w;
  FredkinCell c;
  w << c;
  ASSERT_EQ("-", w.str());
}

TEST(FredkinCellFixture, stream_2) {
  ostringstream w;
  FredkinCell c(true);
  w << c;
  ASSERT_EQ("0", w.str());
}

TEST(FredkinCellFixture, stream_3) {
  ostringstream w;
  FredkinCell c(true);
  c.evolve(1);
  w << c;
  ASSERT_EQ("1", w.str());
}

TEST(FredkinCellFixture, stream_4) {
  ostringstream w;
  FredkinCell c(true);
  int x = 0;
  while (x < 12) {
  	c.evolve(1);
  	++x;
  }
  w << c;
  ASSERT_EQ("+", w.str());
}

/* Cell */
TEST(CellFixture, constructor) {
  AbstractCell* c = new FredkinCell();
  Cell c2(c);
  ASSERT_TRUE(c2._p == c);
}

TEST(CellFixture, copy_constructor) {
  AbstractCell* c = new FredkinCell();
  Cell c2(c);
  Cell c3(c2);
  ASSERT_FALSE(c2._p == c && c3._p == c);
}

TEST(CellFixture, copy_assign) {
  AbstractCell* c = new FredkinCell;
  Cell c2(c);
  Cell c3 = c2;
  ASSERT_FALSE(c2._p == c && c3._p == c);
}

TEST(CellFixture, evolve_1) {
  AbstractCell* c = new ConwayCell;
  Cell c2(c);
  c2.evolve(3);
  ASSERT_TRUE(c2.isAlive());
}

TEST(CellFixture, evolve_2) {
  AbstractCell* c = new FredkinCell;
  Cell c2(c);
  c2.evolve(1);
  ASSERT_TRUE(c2.isAlive());
}

TEST(CellFixture, is_neighbor_1) {
	AbstractCell* c = new ConwayCell;
	Cell c2(c);
	ASSERT_TRUE(c2.isNeighbor(0));
}

TEST(CellFixture, is_neighbor_2) {
	AbstractCell* c = new ConwayCell;
	Cell c2(c);
	ASSERT_TRUE(c2.isNeighbor(2));
}

TEST(CellFixture, is_neighbor_3) {
	AbstractCell* c = new ConwayCell;
	Cell c2(c);
	ASSERT_TRUE(c2.isNeighbor(4));
}

TEST(CellFixture, is_neighbor_4) {
	AbstractCell* c = new FredkinCell;
	Cell c2(c);
	ASSERT_TRUE(c2.isNeighbor(1));
}

TEST(CellFixture, is_alive) {
	AbstractCell* c = new ConwayCell;
	Cell c2(c);
	ASSERT_FALSE(c2.isAlive());
}

TEST(FredkinCellFixture, stream) {
  ostringstream w;
  AbstractCell* c = new FredkinCell;
  Cell c2(c);
  w << c2;
  ASSERT_EQ("-", w.str());
}

/* Life */
TEST(LifeFixture, default_constructor_1) {
	Life<ConwayCell> life = Life<ConwayCell>();
	ASSERT_EQ(0, life._grid.size());
}

TEST(LifeFixture, default_constructor_2) {
	Life<FredkinCell> life = Life<FredkinCell>();
	ASSERT_EQ(0, life._grid.size());
}

TEST(LifeFixture, default_constructor_3) {
	Life<Cell> life = Life<Cell>();
	ASSERT_EQ(0, life._grid.size());
}

TEST(LifeFixture, constructor_1) {
	vector<vector<ConwayCell>> grid(2, vector<ConwayCell>(2));
	grid[0][0] = ConwayCell();
	grid[0][1] = ConwayCell();
	grid[1][0] = ConwayCell();
	grid[1][1] = ConwayCell();

	Life<ConwayCell> life = Life<ConwayCell>(grid);
	ASSERT_EQ(2, life._grid.size());
}

TEST(LifeFixture, constructor_2) {
	vector<vector<FredkinCell>> grid(2, vector<FredkinCell>(2));
	grid[0][0] = FredkinCell();
	grid[0][1] = FredkinCell();
	grid[1][0] = FredkinCell();
	grid[1][1] = FredkinCell();

	Life<FredkinCell> life = Life<FredkinCell>(grid);
	ASSERT_EQ(2, life._grid.size());
}

TEST(LifeFixture, constructor_3) {
	vector<vector<Cell>> grid(2, vector<Cell>(3));
	grid[0][0] = Cell(new FredkinCell());
	grid[0][1] = Cell(new ConwayCell());
	grid[0][2] = Cell(new ConwayCell());
	grid[1][0] = Cell(new FredkinCell());
	grid[1][1] = Cell(new ConwayCell());
	grid[1][2] = Cell(new ConwayCell());

	Life<Cell> life = Life<Cell>(grid);
	ASSERT_EQ(3, life._grid[0].size());
}

TEST(LifeFixture, constructor_4) {
	vector<vector<Cell>> grid(2, vector<Cell>(3));
	grid[0][0] = Cell(new FredkinCell());
	grid[0][1] = Cell(new FredkinCell());
	grid[0][2] = Cell(new FredkinCell());
	grid[1][0] = Cell(new FredkinCell());
	grid[1][1] = Cell(new FredkinCell());
	grid[1][2] = Cell(new FredkinCell());

	Life<Cell> life = Life<Cell>(grid);
	ASSERT_EQ(2, life._grid.size());
}

TEST(LifeFixture, constructor_5) {
	vector<vector<Cell>> grid(2, vector<Cell>(3));
	grid[0][0] = Cell(new ConwayCell());
	grid[0][1] = Cell(new ConwayCell());
	grid[0][2] = Cell(new ConwayCell());
	grid[1][0] = Cell(new ConwayCell());
	grid[1][1] = Cell(new ConwayCell());
	grid[1][2] = Cell(new ConwayCell());

	Life<Cell> life = Life<Cell>(grid);
	ASSERT_EQ(3, life._grid[0].size());
}

TEST(LifeFixture, alive_1) {
	vector<vector<ConwayCell>> grid(2, vector<ConwayCell>(2));
	grid[0][0] = ConwayCell(true);
	grid[0][1] = ConwayCell();
	grid[1][0] = ConwayCell();
	grid[1][1] = ConwayCell();

	Life<ConwayCell> life = Life<ConwayCell>(grid);
	ASSERT_TRUE(life._grid[0][0].isAlive());
}

TEST(LifeFixture, alive_2) {
	vector<vector<ConwayCell>> grid(2, vector<ConwayCell>(2));
	grid[0][0] = ConwayCell(true);
	grid[0][1] = ConwayCell();
	grid[1][0] = ConwayCell();
	grid[1][1] = ConwayCell();

	Life<ConwayCell> life = Life<ConwayCell>(grid);
	ASSERT_FALSE(life._grid[0][1].isAlive());
}

TEST(LifeFixture, evolve_1) {
	vector<vector<ConwayCell>> grid(2, vector<ConwayCell>(2));
	grid[0][0] = ConwayCell(true);
	grid[0][1] = ConwayCell(false);
	grid[1][0] = ConwayCell(true);
	grid[1][1] = ConwayCell(false);

	Life<ConwayCell> life = Life<ConwayCell>(grid);
	life.evolve();
	ASSERT_FALSE(life._grid[0][0].isAlive());
}

TEST(LifeFixture, evolve_2) {
	vector<vector<ConwayCell>> grid(2, vector<ConwayCell>(2));
	grid[0][0] = ConwayCell(true);
	grid[0][1] = ConwayCell(false);
	grid[1][0] = ConwayCell(true);
	grid[1][1] = ConwayCell(false);

	Life<ConwayCell> life = Life<ConwayCell>(grid);
	life.evolve();
	ASSERT_FALSE(life._grid[1][0].isAlive());
}

TEST(LifeFixture, evolve_3) {
	vector<vector<ConwayCell>> grid(2, vector<ConwayCell>(2));
	grid[0][0] = ConwayCell(true);
	grid[0][1] = ConwayCell(false);
	grid[1][0] = ConwayCell(true);
	grid[1][1] = ConwayCell(false);

	Life<ConwayCell> life = Life<ConwayCell>(grid);
	life.evolve();
	life.evolve();
	ASSERT_FALSE(life._grid[0][1].isAlive());
}

TEST(LifeFixture, stream_1) {
  ostringstream w;
  Life<ConwayCell> life = Life<ConwayCell>();
  w << life;
  ASSERT_EQ("Generation = 0, Population = 0.\n", w.str());
}

TEST(LifeFixture, stream_2) {
  ostringstream w;
  Life<FredkinCell> life = Life<FredkinCell>();
  w << life;
  ASSERT_EQ("Generation = 0, Population = 0.\n", w.str());
}

TEST(LifeFixture, stream_3) {
  ostringstream w;
  Life<Cell> life = Life<Cell>();
  w << life;
  ASSERT_EQ("Generation = 0, Population = 0.\n", w.str());
}