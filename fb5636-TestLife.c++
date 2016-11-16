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

#include <iostream> // cout, endl

using namespace std;
using namespace testing;


// ----------------
// ConwayCell Tests
// ----------------

TEST(ConwayFixture, default_constructor) {
  ConwayCell c;
  ASSERT_EQ(c.isAlive(), false);
}

TEST(ConwayFixture, string_constructor_1) {
  ConwayCell c("*");
  ASSERT_EQ(c.isAlive(), true);
}

TEST(ConwayFixture, string_constructor_2) {
  ConwayCell c(".");
  ASSERT_EQ(c.isAlive(), false);
}

TEST(ConwayFixture, clone_1) {
  ConwayCell c("*");
  ConwayCell *result = c.clone();
  bool isalive = result->isAlive();
  delete result;
  ASSERT_EQ(c.isAlive(), isalive);
}

TEST(ConwayFixture, isAlive_1) {
  ConwayCell c("*");
  ASSERT_EQ(c.isAlive(), true);
}

TEST(ConwayFixture, isAlive_2) {
  ConwayCell c(".");
  ASSERT_EQ(c.isAlive(), false);
}

TEST(ConwayFixture, execute_1) {
  ConwayCell c(".");
  c.execute(3);
  ASSERT_EQ(c.isAlive(), true);
}

TEST(ConwayFixture, execute_2) {
  ConwayCell c("*");
  c.execute(1);
  ASSERT_EQ(c.isAlive(), false);
}

TEST(ConwayFixture, execute_3) {
  ConwayCell c("*");
  c.execute(4);
  ASSERT_EQ(c.isAlive(), false);
}

TEST(ConwayFixture, execute_4) {
  ConwayCell c("*");
  c.execute(2);
  ASSERT_EQ(c.isAlive(), true);
}

TEST(ConwayFixture, die_1) {
  ConwayCell c("*");
  c.die();
  ASSERT_EQ(c.isAlive(), false);
}

TEST(ConwayFixture, die_2) {
  ConwayCell c(".");
  c.die();
  ASSERT_EQ(c.isAlive(), false);
}

TEST(ConwayFixture, birth_1) {
  ConwayCell c(".");
  c.birth();
  ASSERT_EQ(c.isAlive(), true);
}

TEST(ConwayFixture, birth_2) {
  ConwayCell c("*");
  c.birth();
  ASSERT_EQ(c.isAlive(), true);
}

TEST(ConwayFixture, neighborhood_1) {
  ConwayCell c("0");
  c.neighborhood(1, 1, 3, 3);
  ASSERT_EQ(c.ifAvailable(1), true);
}

TEST(ConwayFixture, neighborhood_2) {
  ConwayCell c("0");
  c.neighborhood(1, 1, 3, 3);
  ASSERT_EQ(c.ifAvailable(0), true);
}

// -----------------
// FredkinCell Tests
// -----------------

TEST(FredkinFixture, default_constructor) {
  FredkinCell f;
  ASSERT_EQ(f.isAlive(), false);
}

TEST(FredkinFixture, string_constructor_1) {
  FredkinCell f("0");
  ASSERT_EQ(f.isAlive(), true);
}

TEST(FredkinFixture, string_constructor_2) {
  FredkinCell f("-");
  ASSERT_EQ(f.isAlive(), false);
}

TEST(FredkinFixture, clone_1) {
  FredkinCell f("0");
  FredkinCell *result = f.clone();
  bool isAlive = result->isAlive();
  delete result;
  ASSERT_EQ(f.isAlive(), isAlive);
}

TEST(FredkinFixture, isAlive_1) {
  FredkinCell f("0");
  ASSERT_EQ(f.isAlive(), true);
}

TEST(FredkinFixture, isAlive_2) {
  FredkinCell f("-");
  ASSERT_EQ(f.isAlive(), false);
}

TEST(FredkinFixture, execute_1) {
  FredkinCell f("-");
  f.execute(3);
  ASSERT_EQ(f.isAlive(), true);
}

TEST(FredkinFixture, execute_2) {
  FredkinCell f("-");
  f.execute(1);
  ASSERT_EQ(f.isAlive(), true);
}

TEST(FredkinFixture, execute_3) {
  FredkinCell f("0");
  f.execute(4);
  ASSERT_EQ(f.isAlive(), false);
}

