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

TEST(LifeFixture, ConwayCell_pop_live) {
  ConwayCell x('*');
  int y = 0;
  x.census(y);
  ASSERT_EQ(y, 1);
}

TEST(LifeFixture, ConwayCell_pop_dead) {
  ConwayCell x('.');
  int y = 0;
  x.census(y);
  ASSERT_EQ(y, 0);
}

TEST(LifeFixture, ConwayCell_pop_both) {
  ConwayCell x('*'), z('.');
  int y = 0;
  x.census(y);
  z.census(y);
  ASSERT_EQ(y, 1);
}

TEST(LifeFixture, ConwayCell_neighbor_side) {
  ConwayCell x('*');
  ASSERT_TRUE(x.neighbor(0, 0, 0, 1));
}

TEST(LifeFixture, ConwayCell_neighbor_above) {
  ConwayCell x('*');
  ASSERT_TRUE(x.neighbor(0, 0, 1, 0));
}

TEST(LifeFixture, ConwayCell_neighbor_diagnal) {
  ConwayCell x('*');
  ASSERT_TRUE(x.neighbor(0, 0, 1, 1));
}

TEST(LifeFixture, ConwayCell_evolve_sustain) {
  ConwayCell x('*');
  x.evolve(3);
  ASSERT_EQ(x.str(), '*');
}

TEST(LifeFixture, ConwayCell_evolve_sustain2) {
  ConwayCell x('*');
  x.evolve(2);
  ASSERT_EQ(x.str(), '*');
}

TEST(LifeFixture, ConwayCell_evolve_revive) {
  ConwayCell x('.');
  x.evolve(3);
  ASSERT_EQ(x.str(), '*');
}

TEST(LifeFixture, ConwayCell_evolve_solitude) {
  ConwayCell x('*');
  x.evolve(1);
  ASSERT_EQ(x.str(), '.');
}

TEST(LifeFixture, ConwayCell_evolve_overpop) {
  ConwayCell x('*');
  x.evolve(4);
  ASSERT_EQ(x.str(), '.');
}

TEST(LifeFixture, ConwayCell_clone_live) {
  ConwayCell x('*');
  AbstractCell *y = x.clone();
  ASSERT_EQ(x.str(), y->str());
  delete y;
}

TEST(LifeFixture, ConwayCell_clone_dead) {
  ConwayCell x('.');
  AbstractCell *y = x.clone();
  ASSERT_EQ(x.str(), y->str());
  delete y;
}

TEST(LifeFixture, ConwayCell_str_live) {
  ConwayCell x('*');
  ASSERT_EQ(x.str(), '*');
}

TEST(LifeFixture, ConwayCell_str_dead) {
  ConwayCell x('.');
  ASSERT_EQ(x.str(), '.');
}

TEST(LifeFixture, ConwayCell_str_both) {
  ConwayCell x('*');
  ASSERT_EQ(x.str(), '*');
  x.evolve(0);
  ASSERT_EQ(x.str(), '.');
}

TEST(LifeFixture, FredkinCell_pop_live) {
  FredkinCell x('0');
  int y = 0;
  x.census(y);
  ASSERT_EQ(y, 1);
}

TEST(LifeFixture, FredkinCell_pop_dead) {
  FredkinCell x('-');
  int y = 0;
  x.census(y);
  ASSERT_EQ(y, 0);
}

TEST(LifeFixture, FredkinCell_pop_both) {
  FredkinCell x('0'), z('-');
  int y = 0;
  x.census(y);
  z.census(y);
  ASSERT_EQ(y, 1);
}

TEST(LifeFixture, FredkinCell_neighbor_side) {
  FredkinCell x('0');
  ASSERT_TRUE(x.neighbor(0, 0, 0, 1));
}

TEST(LifeFixture, FredkinCell_neighbor_above) {
  FredkinCell x('0');
  ASSERT_TRUE(x.neighbor(0, 0, 1, 0));
}

TEST(LifeFixture, FredkinCell_neighbor_diagnal) {
  FredkinCell x('0');
  ASSERT_FALSE(x.neighbor(0, 0, 1, 1));
}

TEST(LifeFixture, FredkinCell_evolve_revive) {
  FredkinCell x('-');
  x.evolve(3);
  ASSERT_EQ(x.str(), '0');
}

