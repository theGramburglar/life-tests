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
#include <assert.h>
#include <sstream>

using namespace std;

// ----------------
// Life class Tests
// ----------------

TEST(LifeFixture, input_stream_tests) {
  string conway_grid = "3 4\n..**\n**..\n....\n";
  string conway_grid_raw = "..****......";
  istringstream ccg(conway_grid);
  int m;
  int n;
  ccg >> m;
  ccg >> n;
  ASSERT_EQ(m, 3);
  ASSERT_EQ(n, 4);

  Life<ConwayCell> conway_life(m, n);
  ccg >> conway_life;
  ASSERT_EQ(conway_life._m, m + 2);
  ASSERT_EQ(conway_life._n, n + 2);
  ASSERT_EQ(conway_life._population, 4);
  ASSERT_EQ(conway_life._generation, 0);
  for (int row = 1; row < m - 1; ++row) {
    for (int col = 1; col < n - 1; ++col) {
      char expected = conway_grid_raw[(row - 1) * m + (col - 1)];
      ASSERT_EQ(conway_life._world[row][col]._state, expected);
    }
  }

  string fredkin_grid = "5 5\n--00-\n-----\n-0-0-\n-0-0-\n--0--\n";
  string fredkin_grid_raw = "--00-------0-0--0-0---0--";
  istringstream fcg(fredkin_grid);
  fcg >> m;
  fcg >> n;
  ASSERT_EQ(m, 5);
  ASSERT_EQ(n, 5);

  Life<FredkinCell> fredkin_life(m, n);
  fcg >> fredkin_life;
  ASSERT_EQ(fredkin_life._m, m + 2);
  ASSERT_EQ(fredkin_life._n, n + 2);
  ASSERT_EQ(fredkin_life._population, 7);
  ASSERT_EQ(fredkin_life._generation, 0);
  for (int row = 1; row < m - 1; ++row) {
    for (int col = 1; col < n - 1; ++col) {
      char expected = fredkin_grid_raw[(row - 1) * m + (col - 1)];
      ASSERT_EQ(fredkin_life._world[row][col]._state, expected);
    }
  }

  string cell_grid = "3 8\n--**..00\n0--0....\n*--*..0.\n";
  string cell_grid_raw = "--**..000--0....*--*..0.";
  istringstream cg(cell_grid);
  cg >> m;
  cg >> n;
  ASSERT_EQ(m, 3);
  ASSERT_EQ(n, 8);

  Life<Cell> cell_life(m, n);
  cg >> cell_life;
  ASSERT_EQ(cell_life._m, m + 2);
  ASSERT_EQ(cell_life._n, n + 2);
  ASSERT_EQ(cell_life._population, 9);
  ASSERT_EQ(cell_life._generation, 0);
  for (int row = 1; row < m - 1; ++row) {
    for (int col = 1; col < n - 1; ++col) {
      char expected = cell_grid_raw[(row - 1) * m + (col - 1)];
      ASSERT_EQ(cell_life._world[row][col]._p->_state, expected);
    }
  }
}

TEST(LifeFixture, output_stream_tests) {
  string conway_grid = "3 4\n..**\n**..\n....\n";
  istringstream ccg(conway_grid);
  ccg >> conway_grid;
  stringstream printed_conway_grid;
  printed_conway_grid << conway_grid;
  string actual_grid = printed_conway_grid.str();
  ASSERT_EQ(actual_grid, conway_grid);

  string fredkin_grid = "5 5\n--00-\n-----\n-0-0-\n-0-0-\n--0--\n";
  istringstream fcg(fredkin_grid);
  fcg >> fredkin_grid;
  stringstream printed_fredkin_grid;
  printed_fredkin_grid << fredkin_grid;
  actual_grid = printed_fredkin_grid.str();
  ASSERT_EQ(actual_grid, fredkin_grid);

  string cell_grid = "3 8\n--**..00\n0--0....\n*--*..0.\n";
  istringstream cg(cell_grid);
  cg >> cell_grid;
  stringstream printed_cell_grid;
  printed_cell_grid << cell_grid;
  actual_grid = printed_cell_grid.str();
  ASSERT_EQ(actual_grid, cell_grid);
}