TEST(FredkinFixture, execute_4) {
  FredkinCell f("0");
  f.execute(2);
  ASSERT_EQ(f.isAlive(), false);
}

TEST(FredkinFixture, execute_5) {
  FredkinCell f("-");
  f.execute(0);
  ASSERT_EQ(f.isAlive(), false);
}

TEST(FredkinFixture, die_1) {
  FredkinCell f("0");
  f.die();
  ASSERT_EQ(f.isAlive(), false);
}

TEST(FredkinFixture, die_2) {
  FredkinCell f("-");
  f.die();
  ASSERT_EQ(f.isAlive(), false);
}

TEST(FredkinFixture, birth_1) {
  FredkinCell f("-");
  f.birth();
  ASSERT_EQ(f.isAlive(), true);
}

TEST(FredkinFixture, birth_2) {
  FredkinCell f("0");
  f.birth();
  ASSERT_EQ(f.isAlive(), true);
}

TEST(FredkinFixture, survive_1) {
  FredkinCell f("0");
  f.survive();
  ASSERT_EQ(f.age, 1);
}

TEST(FredkinFixture, evolve_1) {
  FredkinCell f("2");
  f.survive();
  f.survive();
  AbstractCell *result = f.evolve();
  ConwayCell *p = dynamic_cast<ConwayCell *>(result);
  delete result;
  ASSERT_TRUE(p);
}

TEST(FredkinFixture, neighborhood_1) {
  FredkinCell c("0");
  c.neighborhood(1, 1, 3, 3);
  ASSERT_EQ(c.ifAvailable(1), true);
}

TEST(FredkinFixture, neighborhood_2) {
  FredkinCell c("0");
  c.neighborhood(1, 1, 3, 3);
  ASSERT_EQ(c.ifAvailable(0), false);
}

// ----------
// Cell Tests
// ----------

TEST(CellFixture, string_constructor_1) {
  Cell c("*");
  ConwayCell *result = dynamic_cast<ConwayCell *>(c._p);
  ASSERT_TRUE(result);
}

TEST(CellFixture, string_constructor_2) {
  Cell c("0");
  FredkinCell *result = dynamic_cast<FredkinCell *>(c._p);
  ASSERT_TRUE(result);
}

TEST(CellFixture, execute_1) {
  Cell c("0");
  int result = c.execute(1);
  ASSERT_EQ(result, 0);
}

TEST(CellFixture, execute_2) {
  Cell c("1");
  int result = c.execute(1);
  ASSERT_EQ(result, 0);
}

TEST(CellFixture, isAlive_1) {
  Cell c("0");
  ASSERT_EQ(c.isAlive(), true);
}

TEST(CellFixture, ifAvailable_1) {
  Cell c("*");
  c.neighborhood(1, 1, 3, 3);
  ASSERT_EQ(c.ifAvailable(0), true);
}

TEST(CellFixture, ifAvailable_2) {
  Cell c(".");
  c.neighborhood(1, 1, 3, 3);
  ASSERT_EQ(c.ifAvailable(0), true);
}

TEST(CellFixture, neighborhood_1) {
  Cell c("0");
  c.neighborhood(1, 1, 3, 3);
  ASSERT_EQ(c.ifAvailable(1), true);
}

TEST(CellFixture, neighborhood_2) {
  Cell c("0");
  c.neighborhood(1, 1, 3, 3);
  ASSERT_EQ(c.ifAvailable(0), false);
}

// ----------
// Life Tests
// ----------

TEST(LifeFixture, constructor) {
  Life<Cell> life;
  ASSERT_EQ(life.max_row, 0);
  ASSERT_EQ(life.max_col, 0);
}

TEST(LifeFixture, initialize_1) {
  Life<FredkinCell> life(0, 3, 3);
  istringstream stream("---\n-0-\n---\n");
  life.initialize(stream);
  ASSERT_EQ(life.grid[0].isAlive(), false);
}

TEST(LifeFixture, initialize_2) {
  Life<FredkinCell> life(0, 3, 3);
  istringstream stream("---\n-0-\n---\n");
  life.initialize(stream);
  ASSERT_EQ(life.grid[4].isAlive(), true);
}

TEST(LifeFixture, execute_1) {
  Life<ConwayCell> life(1, 3, 3);
  istringstream stream("...\n.*.\n...\n");
  life.initialize(stream);
  life.execute();
  ASSERT_EQ(life.current_generation, 1);
}