TEST(LifeFixture, FredkinCell_evolve_revive2) {
  FredkinCell x('-');
  x.evolve(1);
  ASSERT_EQ(x.str(), '0');
}

TEST(LifeFixture, FredkinCell_evolve_solitude) {
  FredkinCell x('0');
  x.evolve(0);
  ASSERT_EQ(x.str(), '-');
}

TEST(LifeFixture, FredkinCell_evolve_overpop) {
  FredkinCell x('0');
  x.evolve(4);
  ASSERT_EQ(x.str(), '-');
}

TEST(LifeFixture, FredkinCell_evolve_death) {
  FredkinCell x('0');
  x.evolve(2);
  ASSERT_EQ(x.str(), '-');
}

TEST(LifeFixture, FredkinCell_evolve_to_Conway) {
  FredkinCell x('1');
  auto tmp = x.evolve(3);
  ASSERT_NE(nullptr, tmp);
  ASSERT_EQ(x.str(), '2');
  delete tmp;
}

TEST(LifeFixture, FredkinCell_clone_live) {
  FredkinCell x('0');
  AbstractCell *y = x.clone();
  ASSERT_EQ(x.str(), y->str());
  delete y;
}

TEST(LifeFixture, FredkinCell_clone_live_old) {
  FredkinCell x('+');
  AbstractCell *y = x.clone();
  ASSERT_EQ(x.str(), y->str());
  delete y;
}

TEST(LifeFixture, FredkinCell_clone_dead) {
  FredkinCell x('-');
  AbstractCell *y = x.clone();
  ASSERT_EQ(x.str(), y->str());
  delete y;
}

TEST(LifeFixture, FredkinCell_str_live) {
  FredkinCell x('0');
  ASSERT_EQ(x.str(), '0');
}

TEST(LifeFixture, FredkinCell_str_dead) {
  FredkinCell x('-');
  ASSERT_EQ(x.str(), '-');
}

TEST(LifeFixture, FredkinCell_str_both) {
  FredkinCell x('1');
  ASSERT_EQ(x.str(), '1');
  x.evolve(0);
  ASSERT_EQ(x.str(), '-');
}

TEST(LifeFixture, Cell_constructor_conway_live) {
  Cell x('*');
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), "*");
}

TEST(LifeFixture, Cell_constructor_conway_dead) {
  Cell x('.');
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), ".");
}

TEST(LifeFixture, Cell_constructor_fredkin_live) {
  Cell x('0');
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), "0");
}

TEST(LifeFixture, Cell_constructor_fredkin_dead) {
  Cell x('-');
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), "-");
}

TEST(LifeFixture, Cell_copy_constructor) {
  Cell x('*'), y(x);
  std::ostringstream osx, osy;
  osx << x;
  osy << y;
  ASSERT_NE(x.c_, y.c_);
  ASSERT_EQ(osx.str(), osy.str());
}

TEST(LifeFixture, Cell_copy_constructor2) {
  Cell x('*'), y(x);
  std::ostringstream osx, osy;
  osx << x;
  y.evolve(0);
  osy << y;
  ASSERT_NE(osx.str(), osy.str());
}

TEST(LifeFixture, Cell_copy_constructor3) {
  Cell x('*'), y(x);
  std::ostringstream osx, osy;
  x.evolve(4);
  osx << x;
  y.evolve(0);
  osy << y;
  ASSERT_EQ(osx.str(), osy.str());
}

TEST(LifeFixture, Cell_assignment_operator) {
  Cell x('*'), y('.');
  y = x;
  std::ostringstream osx, osy;
  osx << x;
  osy << y;
  ASSERT_NE(x.c_, y.c_);
  ASSERT_EQ(osx.str(), osy.str());
}

TEST(LifeFixture, Cell_assignment_operator2) {
  Cell x('*'), y('.');
  y = x;
  std::ostringstream osx, osy;
  osx << x;
  y.evolve(0);
  osy << y;
  ASSERT_NE(osx.str(), osy.str());
}