TEST(LifeFixture, default_constructor_tests) {
  Life<ConwayCell> life;
  ASSERT_EQ(life._m, 0);
  ASSERT_EQ(life._n, 0);
  ASSERT_EQ(life._generation, 0);
  ASSERT_EQ(life._population, 0);
  ASSERT_EQ(life._world.size(), 0);
}

TEST(LifeFixture, double_constructor_tests) {
  Life<ConwayCell> life(2, 3);
  ASSERT_EQ(life._m, 4);
  ASSERT_EQ(life._n, 5);
  ASSERT_EQ(life._generation, 0);
  ASSERT_EQ(life._population, 0);
  // Take into account the MOAT_SIZE
  ASSERT_EQ(life._world.size(), 4);
  // Take into account the MOAT_SIZE
  ASSERT_EQ(life._world[0].size(), 5);

  // Tests to make sure the MOAT is correct
  istringstream r("2 2\n00\n00");
  int m;
  int n;
  r >> m;
  r >> n;
  Life<FredkinCell> life2(m, n);
  r >> life2;
  for (int row = 0; row < 4; ++row) {
    for (int col = 0; col < 4; ++col) {
      if ((row == 1 && col == 1) || (row == 1 && col == 2) ||
          (row == 2 && col == 1) || (row == 2 && col == 2)) {
        // Not the MOAT
        ASSERT_EQ(life2._world[row][col]._state, '0');
        ASSERT_EQ(life2._world[row][col]._alive, true);
      } else {
        // The MOAT
        ASSERT_EQ(life2._world[row][col]._state, '~');
        ASSERT_EQ(life2._world[row][col]._alive, false);
      }
    }
  }
}

