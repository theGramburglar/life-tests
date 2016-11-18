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

/*
/  Tests for ConwayCell
*/

TEST(ConwayCellFixture, construct_alive) {
  ConwayCell cell(true);
  ASSERT_EQ(cell.state(), '*');
}

TEST(ConwayCellFixture, construct_dead) {
  ConwayCell cell(false);
  ASSERT_EQ(cell.state(), '.');
}

TEST(ConwayCellFixture, construct2_1) {
  ConwayCell cell(true, -1);
  ASSERT_EQ(cell.state(), '*');
  ASSERT_EQ(cell.age, -1);
}

TEST(ConwayCellFixture, construct2_2) {
  ConwayCell cell(false, -1);
  ASSERT_EQ(cell.state(), '.');
  ASSERT_EQ(cell.age, -1);
}

/*
/ Tests for FredkinCell
*/

TEST(FredkinCellFixture, construct_alive) {
  FredkinCell cell(true);
  ASSERT_TRUE(cell.state());
  ASSERT_EQ(cell.age, 0);
}

TEST(FredkinCellFixture, construct_dead) {
  FredkinCell cell(false);
  ASSERT_EQ(cell.state(), '-');
  ASSERT_EQ(cell.age, 0);
}

TEST(FredkinCellFixture, construct_age1) {
  FredkinCell cell(true, 1);
  ASSERT_TRUE(cell.state());
  ASSERT_EQ(cell.age, 1);
}

TEST(FredkinCellFixture, construct_age2) {
  FredkinCell cell(false, 3);
  ASSERT_EQ(cell.state(), '-');
  ASSERT_EQ(cell.age, 3);
}

TEST(FredkinCellFixture, construct_age3) {
  FredkinCell cell(false, 6);
  ASSERT_EQ(cell.state(), '-');
  ASSERT_EQ(cell.age, 6);
}

TEST(FredkinCellFixture, state1) {
  FredkinCell cell(true, 3);
  ASSERT_EQ(cell.state(), '3');
  ASSERT_EQ(cell.age, 3);
}

TEST(FredkinCellFixture, state2) {
  FredkinCell cell(true, 0);
  ASSERT_EQ(cell.state(), '0');
  ASSERT_EQ(cell.age, 0);
}

TEST(FredkinCellFixture, state3) {
  FredkinCell cell(false, 5);
  ASSERT_EQ(cell.state(), '-');
  ASSERT_EQ(cell.age, 5);
}

/*
/ Tests for Life
*/

TEST(LifeFixture, 2arg_constructor1) {
  Life<ConwayCell> l(1, 1);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("Generation = 0, Population = 0.\n.\n\n", w.str());
}

TEST(LifeFixture, 2arg_constructor2) {
  Life<ConwayCell> l(1, 3);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("Generation = 0, Population = 0.\n...\n\n", w.str());
}

TEST(LifeFixture, 2arg_constructor3) {
  Life<ConwayCell> l(3, 3);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("Generation = 0, Population = 0.\n...\n...\n...\n\n", w.str());
}

TEST(LifeFixture, input_constructor1) {
  istringstream i;
  i.str("1 1\n.\n");
  Life<ConwayCell> l(i);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("Generation = 0, Population = 0.\n.\n\n", w.str());
}

TEST(LifeFixture, input_constructor2) {
  istringstream i;
  i.str("3 3\n...\n...\n...\n");
  Life<ConwayCell> l(i);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("Generation = 0, Population = 0.\n...\n...\n...\n\n", w.str());
}

TEST(LifeFixture, input_constructor3) {
  istringstream i;
  i.str("3 3\n*..\n.*.\n..*\n");
  Life<ConwayCell> l(i);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("Generation = 0, Population = 3.\n*..\n.*.\n..*\n\n", w.str());
}

