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
#include <stdexcept>
#include <string>

using namespace std;

// ----
// test
// ----

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// ConwayCellFixture ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

TEST(ConwayCellFixture, init_dead) {
  ConwayCell c;
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, init_live) {
  ConwayCell c(true);
  ASSERT_EQ(true, c.is_alive());
}

TEST(ConwayCellFixture, print_dead) {
  ostringstream out;
  ConwayCell c;
  out << c;
  ASSERT_EQ(".", out.str());
}

TEST(ConwayCellFixture, print_live) {
  ostringstream out;
  ConwayCell c(true);
  out << c;
  ASSERT_EQ("*", out.str());
}

TEST(ConwayCellFixture, count_ac_null) {
  ConwayCell c;
  Neighbors<AbstractCell *> n({{nullptr, nullptr, nullptr, nullptr},
                               {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_cc_null) {
  ConwayCell c;
  Neighbors<ConwayCell *> n({{nullptr, nullptr, nullptr, nullptr},
                             {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_ac_one_direct_dead) {
  ConwayCell c;
  ConwayCell other;
  Neighbors<AbstractCell *> n({{&other, nullptr, nullptr, nullptr},
                               {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_cc_one_direct_dead) {
  ConwayCell c;
  ConwayCell other;
  Neighbors<ConwayCell *> n({{&other, nullptr, nullptr, nullptr},
                             {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_ac_one_direct_live) {
  ConwayCell c;
  ConwayCell other(true);
  Neighbors<AbstractCell *> n({{&other, nullptr, nullptr, nullptr},
                               {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(1, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_cc_one_direct_live) {
  ConwayCell c;
  ConwayCell other(true);
  Neighbors<ConwayCell *> n({{&other, nullptr, nullptr, nullptr},
                             {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(1, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_ac_one_diagonal_dead) {
  ConwayCell c;
  ConwayCell other;
  Neighbors<AbstractCell *> n({{nullptr, nullptr, nullptr, nullptr},
                               {&other, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_cc_one_diagonal_dead) {
  ConwayCell c;
  ConwayCell other;
  Neighbors<ConwayCell *> n({{nullptr, nullptr, nullptr, nullptr},
                             {&other, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_ac_one_diagonal_live) {
  ConwayCell c;
  ConwayCell other(true);
  Neighbors<AbstractCell *> n({{nullptr, nullptr, nullptr, nullptr},
                               {&other, nullptr, nullptr, nullptr}});
  ASSERT_EQ(1, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_cc_one_diagonal_live) {
  ConwayCell c;
  ConwayCell other(true);
  Neighbors<ConwayCell *> n({{nullptr, nullptr, nullptr, nullptr},
                             {&other, nullptr, nullptr, nullptr}});
  ASSERT_EQ(1, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_ac_four_mixed) {
  ConwayCell c;
  ConwayCell other(true);
  Neighbors<AbstractCell *> n(
      {{nullptr, &other, nullptr, &other}, {&other, nullptr, &other, nullptr}});
  ASSERT_EQ(4, c.count_neighbors(n));
}

TEST(ConwayCellFixture, count_cc_four_mixed) {
  ConwayCell c;
  ConwayCell other(true);
  Neighbors<ConwayCell *> n(
      {{nullptr, &other, nullptr, &other}, {&other, nullptr, &other, nullptr}});
  ASSERT_EQ(4, c.count_neighbors(n));
}

TEST(ConwayCellFixture, update_dead_zero_neighbors) {
  ConwayCell c;
  auto p = c.update(0);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_dead_one_neighbor) {
  ConwayCell c;
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_dead_two_neighbors) {
  ConwayCell c;
  auto p = c.update(2);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_dead_three_neighbors) {
  ConwayCell c;
  auto p = c.update(3);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(true, c.is_alive());
}

TEST(ConwayCellFixture, update_dead_four_neighbors) {
  ConwayCell c;
  auto p = c.update(4);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_dead_five_neighbors) {
  ConwayCell c;
  auto p = c.update(5);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_dead_six_neighbors) {
  ConwayCell c;
  auto p = c.update(6);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_dead_seven_neighbors) {
  ConwayCell c;
  auto p = c.update(7);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_dead_eight_neighbors) {
  ConwayCell c;
  auto p = c.update(8);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_live_zero_neighbors) {
  ConwayCell c(true);
  auto p = c.update(0);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_live_one_neighbor) {
  ConwayCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_live_two_neighbors) {
  ConwayCell c(true);
  auto p = c.update(2);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(true, c.is_alive());
}

TEST(ConwayCellFixture, update_live_three_neighbors) {
  ConwayCell c(true);
  auto p = c.update(3);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(true, c.is_alive());
}

TEST(ConwayCellFixture, update_live_four_neighbors) {
  ConwayCell c(true);
  auto p = c.update(4);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_live_five_neighbors) {
  ConwayCell c(true);
  auto p = c.update(5);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_live_six_neighbors) {
  ConwayCell c(true);
  auto p = c.update(6);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_live_seven_neighbors) {
  ConwayCell c(true);
  auto p = c.update(7);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, update_live_eight_neighbors) {
  ConwayCell c(true);
  auto p = c.update(8);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, clone_dead) {
  ConwayCell c;
  auto p = c.clone();
  delete p;
  ASSERT_NE(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(ConwayCellFixture, clone_live) {
  ConwayCell c(true);
  auto p = c.clone();
  delete p;
  ASSERT_NE(nullptr, p);
  ASSERT_EQ(true, c.is_alive()); 
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// FredkinCellFixture //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

TEST(FredkinCellFixture, init_dead) {
  FredkinCell c;
  ASSERT_EQ(false, c.is_alive());
}

TEST(FredkinCellFixture, init_live) {
  FredkinCell c(true);
  ASSERT_EQ(true, c.is_alive());
}

TEST(FredkinCellFixture, print_dead) {
  ostringstream out;
  FredkinCell c;
  out << c;
  ASSERT_EQ("-", out.str());
}

TEST(FredkinCellFixture, print_live_zero_generations) {
  ostringstream out;
  FredkinCell c(true);
  out << c;
  ASSERT_EQ("0", out.str());
}

TEST(FredkinCellFixture, print_live_one_generation) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("1", out.str());
}

TEST(FredkinCellFixture, print_live_two_generations) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("2", out.str());
}

TEST(FredkinCellFixture, print_live_three_generations) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("3", out.str());
}

TEST(FredkinCellFixture, print_live_four_generations) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("4", out.str());
}

TEST(FredkinCellFixture, print_live_five_generations) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("5", out.str());
}

TEST(FredkinCellFixture, print_live_six_generations) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("6", out.str());
}

TEST(FredkinCellFixture, print_live_seven_generations) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("7", out.str());
}

TEST(FredkinCellFixture, print_live_eight_generations) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("8", out.str());
}

TEST(FredkinCellFixture, print_live_nine_generations) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("9", out.str());
}

TEST(FredkinCellFixture, print_live_ten_generations) {
  ostringstream out;
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(1);
  ASSERT_EQ(nullptr, p);
  out << c;
  ASSERT_EQ("+", out.str());
}

TEST(FredkinCellFixture, mutate_after_two_turns) {
  FredkinCell c(true, true);
  auto p = c.update(1);
  bool not_null = nullptr == p;
  delete p;
  ASSERT_TRUE(not_null);
  p = c.update(1);
  not_null = nullptr != p;
  ConwayCell *c2 = dynamic_cast<ConwayCell *>(p);
  bool alive = false;
  if (c2)
    alive = c2->is_alive();
  delete p;
  ASSERT_TRUE(not_null);
  ASSERT_TRUE(c2);
  ASSERT_TRUE(alive);
}

TEST(FredkinCellFixture, dont_mutate_after_two_turns_if_dead_on_second_turn) {
  FredkinCell c(true, true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  p = c.update(2);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(FredkinCellFixture, count_ac_null) {
  FredkinCell c;
  Neighbors<AbstractCell *> n({{nullptr, nullptr, nullptr, nullptr},
                               {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_fc_null) {
  FredkinCell c;
  Neighbors<FredkinCell *> n({{nullptr, nullptr, nullptr, nullptr},
                              {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_ac_one_direct_dead) {
  FredkinCell c;
  FredkinCell other;
  Neighbors<AbstractCell *> n({{&other, nullptr, nullptr, nullptr},
                               {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_fc_one_direct_dead) {
  FredkinCell c;
  FredkinCell other;
  Neighbors<FredkinCell *> n({{&other, nullptr, nullptr, nullptr},
                              {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_ac_one_direct_live) {
  FredkinCell c;
  FredkinCell other(true);
  Neighbors<AbstractCell *> n({{&other, nullptr, nullptr, nullptr},
                               {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(1, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_fc_one_direct_live) {
  FredkinCell c;
  FredkinCell other(true);
  Neighbors<FredkinCell *> n({{&other, nullptr, nullptr, nullptr},
                              {nullptr, nullptr, nullptr, nullptr}});
  ASSERT_EQ(1, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_ac_one_diagonal_dead) {
  FredkinCell c;
  FredkinCell other;
  Neighbors<AbstractCell *> n({{nullptr, nullptr, nullptr, nullptr},
                               {&other, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_fc_one_diagonal_dead) {
  FredkinCell c;
  FredkinCell other;
  Neighbors<FredkinCell *> n({{nullptr, nullptr, nullptr, nullptr},
                              {&other, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_ac_one_diagonal_live) {
  FredkinCell c;
  FredkinCell other(true);
  Neighbors<AbstractCell *> n({{nullptr, nullptr, nullptr, nullptr},
                               {&other, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_fc_one_diagonal_live) {
  FredkinCell c;
  FredkinCell other(true);
  Neighbors<FredkinCell *> n({{nullptr, nullptr, nullptr, nullptr},
                              {&other, nullptr, nullptr, nullptr}});
  ASSERT_EQ(0, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_ac_four_mixed) {
  FredkinCell c;
  FredkinCell other(true);
  Neighbors<AbstractCell *> n(
      {{nullptr, &other, nullptr, &other}, {&other, nullptr, &other, nullptr}});
  ASSERT_EQ(2, c.count_neighbors(n));
}

TEST(FredkinCellFixture, count_fc_four_mixed) {
  FredkinCell c;
  FredkinCell other(true);
  Neighbors<FredkinCell *> n(
      {{nullptr, &other, nullptr, &other}, {&other, nullptr, &other, nullptr}});
  ASSERT_EQ(2, c.count_neighbors(n));
}

TEST(FredkinCellFixture, update_dead_zero_neighbors) {
  FredkinCell c;
  auto p = c.update(0);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(FredkinCellFixture, update_dead_one_neighbor) {
  FredkinCell c;
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(true, c.is_alive());
}

TEST(FredkinCellFixture, update_dead_two_neighbors) {
  FredkinCell c;
  auto p = c.update(2);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(FredkinCellFixture, update_dead_three_neighbors) {
  FredkinCell c;
  auto p = c.update(3);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(true, c.is_alive());
}

TEST(FredkinCellFixture, update_dead_four_neighbors) {
  FredkinCell c;
  auto p = c.update(4);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(FredkinCellFixture, update_live_zero_neighbors) {
  FredkinCell c(true);
  auto p = c.update(0);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(FredkinCellFixture, update_live_one_neighbor) {
  FredkinCell c(true);
  auto p = c.update(1);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(true, c.is_alive());
}

TEST(FredkinCellFixture, update_live_two_neighbors) {
  FredkinCell c(true);
  auto p = c.update(2);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(FredkinCellFixture, update_live_three_neighbors) {
  FredkinCell c(true);
  auto p = c.update(3);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(true, c.is_alive());
}

TEST(FredkinCellFixture, update_live_four_neighbors) {
  FredkinCell c(true);
  auto p = c.update(4);
  ASSERT_EQ(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
}

TEST(FredkinCellFixture, clone_dead) {
  FredkinCell c;
  auto p = c.clone();
  FredkinCell *c2 = dynamic_cast<FredkinCell *>(p);
  delete p;
  ASSERT_NE(nullptr, p);
  ASSERT_EQ(false, c.is_alive());
  ASSERT_TRUE(c2 );
}

TEST(FredkinCellFixture, clone_live) {
  FredkinCell c(true);
  auto p = c.clone();
  FredkinCell *c2  = dynamic_cast<FredkinCell *>(p); 
  delete p;
  ASSERT_NE(nullptr, p);
  ASSERT_EQ(true, c.is_alive());
  ASSERT_TRUE(c2);
}

TEST(FredkinCellFixture, clone_young) {
  FredkinCell c(true);
  auto p = c.update(1);
  delete p;
  ASSERT_EQ(nullptr, p);
  c.update(1);
  delete p;
  ASSERT_EQ(nullptr, p);
  p = c.clone();
  FredkinCell *c2 = dynamic_cast<FredkinCell *>(p);
  ostringstream out;
  out << *p;
  delete p;
  ASSERT_NE(nullptr, p);
  ASSERT_TRUE(c2 );
  ASSERT_EQ(true, c.is_alive());
  ASSERT_EQ("2", out.str());
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// CellFixture /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

TEST(CellFixture, init_dead_cc) {
  Cell c(new ConwayCell);
  ASSERT_EQ(false, c.is_alive());
  ostringstream out;
  out << c;
  ASSERT_EQ(".", out.str());
}

TEST(CellFixture, init_live_cc) {
  Cell c(new ConwayCell(true));
  ASSERT_EQ(true, c.is_alive());
  ostringstream out;
  out << c;
  ASSERT_EQ("*", out.str());
}

TEST(CellFixture, init_dead_fc) {
  Cell c(new FredkinCell);
  ASSERT_EQ(false, c.is_alive());
  ostringstream out;
  out << c;
  ASSERT_EQ("-", out.str());
}

TEST(CellFixture, init_live_fc) {
  Cell c(new FredkinCell(true));
  ASSERT_EQ(true, c.is_alive());
  ostringstream out;
  out << c;
  ASSERT_EQ("0", out.str());
}

TEST(CellFixture, copy_construct) {
  Cell c1(new FredkinCell);
  Cell c2 = c1;
  ASSERT_EQ(false, c2.is_alive());
  ostringstream out;
  out << c2;
  ASSERT_EQ("-", out.str());
}

TEST(CellFixture, copy_assign) {
  Cell c1(new FredkinCell);
  Cell c2;
  c2 = c1;
  ASSERT_EQ(false, c2.is_alive());
  ostringstream out;
  out << c2;
  ASSERT_EQ("-", out.str());
}

TEST(CellFixture, count_neighbors_mixed) {
  Cell c(new ConwayCell);
  Cell fc_dead(new FredkinCell);
  Cell fc_live(new FredkinCell(true));
  Cell cc_dead(new ConwayCell);
  Cell cc_live(new ConwayCell(true));
  Neighbors<Cell *> n({{&fc_dead, &fc_dead, &fc_live, &fc_live},
                       {&cc_dead, &cc_dead, &cc_live, &cc_live}});
  ASSERT_EQ(4, c.count_neighbors(n));
}

TEST(CellFixture, count_neighbors_mixed_with_null) {
  Cell c(new ConwayCell);
  Cell fc_dead(new FredkinCell);
  Cell fc_live(new FredkinCell(true));
  Cell cc_dead(new ConwayCell);
  Cell cc_live(new ConwayCell(true));
  Neighbors<Cell *> n({{&fc_dead, &fc_dead, &fc_live, nullptr},
                       {&cc_dead, &cc_dead, &cc_live, nullptr}});
  ASSERT_EQ(2, c.count_neighbors(n));
}

TEST(CellFixture, update_conway) {
  Cell c(new ConwayCell(true));
  c.update(2);
  ostringstream out;
  out << c;
  ASSERT_EQ("*", out.str());
}

TEST(CellFixture, update_fredkin_no_mutate) {
  Cell c(new FredkinCell(true));
  c.update(1);
  c.update(1);
  ostringstream out;
  out << c;
  ASSERT_EQ("2", out.str());
}

TEST(CellFixture, update_fredkin_mutate) {
  Cell c(new FredkinCell(true, true));
  c.update(1);
  c.update(1);
  ostringstream out;
  out << c;
  ASSERT_EQ("*", out.str());
}

TEST(CellFixture, is_alive) {
  Cell c(new ConwayCell(true));
  ASSERT_EQ(true, c.is_alive());
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// CellFixture /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

TEST(LifeFixture, init_empty) {
  Life<ConwayCell> l(1, 1);
  ostringstream out;
  out << l;
  ASSERT_EQ(".\n", out.str());
}

TEST(LifeFixture, init_one_live) {
  Life<ConwayCell> l(1, 1);
  l.insert_cell(0, 0, ConwayCell(true));
  ostringstream out;
  out << l;
  ASSERT_EQ("*\n", out.str());
}

TEST(LifeFixture, init_oob_left) {
  Life<ConwayCell> l(8, 8);
  ASSERT_THROW(l.insert_cell(0, -1, ConwayCell(true)), invalid_argument);
}

TEST(LifeFixture, init_oob_right) {
  Life<ConwayCell> l(8, 8);
  ASSERT_THROW(l.insert_cell(0, 8, ConwayCell(true)), invalid_argument);
}

TEST(LifeFixture, init_oob_top) {
  Life<ConwayCell> l(8, 8);
  ASSERT_THROW(l.insert_cell(-1, 0, ConwayCell(true)), invalid_argument);
}

TEST(LifeFixture, init_oob_bottom) {
  Life<ConwayCell> l(8, 8);
  ASSERT_THROW(l.insert_cell(8, 0, ConwayCell(true)), invalid_argument);
}

TEST(LifeFixture, init_large) {
  Life<Cell> l(8, 6);
  for (int row = 0; row < 8; ++row) {
    for (int col = 0; col < 6; ++col) {
      l.insert_cell(row, col, Cell(new ConwayCell));
    }
  }
  l.insert_cell(0, 4, Cell(new ConwayCell(true)));
  l.insert_cell(5, 0, Cell(new FredkinCell(true)));
  ostringstream out;
  out << l;
  ASSERT_EQ("....*.\n......\n......\n......\n......\n0.....\n......\n......\n",
            out.str());
}

TEST(LifeFixture, step_block) {
  Life<ConwayCell> l(4, 4);
  l.insert_cell(2, 2, ConwayCell(true));
  l.insert_cell(2, 1, ConwayCell(true));
  l.insert_cell(1, 2, ConwayCell(true));
  l.insert_cell(1, 1, ConwayCell(true));
  for (int i = 0; i < 100; ++i) {
    ASSERT_EQ(l.step(), 4);
  }
  ostringstream out;
  out << l;
  ASSERT_EQ("....\n.**.\n.**.\n....\n", out.str());
}

TEST(LifeFixture, step_beehive) {
  Life<ConwayCell> l(3, 4);
  l.insert_cell(0, 1, ConwayCell(true));
  l.insert_cell(0, 2, ConwayCell(true));
  l.insert_cell(1, 0, ConwayCell(true));
  l.insert_cell(1, 3, ConwayCell(true));
  l.insert_cell(2, 1, ConwayCell(true));
  l.insert_cell(2, 2, ConwayCell(true));
  for (int i = 0; i < 100; ++i) {
    ASSERT_EQ(l.step(), 6);
  }
  ostringstream out;
  out << l;
  ASSERT_EQ(".**.\n*..*\n.**.\n", out.str());
}

TEST(LifeFixture, step_blinker) {
  Life<ConwayCell> l(3, 3);
  l.insert_cell(1, 0, ConwayCell(true));
  l.insert_cell(1, 1, ConwayCell(true));
  l.insert_cell(1, 2, ConwayCell(true));
  for (int i = 0; i < 100; ++i) {
    ASSERT_EQ(l.step(), 3);
    ostringstream out1;
    out1 << l;
    ASSERT_EQ(".*.\n.*.\n.*.\n", out1.str());
    ASSERT_EQ(l.step(), 3);
    ostringstream out2;
    out2 << l;
    ASSERT_EQ("...\n***\n...\n", out2.str());
  }
}

TEST(LifeFixture, step_glider) {
  Life<ConwayCell> l(4, 4);
  l.insert_cell(0, 1, ConwayCell(true));
  l.insert_cell(1, 2, ConwayCell(true));
  l.insert_cell(2, 0, ConwayCell(true));
  l.insert_cell(2, 1, ConwayCell(true));
  l.insert_cell(2, 2, ConwayCell(true));

  ASSERT_EQ(l.step(), 5);
  ostringstream out1;
  out1 << l;
  ASSERT_EQ("....\n*.*.\n.**.\n.*..\n", out1.str());

  ASSERT_EQ(l.step(), 5);
  ostringstream out2;
  out2 << l;
  ASSERT_EQ("....\n..*.\n*.*.\n.**.\n", out2.str());

  ASSERT_EQ(l.step(), 5);
  ostringstream out3;
  out3 << l;
  ASSERT_EQ("....\n.*..\n..**\n.**.\n", out3.str());

  ASSERT_EQ(l.step(), 5);
  ostringstream out4;
  out4 << l;
  ASSERT_EQ("....\n..*.\n...*\n.***\n", out4.str());
}