TEST(LifeFixture, run_generation_tests) {
  Life<ConwayCell> life(2, 2);
  // Take into account for the MOAT
  ASSERT_EQ(life._world[1][1]._alive, false);
  ASSERT_EQ(life._world[1][2]._alive, false);
  ASSERT_EQ(life._world[2][1]._alive, false);
  ASSERT_EQ(life._world[2][2]._alive, false);
  life.run_generation();
  // Take into account for the MOAT
  ASSERT_EQ(life._world[1][1]._alive, false);
  ASSERT_EQ(life._world[1][2]._alive, false);
  ASSERT_EQ(life._world[2][1]._alive, false);
  ASSERT_EQ(life._world[2][2]._alive, false);
  // They're all dead.
  ASSERT_EQ(life._population, 0);

  istringstream r("2 2\n**\n*.");
  int m;
  int n;
  r >> m;
  r >> n;
  Life<ConwayCell> life2(m, n);
  r >> life2;
  life2.run_generation();
  ASSERT_EQ(life2._world[1][1]._alive, true);
  ASSERT_EQ(life2._world[1][2]._alive, true);
  ASSERT_EQ(life2._world[2][1]._alive, true);
  ASSERT_EQ(life2._world[2][2]._alive, true);
  ASSERT_EQ(life2._world[1][1]._state, '*');
  ASSERT_EQ(life2._world[1][2]._state, '*');
  ASSERT_EQ(life2._world[2][1]._state, '*');
  ASSERT_EQ(life2._world[2][2]._state, '*');
  // All four of them are alive
  ASSERT_EQ(life2._population, 4);

  istringstream r2("2 2\n**\n*.");
  r2 >> m;
  r2 >> n;
  Life<ConwayCell> life3(m, n);
  r2 >> life3;
  life3.run_generation();
  ASSERT_EQ(life3._world[1][1]._alive, true);
  ASSERT_EQ(life3._world[1][2]._alive, true);
  ASSERT_EQ(life3._world[2][1]._alive, true);
  ASSERT_EQ(life3._world[2][2]._alive, true);
  ASSERT_EQ(life3._world[1][1]._state, '*');
  ASSERT_EQ(life3._world[1][2]._state, '*');
  ASSERT_EQ(life3._world[2][1]._state, '*');
  ASSERT_EQ(life3._world[2][2]._state, '*');
  // All four of them are alive
  ASSERT_EQ(life3._population, 4);

  istringstream r3("2 2\n--\n0-");
  r3 >> m;
  r3 >> n;
  Life<FredkinCell> life4(m, n);
  r3 >> life4;
  life4.run_generation();
  ASSERT_EQ(life4._world[1][1]._alive, true);
  ASSERT_EQ(life4._world[1][2]._alive, false);
  ASSERT_EQ(life4._world[2][1]._alive, false);
  ASSERT_EQ(life4._world[2][2]._alive, true);
  ASSERT_EQ(life4._world[1][1]._state, '0');
  ASSERT_EQ(life4._world[1][2]._state, '-');
  ASSERT_EQ(life4._world[2][1]._state, '-');
  ASSERT_EQ(life4._world[2][2]._state, '0');
  // Two of them are alive now.
  ASSERT_EQ(life4._population, 2);

  life4.run_generation();
  ASSERT_EQ(life4._world[1][1]._alive, false);
  ASSERT_EQ(life4._world[1][2]._alive, false);
  ASSERT_EQ(life4._world[2][1]._alive, false);
  ASSERT_EQ(life4._world[2][2]._alive, false);
  ASSERT_EQ(life4._world[1][1]._state, '-');
  ASSERT_EQ(life4._world[1][2]._state, '-');
  ASSERT_EQ(life4._world[2][1]._state, '-');
  ASSERT_EQ(life4._world[2][2]._state, '-');
  // Two of them are alive now.
  ASSERT_EQ(life4._population, 0);

  istringstream r4("3 3\n-0*\n**0\n0.-");
  r4 >> m;
  r4 >> n;
  Life<Cell> life5(m, n);
  r4 >> life5;
  life5.run_generation();
  ASSERT_EQ(life5._world[1][1]._p->_alive, false);
  ASSERT_EQ(life5._world[1][2]._p->_alive, false);
  ASSERT_EQ(life5._world[1][3]._p->_alive, true);
  ASSERT_EQ(life5._world[2][1]._p->_alive, true);
  ASSERT_EQ(life5._world[2][2]._p->_alive, false);
  ASSERT_EQ(life5._world[2][3]._p->_alive, false);
  ASSERT_EQ(life5._world[3][1]._p->_alive, true);
  ASSERT_EQ(life5._world[3][2]._p->_alive, false);
  ASSERT_EQ(life5._world[3][3]._p->_alive, true);

  ASSERT_EQ(life5._world[1][1]._p->_state, '-');
  ASSERT_EQ(life5._world[1][2]._p->_state, '-');
  ASSERT_EQ(life5._world[1][3]._p->_state, '*');
  ASSERT_EQ(life5._world[2][1]._p->_state, '*');
  ASSERT_EQ(life5._world[2][2]._p->_state, '.');
  ASSERT_EQ(life5._world[2][3]._p->_state, '-');
  ASSERT_EQ(life5._world[3][1]._p->_state, '1');
  ASSERT_EQ(life5._world[3][2]._p->_state, '.');
  ASSERT_EQ(life5._world[3][3]._p->_state, '0');
  ASSERT_EQ(life5._population, 4);
}

