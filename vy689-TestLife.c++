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

// Conway

TEST(ConwayFixture, conliveTest1) {
  ConwayCell x(1);
  ASSERT_TRUE(x.isLive());
}

TEST(ConwayFixture, conliveTest2) {
  ConwayCell x(0);
  ASSERT_FALSE(x.isLive());
}

TEST(ConwayFixture, conliveTest3) {
  ConwayCell x(0);
  x.run(3);
  ASSERT_TRUE(x.isLive());
}

TEST(ConwayFixture, conliveTest4) {
  ConwayCell x(1);
  x.run(4);
  ASSERT_FALSE(x.isLive());
}

TEST(ConwayFixture, conliveTest5) {
  ConwayCell x(1);
  x.run(2);
  ASSERT_TRUE(x.isLive());
}

TEST(ConwayFixture, conliveTest6) {
  ConwayCell x(1);
  x.run(3);
  ASSERT_TRUE(x.isLive());
}

TEST(ConwayFixture, concopyTest1) {
  ConwayCell x(1);
  ConwayCell y(0);
  x = y;
  ASSERT_FALSE(x.isLive());
}

TEST(ConwayFixture, concopyTest2) {
  ConwayCell x(0);
  ConwayCell y(1);
  x = y;
  ASSERT_TRUE(y.isLive());
  ASSERT_TRUE(x.isLive());
}

TEST(ConwayFixture, concopyTest3) {
  ConwayCell x(1);
  ConwayCell y(1);
  x = y;
  ASSERT_TRUE(x.isLive());
}

TEST(ConwayFixture, concopyconTest1) {
  ConwayCell y(0);
  ConwayCell x(y);
  ASSERT_FALSE(x.isLive());
}

TEST(ConwayFixture, concopyconTest2) {
  ConwayCell y(1);
  ConwayCell x(y);
  ASSERT_TRUE(y.isLive());
  ASSERT_TRUE(x.isLive());
}

TEST(ConwayFixture, concopyconTest3) {
  ConwayCell y(1);
  ConwayCell x(y);
  ASSERT_TRUE(x.isLive());
}

// Fredkin

TEST(FredkinFixture, fliveTest1) {
  FredkinCell x(3);
  ASSERT_TRUE(x.isLive());
}

TEST(FredkinFixture, fliveTest2) {
  FredkinCell x(2);
  ASSERT_FALSE(x.isLive());
}

TEST(FredkinFixture, fliveTest3) {
  FredkinCell x(2);
  x.run(10);
  ASSERT_TRUE(x.isLive());
}

TEST(FredkinFixture, fliveTest4) {
  FredkinCell x(2);
  x.run(20);
  ASSERT_FALSE(x.isLive());
}

TEST(FredkinFixture, fliveTest5) {
  FredkinCell x(3);
  x.run(20);
  ASSERT_FALSE(x.isLive());
}

TEST(FredkinFixture, fliveTest6) {
  FredkinCell x(3);
  x.run(10);
  ASSERT_TRUE(x.isLive());
}

TEST(FredkinFixture, fcopyTest1) {
  FredkinCell x(3);
  FredkinCell y(2);
  x = y;
  ASSERT_FALSE(x.isLive());
}

TEST(FredkinFixture, fcopyTest2) {
  FredkinCell x(2);
  FredkinCell y(3);
  x = y;
  ASSERT_TRUE(x.isLive());
}

TEST(FredkinFixture, fcopyTest3) {
  FredkinCell x(3);
  FredkinCell y(3);
  x = y;
  ASSERT_TRUE(x.isLive());
}

TEST(FredkinFixture, fcopyconTest1) {
  FredkinCell y(2);
  FredkinCell x(y);
  ASSERT_FALSE(x.isLive());
}

TEST(FredkinFixture, fcopyconTest2) {
  FredkinCell y(3);
  FredkinCell x(y);
  ASSERT_TRUE(x.isLive());
}

TEST(FredkinFixture, fcopyconTest3) {
  FredkinCell y(3);
  FredkinCell x(y);
  ASSERT_TRUE(x.isLive());
}

