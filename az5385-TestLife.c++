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

#include <sstream>

using namespace std;

// -----------
// ConwayTests
// -----------

TEST(ConwayFixture, test_print_1) {
  ConwayCell c('.');
  ostringstream out;
  c.print(out);
  ASSERT_EQ(".", out.str());
}

TEST(ConwayFixture, test_print_2) {
  ConwayCell c('*');
  ostringstream out;
  c.print(out);
  ASSERT_EQ("*", out.str());
}

TEST(ConwayFixture, test_mutate_dtoa) {
  ConwayCell c('.');
  ConwayCell alive('*');
  const AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                      nullptr, &alive,  &alive,  &alive};

  c.process_neighbors(neighbors);
  ASSERT_EQ(1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("*", out.str());
}

TEST(ConwayFixture, test_mutate_dtod_1) {
  ConwayCell c('.');
  ConwayCell alive('*');
  const AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ(".", out.str());
}

TEST(ConwayFixture, test_mutate_dtod_2) {
  ConwayCell c('.');
  ConwayCell alive('*');
  const AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                      nullptr, nullptr, &alive,  &alive};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ(".", out.str());
}

TEST(ConwayFixture, test_mutate_atod_1) {
  ConwayCell c('*');
  ConwayCell alive('*');
  const AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(-1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ(".", out.str());
}

TEST(ConwayFixture, test_mutate_atod_2) {
  ConwayCell c('*');
  ConwayCell alive('*');
  const AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, &alive,
                                      &alive,  &alive,  &alive,  &alive};

  c.process_neighbors(neighbors);
  ASSERT_EQ(-1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ(".", out.str());
}

TEST(ConwayFixture, test_mutate_atoa_1) {
  ConwayCell c('*');
  ConwayCell alive('*');
  const AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                      nullptr, nullptr, &alive,  &alive};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("*", out.str());
}

TEST(ConwayFixture, test_mutate_atoa_2) {
  ConwayCell c('*');
  ConwayCell alive('*');
  const AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                      nullptr, &alive,  &alive,  &alive};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("*", out.str());
}

TEST(ConwayFixture, test_clone_1) {
  ConwayCell c('*');
  AbstractCell *clone = c.clone();
  ASSERT_TRUE(dynamic_cast<ConwayCell *>(clone));

  ostringstream out;
  clone->print(out);
  ASSERT_EQ("*", out.str());

  delete clone;
}

TEST(ConwayFixture, test_clone_2) {
  ConwayCell c('.');
  AbstractCell *clone = c.clone();
  ASSERT_TRUE(dynamic_cast<ConwayCell *>(clone));

  ostringstream out;
  clone->print(out);
  ASSERT_EQ(".", out.str());

  delete clone;
}

TEST(ConwayFixture, test_clone_3) {
  ConwayCell c('*');
  AbstractCell *c1 = c.clone();
  AbstractCell *c2 = c1->clone();

  ASSERT_TRUE(dynamic_cast<ConwayCell *>(c2));

  ostringstream out;
  c2->print(out);
  ASSERT_EQ("*", out.str());

  delete c2;
}

// ------------
// FredkinTests
// ------------

TEST(FredkinFixture, test_print_1) {
  FredkinCell c('-');
  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_print_2) {
  FredkinCell c('0');
  ostringstream out;
  c.print(out);
  ASSERT_EQ("0", out.str());
}

TEST(FredkinFixture, test_print_3) {
  FredkinCell c('9');
  ostringstream out;
  c.print(out);
  ASSERT_EQ("0", out.str());
}

TEST(FredkinFixture, test_print_4) {
  FredkinCell c('0');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  for (int i = 0; i < 10; i++) {
    c.mutate();
  }

  ostringstream out;
  c.print(out);
  ASSERT_EQ("+", out.str());
}

