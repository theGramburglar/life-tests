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
#include <iostream>
using namespace std;

// ----
// ConwayCell tests
// ----

TEST(CCFixture, test_constructor_valid_dead) {
  ASSERT_NO_THROW(ConwayCell cc('.'));
}

TEST(CCFixture, test_constructor_valid_live) {
  ASSERT_NO_THROW(ConwayCell cc('*'));
}

TEST(CCFixture, test_constructor_invalid_fc_dead) {
  ASSERT_ANY_THROW(ConwayCell cc('-'));
}

TEST(CCFixture, test_constructor_invalid_fc) {
  ASSERT_ANY_THROW(ConwayCell cc('0'));
}

TEST(CCFixture, test_output) {
  ConwayCell cc('.');
  ostringstream os;
  os << cc;
  ASSERT_EQ(os.str(), ".");
}

TEST(CCFixture, test_deadness) {
  ConwayCell cc('.');
  ASSERT_EQ(false, cc.is_alive());
}

TEST(CCFixture, test_liveness) {
  ConwayCell cc('*');
  ASSERT_EQ(true, cc.is_alive());
}

TEST(CCFixture, test_evolve_dead_to_alive) {
  ConwayCell cc('.');
  cc.evolve(pair<int, int>(2, 1));
  ostringstream os;
  os << cc;
  ASSERT_EQ("*", os.str());
}

TEST(CCFixture, test_evolve_dead_stay_dead) {
  ConwayCell cc('.');
  for (int i = 0; i <= 4; i++) {
    if (i != 3) {
      cc.evolve(pair<int, int>(i, 0));
      ostringstream os;
      os << cc;
      ASSERT_EQ(".", os.str());
    }
  }
}

TEST(CCFixture, test_evolve_alive_stay_alive) {
  ConwayCell cc('*');
  for (int i = 2; i <= 3; i++) {
    cc.evolve(pair<int, int>(i, 0));
    ostringstream os;
    os << cc;
    ASSERT_EQ("*", os.str());
  }
}

TEST(CCFixture, test_evolve_alive_turn_dead) {
  for (int i = 0; i <= 4; i++) {
    if (i < 2 || i > 3) {
      ConwayCell cc('*');
      cc.evolve(pair<int, int>(i, 0));
      ostringstream os;
      os << cc;
      ASSERT_EQ(".", os.str());
    }
  }
}

TEST(CCFixture, test_neighbor_validation) {
  ConwayCell cc('.');
  for (int i = 9; i <= 50; i++) {
    ASSERT_ANY_THROW(cc.evolve(pair<int, int>(i, 0)));
  }
}

// ----
// FredkinCell tests
// ----

TEST(FCFixture, test_constructor_valid_dead) {
  ASSERT_NO_THROW(FredkinCell fc('0'));
}

TEST(FCFixture, test_constructor_valid_live) {
  ASSERT_NO_THROW(FredkinCell fc('-'));
}

TEST(FCFixture, test_constructor_invalid_cc_dead) {
  ASSERT_ANY_THROW(FredkinCell fc('*'));
}

TEST(FCFixture, test_constructor_invalid_cc) {
  ASSERT_ANY_THROW(FredkinCell fc('.'));
}

TEST(FCFixture, test_output) {
  FredkinCell fc('0');
  ostringstream os;
  os << fc;
  ASSERT_EQ(os.str(), "0");
}

TEST(FCFixture, test_deadness) {
  FredkinCell fc('-');
  ASSERT_EQ(false, fc.is_alive());
}

TEST(FCFixture, test_liveness) {
  FredkinCell fc('0');
  ASSERT_EQ(true, fc.is_alive());
}

TEST(FCFixture, test_evolve_alive_to_dead) {
  for (int i = 0; i <= 4; i++) {
    FredkinCell fc('0');
    if (i % 2 == 0) {
      fc.evolve(pair<int, int>(i, 2));
      ostringstream os;
      os << fc;
      ASSERT_EQ("-", os.str());
    }
  }
}

TEST(FCFixture, test_evolve_alive_stay_alive) {
  FredkinCell fc('0');
  for (int i = 0; i <= 4; i++) {
    if (i != 0 && i != 2 && i != 4) {
      fc.evolve(pair<int, int>(i, 2));
      ostringstream os;
      os << fc;
      ASSERT_NE("-", os.str());
    }
  }
}