TEST(LifeFixture, update_neighbor_world_tests) {
  int m;
  int n;
  istringstream r("2 2\n.*\n00");
  r >> m;
  r >> n;
  Life<Cell> life(m, n);
  r >> life;
  vector<vector<int>> neighbors_world;
  life.update_neighbor_world(neighbors_world);
  ASSERT_EQ(neighbors_world[0][0], 3);
  ASSERT_EQ(neighbors_world[0][1], 2);
  ASSERT_EQ(neighbors_world[1][0], 1);
  ASSERT_EQ(neighbors_world[1][1], 2);

  istringstream r2("2 2\n.0\n0.");
  r2 >> m;
  r2 >> n;
  Life<Cell> life2(m, n);
  r2 >> life2;
  vector<vector<int>> neighbors_world2;
  life2.update_neighbor_world(neighbors_world2);
  ASSERT_EQ(neighbors_world2[0][0], 2);
  ASSERT_EQ(neighbors_world2[0][1], 0);
  ASSERT_EQ(neighbors_world2[1][0], 0);
  ASSERT_EQ(neighbors_world2[1][1], 2);

  istringstream r3("3 3\n00.\n*.-\n*0*");
  r3 >> m;
  r3 >> n;
  Life<Cell> life3(m, n);
  r3 >> life3;
  vector<vector<int>> neighbors_world3;
  life3.update_neighbor_world(neighbors_world3);
  ASSERT_EQ(neighbors_world3[0][0], 2);
  ASSERT_EQ(neighbors_world3[0][1], 1);
  ASSERT_EQ(neighbors_world3[0][2], 1);
  ASSERT_EQ(neighbors_world3[1][0], 4);
  ASSERT_EQ(neighbors_world3[1][1], 6);
  ASSERT_EQ(neighbors_world3[1][2], 1);
  ASSERT_EQ(neighbors_world3[2][0], 2);
  ASSERT_EQ(neighbors_world3[2][1], 2);
  ASSERT_EQ(neighbors_world3[2][2], 1);
}

// ----------------------
// ConwayCell class Tests
// ----------------------

TEST(ConwayCellFixture, default_constructor_tests) {
  ConwayCell cc;
  ASSERT_EQ(cc._alive, false);
  ASSERT_EQ(cc._state, '~');
}

TEST(ConwayCellFixture, constructor_tests) {
  ConwayCell cc1('*');
  ASSERT_EQ(cc1._alive, true);
  ASSERT_EQ(cc1._state, '*');

  ConwayCell cc2('.');
  ASSERT_EQ(cc2._alive, false);
  ASSERT_EQ(cc2._state, '.');
}

TEST(ConwayCellFixture, copy_assignment_tests) {
  ConwayCell cc1_mock;
  ConwayCell cc1_copy(cc1_mock);
  ASSERT_EQ(cc1_copy._alive, false);
  ASSERT_EQ(cc1_copy._state, '~');

  ConwayCell cc2_mock('*');
  ConwayCell cc2_copy(cc2_mock);
  ASSERT_EQ(cc2_copy._alive, true);
  ASSERT_EQ(cc2_copy._state, '*');

  ConwayCell cc3_mock('.');
  ConwayCell cc3_copy(cc3_mock);
  ASSERT_EQ(cc3_copy._alive, false);
  ASSERT_EQ(cc3_copy._state, '.');
}

TEST(ConwayCellFixture, determine_life_tests) {
  ConwayCell cc('*');
  ASSERT_EQ(cc._alive, true);
  ASSERT_EQ(cc._state, '*');

  int neighbors = 7;
  cc.determine_life_status(neighbors);
  ASSERT_EQ(cc._alive, false);
  ASSERT_EQ(cc._state, '.');

  neighbors = 3;
  cc.determine_life_status(neighbors);
  ASSERT_EQ(cc._alive, true);
  ASSERT_EQ(cc._state, '*');

  neighbors = 2;
  cc.determine_life_status(neighbors);
  ASSERT_EQ(cc._alive, true);
  ASSERT_EQ(cc._state, '*');
}

