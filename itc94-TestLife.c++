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

TEST(LifeFixture, add1) {
  ConwayCell cell;
  Life<ConwayCell> life(1, 1);
  life.add(cell);
}

TEST(LifeFixture, add2) {
  FredkinCell cell;
  Life<FredkinCell> life(1, 1);
  life.add(cell);
}

TEST(LifeFixture, add3) {
  Cell cell(new ConwayCell());
  Life<Cell> life(1, 1);
  life.add(cell);
}

TEST(LifeFixture, add4) {
  Cell cell(new FredkinCell());
  Life<Cell> life(1, 1);
  life.add(cell);
}

TEST(LifeFixture, at1) {
  ConwayCell cell;
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  life.add(cell);
  const ConwayCell *at = life.at(0, 0);
  ASSERT_NE(at, nullptr);
}

TEST(LifeFixture, at2) {
  ConwayCell cell;
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  life.add(cell);
  const ConwayCell *at = life.at(0, 1);
  ASSERT_NE(at, nullptr);
  ASSERT_TRUE(at->alive());
}

TEST(LifeFixture, at3) {
  ConwayCell cell(false);
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  life.add(cell);
  const ConwayCell *at = life.at(0, 0);
  ASSERT_NE(at, nullptr);
  ASSERT_FALSE(at->alive());
}

TEST(LifeFixture, at4) {
  ConwayCell cell(false);
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  life.add(cell);
  const ConwayCell *at = life.at(0, 1);
  ASSERT_NE(at, nullptr);
  ASSERT_FALSE(at->alive());
}

TEST(LifeFixture, at5) {
  FredkinCell cell;
  Life<FredkinCell> life(1, 2);
  life.add(cell);
  life.add(cell);
  const FredkinCell *at = life.at(0, 0);
  ASSERT_NE(at, nullptr);
}

TEST(LifeFixture, at6) {
  FredkinCell cell;
  Life<FredkinCell> life(1, 2);
  life.add(cell);
  life.add(cell);
  const FredkinCell *at = life.at(0, 1);
  ASSERT_NE(at, nullptr);
  ASSERT_TRUE(at->alive());
}

TEST(LifeFixture, at7) {
  FredkinCell cell(false);
  Life<FredkinCell> life(1, 2);
  life.add(cell);
  life.add(cell);
  const FredkinCell *at = life.at(0, 0);
  ASSERT_NE(at, nullptr);
  ASSERT_FALSE(at->alive());
}

TEST(LifeFixture, at8) {
  FredkinCell cell(false);
  Life<FredkinCell> life(1, 2);
  life.add(cell);
  life.add(cell);
  const FredkinCell *at = life.at(0, 1);
  ASSERT_NE(at, nullptr);
  ASSERT_FALSE(at->alive());
}

TEST(LifeFixture, population1) {
  ConwayCell cell;
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  ASSERT_EQ(life.population(), 1);
}

TEST(LifeFixture, population2) {
  FredkinCell cell;
  Life<FredkinCell> life(1, 2);
  life.add(cell);
  ASSERT_EQ(life.population(), 1);
}

TEST(LifeFixture, population3) {
  Cell cell(new ConwayCell());
  Life<Cell> life(1, 2);
  life.add(cell);
  ASSERT_EQ(life.population(), 1);
}

TEST(LifeFixture, population4) {
  Cell cell(new FredkinCell());
  Life<Cell> life(1, 2);
  life.add(cell);
  ASSERT_EQ(life.population(), 1);
}

TEST(LifeFixture, population5) {
  ConwayCell cell(false);
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  ASSERT_EQ(life.population(), 0);
}

TEST(LifeFixture, population6) {
  FredkinCell cell(false);
  Life<FredkinCell> life(1, 2);
  life.add(cell);
  ASSERT_EQ(life.population(), 0);
}

TEST(LifeFixture, population7) {
  Cell cell(new ConwayCell(false));
  Life<Cell> life(1, 2);
  life.add(cell);
  ASSERT_EQ(life.population(), 0);
}

TEST(LifeFixture, population8) {
  Cell cell(new FredkinCell(false));
  Life<Cell> life(1, 2);
  life.add(cell);
  ASSERT_EQ(life.population(), 0);
}

