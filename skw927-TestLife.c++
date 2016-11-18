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

TEST(ConwayFixture, defaultConstructor1) {
  ConwayCell c;
  ASSERT_FALSE(c.alive);
}

TEST(ConwayFixture, boolConstructor1) {
  ConwayCell c(false);
  ASSERT_FALSE(c.alive);
}

TEST(ConwayFixture, boolConstructor2) {
  ConwayCell c(true);
  ASSERT_TRUE(c.alive);
}

TEST(ConwayFixture, clone1) {
  AbstractCell *a1;
  ConwayCell c(true);
  a1 = c.clone();
  bool alive = a1->isAlive();
  delete a1;
  ASSERT_TRUE(alive);
}

TEST(ConwayFixture, clone2) {
  AbstractCell *a1;
  ConwayCell c(false);
  a1 = c.clone();
  bool alive = a1->isAlive();
  delete a1;
  ASSERT_FALSE(alive);
}

TEST(ConwayFixture, clone3) {
  AbstractCell *a1;
  ConwayCell c;
  a1 = c.clone();
  bool alive = a1->isAlive();
  delete a1;
  ASSERT_FALSE(alive);
}

TEST(ConwayFixture, print1) {
  ConwayCell c(true);
  ostringstream w;
  c.print(w);
  ASSERT_EQ("*", w.str());
}

TEST(ConwayFixture, print2) {
  ConwayCell c(false);
  ostringstream w;
  c.print(w);
  ASSERT_EQ(".", w.str());
}

TEST(ConwayFixture, print3) {
  ConwayCell c;
  ostringstream w;
  c.print(w);
  ASSERT_EQ(".", w.str());
}

TEST(ConwayFixture, isAlive1) {
  ConwayCell c;
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayFixture, isAlive2) {
  ConwayCell c(true);
  ASSERT_TRUE(c.isAlive());
}

TEST(ConwayFixture, isAlive3) {
  ConwayCell c(false);
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayFixture, step1) {
  ConwayCell c(true);
  ASSERT_EQ(c.step(1, 0), 0);
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayFixture, step2) {
  ConwayCell c(true);
  ASSERT_EQ(c.step(1, 3), 0);
  ASSERT_FALSE(c.isAlive());
}