TEST(ConwayCellFixture, check_neighbor_tests) {
  ConwayCell cc;

  ASSERT_FALSE(cc.check_valid_neighbor(5, 5, 7, 7));
  ASSERT_TRUE(cc.check_valid_neighbor(5, 5, 6, 6));
  ASSERT_FALSE(cc.check_valid_neighbor(5, 5, 9, 4));
  ASSERT_FALSE(cc.check_valid_neighbor(5, 5, 9, 9));
}

TEST(ConwayCellFixture, clone_tests) {
  ConwayCell cc1;
  ConwayCell *ac = dynamic_cast<ConwayCell *>(cc1.clone());
  bool ac_alive = ac->_alive;
  char ac_state = ac->_state;
  delete (ac);
  ASSERT_EQ(cc1._alive, ac_alive);
  ASSERT_EQ(cc1._state, ac_state);

  ConwayCell cc2('*');
  ac = dynamic_cast<ConwayCell *>(cc2.clone());
  ac_alive = ac->_alive;
  ac_state = ac->_state;
  delete (ac);
  ASSERT_EQ(cc2._alive, ac_alive);
  ASSERT_EQ(cc2._state, ac_state);

  ConwayCell cc3(cc2);
  ac = dynamic_cast<ConwayCell *>(cc3.clone());
  ac_alive = ac->_alive;
  ac_state = ac->_state;
  delete (ac);
  ASSERT_EQ(cc3._alive, ac_alive);
  ASSERT_EQ(cc3._state, ac_state);
}

// -----------------------
// FredkinCell class Tests
// -----------------------

TEST(FredkinCellFixture, default_constructor_tests) {
  FredkinCell fc;
  ASSERT_EQ(fc._alive, false);
  ASSERT_EQ(fc._state, '~');
  ASSERT_EQ(fc._generation, 0);
}

TEST(FredkinCellFixture, single_constructor_tests) {
  FredkinCell fc('-');
  ASSERT_EQ(fc._alive, false);
  ASSERT_EQ(fc._state, '-');
  ASSERT_EQ(fc._generation, 0);

  FredkinCell fc2('0');
  ASSERT_EQ(fc2._alive, true);
  ASSERT_EQ(fc2._state, '0');
  ASSERT_EQ(fc2._generation, 0);

  FredkinCell fc3('+');
  ASSERT_EQ(fc3._alive, true);
  ASSERT_EQ(fc3._state, '+');
  ASSERT_EQ(fc3._generation, 0);
}

TEST(FredkinCellFixture, copy_assignment_tests) {
  FredkinCell fc;
  FredkinCell fc_copy('+');

  fc = fc_copy;
  ASSERT_EQ(fc._state, '+');

  FredkinCell fc2;
  FredkinCell fc2_copy('-');

  fc2 = fc2_copy;
  ASSERT_EQ(fc2._state, '-');

  FredkinCell fc3;
  FredkinCell fc3_copy('.');

  fc3 = fc3_copy;
  ASSERT_EQ(fc3._state, '.');
}

TEST(FredkinCellFixture, determine_life_status_tests) {
  FredkinCell fc;

  fc.determine_life_status(1);
  ASSERT_EQ(fc._generation, 0);
  ASSERT_EQ(fc._state, '0');
  ASSERT_EQ(fc._alive, true);

  FredkinCell fc2('0');

  fc2.determine_life_status(1);
  ASSERT_EQ(fc2._generation, 1);
  ASSERT_EQ(fc2._state, '1');
  ASSERT_EQ(fc2._alive, true);

  FredkinCell fc3('9');

  fc3.determine_life_status(3);
  ASSERT_EQ(fc3._generation, 1);
  ASSERT_EQ(fc3._state, '1');
  ASSERT_EQ(fc3._alive, true);

  FredkinCell fc4('-');

  fc4.determine_life_status(4);
  ASSERT_EQ(fc4._generation, 0);
  ASSERT_EQ(fc4._state, '-');
  ASSERT_EQ(fc4._alive, false);
}