TEST(LifeFixture, Cell_assignment_operator3) {
  Cell x('*'), y('.');
  y = x;
  std::ostringstream osx, osy;
  x.evolve(4);
  osx << x;
  y.evolve(0);
  osy << y;
  ASSERT_EQ(osx.str(), osy.str());
}

TEST(LifeFixture, Cell_pop_live_conway) {
  Cell x('*');
  int y = 0;
  x.census(y);
  ASSERT_EQ(y, 1);
}

TEST(LifeFixture, Cell_pop_dead_conway) {
  Cell x('.');
  int y = 0;
  x.census(y);
  ASSERT_EQ(y, 0);
}

TEST(LifeFixture, Cell_pop_both_conway) {
  Cell x('*'), z('.');
  int y = 0;
  x.census(y);
  z.census(y);
  ASSERT_EQ(y, 1);
}

TEST(LifeFixture, Cell_pop_live_fredkin) {
  Cell x('0');
  int y = 0;
  x.census(y);
  ASSERT_EQ(y, 1);
}

TEST(LifeFixture, Cell_pop_dead_fredkin) {
  Cell x('-');
  int y = 0;
  x.census(y);
  ASSERT_EQ(y, 0);
}

TEST(LifeFixture, Cell_pop_both_fredkin) {
  Cell x('0'), z('-');
  int y = 0;
  x.census(y);
  z.census(y);
  ASSERT_EQ(y, 1);
}

TEST(LifeFixture, Cell_neighbor_side_conway) {
  Cell x('*');
  ASSERT_TRUE(x.neighbor(0, 0, 0, 1));
}

TEST(LifeFixture, Cell_neighbor_above_conway) {
  Cell x('*');
  ASSERT_TRUE(x.neighbor(0, 0, 1, 0));
}

TEST(LifeFixture, Cell_neighbor_diagnal_conway) {
  Cell x('*');
  ASSERT_TRUE(x.neighbor(0, 0, 1, 1));
}

TEST(LifeFixture, Cell_neighbor_side_fredkin) {
  Cell x('0');
  ASSERT_TRUE(x.neighbor(0, 0, 0, 1));
}

TEST(LifeFixture, Cell_neighbor_above_fredkin) {
  Cell x('0');
  ASSERT_TRUE(x.neighbor(0, 0, 1, 0));
}

TEST(LifeFixture, Cell_neighbor_diagnal_fredkin) {
  Cell x('0');
  ASSERT_FALSE(x.neighbor(0, 0, 1, 1));
}

TEST(LifeFixture, Cell_evolve_revive_conway) {
  Cell x('.');
  x.evolve(3);
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), "*");
}

TEST(LifeFixture, Cell_evolve_solitude_conway) {
  Cell x('*');
  x.evolve(1);
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), ".");
}

TEST(LifeFixture, Cell_evolve_overpop_conway) {
  Cell x('*');
  x.evolve(4);
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), ".");
}

TEST(LifeFixture, Cell_evolve_revive_fredkin) {
  Cell x('-');
  x.evolve(3);
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), "0");
}

TEST(LifeFixture, Cell_evolve_solitude_fredkin) {
  Cell x('0');
  x.evolve(0);
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), "-");
}

TEST(LifeFixture, Cell_evolve_overpop_fredkin) {
  Cell x('0');
  x.evolve(4);
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), "-");
}

TEST(LifeFixture, Cell_evolve_to_Conway_fredkin) {
  Cell x('1');
  x.evolve(3);
  std::ostringstream os;
  os << x;
  ASSERT_EQ(os.str(), "*");
}

TEST(LifeFixture, Life_constructor_conway) {
  Life<ConwayCell> cc_life(0, 0);
  std::ostringstream os;
  os << cc_life;
  ASSERT_EQ("Generation = 0, Population = 0.\n", os.str());
}

TEST(LifeFixture, Life_constructor_fredkin) {
  Life<FredkinCell> fc_life(0, 0);
  std::ostringstream os;
  os << fc_life;
  ASSERT_EQ("Generation = 0, Population = 0.\n", os.str());
}

TEST(LifeFixture, Life_constructor_cell) {
  Life<Cell> c_life(0, 0);
  std::ostringstream os;
  os << c_life;
  ASSERT_EQ("Generation = 0, Population = 0.\n", os.str());
}