TEST(FredkinFixture, test_mutate_ignore_corners) {
  FredkinCell c('-');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {&alive,  nullptr, nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_mutate_dtod_1) {
  FredkinCell c('-');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_mutate_dtod_2) {
  FredkinCell c('-');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_mutate_dtod_3) {
  FredkinCell c('-');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                      &alive,  nullptr, &alive,  nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_mutate_atod_1) {
  FredkinCell c('0');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(-1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_mutate_atod_2) {
  FredkinCell c('0');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(-1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_mutate_atod_3) {
  FredkinCell c('0');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                      &alive,  nullptr, &alive,  nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(-1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_mutate_dtoa_1) {
  FredkinCell c('-');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("0", out.str());
}

TEST(FredkinFixture, test_mutate_dtoa_2) {
  FredkinCell c('-');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                      &alive,  nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("0", out.str());
}

TEST(FredkinFixture, test_mutate_atoa_1) {
  FredkinCell c('0');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("1", out.str());
}

TEST(FredkinFixture, test_mutate_atoa_2) {
  FredkinCell c('0');
  FredkinCell alive('0');
  const AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                      &alive,  nullptr, nullptr, nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(0, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("1", out.str());
}

TEST(FredkinFixture, test_preserve_age) {
  FredkinCell c('0');
  FredkinCell alive('0');
  const AbstractCell *alive_neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                            &alive,  nullptr, nullptr, nullptr};
  const AbstractCell *dead_neighbors[8] = {nullptr, nullptr, nullptr, &alive,
                                           &alive,  nullptr, nullptr, nullptr};

  c.process_neighbors(alive_neighbors);
  c.mutate();
  c.process_neighbors(dead_neighbors);
  c.mutate();
  c.process_neighbors(alive_neighbors);
  c.mutate();
  c.mutate();

  ostringstream out;
  c.print(out);
  ASSERT_EQ("2", out.str());
}

TEST(FredkinFixture, test_clone_1) {
  FredkinCell c('0');
  AbstractCell *clone = c.clone();
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(clone));

  ostringstream out;
  clone->print(out);
  ASSERT_EQ("0", out.str());

  delete clone;
}

TEST(FredkinFixture, test_clone_2) {
  FredkinCell c('-');
  AbstractCell *clone = c.clone();
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(clone));

  ostringstream out;
  clone->print(out);
  ASSERT_EQ("-", out.str());

  delete clone;
}

TEST(FredkinFixture, test_clone_3) {
  FredkinCell c('1');
  AbstractCell *clone = c.clone();
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(clone));

  ostringstream out;
  clone->print(out);
  ASSERT_EQ("0", out.str());

  delete clone;
}

TEST(FredkinFixture, test_clone_4) {
  FredkinCell c('0');
  AbstractCell *c1 = c.clone();
  AbstractCell *c2 = c1->clone();
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(c2));

  ostringstream out;
  c2->print(out);
  ASSERT_EQ("0", out.str());

  delete c2;
}

TEST(FredkinFixture, test_evolution) {
  FredkinCell c('0');
  FredkinCell alive('0');
  const AbstractCell *alive_neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                            &alive,  nullptr, nullptr, nullptr};

  c.process_neighbors(alive_neighbors);
  c.mutate(); // Should be age 1
  ASSERT_TRUE(c.mutate().second);
}

// ---------
// CellTests
// ---------

TEST(CellFixture, test_print_1) {
  Cell c('.');

  ostringstream out;
  c.print(out);
  ASSERT_EQ(".", out.str());
}

