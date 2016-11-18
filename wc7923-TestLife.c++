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

TEST(ConwayFixture, ConwayCellConstructorAlive) {
  ConwayCell c('*');
  ASSERT_EQ(c._symbol, '*');
}

TEST(ConwayFixture, ConwayCellConstructorDead) {
  ConwayCell c('.');
  ASSERT_EQ(c._symbol, '.');
}

TEST(ConwayFixture, ConwayCellIsAlive) {
  ConwayCell c('*');
  ASSERT_EQ(c.is_alive(), true);
}

TEST(ConwayFixture, ConwayCellIsAlive2) {
  ConwayCell c('.');
  ASSERT_EQ(c.is_alive(), false);
}

TEST(FredkinFixture, FredkinCellConstructorAlive) {
  FredkinCell c('0');
  ASSERT_EQ(c._symbol, '0');
}

TEST(FredkinFixture, FredkinCellConstructorDead) {
  FredkinCell c('-');
  ASSERT_EQ(c._symbol, '-');
}

TEST(FredkinFixture, FredkinCellIsAlive2) {
  FredkinCell c('-');
  ASSERT_EQ(c.is_alive(), false);
}

TEST(LifeFixture, ConwayCellRun) {
	int r = 5; 
	int c = 5;
	istringstream is(".....\n.....\n..***\n.....\n.....\n");
  ostringstream os;
  Life<ConwayCell> b1(r, c, is);

  for (int i = 0; i < 5; i++) {
    b1.print_board(os);
    b1.start();
  }
  ASSERT_EQ(3, b1.population);
}

TEST(LifeFixture, FredkinCellRun) {
  int r = 5; 
  int c = 5;
  istringstream is("-----\n-----\n--000\n-----\n-----\n");
  ostringstream os;
  Life<ConwayCell> b1(r, c, is);

  for (int i = 0; i < 5; i++) {
    b1.print_board(os);
    b1.start();
  }
  ASSERT_EQ(3, b1.population);
}


TEST(LifeFixture, CellRun) {
  int r = 5;
  int c = 5;
  istringstream is("00---\n0---0\n--000\n-----\n0---0\n");
  ostringstream os;
  Life<Cell> b1(r, c, is);

  for (int i = 0; i < 5; i++) {
    b1.print_board(os);
    b1.start();

  }
  // ASSERT_EQ(14, b1.population);
}