TEST(FredkinFixture, fageTest1) {
  FredkinCell x(2);
  x.run(10);
  ASSERT_EQ(0, x.age);
}

TEST(FredkinFixture, fageTest2) {
  FredkinCell x(2);
  x.run(20);
  ASSERT_EQ(0, x.age);
}

TEST(FredkinFixture, fageTest3) {
  FredkinCell x(3);
  x.run(20);
  ASSERT_EQ(0, x.age);
}

TEST(FredkinFixture, fageTest4) {
  FredkinCell x(3);
  x.run(10);
  ASSERT_EQ(1, x.age);
}

// Cell

TEST(CellFixture, celiveTest1) {
  Cell x(1);
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, celiveTest2) {
  Cell x(0);
  ASSERT_FALSE(x.isLive());
}

TEST(CellFixture, celiveTest3) {
  Cell x(0);
  x.run(3);
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, celiveTest4) {
  Cell x(1);
  x.run(4);
  ASSERT_FALSE(x.isLive());
}

TEST(CellFixture, celiveTest5) {
  Cell x(1);
  x.run(2);
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, celiveTest6) {
  Cell x(1);
  x.run(3);
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, celiveTest7) {
  Cell x(3);
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, celiveTest8) {
  Cell x(2);
  ASSERT_FALSE(x.isLive());
}

TEST(CellFixture, celiveTest9) {
  Cell x(2);
  x.run(10);
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, celiveTest10) {
  Cell x(2);
  x.run(20);
  ASSERT_FALSE(x.isLive());
}

TEST(CellFixture, celiveTest11) {
  Cell x(3);
  x.run(20);
  ASSERT_FALSE(x.isLive());
}

TEST(CellFixture, celiveTest12) {
  Cell x(3);
  x.run(10);
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, cecopyTest1) {
  Cell x(1);
  Cell y(0);
  x = y;
  ASSERT_FALSE(x.isLive());
}

TEST(CellFixture, cecopyTest2) {
  Cell x(0);
  Cell y(1);
  x = y;
  ASSERT_TRUE(y.isLive());
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, cecopyTest3) {
  Cell x(1);
  Cell y(1);
  x = y;
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, cecopyTest4) {
  Cell x(3);
  Cell y(2);
  x = y;
  ASSERT_FALSE(x.isLive());
}

TEST(CellFixture, cecopyTest5) {
  Cell x(2);
  Cell y(3);
  x = y;
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, cecopyTest6) {
  Cell x(3);
  Cell y(3);
  x = y;
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, cecopyconTest1) {
  Cell y(0);
  Cell x(y);
  ASSERT_FALSE(x.isLive());
}

TEST(CellFixture, cecopyconTest2) {
  Cell y(1);
  Cell x(y);
  ASSERT_TRUE(y.isLive());
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, cecopyconTest3) {
  Cell y(1);
  Cell x(y);
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, cecopyconTest4) {
  Cell y(2);
  Cell x(y);
  ASSERT_FALSE(x.isLive());
}

TEST(CellFixture, cecopyconTest5) {
  Cell y(3);
  Cell x(y);
  ASSERT_TRUE(x.isLive());
}

TEST(CellFixture, cecopyconTest6) {
  Cell y(3);
  Cell x(y);
  ASSERT_TRUE(x.isLive());
}

// Life

TEST(LifeFixture, lifeconTest1) {
  istringstream r("1 1\n*");
  Life<ConwayCell> x(r);
  ASSERT_TRUE(x.board[0][0].isLive());
  ASSERT_EQ(1, x.rows);
  ASSERT_EQ(1, x.cols);
}

TEST(LifeFixture, lifeconTest2) {
  istringstream r("1 2\n*\n.");
  Life<ConwayCell> x(r);
  ASSERT_TRUE(x.board[0][0].isLive());
  ASSERT_FALSE(x.board[0][1].isLive());
  ASSERT_EQ(1, x.rows);
  ASSERT_EQ(2, x.cols);
}