TEST(ConwayFixture, step3) {
  ConwayCell c(true);
  ASSERT_EQ(c.step(1, 1), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(ConwayFixture, step4) {
  ConwayCell c(true);
  ASSERT_EQ(c.step(0, 2), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(ConwayFixture, step5) {
  ConwayCell c(true);
  ASSERT_EQ(c.step(2, 0), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(ConwayFixture, step6) {
  ConwayCell c; // alive = false
  ASSERT_EQ(c.step(2, 1), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(ConwayFixture, step7) {
  ConwayCell c;
  ASSERT_EQ(c.step(0, 3), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(ConwayFixture, step8) {
  ConwayCell c;
  ASSERT_EQ(c.step(3, 0), 0);
  ASSERT_TRUE(c.isAlive());
}

// END CONWAYCELL TESTS

// BEGIN CELL TESTS

TEST(CellFixture, defaultConstructor1) {
  Cell c;
  ASSERT_EQ(nullptr, c.cell);
}

TEST(CellFixture, pointerConstructor1) {
  ConwayCell *conway = new ConwayCell();
  Cell c(conway);
  ASSERT_EQ(conway, c.cell);
}

TEST(CellFixture, pointerConstructor2) {
  FredkinCell *fredkin = new FredkinCell;
  Cell c(fredkin);
  ASSERT_EQ(fredkin, c.cell);
}

TEST(CellFixture, clone1) {
  AbstractCell *a1;
  Cell c(new ConwayCell());
  a1 = c.clone();
  bool alive = a1->isAlive();
  delete a1;
  ASSERT_FALSE(alive);
}

TEST(CellFixture, clone2) {
  AbstractCell *a1;
  Cell c(new ConwayCell(true));
  a1 = c.clone();
  bool alive = a1->isAlive();
  delete a1;
  ASSERT_TRUE(alive);
}

TEST(CellFixture, clone3) {
  AbstractCell *a1;
  Cell c(new FredkinCell());
  a1 = c.clone();
  bool alive = a1->isAlive();
  delete a1;
  ASSERT_FALSE(alive);
}

TEST(CellFixture, assign1) {
  Cell c1(new ConwayCell(true));
  ASSERT_TRUE(c1.isAlive());
  Cell c2(new ConwayCell(false));
  c1 = c2;
  ASSERT_FALSE(c1.isAlive());
}

TEST(CellFixture, assign2) {
  Cell c1(new ConwayCell(false));
  ASSERT_FALSE(c1.isAlive());
  Cell c2(new ConwayCell(true));
  c1 = c2;
  ASSERT_TRUE(c1.isAlive());
}

TEST(CellFixture, assign3) {
  Cell c1(new ConwayCell(true));
  ASSERT_TRUE(c1.isAlive());
  Cell c2(new FredkinCell());
  c1 = c2;
  ASSERT_FALSE(c1.isAlive());
}

TEST(CellFixture, print1) {
  Cell c(new ConwayCell(true));
  ostringstream w;
  c.print(w);
  ASSERT_EQ("*", w.str());
}

TEST(CellFixture, print2) {
  Cell c(new ConwayCell(false));
  ostringstream w;
  c.print(w);
  ASSERT_EQ(".", w.str());
}

TEST(CellFixture, print3) {
  Cell c(new FredkinCell());
  ostringstream w;
  c.print(w);
  ASSERT_EQ("-", w.str());
}

TEST(CellFixture, isAlive1) {
  Cell c(new ConwayCell());
  ASSERT_FALSE(c.isAlive());
}

TEST(CellFixture, isAlive2) {
  Cell c(new ConwayCell(true));
  ASSERT_TRUE(c.isAlive());
}

TEST(CellFixture, isAlive3) {
  Cell c(new FredkinCell());
  ASSERT_FALSE(c.isAlive());
}

TEST(CellFixture, step1) {
  Cell c(new ConwayCell(true));
  ASSERT_EQ(c.step(1, 0), 0);
  ASSERT_FALSE(c.isAlive());
}

TEST(CellFixture, step2) {
  Cell c(new ConwayCell(true));
  ASSERT_EQ(c.step(1, 3), 0);
  ASSERT_FALSE(c.isAlive());
}

TEST(CellFixture, step3) {
  Cell c(new ConwayCell(true));
  ASSERT_EQ(c.step(1, 1), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(CellFixture, step4) {
  Cell c(new ConwayCell(true));
  ASSERT_EQ(c.step(0, 2), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(CellFixture, step5) {
  Cell c(new ConwayCell(true));
  ASSERT_EQ(c.step(2, 0), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(CellFixture, step6) {
  Cell c(new FredkinCell()); // alive = false
  ASSERT_EQ(c.step(1, 0), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(CellFixture, step7) {
  Cell c(new FredkinCell()); // alive = false
  ASSERT_EQ(c.step(2, 0), 0);
  ASSERT_FALSE(c.isAlive());
}

TEST(CellFixture, step8) {
  Cell c(new FredkinCell(true, 0)); // alive = false
  ASSERT_EQ(c.step(1, 0), 1);
  ASSERT_EQ(c.step(1, 0), 2);
  ASSERT_EQ(c.step(2, 0), 0);
}

// END CELL TESTS

// BEGIN LIFE TESTS

TEST(LifeFixture, constructor1) {
  Life<int> b(1, 1);
  ASSERT_EQ(1, b.rows);
  ASSERT_EQ(1, b.cols);
  ASSERT_EQ(0, b.generation);
  ASSERT_EQ(1, b.board.size());
}

TEST(LifeFixture, constructor2) {
  Life<int> b(3, 5);
  ASSERT_EQ(3, b.rows);
  ASSERT_EQ(5, b.cols);
  ASSERT_EQ(0, b.generation);
  ASSERT_EQ(15, b.board.size());
}

TEST(LifeFixture, constructor3) {
  Life<int> b(10, 10);
  ASSERT_EQ(10, b.rows);
  ASSERT_EQ(10, b.cols);
  ASSERT_EQ(0, b.generation);
  ASSERT_EQ(100, b.board.size());
}

TEST(LifeFixture, put1) {
  Life<ConwayCell> b(10, 10);
  ASSERT_FALSE(b.board[44].isAlive());
  b.putCell(4, 4, ConwayCell(true));
  ASSERT_TRUE(b.board[44].isAlive());
}

TEST(LifeFixture, put2) {
  Life<ConwayCell> b(10, 10);
  ASSERT_FALSE(b.board[30].isAlive());
  b.putCell(3, 0, ConwayCell(true));
  ASSERT_TRUE(b.board[30].isAlive());
}

TEST(LifeFixture, put3) {
  Life<FredkinCell> b(10, 10);
  ASSERT_FALSE(b.board[44].isAlive());
  b.putCell(4, 4, FredkinCell(true, 0));
  ASSERT_TRUE(b.board[44].isAlive());
}

TEST(LifeFixture, population1) {
  Life<ConwayCell> b(10, 10);
  b.putCell(0, 0, ConwayCell(true));
  ASSERT_EQ(1, b.population());
}

TEST(LifeFixture, population2) {
  Life<ConwayCell> b(10, 10);
  b.putCell(0, 0, ConwayCell(true));
  b.putCell(0, 1, ConwayCell(true));
  b.putCell(0, 2, ConwayCell(true));
  b.putCell(0, 3, ConwayCell(true));
  b.putCell(0, 4, ConwayCell(true));
  ASSERT_EQ(5, b.population());
}

TEST(LifeFixture, population3) {
  Life<FredkinCell> b(10, 10);
  b.putCell(0, 0, FredkinCell(true, 0));
  b.putCell(0, 1, FredkinCell(true, 0));
  b.putCell(0, 2, FredkinCell(false, 0));
  ASSERT_EQ(2, b.population());
}

TEST(LifeFixture, print1) {
  Life<ConwayCell> b(2, 2);
  ostringstream w;
  b.print(w);
  ASSERT_EQ("Generation = 0, Population = 0.\n..\n..\n\n", w.str());
}

TEST(LifeFixture, print2) {
  Life<ConwayCell> b(3, 3);
  b.putCell(1, 1, ConwayCell(true));
  ostringstream w;
  b.print(w);
  ASSERT_EQ("Generation = 0, Population = 1.\n...\n.*.\n...\n\n", w.str());
}

TEST(LifeFixture, print3) {
  Life<FredkinCell> b(2, 2);
  ostringstream w;
  b.print(w);
  ASSERT_EQ("Generation = 0, Population = 0.\n--\n--\n\n", w.str());
}

TEST(LifeFixture, evolve1) {
  Life<ConwayCell> b(3, 3);
  b.putCell(1, 1, ConwayCell(true));
  ostringstream w;
  b.print(w);
  ASSERT_EQ("Generation = 0, Population = 1.\n...\n.*.\n...\n\n", w.str());
  b.evolve();
  ASSERT_EQ(0, b.population());
}

TEST(LifeFixture, evolve2) {
  Life<FredkinCell> b(3, 3);
  b.putCell(1, 0, FredkinCell(true, 0));
  b.putCell(1, 1, FredkinCell(true, 0));
  b.putCell(1, 2, FredkinCell(true, 0));
  ASSERT_EQ(3, b.population());
  b.evolve();
  ASSERT_EQ(8, b.population());
  b.evolve();
  ASSERT_EQ(0, b.population());
}

TEST(LifeFixture, evolve3) {
  Life<Cell> b(3, 3);
  b.putCell(0, 0, Cell(new ConwayCell()));
  b.putCell(0, 1, Cell(new ConwayCell()));
  b.putCell(0, 2, Cell(new ConwayCell()));
  b.putCell(1, 0, Cell(new FredkinCell(true, 0)));
  b.putCell(1, 1, Cell(new ConwayCell(true)));
  b.putCell(1, 2, Cell(new ConwayCell(true)));
  b.putCell(2, 0, Cell(new ConwayCell()));
  b.putCell(2, 1, Cell(new ConwayCell()));
  b.putCell(2, 2, Cell(new ConwayCell()));
  ASSERT_EQ(3, b.population());
  b.evolve();
  ASSERT_EQ(4, b.population());
  b.evolve();
  ASSERT_EQ(7, b.population());
}
// END CELL TESTS

// BEGIN FREDKINCELL TESTS

TEST(FredkinFixture, defaultConstructor1) {
  FredkinCell c;
  ASSERT_FALSE(c.alive);
  ASSERT_EQ(c.age, 0);
}

TEST(FredkinFixture, boolIntConstructor1) {
  FredkinCell c(true, 7);
  ASSERT_TRUE(c.alive);
  ASSERT_EQ(c.age, 7);
}

TEST(FredkinFixture, boolIntConstructor2) {
  FredkinCell c(false, 2);
  ASSERT_FALSE(c.alive);
  ASSERT_EQ(c.age, 2);
}

TEST(FredkinFixture, print1) {
  FredkinCell c(true, 7);
  ostringstream w;
  c.print(w);
  ASSERT_EQ("7", w.str());
}

TEST(FredkinFixture, print2) {
  FredkinCell c;
  ostringstream w;
  c.print(w);
  ASSERT_EQ("-", w.str());
}

TEST(FredkinFixture, print3) {
  FredkinCell c(true, 12);
  ostringstream w;
  c.print(w);
  ASSERT_EQ("+", w.str());
}

TEST(FredkinFixture, clone1) {
  AbstractCell *a1;
  FredkinCell c(true, 7);
  a1 = c.clone();
  bool alive = a1->isAlive();
  delete a1;
  ASSERT_TRUE(alive);
  ostringstream w;
  c.print(w);
  ASSERT_EQ("7", w.str());
}

TEST(FredkinFixture, clone2) {
  AbstractCell *a1;
  FredkinCell c;
  a1 = c.clone();
  bool alive = a1->isAlive();
  delete a1;
  ASSERT_FALSE(alive);
  ostringstream w;
  c.print(w);
  ASSERT_EQ("-", w.str());
}

TEST(FredkinFixture, clone3) {
  AbstractCell *a1;
  FredkinCell c;
  a1 = c.clone();
  bool alive = a1->isAlive();
  delete a1;
  ASSERT_FALSE(alive);
  ostringstream w;
  c.print(w);
  ASSERT_EQ("-", w.str());
}

TEST(FredkinFixture, isAlive1) {
  FredkinCell c;
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinFixture, isAlive2) {
  FredkinCell c(true, 2);
  ASSERT_TRUE(c.isAlive());
}

TEST(FredkinFixture, isAlive3) {
  FredkinCell c(true, 30);
  ASSERT_TRUE(c.isAlive());
}

TEST(FredkinFixture, step1) {
  FredkinCell c;
  ASSERT_EQ(c.step(0, 999), 0);
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinFixture, step2) {
  FredkinCell c;
  ASSERT_EQ(c.step(1, 999), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(FredkinFixture, step3) {
  FredkinCell c;
  ASSERT_EQ(c.step(3, 999), 0);
  ASSERT_TRUE(c.isAlive());
}

TEST(FredkinFixture, step4) {
  FredkinCell c(true, 2);
  ASSERT_EQ(c.step(0, 999), 2);
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinFixture, step5) {
  FredkinCell c(true, 6);
  ASSERT_EQ(c.step(2, 999), 6);
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinFixture, step6) {
  FredkinCell c(true, 77);
  ASSERT_EQ(c.step(4, 999), 77);
  ASSERT_FALSE(c.isAlive());
}

TEST(FredkinFixture, step7) {
  FredkinCell c(true, 7);
  ASSERT_EQ(c.step(1, 999), 8);
  ASSERT_TRUE(c.isAlive());
}

TEST(FredkinFixture, step8) {
  FredkinCell c(true, 5);
  ASSERT_EQ(c.step(3, 999), 6);
  ASSERT_TRUE(c.isAlive());
}

// END FREDKINCELL TESTS
