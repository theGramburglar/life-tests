// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// ap39356 - Project 5 - Life - TestLife.c++

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Life.h"

#include <sstream>

using namespace std;

// ----
// ConwayCell Tests
// ----

// print_symbol tests

TEST(ConwayFixture, test_symbol1) {
  ConwayCell c('.');
  char name = c.print_symbol();
  ASSERT_EQ(name, '.');
}

TEST(ConwayFixture, test_symbol2) {
  ConwayCell c('*');
  char name = c.print_symbol();
  ASSERT_EQ(name, '*');
}

TEST(ConwayFixture, test_symbol3) {
  ConwayCell c('3');
  char name = c.print_symbol();
  ASSERT_EQ(name, '*');
}

// next_generation tests

TEST(ConwayFixture, test_mutate1) {
  ConwayCell c('.');
  ConwayCell alive('*');
  AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                nullptr, &alive,  &alive,  &alive};
  bool mutated = c.next_generation(neighbors);
  ASSERT_TRUE(mutated);
}

TEST(ConwayFixture, test_mutate2) {
  ConwayCell c('*');
  ConwayCell alive('*');
  AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                &alive,  &alive,  &alive,  &alive};
  bool mutated = c.next_generation(neighbors);
  ASSERT_TRUE(mutated);
}

TEST(ConwayFixture, test_mutate3) {
  ConwayCell c('*');
  ConwayCell alive('*');
  AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                nullptr, nullptr, &alive,  &alive};
  bool mutated = c.next_generation(neighbors);
  ASSERT_FALSE(mutated);
}

// need_to_change tests

TEST(ConwayFixture, test_change1) {
  ConwayCell c('*');
  ASSERT_FALSE(c.need_to_change());
}

TEST(ConwayFixture, test_change2) {
  ConwayCell c('.');
  ASSERT_FALSE(c.need_to_change());
}

TEST(ConwayFixture, test_change3) {
  ConwayCell c('3');
  ASSERT_FALSE(c.need_to_change());
}

// clone tests

TEST(ConwayFixture, clone1) {
  ConwayCell cc1('*');
  ConwayCell *cc2 = dynamic_cast<ConwayCell *>(cc1.clone());
  ASSERT_EQ(cc1.print_symbol(), (*cc2).print_symbol());
}

TEST(ConwayFixture, clone2) {
  ConwayCell cc1('.');
  ConwayCell *cc2 = dynamic_cast<ConwayCell *>(cc1.clone());
  ASSERT_EQ(cc1.print_symbol(), (*cc2).print_symbol());
}

TEST(ConwayFixture, clone3) {
  ConwayCell cc1('3');
  ConwayCell *cc2 = dynamic_cast<ConwayCell *>(cc1.clone());
  ASSERT_EQ(cc1.print_symbol(), (*cc2).print_symbol());
}

// ----
// FredkinCell Tests
// ----

// print_symbol tests

TEST(FredkinFixture, test_symbol1) {
  FredkinCell c('0');
  char name = c.print_symbol();
  ASSERT_EQ(name, '0');
}

TEST(FredkinFixture, test_symbol2) {
  FredkinCell c('2');
  char name = c.print_symbol();
  ASSERT_EQ(name, '2');
}

TEST(FredkinFixture, test_symbol3) {
  FredkinCell c('3');
  char name = c.print_symbol();
  ASSERT_EQ(name, '3');
}

TEST(FredkinFixture, test_symbol4) {
  FredkinCell c('-');
  char name = c.print_symbol();
  ASSERT_EQ(name, '-');
}

// next_generation tests

TEST(FredkinFixture, test_mutate1) {
  FredkinCell c('0');
  FredkinCell alive('0');
  AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                nullptr, nullptr, nullptr, nullptr};
  bool mutated = c.next_generation(neighbors);
  ASSERT_TRUE(mutated);
}

TEST(FredkinFixture, test_mutate2) {
  FredkinCell c('-');
  FredkinCell alive('0');
  AbstractCell *neighbors[8] = {nullptr, &alive,  nullptr, &alive,
                                nullptr, nullptr, nullptr, nullptr};
  bool mutated = c.next_generation(neighbors);
  ASSERT_FALSE(mutated);
}

TEST(FredkinFixture, test_mutate3) {
  FredkinCell c('-');
  FredkinCell alive('0');
  AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, &alive,
                                nullptr, nullptr, nullptr, nullptr};
  bool mutated = c.next_generation(neighbors);
  ASSERT_TRUE(mutated);
}

TEST(FredkinFixture, test_mutate4) {
  FredkinCell c('0');
  FredkinCell alive('0');
  AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, &alive,
                                nullptr, nullptr, nullptr, nullptr};
  bool mutated = c.next_generation(neighbors);
  ASSERT_FALSE(mutated);
}

// need_to_change tests

TEST(FredkinFixture, test_change1) {
  FredkinCell c('1');
  ASSERT_FALSE(c.need_to_change());
}

