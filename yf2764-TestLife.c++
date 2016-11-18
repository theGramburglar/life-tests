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

TEST(LifeFixture, getPair) {
    Life<Cell> x(2, 2);
	ASSERT_TRUE(x.getPair(0) == make_pair(0, 0));
}

TEST(LifeFixture, getPair1) {
    Life<Cell> x(2, 2);
	ASSERT_TRUE(x.getPair(2) == make_pair(1, 0));
}

TEST(LifeFixture, getPair2) {
    Life<Cell> x(2, 2);
	ASSERT_TRUE(x.getPair(3) == make_pair(1, 1));
}

TEST(LifeFixture, getIndex) {
	Life<Cell> x(2, 2);
	ASSERT_EQ(x.getIndex(make_pair(0, 0)), 0);
}

TEST(LifeFixture, getIndex1) {
	Life<Cell> x(2, 2);
	ASSERT_EQ(x.getIndex(make_pair(1, 0)), 2);
}

TEST(LifeFixture, getIndex2) {
	Life<Cell> x(2, 2);
	ASSERT_EQ(x.getIndex(make_pair(1, 1)), 3);
}

TEST(LifeFixture, addCell) {
	Life<ConwayCell> x(2, 2);
	ConwayCell c(false);
	x.addCell(&c, false);
	ASSERT_EQ(x.board[0], &c);
}

TEST(LifeFixture, addCell1) {
	Life<ConwayCell> x(2, 2);
	ConwayCell c(false);
	ConwayCell c2(true);
	x.addCell(&c, false);
	x.addCell(&c2, true);
	ASSERT_EQ(x.board[1], &c2);
}

TEST(LifeFixture, addCell2) {
	Life<ConwayCell> x(2, 2);
	ConwayCell c(false);
	ConwayCell c2(true);
	x.addCell(&c, false);
	x.addCell(&c2, true);
	ASSERT_TRUE(x.neighbors[0]==make_pair(1, 0));
}

TEST(LifeFixture, goNeighborCount) {
	Life<ConwayCell> x(2, 2);
	ConwayCell c(false);
	ConwayCell c2(true);
	ConwayCell c3(false);
	ConwayCell c4(true);
	x.addCell(&c, false);
	x.addCell(&c2, true);
	x.addCell(&c3, false);
	x.addCell(&c4, true);
	x.go();
	ASSERT_TRUE(x.neighbors[0] == make_pair(0, 0));
	ASSERT_TRUE(x.neighbors[1] == make_pair(0, 0));
	ASSERT_TRUE(x.neighbors[2] == make_pair(0, 0));
	ASSERT_TRUE(x.neighbors[3] == make_pair(0, 0));
}

TEST(LifeFixture, goNeighborCount1) {
	Life<ConwayCell> x(2, 2);
	ConwayCell c(false);
	ConwayCell c2(true);
	ConwayCell c3(true);
	ConwayCell c4(true);
	x.addCell(&c, false);
	x.addCell(&c2, true);
	x.addCell(&c3, true);
	x.addCell(&c4, true);
	x.go();
	ASSERT_TRUE(x.neighbors[0] == make_pair(2, 1));
	ASSERT_TRUE(x.neighbors[1] == make_pair(2, 1));
	ASSERT_TRUE(x.neighbors[2] == make_pair(2, 1));
	ASSERT_TRUE(x.neighbors[3] == make_pair(2, 1));
}

TEST(LifeFixture, go) {
	Life<ConwayCell> x(2, 2);
	ConwayCell c(false);
	ConwayCell c2(true);
	ConwayCell c3(false);
	ConwayCell c4(true);
	x.addCell(&c, false);
	x.addCell(&c2, true);
	x.addCell(&c3, false);
	x.addCell(&c4, true);
	x.go();
	ASSERT_TRUE(!(x.board[0]->alive));
	ASSERT_TRUE(!(x.board[1]->alive));
	ASSERT_TRUE(!(x.board[2]->alive));
	ASSERT_TRUE(!(x.board[3]->alive));
}

TEST(LifeFixture, go1) {
	Life<ConwayCell> x(2, 2);
	ConwayCell c(false);
	ConwayCell c2(true);
	ConwayCell c3(true);
	ConwayCell c4(true);
	x.addCell(&c, false);
	x.addCell(&c2, true);
	x.addCell(&c3, true);
	x.addCell(&c4, true);
	x.go();
	ASSERT_TRUE(x.board[0]->alive);
	ASSERT_TRUE(x.board[1]->alive);
	ASSERT_TRUE(x.board[2]->alive);
	ASSERT_TRUE(x.board[3]->alive);
}

TEST(ConwayCellFixture, go) {
	ConwayCell c(false);
	ASSERT_TRUE(c.go(make_pair(1, 2)));
}

TEST(ConwayCellFixture, go1) {
	ConwayCell c(true);
	ASSERT_TRUE(c.go(make_pair(1, 2)));
}

TEST(ConwayCellFixture, go2) {
	ConwayCell c(true);
	ASSERT_TRUE(!(c.go(make_pair(0, 0))));
}

TEST(ConwayCellFixture, clone) {
	ConwayCell c(true);
	AbstractCell* a = c.clone();
	ASSERT_TRUE(a->alive);
}

TEST(FredkinCellFixture, go) {
	FredkinCell f(false);
	ASSERT_TRUE(f.go(make_pair(3, 0)));
}

TEST(FredkinCellFixture, go1) {
	FredkinCell f(true);
	ASSERT_TRUE(!(f.go(make_pair(2, 0))));
}

TEST(FredkinCellFixture, go2) {
	FredkinCell f(true);
	ASSERT_TRUE(f.go(make_pair(3, 0)));
}

TEST(FredkinCellFixture, go3) {
	FredkinCell f(false);
	ASSERT_TRUE(f.go(make_pair(3, 1)));
}

TEST(FredkinCellFixture, clone1) {
	FredkinCell f(true);
	AbstractCell* a = f.clone();
	ASSERT_TRUE(a->alive);
}

TEST(CellFixture, equal) {
	Cell c(new ConwayCell(true));
	Cell c1 = c;
	ASSERT_TRUE(c1.cell->alive);
}

TEST(CellFixture, copy) {
	Cell c(new ConwayCell(true));
	Cell c1(c);
	ASSERT_TRUE(c1.cell->alive);
}