TEST(LifeFixture, Life_addRow_conway) {
  Life<ConwayCell> cc_life(2, 2);
  cc_life.addRow(0, "*.");
  cc_life.addRow(1, ".*");
  std::ostringstream os;
  os << cc_life;
  ASSERT_EQ("Generation = 0, Population = 2.\n*.\n.*\n", os.str());
}

TEST(LifeFixture, Life_addRow_fredkin) {
  Life<FredkinCell> fc_life(2, 2);
  fc_life.addRow(0, "0-");
  fc_life.addRow(1, "-0");
  std::ostringstream os;
  os << fc_life;
  ASSERT_EQ("Generation = 0, Population = 2.\n0-\n-0\n", os.str());
}

TEST(LifeFixture, Life_addRow_cell) {
  Life<Cell> c_life(2, 2);
  c_life.addRow(0, "0*");
  c_life.addRow(1, "-.");
  std::ostringstream os;
  os << c_life;
  ASSERT_EQ("Generation = 0, Population = 2.\n0*\n-.\n", os.str());
}

TEST(LifeFixture, Life_evolve_conway) {
  Life<ConwayCell> cc_life(3, 3);
  cc_life.addRow(0, ".*.");
  cc_life.addRow(1, "*.*");
  cc_life.addRow(2, "...");
  std::ostringstream os;
  os << cc_life;
  cc_life.evolve();
  os << cc_life;
  ASSERT_EQ("Generation = 0, Population = 3.\n.*.\n*.*\n...\nGeneration = 1, "
            "Population = 2.\n.*.\n.*.\n...\n",
            os.str());
}

TEST(LifeFixture, Life_evolve_fredkin) {
  Life<FredkinCell> fc_life(3, 3);
  fc_life.addRow(0, "-+-");
  fc_life.addRow(1, "010");
  fc_life.addRow(2, "---");
  std::ostringstream os;
  os << fc_life;
  fc_life.evolve();
  os << fc_life;
  ASSERT_EQ("Generation = 0, Population = 4.\n-+-\n010\n---\nGeneration = 1, "
            "Population = 7.\n-+-\n121\n000\n",
            os.str());
}

TEST(LifeFixture, Life_evolve_cell) {
  Life<Cell> c_life(3, 3);
  c_life.addRow(0, ".1.");
  c_life.addRow(1, ".*.");
  c_life.addRow(2, ".1.");
  std::ostringstream os;
  os << c_life;
  c_life.evolve();
  os << c_life;
  ASSERT_EQ("Generation = 0, Population = 3.\n.1.\n.*.\n.1.\nGeneration = 1, "
            "Population = 5.\n.*.\n***\n.*.\n",
            os.str());
}

TEST(LifeFixture, Life_copy_conway) {
  Life<ConwayCell> cc_life(3, 3), cc_life_cpy(0, 0);
  cc_life.addRow(0, ".*.");
  cc_life.addRow(1, "*.*");
  cc_life.addRow(2, "...");
  cc_life_cpy = cc_life;
  cc_life.evolve();
  std::ostringstream os, os_cpy;
  os << cc_life;
  os_cpy << cc_life_cpy;
  ASSERT_NE(os.str(), os_cpy.str());
}

TEST(LifeFixture, Life_copy_fredkin) {
  Life<FredkinCell> fc_life(3, 3), fc_life_cpy(0, 0);
  fc_life.addRow(0, "-+-");
  fc_life.addRow(1, "010");
  fc_life.addRow(2, "---");
  fc_life_cpy = fc_life;
  fc_life.evolve();
  std::ostringstream os, os_cpy;
  os << fc_life;
  os_cpy << fc_life_cpy;

  ASSERT_NE(os.str(), os_cpy.str());
}

TEST(LifeFixture, Life_copy_cell) {
  Life<Cell> c_life(3, 3), c_life_cpy(0, 0);
  c_life.addRow(0, ".1.");
  c_life.addRow(1, ".*.");
  c_life.addRow(2, ".1.");
  c_life_cpy = c_life;
  c_life.evolve();
  std::ostringstream os, os_cpy;
  os << c_life;
  os_cpy << c_life_cpy;
  ASSERT_NE(os.str(), os_cpy.str());
}