TEST(LifeFixture, liferunTest1) {
  istringstream r("1 2\n*\n.");
  Life<ConwayCell> x(r);
  x.oneTurn();
  ASSERT_FALSE(x.board[0][0].isLive());
  ASSERT_FALSE(x.board[0][1].isLive());
  ASSERT_EQ(1, x.rows);
  ASSERT_EQ(2, x.cols);
  ASSERT_EQ(1, x.turnCount);
  ASSERT_EQ(0, x.pop);
}

TEST(LifeFixture, liferunTest2) {
  istringstream r("1 2\n0\n0");
  Life<FredkinCell> x(r);
  x.oneTurn();
  ASSERT_TRUE(x.board[0][0].isLive());
  ASSERT_TRUE(x.board[0][1].isLive());
  ASSERT_EQ(1, x.rows);
  ASSERT_EQ(2, x.cols);
  ASSERT_EQ(1, x.turnCount);
  ASSERT_EQ(2, x.pop);
}

TEST(LifeFixture, lifenbrTest1) {
  istringstream r("1 2\n0\n0");
  Life<FredkinCell> x(r);
  ASSERT_EQ(11, x.getNeighborCount(0, 0));
}

TEST(LifeFixture, lifenbrTest2) {
  istringstream r("1 2\n0\n0");
  Life<FredkinCell> x(r);
  ASSERT_EQ(11, x.getNeighborCount(0, 1));
}

TEST(LifeFixture, lifenbrTest3) {
  istringstream r("2 2\n00\n00");
  Life<FredkinCell> x(r);
  ASSERT_EQ(23, x.getNeighborCount(0, 0));
}

TEST(LifeFixture, lifenbrTest4) {
  istringstream r("2 2\n00\n00");
  Life<FredkinCell> x(r);
  ASSERT_EQ(23, x.getNeighborCount(0, 1));
}

TEST(LifeFixture, lifenbrTest5) {
  istringstream r("3 3\n000\n000\n000");
  Life<FredkinCell> x(r);
  ASSERT_EQ(48, x.getNeighborCount(1, 1));
}

TEST(LifeFixture, lifenbrTest6) {
  istringstream r("3 3\n000\n000\n000");
  Life<FredkinCell> x(r);
  ASSERT_EQ(23, x.getNeighborCount(0, 0));
}

TEST(LifeFixture, lifenbrTest7) {
  istringstream r("3 3\n000\n000\n000");
  Life<FredkinCell> x(r);
  ASSERT_EQ(23, x.getNeighborCount(2, 0));
}

TEST(LifeFixture, lifenbrTest8) {
  istringstream r("3 3\n000\n000\n000");
  Life<FredkinCell> x(r);
  ASSERT_EQ(23, x.getNeighborCount(0, 2));
}

TEST(LifeFixture, lifenbrTest9) {
  istringstream r("3 3\n000\n000\n000");
  Life<FredkinCell> x(r);
  ASSERT_EQ(35, x.getNeighborCount(1, 0));
}

TEST(LifeFixture, lifenbrTest10) {
  istringstream r("3 3\n000\n000\n000");
  Life<FredkinCell> x(r);
  ASSERT_EQ(35, x.getNeighborCount(0, 1));
}

TEST(LifeFixture, lifenbrTest11) {
  istringstream r("3 3\n000\n000\n000");
  Life<FredkinCell> x(r);
  ASSERT_EQ(23, x.getNeighborCount(2, 2));
}

TEST(LifeFixture, lifenbrTest12) {
  istringstream r("3 3\n000\n000\n000");
  Life<FredkinCell> x(r);
  ASSERT_EQ(35, x.getNeighborCount(1, 2));
}

TEST(LifeFixture, lifenbrTest13) {
  istringstream r("3 3\n000\n000\n000");
  Life<FredkinCell> x(r);
  ASSERT_EQ(35, x.getNeighborCount(2, 1));
}

TEST(LifeFixture, lifenbrTest14) {
  istringstream r("3 3\n000\n0-0\n000");
  Life<Cell> x(r);
  ASSERT_EQ(22, x.getNeighborCount(2, 2));
}