TEST(CellFixture, test_print_2) {
  Cell c('-');

  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(CellFixture, test_mutate_conway_1) {
  Cell c('.');
  Cell c_alive('*');
  Cell f_alive('0');
  const Cell *neighbors[8] = {&c_alive, &f_alive, &c_alive, nullptr,
                              nullptr,  nullptr,  nullptr,  nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("*", out.str());
}

TEST(CellFixture, test_mutate_conway_2) {
  Cell c('*');
  Cell c_alive('*');
  Cell f_alive('0');
  const Cell *neighbors[8] = {&c_alive, &f_alive, &c_alive, &f_alive,
                              &c_alive, nullptr,  nullptr,  nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(-1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ(".", out.str());
}

TEST(CellFixture, test_mutate_fredkin_1) {
  Cell c('-');
  Cell c_alive('*');
  Cell f_alive('0');
  const Cell *neighbors[8] = {&c_alive, &f_alive, &c_alive, nullptr,
                              nullptr,  nullptr,  nullptr,  nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("0", out.str());
}

TEST(CellFixture, test_mutate_fredkin_2) {
  Cell c('0');
  Cell c_alive('*');
  Cell f_alive('0');
  const Cell *neighbors[8] = {&c_alive, &f_alive, &c_alive, &f_alive,
                              nullptr,  nullptr,  nullptr,  nullptr};

  c.process_neighbors(neighbors);
  ASSERT_EQ(-1, c.mutate().first);

  ostringstream out;
  c.print(out);
  ASSERT_EQ("-", out.str());
}

TEST(CellFixture, test_mutate_fredkin_evolve) {
  Cell c('0');
  Cell c_alive('*');
  Cell f_alive('0');
  const Cell *neighbors[8] = {&c_alive, &f_alive, &c_alive, nullptr,
                              nullptr,  nullptr,  nullptr,  nullptr};

  c.process_neighbors(neighbors);
  c.mutate();
  c.mutate();

  ostringstream out;
  c.print(out);
  ASSERT_EQ("*", out.str());
}

TEST(CellFixture, test_copy_constructor_0) {
  Cell c1('0');
  Cell c2(c1);

  ostringstream out;
  c2.print(out);

  ASSERT_EQ("0", out.str());
}

TEST(CellFixture, test_copy_constructor_1) {
  Cell c1('.');
  Cell c2(c1);

  ostringstream out;
  c2.print(out);

  ASSERT_EQ(".", out.str());
}

TEST(CellFixture, test_copy_assignment_0) {
  Cell c1('0');
  Cell c2('.');
  c1 = c2;

  ostringstream out;
  c1.print(out);

  ASSERT_EQ(".", out.str());
}

TEST(CellFixture, test_copy_assignment_1) {
  Cell c1('0');
  Cell c2('.');
  c2 = c1;

  ostringstream out;
  c2.print(out);

  ASSERT_EQ("0", out.str());
}

// ----------------
// LifeConway Tests
// ----------------

TEST(LifeConwayFixture, test_print) {
  istringstream in("2 2\n"
                   "..\n"
                   "**\n");

  Life<ConwayCell> life(in);

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 0, Population = 2.\n"
            "..\n"
            "**\n",
            out.str());
}

TEST(LifeConwayFixture, test_print_1) {
  istringstream in("2 2\n"
                   "..\n"
                   "..\n");

  Life<ConwayCell> life(in);

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 0, Population = 0.\n"
            "..\n"
            "..\n",
            out.str());
}

TEST(LifeConwayFixture, test_print_2) {
  istringstream in("2 2\n"
                   "*.\n"
                   ".*\n");

  Life<ConwayCell> life(in);

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 0, Population = 2.\n"
            "*.\n"
            ".*\n",
            out.str());
}

TEST(LifeConwayFixture, test_generation) {
  istringstream in("3 5\n"
                   ".....\n"
                   ".***.\n"
                   ".....\n");

  Life<ConwayCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 3.\n"
            "..*..\n"
            "..*..\n"
            "..*..\n",
            out.str());
}

TEST(LifeConwayFixture, test_generation_1) {
  istringstream in("3 3\n"
                   "...\n"
                   "...\n"
                   "...\n");

  Life<ConwayCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 0.\n"
            "...\n"
            "...\n"
            "...\n",
            out.str());
}

TEST(LifeConwayFixture, test_generation_2) {
  istringstream in("3 4\n"
                   "....\n"
                   ".**.\n"
                   "....\n");

  Life<ConwayCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 0.\n"
            "....\n"
            "....\n"
            "....\n",
            out.str());
}

TEST(LifeConwayFixture, test_generation_3) {
  istringstream in("3 4\n"
                   ".**.\n"
                   ".**.\n"
                   ".**.\n");

  Life<ConwayCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 6.\n"
            ".**.\n"
            "*..*\n"
            ".**.\n",
            out.str());
}