TEST(FCFixture, test_evolve_dead_stay_dead) {
  FredkinCell fc('-');
  for (int i = 0; i <= 4; i++) {
    if (i != 1 && i != 3) {
      fc.evolve(pair<int, int>(i, 2));
      ostringstream os;
      os << fc;
      ASSERT_EQ("-", os.str());
    }
  }
}

TEST(FCFixture, test_evolve_dead_turn_alive) {
  for (int i = 1; i <= 3; i++) {
    if (i == 1 || i == 3) {
      FredkinCell fc('-');
      fc.evolve(pair<int, int>(i, 2));
      ostringstream os;
      os << fc;
      ASSERT_NE("-", os.str());
    }
  }
}

TEST(FCFixture, test_evolution_symbol_numerical) {
  FredkinCell fc('0');
  for (int i = 1; i < 10; i++) {
    fc.evolve(pair<int, int>(1, 2));
    ostringstream os;
    os << fc;
    ASSERT_EQ(std::to_string(i), os.str());
  }
}

TEST(FCFixture, test_evolution_symbol_plus) {
  FredkinCell fc('0');
  for (int i = 0; i < 20; i++) {
    fc.evolve(pair<int, int>(1, 2));
    if (i >= 10) {
      ostringstream os;
      os << fc;
      ASSERT_EQ("+", os.str());
    }
  }
}

TEST(FCFixture, test_evolution_return_alive) {
  FredkinCell fc('0');
  for (int i = 1; i < 20; i++) {
    ASSERT_EQ(i == 2, fc.evolve(pair<int, int>(1, 2)));
  }
}

TEST(FCFixture, test_evolution_return_value_dead) {
  FredkinCell fc('-');
  for (int i = 0; i < 20; i++) {
    ASSERT_EQ(false, fc.evolve(pair<int, int>(2, 2)));
  }
}

TEST(FCFixture, test_neighbor_validation) {
  FredkinCell fc('-');
  for (int i = 9; i <= 50; i++) {
    ASSERT_ANY_THROW(fc.evolve(pair<int, int>(i, 2)));
  }
}

// ----
// Cell tests
// ----
TEST(FCFixture, test_cell_construction_live_cc) {
  ASSERT_NO_THROW(Cell c('*'));
}

TEST(FCFixture, test_cell_construction_dead_cc) {
  ASSERT_NO_THROW(Cell c('.'));
}

TEST(FCFixture, test_cell_construction_alive_fc) {
  ASSERT_NO_THROW(Cell c('0'));
}

TEST(FCFixture, test_cell_construction_dead_fc) {
  ASSERT_NO_THROW(Cell c('-'));
}

TEST(FCFixture, test_cell_construction_bad) { ASSERT_ANY_THROW(Cell c('+')); }

TEST(FCFixture, test_cc_output) {
  Cell c('*');
  ostringstream os;
  os << c;
  ASSERT_EQ("*", os.str());
}

TEST(FCFixture, test_fc_output) {
  Cell c('0');
  ostringstream os;
  os << c;
  ASSERT_EQ("0", os.str());
}

TEST(FCFixture, test_fc_evolution_into_cc) {
  Cell c('0');
  for (int i = 1; i < 5; i++) {
    c.evolve(pair<int, int>(1, 1));
    ostringstream os;
    os << c;
    if (i == 1)
      ASSERT_EQ("1", os.str());
    else
      ASSERT_EQ("*", os.str());
  }
}

// ----
// Life tests
// ----
TEST(LifeFixture, valid_life_construction_fc) {
  string input = "2 2\n-0\n0-";
  istringstream is(input);
  ASSERT_NO_THROW(Life<FredkinCell> l(is));
}

TEST(LifeFixture, invalid_life_construction_fc_rows) {
  string input = "3 2\n00\n00";
  istringstream is(input);
  ASSERT_ANY_THROW(Life<FredkinCell> l(is));
}

TEST(LifeFixture, invalid_life_construction_fc_cols) {
  string input = "2 2\n0\n0";
  istringstream is(input);
  ASSERT_ANY_THROW(Life<FredkinCell> l(is));
}

TEST(LifeFixture, invalid_life_construction_fc_cc) {
  string input = "2 2\n0*\n0*";
  istringstream is(input);
  ASSERT_ANY_THROW(Life<FredkinCell> l(is));
}

TEST(LifeFixture, valid_life_construction_cc) {
  string input = "2 2\n*.\n.*";
  istringstream is(input);
  ASSERT_NO_THROW(Life<ConwayCell> l(is));
}