TEST(FredkinFixture, test_change2) {
  FredkinCell c('2');
  ASSERT_TRUE(c.need_to_change());
}

TEST(FredkinFixture, test_change3) {
  FredkinCell c('-');
  ASSERT_FALSE(c.need_to_change());
}

// clone tests

TEST(FredkinFixture, clone1) {
  FredkinCell cc1('0');
  FredkinCell *cc2 = dynamic_cast<FredkinCell *>(cc1.clone());
  ASSERT_EQ(cc1.print_symbol(), (*cc2).print_symbol());
}

TEST(FredkinFixture, clone2) {
  FredkinCell cc1('2');
  FredkinCell *cc2 = dynamic_cast<FredkinCell *>(cc1.clone());
  ASSERT_EQ(cc1.print_symbol(), (*cc2).print_symbol());
}

TEST(FredkinFixture, clone3) {
  FredkinCell cc1('-');
  FredkinCell *cc2 = dynamic_cast<FredkinCell *>(cc1.clone());
  ASSERT_EQ(cc1.print_symbol(), (*cc2).print_symbol());
}

// ----
// ConwayCell Tests
// ----

// print_symbol tests

TEST(CellFixture, test_symbol1) {
  Cell c('.');
  char name = c.print_symbol();
  ASSERT_EQ(name, '.');
}

TEST(CellFixture, test_symbol2) {
  Cell c('*');
  char name = c.print_symbol();
  ASSERT_EQ(name, '*');
}

TEST(CellFixture, test_symbol3) {
  Cell c('-');
  char name = c.print_symbol();
  ASSERT_EQ(name, '-');
}

TEST(CellFixture, test_symbol4) {
  Cell c('0');
  char name = c.print_symbol();
  ASSERT_EQ(name, '0');
}

// test toggle_state

TEST(CellFixture, test_toggle1) {
  Cell c('.');
  c.toggle_state();
  ASSERT_TRUE(c.live());
}

TEST(CellFixture, test_toggle2) {
  Cell c('*');
  c.toggle_state();
  ASSERT_FALSE(c.live());
}

TEST(CellFixture, test_toggle3) {
  Cell c('-');
  c.toggle_state();
  ASSERT_TRUE(c.live());
}

TEST(CellFixture, test_toggle4) {
  Cell c('1');
  c.toggle_state();
  ASSERT_FALSE(c.live());
}

// test live

TEST(CellFixture, test_live1) {
  Cell c('*');
  ASSERT_TRUE(c.live());
}

TEST(CellFixture, test_live2) {
  Cell c('.');
  ASSERT_FALSE(c.live());
}

TEST(CellFixture, test_live3) {
  Cell c('1');
  ASSERT_TRUE(c.live());
}

TEST(CellFixture, test_live4) {
  Cell c('-');
  ASSERT_FALSE(c.live());
}

// test next_generation

TEST(CellFixture, test_mutate_conway1) {
  Cell c('*');
  Cell alive('*');
  AbstractCell *neighbors[8] = {nullptr, nullptr, nullptr, nullptr,
                                &alive,  &alive,  &alive,  &alive};
  bool mutated = c.next_generation(neighbors);
  ASSERT_TRUE(mutated);
}

TEST(CellFixture, test_mutate_conway2) {
  Cell c('*');
  Cell alive('*');
  Cell dead('.');
  AbstractCell *neighbors[8] = {nullptr, &dead,   nullptr, &dead,
                                nullptr, nullptr, &alive,  &alive};
  bool mutated = c.next_generation(neighbors);
  ASSERT_FALSE(mutated);
}

TEST(CellFixture, test_mutate_fredkin1) {
  Cell c('-');
  Cell f_alive('1');
  Cell c_alive('*');
  AbstractCell *neighbors[8] = {nullptr, &f_alive, nullptr, &f_alive,
                                nullptr, &c_alive, nullptr, nullptr};
  bool mutated = c.next_generation(neighbors);
  ASSERT_TRUE(mutated);
}

TEST(CellFixture, test_mutate_fredkin2) {
  Cell c('1');
  Cell f_alive('+');
  Cell c_alive('*');
  Cell c_dead('.');
  AbstractCell *neighbors[8] = {nullptr, &f_alive, &c_dead, &f_alive,
                                &c_dead, &c_alive, nullptr, &c_alive};
  bool mutated = c.next_generation(neighbors);
  ASSERT_TRUE(mutated);
}

// need_to_change tests

TEST(CellFixture, test_change1) {
  Cell c('*');
  ASSERT_FALSE(c.need_to_change());
}

TEST(CellFixture, test_change2) {
  Cell c('.');
  ASSERT_FALSE(c.need_to_change());
}

TEST(CellFixture, test_change3) {
  Cell c('2');
  ASSERT_TRUE(c.need_to_change());
}

TEST(CellFixture, test_change4) {
  Cell c('1');
  ASSERT_FALSE(c.need_to_change());
}