TEST(LifeConwayFixture, test_generation_4) {
  istringstream in("3 3\n"
                   ".*.\n"
                   ".*.\n"
                   ".*.\n");

  Life<ConwayCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 3.\n"
            "...\n"
            "***\n"
            "...\n",
            out.str());
}

TEST(LifeConwayFixture, test_generation_5) {
  istringstream in("3 3\n"
                   "...\n"
                   ".*.\n"
                   "...\n");

  Life<ConwayCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 0.\n"
            "...\n"
            "...\n"
            "...\n",
            out.str());
}

// -----------------
// LifeFredkin Tests
// -----------------

TEST(LifeFredkinFixture, test_print) {
  istringstream in("2 2\n"
                   "--\n"
                   "00\n");

  Life<FredkinCell> life(in);

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 0, Population = 2.\n"
            "--\n"
            "00\n",
            out.str());
}

TEST(LifeFredkinFixture, test_print_1) {
  istringstream in("2 2\n"
                   "-0\n"
                   "0-\n");

  Life<FredkinCell> life(in);

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 0, Population = 2.\n"
            "-0\n"
            "0-\n",
            out.str());
}

TEST(LifeFredkinFixture, test_print_2) {
  istringstream in("2 2\n"
                   "--\n"
                   "--\n");

  Life<FredkinCell> life(in);

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 0, Population = 0.\n"
            "--\n"
            "--\n",
            out.str());
}

TEST(LifeFredkinFixture, test_generation) {
  istringstream in("3 4\n"
                   "----\n"
                   "-00-\n"
                   "----\n");

  Life<FredkinCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 8.\n"
            "-00-\n"
            "0110\n"
            "-00-\n",
            out.str());
}

TEST(LifeFredkinFixture, test_generation_1) {
  istringstream in("3 3\n"
                   "---\n"
                   "-0-\n"
                   "---\n");

  Life<FredkinCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 4.\n"
            "-0-\n"
            "0-0\n"
            "-0-\n",
            out.str());
}

TEST(LifeFredkinFixture, test_generation_2) {
  istringstream in("3 3\n"
                   "---\n"
                   "---\n"
                   "---\n");

  Life<FredkinCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 0.\n"
            "---\n"
            "---\n"
            "---\n",
            out.str());
}

TEST(LifeFredkinFixture, test_generation_3) {
  istringstream in("3 3\n"
                   "-0-\n"
                   "0-0\n"
                   "-0-\n");

  Life<FredkinCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 0.\n"
            "---\n"
            "---\n"
            "---\n",
            out.str());
}

TEST(LifeFredkinFixture, test_generation_4) {
  istringstream in("3 3\n"
                   "---\n"
                   "000\n"
                   "---\n");

  Life<FredkinCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 8.\n"
            "000\n"
            "1-1\n"
            "000\n",
            out.str());
}

TEST(LifeFredkinFixture, test_generation_5) {
  istringstream in("3 3\n"
                   "000\n"
                   "000\n"
                   "000\n");

  Life<FredkinCell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 4.\n"
            "-1-\n"
            "1-1\n"
            "-1-\n",
            out.str());
}

// --------------
// CellLife Tests
// --------------

TEST(LifeCellFixture, test_print) {
  istringstream in("2 2\n"
                   "**\n"
                   "00\n");

  Life<Cell> life(in);

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 0, Population = 4.\n"
            "**\n"
            "00\n",
            out.str());
}

TEST(LifeCellFixture, test_generation) {
  istringstream in("2 2\n"
                   "**\n"
                   "00\n");

  Life<Cell> life(in);

  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 1, Population = 2.\n"
            "**\n"
            "--\n",
            out.str());
}

TEST(LifeCellFixture, test_generation_1) {
  istringstream in("2 2\n"
                   "00\n"
                   "..\n");

  Life<Cell> life(in);

  life.advanceGeneration();
  life.advanceGeneration();

  ostringstream out;
  life.print(out);
  ASSERT_EQ("Generation = 2, Population = 2.\n"
            "**\n"
            "..\n",
            out.str());
}