TEST(LifeFixture, neighbors1) {
  ConwayCell cell;
  Life<ConwayCell> life(1, 1);
  life.add(cell);
  const vector<bool> neighbors = life.neighbors(0, 0);
  const vector<bool> expected = {false, false, false, false,
                                 false, false, false, false};
  ASSERT_EQ(neighbors.size(), expected.size());
  ASSERT_EQ(neighbors, expected);
}

TEST(LifeFixture, neighbors2) {
  ConwayCell cell;
  Life<ConwayCell> life(3, 3);
  life.add(cell);
  life.add(cell);
  life.add(cell);
  life.add(cell);
  life.add(cell);
  life.add(cell);
  life.add(cell);
  life.add(cell);
  life.add(cell);
  const vector<bool> neighbors = life.neighbors(1, 1);
  const vector<bool> expected = {true, true, true, true,
                                 true, true, true, true};
  ASSERT_EQ(neighbors.size(), expected.size());
  ASSERT_EQ(neighbors, expected);
}

TEST(LifeFixture, neighbors3) {
  ConwayCell alive;
  ConwayCell dead(false);
  Life<ConwayCell> life(2, 3);
  life.add(alive);
  life.add(alive);
  life.add(alive);
  life.add(alive);
  life.add(dead);
  life.add(alive);
  const vector<bool> neighbors = life.neighbors(1, 1);
  const vector<bool> expected = {true, true,  true,  true,
                                 true, false, false, false};
  ASSERT_EQ(neighbors.size(), expected.size());
  ASSERT_EQ(neighbors, expected);
}

TEST(LifeFixture, neighbors4) {
  ConwayCell alive;
  ConwayCell dead(false);
  Life<ConwayCell> life(3, 3);
  life.add(alive);
  life.add(alive);
  life.add(alive);
  life.add(dead);
  life.add(dead);
  life.add(dead);
  life.add(alive);
  life.add(alive);
  life.add(alive);
  const vector<bool> neighbors = life.neighbors(1, 1);
  const vector<bool> expected = {false, true, true, true,
                                 false, true, true, true};
  ASSERT_EQ(neighbors.size(), expected.size());
  ASSERT_EQ(neighbors, expected);
}

TEST(LifeFixture, loop1) {
  ConwayCell cell;
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  life.loop();
}

TEST(LifeFixture, loop2) {
  ConwayCell cell;
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  life.loop();
  life.loop();
}

TEST(LifeFixture, loop3) {
  ConwayCell cell;
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  life.loop();
  life.loop();
  life.loop();
}

TEST(LifeFixture, loop4) {
  ConwayCell cell;
  Life<ConwayCell> life(1, 2);
  life.add(cell);
  life.loop();
  life.loop();
  life.loop();
  life.loop();
}

TEST(LifeFixture, alive1) {
  ConwayCell cell;
  ASSERT_EQ(cell.alive(), true);
}

TEST(LifeFixture, alive2) {
  ConwayCell cell(false);
  ASSERT_EQ(cell.alive(), false);
}

TEST(LifeFixture, alive3) {
  FredkinCell cell;
  ASSERT_EQ(cell.alive(), true);
}

TEST(LifeFixture, alive4) {
  FredkinCell cell(false);
  ASSERT_EQ(cell.alive(), false);
}

TEST(LifeFixture, alive5) {
  Cell cell(new ConwayCell());
  ASSERT_EQ(cell.alive(), true);
}

TEST(LifeFixture, alive6) {
  Cell cell(new ConwayCell(false));
  ASSERT_EQ(cell.alive(), false);
}

TEST(LifeFixture, alive7) {
  Cell cell(new FredkinCell());
  ASSERT_EQ(cell.alive(), true);
}

TEST(LifeFixture, alive8) {
  Cell cell(new FredkinCell(false));
  ASSERT_EQ(cell.alive(), false);
}

TEST(LifeFixture, clone1) {
  ConwayCell cell;
  ASSERT_NE(cell.clone(), nullptr);
}

TEST(LifeFixture, clone2) {
  FredkinCell cell;
  ASSERT_NE(cell.clone(), nullptr);
}

