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

// -------------------
// AbstractCellFixture
// -------------------

TEST(AbstractCellFixture, countNeighbors1) {
  ConwayCell c[8] = {};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3],
                         &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(AbstractCell::countNeighbors(cp, true), 0);
}

TEST(AbstractCellFixture, countNeighbors2) {
  ConwayCell c[8] = {true, true, true, true, true, true, true, true};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3],
                         &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(AbstractCell::countNeighbors(cp, true), 8);
}

TEST(AbstractCellFixture, countNeighbors3) {
  ConwayCell c[8] = {true, true, true, true, true, true, true, true};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3],
                         &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(AbstractCell::countNeighbors(cp, false), 4);
}

TEST(AbstractCellFixture, countNeighbors4) {
  ConwayCell c[8] = {true, true, true, true, true, false, false, false};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6]};

  ASSERT_EQ(AbstractCell::countNeighbors(cp, true), 5);
}

TEST(AbstractCellFixture, countNeighbors5) {
  ConwayCell c[8] = {true, true, true, true, true, false, false, false};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3], &c[4], &c[5]};

  ASSERT_EQ(AbstractCell::countNeighbors(cp, false), 3);
}

// -----------------
// ConwayCellFixture
// -----------------

TEST(ConwayCellFixture, neighbors1) {
  ConwayCell c[8] = {true, true, true, true, true, true, true, true};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3],
                         &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(c[0].neighbors(cp), 8);
}

TEST(ConwayCellFixture, neighbors2) {
  ConwayCell c[8] = {};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3],
                         &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(c[0].neighbors(cp), 0);
}

TEST(ConwayCellFixture, neighbors3) {
  ConwayCell c[8] = {false, true, false, true, false, true, false, true};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3],
                         &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(c[0].neighbors(cp), 4);
}

TEST(ConwayCellFixture, advance1) {
  ConwayCell c(true);
  c.advance(1);

  ASSERT_TRUE(!(c._live));
}

TEST(ConwayCellFixture, advance2) {
  ConwayCell c(false);
  c.advance(3);

  ASSERT_TRUE(c._live);
}

TEST(ConwayCellFixture, advance3) {
  ConwayCell c(true);
  c.advance(3);

  ASSERT_TRUE(c._live);
}

TEST(ConwayCellFixture, advance4) {
  ConwayCell c(false);
  c.advance(1);

  ASSERT_TRUE(!(c._live));
}

// ------------------
// FredkinCellFixture
// ------------------

TEST(FredkinCellFixture, neighbors1) {
  FredkinCell c[8] = {true, true, true, true, true, true, true, true};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3],
                         &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(c[0].neighbors(cp), 4);
}