TEST(FredkinCellFixture, check_valid_neighbor_tests) {
  FredkinCell fc;
  ASSERT_EQ(fc.check_valid_neighbor(1, 1, 0, 1), true);
  ASSERT_EQ(fc.check_valid_neighbor(1, 1, 1, 2), true);
  ASSERT_EQ(fc.check_valid_neighbor(1, 1, 2, 1), true);
  ASSERT_EQ(fc.check_valid_neighbor(1, 1, 1, 0), true);
  ASSERT_EQ(fc.check_valid_neighbor(5, 5, 5, 2), false);
  ASSERT_EQ(fc.check_valid_neighbor(1, 1, 0, 0), false);
  ASSERT_EQ(fc.check_valid_neighbor(1, 1, 0, 2), false);
  ASSERT_EQ(fc.check_valid_neighbor(1, 1, 2, 0), false);
  ASSERT_EQ(fc.check_valid_neighbor(1, 1, 2, 2), false);
  ASSERT_EQ(fc.check_valid_neighbor(1, 1, 1, 3), false);
}

TEST(FredkinCellFixture, mutate_tests) {
  FredkinCell fc;
  ASSERT_EQ(fc._generation, 0);
  ASSERT_EQ(fc.mutate(), false);

  FredkinCell fc2('0');
  fc2.determine_life_status(1);
  fc2.determine_life_status(1);
  ASSERT_EQ(fc2._generation, 2);
  ASSERT_EQ(fc2.mutate(), true);
  fc2.determine_life_status(1);
  ASSERT_EQ(fc2._generation, 3);
  ASSERT_EQ(fc2.mutate(), false);
}

TEST(FredkinCellFixture, clone_tests) {
  FredkinCell fc;
  FredkinCell *ac = dynamic_cast<FredkinCell *>(fc.clone());
  bool ac_alive = ac->_alive;
  char ac_state = ac->_state;
  delete ac;
  ASSERT_EQ(fc._alive, ac_alive);
  ASSERT_EQ(fc._state, ac_state);

  FredkinCell fc2('0');
  ac = dynamic_cast<FredkinCell *>(fc2.clone());
  ac_alive = ac->_alive;
  ac_state = ac->_state;
  delete ac;
  ASSERT_EQ(fc2._alive, ac_alive);
  ASSERT_EQ(fc2._state, ac_state);

  FredkinCell fc3('+');
  ac = dynamic_cast<FredkinCell *>(fc3.clone());
  ac_alive = ac->_alive;
  ac_state = ac->_state;
  delete ac;
  ASSERT_EQ(fc3._alive, ac_alive);
  ASSERT_EQ(fc3._state, ac_state);
}

// ----------------
// Cell class Tests
// ----------------

TEST(CellFixture, print_tests) {
  Cell c;
  ostringstream w;
  w << c;
  ASSERT_EQ(w.str(), "");

  // c2._p pointing to ConwayCell
  ostringstream w2;
  Cell c2('.');
  w2 << c2;
  ASSERT_EQ(w2.str(), ".");

  // c3._p pointing to FredkinCell
  ostringstream w3;
  Cell c3('-');
  w3 << c3;
  ASSERT_EQ(w3.str(), "-");

  // c4._p pointing to ConwayCell
  ostringstream w4;
  Cell c4('*');
  w4 << c4;
  ASSERT_EQ(w4.str(), "*");
}

TEST(CellFixture, default_constructor_tests) {
  Cell c;
  ASSERT_EQ(c._p, nullptr);
}

TEST(CellFixture, single_constructor_tests) {
  Cell c('*');
  ASSERT_EQ((c._p)->_state, '*');

  Cell c2('-');
  ASSERT_EQ((c2._p)->_state, '-');
  ASSERT_EQ(c2._p->_alive, false);
  ASSERT_EQ((dynamic_cast<FredkinCell *>(c2._p))->_generation, 0);

  Cell c3('0');
  ASSERT_EQ((c3._p)->_state, '0');
  ASSERT_EQ(c3._p->_alive, true);
  ASSERT_EQ((dynamic_cast<FredkinCell *>(c3._p))->_generation, 0);
}