TEST(LifeFixture, invalid_life_construction_cc_fc) {
  string input = "2 2\n*0\n.*";
  istringstream is(input);
  ASSERT_ANY_THROW(Life<ConwayCell> l(is));
}

TEST(LifeFixture, valid_life_construction_mixed_cells) {
  string input = "2 4\n*0-.\n-0.*";
  istringstream is(input);
  ASSERT_NO_THROW(Life<Cell> l(is));
}
TEST(LifeFixture, neighbor_count_mixed_cells_non_diag) {
  string input = "3 3\n"
                 "*0-\n"
                 "*0-\n"
                 "-0.";
  istringstream is(input);
  Life<Cell> l(is);
  ASSERT_EQ(3, l.get_neighbor_count(1, 1).first);
}

TEST(LifeFixture, neighbor_count_mixed_cells_diag) {
  string input = "3 3\n"
                 "*0-\n"
                 "*0-\n"
                 "-0.";
  istringstream is(input);
  Life<Cell> l(is);
  ASSERT_EQ(1, l.get_neighbor_count(1, 1).second);
}

TEST(LifeFixture, neighbor_count_mixed_cells_edge_non_diag) {
  string input = "3 3\n"
                 "*0-\n"
                 "*0-\n"
                 "-0.";
  istringstream is(input);
  Life<Cell> l(is);
  ASSERT_EQ(2, l.get_neighbor_count(0, 0).first);
}

TEST(LifeFixture, neighbor_count_mixed_cells_edge_diag) {
  string input = "3 3\n"
                 "*0-\n"
                 "*0-\n"
                 "-0.";
  istringstream is(input);
  Life<Cell> l(is);
  ASSERT_EQ(1, l.get_neighbor_count(0, 0).second);
}

TEST(LifeFixture, alive_count_mixed_cells) {
  string input = "3 3\n"
                 "*0-\n"
                 "*0-\n"
                 "-0.";
  istringstream is(input);
  Life<Cell> l(is);
  ASSERT_EQ(5, l.determine_alive());
}

TEST(LifeFixture, mixed_cells_initial_output) {
  string input = "3 3\n"
                 "*0-\n"
                 "*0-\n"
                 "-0.";
  istringstream is(input);
  Life<Cell> l(is);
  string expected = "Generation = 0, Population = 5.\n"
                    "*0-\n"
                    "*0-\n"
                    "-0.\n";
  ostringstream os;
  os << l;
  ASSERT_EQ(expected, os.str());
}

TEST(LifeFixture, live_mixed_cells) {
  string input = "3 3\n"
                 "*0-\n"
                 "*0-\n"
                 "-0.";
  istringstream is(input);
  Life<Cell> l(is);
  l.live();
  string expected = "Generation = 1, Population = 5.\n"
                    "*-0\n"
                    ".10\n"
                    "-1.\n";
  ostringstream os;
  os << l;
  ASSERT_EQ(expected, os.str());
}

TEST(LifeFixture, fredkin_cells_living) {
  string input = "3 3\n"
                 "---\n"
                 "-0-\n"
                 "---";
  istringstream is(input);
  Life<FredkinCell> l(is);
  l.live();
  string expected = "Generation = 1, Population = 4.\n"
                    "-0-\n"
                    "0-0\n"
                    "-0-\n";
  ostringstream os;
  os << l;
  ASSERT_EQ(expected, os.str());
}

TEST(LifeFixture, fredkin_cells_living_twice) {
  string input = "3 3\n"
                 "---\n"
                 "-0-\n"
                 "---";
  istringstream is(input);
  Life<FredkinCell> l(is);
  l.live();
  l.live();
  string expected = "Generation = 2, Population = 0.\n"
                    "---\n"
                    "---\n"
                    "---\n";
  ostringstream os;
  os << l;
  ASSERT_EQ(expected, os.str());
}

TEST(LifeFixture, fredkin_cells_living_thrice) {
  string input = "3 3\n"
                 "---\n"
                 "-0-\n"
                 "---";
  istringstream is(input);
  Life<FredkinCell> l(is);
  l.live();
  l.live();
  l.live();
  string expected = "Generation = 3, Population = 0.\n"
                    "---\n"
                    "---\n"
                    "---\n";
  ostringstream os;
  os << l;
  ASSERT_EQ(expected, os.str());
}