TEST(LifeFixture, clone3) {
  ConwayCell cell(false);
  ASSERT_NE(cell.clone(), nullptr);
}

TEST(LifeFixture, clone4) {
  FredkinCell cell(false);
  ASSERT_NE(cell.clone(), nullptr);
}

TEST(LifeFixture, life_print_conway1) {
  Life<ConwayCell> life(2, 2);
  ConwayCell one(false);
  ConwayCell two(true);
  ConwayCell three(false);
  ConwayCell four(true);
  life.add(one);
  life.add(three);
  life.add(two);
  life.add(four);
  ostringstream out;
  out << life;
  ASSERT_EQ("Generation = 0, Population = 2.\n..\n**\n", out.str());
}

TEST(LifeFixture, life_print_conway2) {
  Life<ConwayCell> life(2, 2);
  ConwayCell one(false);
  ConwayCell two(true);
  ConwayCell three(false);
  ConwayCell four(true);
  life.add(one);
  life.add(three);
  life.add(two);
  life.add(four);
  life.loop();
  ostringstream out;
  out << life;
  ASSERT_EQ("Generation = 1, Population = 0.\n..\n..\n", out.str());
}

TEST(LifeFixture, life_print_conway3) {
  Life<ConwayCell> life(2, 2);
  ConwayCell one(false);
  ConwayCell two(true);
  ConwayCell three(false);
  ConwayCell four(true);
  life.add(one);
  life.add(three);
  life.add(two);
  life.add(four);
  life.loop();
  life.loop();
  ostringstream out;
  out << life;
  ASSERT_EQ("Generation = 2, Population = 0.\n..\n..\n", out.str());
}

TEST(LifeFixture, life_print_conway4) {
  Life<ConwayCell> life(2, 2);
  ConwayCell one(false);
  ConwayCell two(true);
  ConwayCell three(false);
  ConwayCell four(true);
  life.add(one);
  life.add(three);
  life.add(two);
  life.add(four);
  life.loop();
  life.loop();
  life.loop();
  ostringstream out;
  out << life;
  ASSERT_EQ("Generation = 3, Population = 0.\n..\n..\n", out.str());
}

TEST(LifeFixture, life_print_cell1) {
  Life<Cell> life(2, 2);
  Cell one(new ConwayCell(false));
  Cell two(new ConwayCell(true));
  Cell three(new ConwayCell(false));
  Cell four(new ConwayCell(true));
  life.add(one);
  life.add(three);
  life.add(two);
  life.add(four);
  ostringstream out;
  out << life;
  ASSERT_EQ("Generation = 0, Population = 2.\n..\n**\n", out.str());
}
TEST(LifeFixture, life_print_cell2) {
  Life<Cell> life(2, 2);
  Cell one(new ConwayCell(false));
  Cell two(new ConwayCell(true));
  Cell three(new ConwayCell(false));
  Cell four(new ConwayCell(true));
  life.add(one);
  life.add(three);
  life.add(two);
  life.add(four);
  life.loop();
  ostringstream out;
  out << life;
  ASSERT_EQ("Generation = 1, Population = 0.\n..\n..\n", out.str());
}
TEST(LifeFixture, life_print_cell3) {
  Life<Cell> life(2, 2);
  Cell one(new ConwayCell(false));
  Cell two(new ConwayCell(true));
  Cell three(new ConwayCell(false));
  Cell four(new ConwayCell(true));
  life.add(one);
  life.add(three);
  life.add(two);
  life.add(four);
  life.loop();
  life.loop();
  ostringstream out;
  out << life;
  ASSERT_EQ("Generation = 2, Population = 0.\n..\n..\n", out.str());
}
TEST(LifeFixture, life_print_cell4) {
  Life<Cell> life(2, 2);
  Cell one(new ConwayCell(false));
  Cell two(new ConwayCell(true));
  Cell three(new ConwayCell(false));
  Cell four(new ConwayCell(true));
  life.add(one);
  life.add(three);
  life.add(two);
  life.add(four);
  life.loop();
  life.loop();
  life.loop();
  ostringstream out;
  out << life;
  ASSERT_EQ("Generation = 3, Population = 0.\n..\n..\n", out.str());
}