TEST(CellFixture, copy_constructor_tests) {
  Cell c('.');
  Cell c_copy(c);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c_copy._p)->_state, '.');

  Cell c2('*');
  Cell c2_copy(c2);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2_copy._p)->_state, '*');
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2_copy._p)->_alive, true);

  Cell c3;
  Cell c3_copy(c3);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c3_copy._p), nullptr);

  Cell c4('-');
  Cell c4_copy(c4);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c4_copy._p)->_state, '-');
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c4_copy._p)->_alive, false);

  Cell c5('0');
  Cell c5_copy(c5);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c5_copy._p)->_state, '0');
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c5_copy._p)->_alive, true);
}

TEST(CellFixture, copy_assignment_tests) {
  Cell c;
  Cell c_copy('.');
  c = c_copy;
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c._p)->_state, '.');
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c._p)->_alive, false);
  ASSERT_FALSE(c._p == c_copy._p);

  Cell c2;
  Cell c2_copy('*');
  c2 = c2_copy;
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2._p)->_state, '*');
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2._p)->_alive, true);
  ASSERT_FALSE(c2._p == c2_copy._p);

  Cell c3;
  Cell c3_copy('-');
  c3 = c3_copy;
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c3._p)->_state, '-');
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c3._p)->_alive, false);
  ASSERT_FALSE(c3._p == c3_copy._p);

  Cell c4;
  Cell c4_copy('0');
  c4 = c4_copy;
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c4._p)->_state, '0');
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c4._p)->_alive, true);
  ASSERT_FALSE(c4._p == c3_copy._p);
}

TEST(CellFixture, get_alive_tests) {
  Cell c;
  ASSERT_EQ(c.get_alive(), false);

  Cell c2('.');
  ASSERT_EQ(c2.get_alive(), false);

  Cell c3('*');
  ASSERT_EQ(c3.get_alive(), true);

  Cell c4('-');
  ASSERT_EQ(c4.get_alive(), false);

  Cell c5('0');
  ASSERT_EQ(c5.get_alive(), true);
}

TEST(CellFixture, determine_life_status_tests) {
  Cell c('.');
  c.determine_life_status(0);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c._p)->_alive, false);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c._p)->_state, '.');

  Cell c2('*');
  c2.determine_life_status(3);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2._p)->_alive, true);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2._p)->_state, '*');

  Cell c3('-');
  c3.determine_life_status(1);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c3._p)->_alive, true);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c3._p)->_state, '0');

  Cell c4('0');
  c4.determine_life_status(4);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c4._p)->_alive, false);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c4._p)->_state, '-');
}

TEST(CellFixture, check_valid_neighbor) {
  // FredkinCell
  Cell c('-');
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(1, 1, 0, 1),
            true);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(1, 1, 1, 2),
            true);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(1, 1, 2, 1),
            true);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(1, 1, 1, 0),
            true);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(5, 5, 5, 2),
            false);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(1, 1, 0, 0),
            false);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(1, 1, 0, 2),
            false);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(1, 1, 2, 0),
            false);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(1, 1, 2, 2),
            false);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(c._p)->check_valid_neighbor(1, 1, 1, 3),
            false);

  // ConwayCell
  Cell c2('.');
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2._p)->check_valid_neighbor(1, 1, 0, 0),
            true);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2._p)->check_valid_neighbor(1, 1, 1, 1),
            false);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2._p)->check_valid_neighbor(1, 1, 1, 4),
            false);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2._p)->check_valid_neighbor(1, 1, 4, 1),
            false);
  ASSERT_EQ(dynamic_cast<ConwayCell *>(c2._p)->check_valid_neighbor(1, 1, 2, 1),
            true);
}