TEST(LifeFixture, input_constructor4) {
  istringstream i;
  i.str("5 5\n*..*.\n.*..*\n*.*.*\n");
  Life<ConwayCell> l(i);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ(
      "Generation = 0, Population = 17.\n*..*.\n.*..*\n*.*.*\n*****\n*****\n\n",
      w.str());
}

TEST(LifeFixture, play_conway_empty) {
  Life<ConwayCell> l(3, 3);
  ostringstream w;
  l.play();
  l.printBoard(w);
  ASSERT_EQ("Generation = 1, Population = 0.\n...\n...\n...\n\n", w.str());
}

TEST(LifeFixture, play_conway1) {
  istringstream i;
  i.str("3 3\n*..\n.*.\n..*\n");
  Life<ConwayCell> l(i);
  ostringstream w;
  l.play();
  l.printBoard(w);
  ASSERT_EQ("Generation = 1, Population = 1.\n...\n.*.\n...\n\n", w.str());
}

TEST(LifeFixture, play_conway2) {
  istringstream i;
  i.str("5 5\n*..*.\n.*..*\n*.*.*\n");
  Life<ConwayCell> l(i);
  ostringstream w;
  l.play();
  l.printBoard(w);
  ASSERT_EQ(
      "Generation = 1, Population = 8.\n.....\n***.*\n*...*\n.....\n*...*\n\n",
      w.str());
}

TEST(LifeFixture, play_fredkin_empty) {
  istringstream i;
  i.str("3 3\n---\n---\n---\n");
  Life<FredkinCell> l(i);
  ostringstream w;
  l.play();
  l.printBoard(w);
  ASSERT_EQ("Generation = 1, Population = 0.\n---\n---\n---\n\n", w.str());
}

TEST(LifeFixture, play_fredkin1) {
  istringstream i;
  i.str("3 3\n-0-\n0--\n--0\n");
  Life<FredkinCell> l(i);
  ostringstream w;
  l.play();
  l.printBoard(w);
  ASSERT_EQ("Generation = 1, Population = 4.\n--0\n--0\n00-\n\n", w.str());
}

TEST(LifeFixture, play_fredkin2) {
  istringstream i;
  i.str("5 5\n0-0--\n-0--0\n0-0-0\n");
  Life<FredkinCell> l(i);
  ostringstream w;
  l.play();
  l.printBoard(w);
  ASSERT_EQ(
      "Generation = 1, Population = 17.\n-0-00\n0-001\n1-10-\n11-11\n-111-\n\n",
      w.str());
}

TEST(LifeFixture, play_cell_empty) {
  istringstream i;
  i.str("3 3\n---\n---\n---\n");
  Life<Cell> l(i);
  ostringstream w;
  l.play();
  l.printBoard(w);
  ASSERT_EQ("Generation = 1, Population = 0.\n---\n---\n---\n\n", w.str());
}

TEST(LifeFixture, play_cell1) {
  istringstream i;
  i.str("3 3\n-0-\n0--\n-00\n");
  Life<Cell> l(i);
  ostringstream w;
  l.play();
  l.printBoard(w);
  ASSERT_EQ("Generation = 1, Population = 5.\n--0\n-00\n-11\n\n", w.str());
}

TEST(LifeFixture, play_cell2) {
  istringstream i;
  i.str("5 5\n0-0--\n-0--0\n0-0-0\n");
  Life<Cell> l(i);
  ostringstream w;
  l.play();
  l.printBoard(w);
  ASSERT_EQ(
      "Generation = 1, Population = 17.\n-0-00\n0-001\n1-10-\n11-11\n-111-\n\n",
      w.str());
}

TEST(LifeFixture, play_cell3) {
  istringstream i;
  i.str("5 5\n0-0--\n-0--0\n0-0-0\n");
  Life<Cell> l(i);
  ostringstream w;
  l.play();
  l.play();
  l.printBoard(w);
  ASSERT_EQ(
      "Generation = 2, Population = 8.\n--0--\n10---\n-0-10\n---**\n-----\n\n",
      w.str());
}