TEST(FredkinCellFixture, neighbors2) {
  FredkinCell c[8] = {};
  AbstractCell *cp[8] = {&c[0], &c[1], &c[2], &c[3],
                         &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(c[0].neighbors(cp), 0);
}

TEST(FredkinCellFixture, neighbors3) {
  FredkinCell c[8] = {false, true, false, true, false, true, false, true};
  AbstractCell *cp[8] = {&c[0]};

  ASSERT_EQ(c[0].neighbors(cp), 0);
}

TEST(FredkinCellFixture, advance1) {
  FredkinCell c(true);
  int i = c.advance(0);

  ASSERT_TRUE(!(c._live));
  ASSERT_EQ(i, 0);
}

TEST(FredkinCellFixture, advance2) {
  FredkinCell c(false);
  int i = c.advance(1);

  ASSERT_TRUE(c._live);
  ASSERT_EQ(i, 0);
}

TEST(FredkinCellFixture, advance3) {
  FredkinCell c(true);
  int i = c.advance(1);

  ASSERT_TRUE(c._live);
  ASSERT_EQ(i, 1);
}

TEST(FredkinCellFixture, advance4) {
  FredkinCell c(false);
  int i = c.advance(0);

  ASSERT_TRUE(!(c._live));
  ASSERT_EQ(i, 0);
}

// -----------
// CellFixture
// -----------

TEST(CellFixture, constructor) {
  Cell c1(new ConwayCell);
  Cell c2(c1);
  ASSERT_TRUE(c1._cell != c2._cell);
}

TEST(CellFixture, neighbors1) {
  Cell c1(new ConwayCell);
  Cell c2(new FredkinCell);

  Cell c[8] = {new ConwayCell(true), new ConwayCell(true), new ConwayCell(true),
               new ConwayCell(true), new ConwayCell(true), new ConwayCell(true),
               new ConwayCell(true), new ConwayCell(true)};
  Cell *cp[8] = {&c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(c1.neighbors(cp), 8);
  ASSERT_EQ(c2.neighbors(cp), 4);
}

TEST(CellFixture, neighbors2) {
  Cell c1(new ConwayCell);
  Cell c2(new FredkinCell);

  Cell c[8] = {new ConwayCell(false), new ConwayCell(true),
               new ConwayCell(false), new ConwayCell(true),
               new ConwayCell(false), new ConwayCell(true),
               new ConwayCell(false), new ConwayCell(true)};
  Cell *cp[8] = {&c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6], &c[7]};

  ASSERT_EQ(c1.neighbors(cp), 4);
  ASSERT_EQ(c2.neighbors(cp), 0);
}

TEST(CellFixture, neighbors3) {
  Cell c1(new ConwayCell);
  Cell c2(new FredkinCell);

  Cell c(new FredkinCell(false));
  Cell *cp[8] = {&c};

  ASSERT_EQ(c1.neighbors(cp), 0);
  ASSERT_EQ(c2.neighbors(cp), 0);
}

TEST(CellFixture, advance1) {
  Cell c1(new ConwayCell);
  Cell c2(new FredkinCell);

  c1.advance(1);
  c2.advance(1);

  ASSERT_TRUE(!(c1._cell->_live));
  ASSERT_TRUE(c2._cell->_live);
}

TEST(CellFixture, advance2) {
  Cell c1(new ConwayCell(true));
  Cell c2(new FredkinCell(true));

  c1.advance(2);
  c2.advance(2);

  ASSERT_TRUE(c1._cell->_live);
  ASSERT_TRUE(!(c2._cell->_live));
}

TEST(CellFixture, advance3) {
  Cell c1(new FredkinCell(true));

  int i1 = c1.advance(1);
  int i2 = c1.advance(1);
  int i3 = c1.advance(1);

  ASSERT_EQ(i1, 1);
  ASSERT_EQ(i2, 2);
  ASSERT_EQ(i3, -1);
}

// -----------
// LifeFixture
// -----------

TEST(LifeFixture, print1){
  vector<ConwayCell> c(3 * 3);
  c[4] = true;
  Life<ConwayCell> l(c, 3, 3);

  l.print();
}

TEST(LifeFixture, print2) {
  vector<FredkinCell> c(3 * 3);
  c[4] = true;
  Life<FredkinCell> l(c, 3, 3);

  l.print();
}

TEST(LifeFixture, print3) {
  vector<Cell> c(3 * 3, new FredkinCell(false));
  c[4] = new ConwayCell(true);
  Life<Cell> l(c, 3, 3);
  
  l.print();

}

TEST(LifeFixture, simulate1) {
  vector<ConwayCell> c(3 * 3);
  c[4] = true;
  Life<ConwayCell> l(c, 3, 3);

  l.simulate();
  l.print();
}

TEST(LifeFixture, simulate2) {
  vector<FredkinCell> c(3 * 3);
  c[4] = true;
  Life<FredkinCell> l(c, 3, 3);

  l.simulate();
  l.print();
}

TEST(LifeFixture, simulate3) {
  vector<Cell> c(3 * 3, new FredkinCell(false));
  c[4] = new ConwayCell(true);
  Life<Cell> l(c, 3, 3);

  l.simulate();
  l.print();
}
