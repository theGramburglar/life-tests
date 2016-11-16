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
#include <algorithm> // find
#include <stdlib.h>  // rand
#include <sstream>   // istringtstream, ostringstream
#include "Life.h"

using namespace std;

// -----------------------
// ConwayCell construction
// -----------------------

TEST(LifeFixture, conway_cell_construction_test0) {
  ConwayCell c;
  ASSERT_FALSE(c.alive);
  ASSERT_EQ(c.representation, '.');
}

TEST(LifeFixture, conway_cell_construction_test1) {
  // make an alive cell
  ConwayCell c('*');
  ASSERT_TRUE(c.alive);
  ASSERT_EQ(c.representation, '*');
}

// -----------------------
// ConwayCell updateStatus
// -----------------------
TEST(LifeFixture, conway_cell_update_test1) {
  ConwayCell c('*');

  for (int i = 0; i < 20; ++i) {
    c.updateStatus((unsigned)i, false);

    if (i == 3 || (i == 2 && c.alive)) {
      ASSERT_TRUE(c.alive);
      ASSERT_EQ(c.representation, '*');
    } else {
      ASSERT_FALSE(c.alive);
      ASSERT_EQ(c.representation, '.');
    }
  }
}

// ----------------------------
// ConwayCell vector<int> neighboringCells(int index, int rows, int cols) {
// ----------------------------
TEST(LifeFixture, conway_cell_neighboring_cells_test0) {
  // spot check
  ConwayCell c('*'); // positioned at (0,0)
  vector<int> result = c.neighboringCells(0, 4, 4);
  ASSERT_EQ(result.size(), 3);
  ASSERT_TRUE(find(result.begin(), result.end(), 1) != result.end());
  ASSERT_TRUE(find(result.begin(), result.end(), 4) != result.end());
  ASSERT_TRUE(find(result.begin(), result.end(), 5) != result.end());
}

TEST(LifeFixture, conway_cell_neighboring_cells_test1) {
  ConwayCell c('*');
  // spot check corners

  vector<int> result = c.neighboringCells(0, 4, 4);
  ASSERT_EQ(result.size(), 3);

  result = c.neighboringCells(3, 4, 4);
  ASSERT_EQ(result.size(), 3);

  result = c.neighboringCells(15, 4, 4);
  ASSERT_EQ(result.size(), 3);

  result = c.neighboringCells(12, 4, 4);
  ASSERT_EQ(result.size(), 3);
}

TEST(LifeFixture, conway_cell_neighboring_cells_test2) {
  // spot check number of results for interior cells
  ConwayCell c('*');
  for (int i = 1; i < 3; ++i) {
    for (int j = 1; j < 3; ++j) {
      vector<int> result = c.neighboringCells(i * 4 + j, 4, 4);
      ASSERT_EQ(result.size(), 8);
    }
  }
}

TEST(LifeFixture, conway_cell_neighboring_cells_test3) {

  // spot check number of results for top cells, excluding corners
  ConwayCell c('*');

  vector<int> result;
  for (size_t i = 1; i < 3; i++) {
    result = c.neighboringCells(i, 4, 4);
    ASSERT_EQ(result.size(), 5);
  }
}

TEST(LifeFixture, conway_cell_neighboring_cells_test4) {

  // spot check number of results for right side cells, excluding corners
  ConwayCell c('*');

  vector<int> result;

  for (size_t i = 2; i < 4; i++) {
    result = c.neighboringCells(i * 4 - 1, 4, 4);
    ASSERT_EQ(result.size(), 5);
  }
}

TEST(LifeFixture, conway_cell_neighboring_cells_test5) {

  // spot check number of results for left side cells, excluding corners
  ConwayCell c('*');

  vector<int> result;

  for (size_t i = 1; i < 3; i++) {
    result = c.neighboringCells(i * 4, 4, 4);
    ASSERT_EQ(result.size(), 5);
  }
}

TEST(LifeFixture, conway_cell_neighboring_cells_test6) {

  // spot check number of results for bottom cells, excluding corners
  ConwayCell c('*');

  vector<int> result;

  for (size_t i = 13; i < 15; i++) {
    result = c.neighboringCells(i, 4, 4);
    ASSERT_EQ(result.size(), 5);
  }
}

TEST(LifeFixture, conway_cell_neighboring_cells_test7) {

  // spot check number of results for side cells, excluding corners
  // for randomly sized grids; r < 500 and c < 500

  ConwayCell c('*');
  unsigned int test_rounds = 100;
  for (unsigned int n = 0; n < test_rounds; ++n) {
    unsigned int row = 0;
    unsigned int col = 0;

    while (row == 0 || col == 0) {
      row = rand() % 500;
      col = rand() % 500;
    }
    vector<int> result;

    // top row
    for (size_t i = 1; i < col - 1; i++) {
      result = c.neighboringCells(i, row, col);
      ASSERT_EQ(result.size(), 5);
    }

    // right side
    for (size_t i = 2; i < row; i++) {
      result = c.neighboringCells(i * col - 1, row, col);
      ASSERT_EQ(result.size(), 5);
    }

    // left side
    for (size_t i = 1; i < row - 1; i++) {
      result = c.neighboringCells(i * col, row, col);
      ASSERT_EQ(result.size(), 5);
    }

    // bottom row
    for (size_t i = row * col - col + 1; i < row * col - 1; i++) {
      result = c.neighboringCells(i, row, col);
      ASSERT_EQ(result.size(), 5);
    }
  }
}

// -----------------
//  ConwayCell clone
// -----------------
TEST(LifeFixture, test_cc_clone_test0) {
  ConwayCell c('*');
  AbstractCell *p = c.clone();

  ASSERT_TRUE(p->alive);
  ASSERT_EQ(p->representation, '*');
}

TEST(LifeFixture, test_cc_clone_test1) {
  ConwayCell c('.');
  AbstractCell *p = c.clone();

  ASSERT_FALSE(p->alive);
  ASSERT_EQ(p->representation, '.');
}

TEST(LifeFixture, test_cc_clone_test2) {
  ConwayCell c;
  AbstractCell *p = c.clone();

  ASSERT_FALSE(p->alive);
  ASSERT_EQ(p->representation, '.');
}

// -----------------------
//  ConwayCell numAlive
// -----------------------
TEST(LifeFixture, test_cc_num_alive_test0) {
  ConwayCell c('*');
  vector<ConwayCell *> neighbors;
  for (int i = 0; i < 8; ++i) {
    ConwayCell tmp('.');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 0);
}

TEST(LifeFixture, test_cc_num_alive_test1) {
  ConwayCell c('*');
  vector<ConwayCell *> neighbors;
  for (int i = 0; i < 8; ++i) {
    ConwayCell tmp('*');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 8);
}

TEST(LifeFixture, test_cc_num_alive_test2) {
  ConwayCell c('*');
  vector<ConwayCell *> neighbors;
  for (int i = 0; i < 4; ++i) {

    ConwayCell tmp('*');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 4);
}

TEST(LifeFixture, test_cc_num_alive_test3) {
  unsigned int test_rounds = 100;
  ConwayCell c('*');

  ConwayCell dead('.');
  ConwayCell alive('*');

  for (unsigned int n = 0; n < test_rounds; ++n) {
    unsigned int index = rand() % 3;
    unsigned int num_neighbors[] = {3, 5, 8};
    unsigned int total_neighbors = num_neighbors[index];
    unsigned int num_alive = rand() % total_neighbors + 1;
    vector<ConwayCell *> neighbors;

    // create list of neighbors with mix of
    for (size_t a = 0; a < num_alive; a++) {
      neighbors.push_back(&alive);
    }

    for (size_t d = 0; d < total_neighbors - num_alive; d++) {
      neighbors.push_back(&dead);
    }
    unsigned int result = c.numAlive(neighbors);
    ASSERT_EQ(result, num_alive);
  }
}

// -----------------------
//  AbstractCell numAlive
// -----------------------

TEST(LifeFixture, test_num_alive_test0) {
  ConwayCell c('*');
  vector<AbstractCell *> neighbors;
  for (int i = 0; i < 8; ++i) {
    ConwayCell tmp('.');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 0);
}

TEST(LifeFixture, test_num_alive_test1) {
  ConwayCell c('*');
  vector<AbstractCell *> neighbors;
  for (int i = 0; i < 8; ++i) {
    ConwayCell tmp('*');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 8);
}

TEST(LifeFixture, test_num_alive_test2) {
  ConwayCell c('*');
  vector<AbstractCell *> neighbors;
  for (int i = 0; i < 4; ++i) {

    ConwayCell tmp('*');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 4);
}

TEST(LifeFixture, test_num_alive_test3) {
  unsigned int test_rounds = 100;
  ConwayCell c('*');

  ConwayCell dead('.');
  ConwayCell alive('*');

  for (unsigned int n = 0; n < test_rounds; ++n) {
    unsigned int index = rand() % 3;
    unsigned int num_neighbors[] = {3, 5, 8};
    unsigned int total_neighbors = num_neighbors[index];
    unsigned int num_alive = rand() % total_neighbors + 1;
    vector<AbstractCell *> neighbors;

    // create list of neighbors with mix of
    for (size_t a = 0; a < num_alive; a++) {
      neighbors.push_back(&alive);
    }

    for (size_t d = 0; d < total_neighbors - num_alive; d++) {
      neighbors.push_back(&dead);
    }
    unsigned int result = c.numAlive(neighbors);
    ASSERT_EQ(result, num_alive);
  }
}

// -----------------------
// FredkinCell construction
// -----------------------
TEST(LifeFixture, fc_construction_test0) {
  FredkinCell f;
  ASSERT_FALSE(f.alive);
  ASSERT_EQ(f.representation, '-');
}

TEST(LifeFixture, fc_construction_test1) {
  FredkinCell f('+');
  ASSERT_TRUE(f.alive);
  ASSERT_EQ(f.representation, '+');
}

TEST(LifeFixture, fc_construction_test2) {
  FredkinCell f('-');
  ASSERT_FALSE(f.alive);
  ASSERT_EQ(f.representation, '-');
}

// -----------------
//  FredkinCell clone
// -----------------
TEST(LifeFixture, test_fc_clone_test0) {
  FredkinCell fc('+');
  AbstractCell *p = fc.clone();

  ASSERT_TRUE(p->alive);
  ASSERT_EQ(p->representation, '+');
}

TEST(LifeFixture, test_fc_clone_test1) {
  FredkinCell fc('-');
  AbstractCell *p = fc.clone();

  ASSERT_FALSE(p->alive);
  ASSERT_EQ(p->representation, '-');
}

TEST(LifeFixture, test_fc_clone_test2) {
  FredkinCell fc;
  AbstractCell *p = fc.clone();

  ASSERT_FALSE(p->alive);
  ASSERT_EQ(p->representation, '-');
}

// ------------------------
// FredkinCell updateStatus
// ------------------------
TEST(LifeFixture, fc_update_test0) {
  FredkinCell c('0');

  // increase the age so the the char is a '+'
  for (size_t i = 0; i < 11; i++) {
    c.updateStatus(3, false);
  }

  for (unsigned int i = 0; i < 8; ++i) {
    c.updateStatus(i, false);

    if (i == 1 || i == 3) {
      ASSERT_TRUE(c.alive);
      ASSERT_EQ(c.representation, '+');
    } else {
      ASSERT_FALSE(c.alive);
      ASSERT_EQ(c.representation, '-');
    }
  }
}

TEST(LifeFixture, fc_update_test1) {
  FredkinCell c('0');

  for (unsigned int i = 0; i < 10; ++i) {
    char expected_rep = i + '0';
    ASSERT_TRUE(c.alive);
    ASSERT_EQ(c.representation, expected_rep);
    c.updateStatus(3, false);
  }
}

TEST(LifeFixture, fc_update_test2) {
  FredkinCell c('0');
  unsigned int age = 0;
  for (unsigned int i = 0; i < 10; ++i) {
    c.updateStatus(i, false);

    if (i == 1 || i == 3) {
      char expected_rep = age + '0';
      ASSERT_TRUE(c.alive);

      if (c.representation >= '0' && c.representation <= '9') {
        ASSERT_TRUE(true);
      } else {
        ASSERT_TRUE(false);
      }

      ASSERT_EQ(c.representation, expected_rep);
    } else {
      ASSERT_FALSE(c.alive);
      ASSERT_EQ(c.representation, '-');
    }
  }
}

TEST(LifeFixture, fc_update_test3) {
  // check if FredkinCell mutates at age 2
  FredkinCell c('0');

  AbstractCell *cc = c.updateStatus(3, true);
  while (cc == nullptr) {
    cc = c.updateStatus(3, true);
  }

  if (const ConwayCell *p = dynamic_cast<const ConwayCell *>(cc)) {
    ASSERT_TRUE(true);
  } else {
    ASSERT_TRUE(false);
  }
}

// ----------------------------
// FredkinCell neighboringCells
// ----------------------------
TEST(LifeFixture, fc_neighboring_cells_test0) {
  // spot check
  FredkinCell c('*'); // positioned at (0,0)
  vector<int> result = c.neighboringCells(0, 4, 4);
  ASSERT_EQ(result.size(), 2);
  ASSERT_TRUE(find(result.begin(), result.end(), 1) != result.end());
  ASSERT_TRUE(find(result.begin(), result.end(), 4) != result.end());
}

TEST(LifeFixture, fc_neighboring_cells_test1) {
  FredkinCell c('*');
  // spot check corners

  vector<int> result = c.neighboringCells(0, 4, 4);
  ASSERT_EQ(result.size(), 2);

  result = c.neighboringCells(3, 4, 4);
  ASSERT_EQ(result.size(), 2);

  result = c.neighboringCells(15, 4, 4);
  ASSERT_EQ(result.size(), 2);

  result = c.neighboringCells(12, 4, 4);
  ASSERT_EQ(result.size(), 2);
}

TEST(LifeFixture, fc_neighboring_cells_test2) {
  // spot check number of results for interior cells
  FredkinCell c('*');
  for (int i = 1; i < 3; ++i) {
    for (int j = 1; j < 3; ++j) {
      vector<int> result = c.neighboringCells(i * 4 + j, 4, 4);
      ASSERT_EQ(result.size(), 4);
    }
  }
}

TEST(LifeFixture, fc_neighboring_cells_test3) {

  // spot check number of results for top cells, excluding corners
  FredkinCell c('*');

  vector<int> result;
  for (size_t i = 1; i < 3; i++) {
    result = c.neighboringCells(i, 4, 4);
    ASSERT_EQ(result.size(), 3);
  }
}

TEST(LifeFixture, fc_neighboring_cells_test4) {

  // spot check number of results for right side cells, excluding corners
  FredkinCell c('*');

  vector<int> result;

  for (size_t i = 2; i < 4; i++) {
    result = c.neighboringCells(i * 4 - 1, 4, 4);
    ASSERT_EQ(result.size(), 3);
  }
}

TEST(LifeFixture, fc_neighboring_cells_test5) {

  // spot check number of results for left side cells, excluding corners
  FredkinCell c('*');

  vector<int> result;

  for (size_t i = 1; i < 3; i++) {
    result = c.neighboringCells(i * 4, 4, 4);
    ASSERT_EQ(result.size(), 3);
  }
}

TEST(LifeFixture, fc_neighboring_cells_test6) {

  // spot check number of results for bottom cells, excluding corners
  FredkinCell c('*');

  vector<int> result;

  for (size_t i = 13; i < 15; i++) {
    result = c.neighboringCells(i, 4, 4);
    ASSERT_EQ(result.size(), 3);
  }
}

TEST(LifeFixture, fc_neighboring_cells_test7) {

  // spot check number of results for side cells, excluding corners
  // for randomly sized grids; r < 500 and c < 500

  FredkinCell c('*');
  unsigned int test_rounds = 100;
  for (unsigned int n = 0; n < test_rounds; ++n) {
    unsigned int row = 0;
    unsigned int col = 0;

    while (row == 0 || col == 0) {
      row = rand() % 500;
      col = rand() % 500;
    }
    vector<int> result;

    // top row
    for (size_t i = 1; i < col - 1; i++) {
      result = c.neighboringCells(i, row, col);
      ASSERT_EQ(result.size(), 3);
    }

    // right side
    for (size_t i = 2; i < row; i++) {
      result = c.neighboringCells(i * col - 1, row, col);
      ASSERT_EQ(result.size(), 3);
    }

    // left side
    for (size_t i = 1; i < row - 1; i++) {
      result = c.neighboringCells(i * col, row, col);
      ASSERT_EQ(result.size(), 3);
    }

    // bottom row
    for (size_t i = row * col - col + 1; i < row * col - 1; i++) {
      result = c.neighboringCells(i, row, col);
      ASSERT_EQ(result.size(), 3);
    }
  }
}

TEST(LifeFixture, fredkin_cell_neighboring_cells_test8) {
  FredkinCell f('-');
  vector<int> result = f.neighboringCells(0, 5, 5);
  ASSERT_EQ(result.size(), 2);
}

// ---------------------
//  FredkinCell numAlive
// ---------------------
TEST(LifeFixture, test_fc_num_alive_test0) {
  FredkinCell c('+');
  vector<FredkinCell *> neighbors;
  for (int i = 0; i < 8; ++i) {
    FredkinCell tmp('-');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 0);
}

TEST(LifeFixture, test_fc_num_alive_test1) {
  FredkinCell c('+');
  vector<FredkinCell *> neighbors;
  for (int i = 0; i < 8; ++i) {
    FredkinCell tmp('+');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 8);
}

TEST(LifeFixture, test_fc_num_alive_test2) {
  FredkinCell c('+');
  vector<FredkinCell *> neighbors;
  for (int i = 0; i < 4; ++i) {

    FredkinCell tmp('+');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 4);
}

TEST(LifeFixture, test_fc_num_alive_test3) {
  unsigned int test_rounds = 100;
  FredkinCell c('+');

  FredkinCell dead('-');
  FredkinCell alive('+');

  for (unsigned int n = 0; n < test_rounds; ++n) {
    unsigned int index = rand() % 3;
    unsigned int num_neighbors[] = {3, 5, 8};
    unsigned int total_neighbors = num_neighbors[index];
    unsigned int num_alive = rand() % total_neighbors + 1;
    vector<FredkinCell *> neighbors;

    // create list of neighbors with mix of alive and dead
    for (size_t a = 0; a < num_alive; a++) {
      neighbors.push_back(&alive);
    }

    for (size_t d = 0; d < total_neighbors - num_alive; d++) {
      neighbors.push_back(&dead);
    }
    unsigned int result = c.numAlive(neighbors);
    ASSERT_EQ(result, num_alive);
  }
}

// -------------------------------------------
// AbstractCell incrAlive(unsigned int &count)
// -------------------------------------------
TEST(LifeFixture, test_incr_alive_test0) {
  unsigned int count = 0;
  ConwayCell c('*');
  for (size_t i = 0; i < 20; i++) {
    c.incrAlive(count);
    ASSERT_EQ(count, i + 1);
  }
}

TEST(LifeFixture, test_incr_alive_test1) {
  unsigned int count = 0;
  ConwayCell c('.');
  for (size_t i = 0; i < 20; i++) {
    c.incrAlive(count);
    ASSERT_EQ(count, 0);
  }
}

TEST(LifeFixture, test_incr_alive_test2) {

  FredkinCell c('+');
  vector<FredkinCell *> neighbors;
  unsigned int count = 0;
  for (int i = 0; i < 8; ++i) {
    FredkinCell tmp('-');
    neighbors.push_back(&tmp);
  }

  for (size_t i = 0; i < neighbors.size(); i++) {
    neighbors[i]->incrAlive(count);
  }

  ASSERT_EQ(count, 0);
}

TEST(LifeFixture, test_incr_alive_test3) {

  FredkinCell c('+');
  vector<FredkinCell *> neighbors;
  unsigned int count = 0;
  for (int i = 0; i < 8; ++i) {
    FredkinCell tmp('+');
    neighbors.push_back(&tmp);
  }

  for (size_t i = 0; i < neighbors.size(); i++) {
    neighbors[i]->incrAlive(count);
  }

  ASSERT_EQ(count, 8);
}

TEST(LifeFixture, test_incr_alive_test4) {

  FredkinCell c('+');
  vector<FredkinCell *> neighbors;
  unsigned int count = 0;
  for (int i = 0; i < 4; ++i) {
    FredkinCell tmp('+');
    neighbors.push_back(&tmp);
  }

  for (size_t i = 0; i < neighbors.size(); i++) {
    neighbors[i]->incrAlive(count);
  }

  ASSERT_EQ(count, 4);
}

TEST(LifeFixture, test_incr_alive_test5) {
  unsigned int test_rounds = 100;
  FredkinCell c('+');

  FredkinCell dead('-');
  FredkinCell alive('+');

  for (unsigned int n = 0; n < test_rounds; ++n) {
    unsigned int count = 0;

    unsigned int total_cells = rand() % 500;
    unsigned int num_alive = rand() % total_cells + 1;
    vector<FredkinCell *> cells;

    // create list of neighbors with mix of alive and dead
    for (size_t a = 0; a < num_alive; a++) {
      cells.push_back(&alive);
    }

    for (size_t d = 0; d < total_cells - num_alive; d++) {
      cells.push_back(&dead);
    }

    for (size_t i = 0; i < cells.size(); i++) {
      cells[i]->incrAlive(count);
    }

    ASSERT_EQ(count, num_alive);
  }
}

// -----------------
// Cell constructors
// -----------------
TEST(LifeFixture, c_construction_test0) {
  Cell c;
  ASSERT_EQ(c.p, nullptr);
}

TEST(LifeFixture, c_construction_test1) {
  Cell c('-');
  ASSERT_FALSE(c.p->alive);
  ASSERT_EQ(c.p->representation, '-');
}

TEST(LifeFixture, c_construction_test2) {
  Cell c('+');
  ASSERT_TRUE(c.p->alive);
  ASSERT_EQ(c.p->representation, '+');
}

TEST(LifeFixture, c_construction_test3) {
  Cell c('0');
  ASSERT_TRUE(c.p->alive);
  ASSERT_EQ(c.p->representation, '0');
  if (const FredkinCell *p = dynamic_cast<const FredkinCell *>(c.p)) {
    ASSERT_TRUE(true);
  } else {
    ASSERT_TRUE(false);
  }
}

// -------------
// Cell numAlive
// -------------
TEST(LifeFixture, test_c_num_alive_test0) {
  Cell c('+');
  vector<Cell *> neighbors;
  for (int i = 0; i < 8; ++i) {
    Cell tmp('-');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 0);
}

TEST(LifeFixture, test_c_num_alive_test1) {
  Cell c('+');
  vector<Cell *> neighbors;
  for (int i = 0; i < 8; ++i) {
    Cell tmp('+');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 8);
}

TEST(LifeFixture, test_c_num_alive_test2) {
  Cell c('+');
  vector<Cell *> neighbors;
  for (int i = 0; i < 4; ++i) {

    Cell tmp('+');
    neighbors.push_back(&tmp);
  }
  unsigned int result = c.numAlive(neighbors);
  ASSERT_EQ(result, 4);
}

TEST(LifeFixture, test_c_num_alive_test3) {
  unsigned int test_rounds = 100;
  Cell c('+');

  Cell dead('-');
  Cell alive('+');

  for (unsigned int n = 0; n < test_rounds; ++n) {
    unsigned int index = rand() % 3;
    unsigned int num_neighbors[] = {3, 5, 8};
    unsigned int total_neighbors = num_neighbors[index];
    unsigned int num_alive = rand() % total_neighbors + 1;
    vector<Cell *> neighbors;

    // create list of neighbors with mix of alive and dead
    for (size_t a = 0; a < num_alive; a++) {
      neighbors.push_back(&alive);
    }

    for (size_t d = 0; d < total_neighbors - num_alive; d++) {
      neighbors.push_back(&dead);
    }
    unsigned int result = c.numAlive(neighbors);
    ASSERT_EQ(result, num_alive);
  }
}

// ----------------
// Life constructor
// ----------------
TEST(LifeFixture, life_construction_test0) {
  Life<ConwayCell> l(0, 0, 0);
  ASSERT_EQ(l.rows, 0);
  ASSERT_EQ(l.cols, 0);
  ASSERT_EQ(l.generations, 0);
  ASSERT_EQ(l.population, 0);
}

TEST(LifeFixture, life_construction_test1) {
  unsigned int r = rand() % 500;
  unsigned int c = rand() % 500;
  unsigned int g = rand() % 1000;

  Life<ConwayCell> l(r, c, g);
  ASSERT_EQ(l.rows, r);
  ASSERT_EQ(l.cols, c);
  ASSERT_EQ(l.generations, g);

  ASSERT_EQ(l.population, 0);
}

// -----------------------------------------
// printBoard(const unsigned int& gen, const unsigned int& pop)
// -----------------------------------------

// ---------------------------------------------
// executeSim(bool printAll, bool printFirstTen, int printInterval,
// vector<unsigned int> specificGen)
// ---------------------------------------------
TEST(LifeFixture, life_exe_test0) {
  stringstream r(".....\n.....\n.....\n.....\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 5);
  // void executeSim(istream &f, bool printAll, bool printFirstTen, int
  // printInterval,
  //                vector<unsigned int> specificGen
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 0);
}

TEST(LifeFixture, life_exe_test1) {
  stringstream r(".....\n.....\n..*..\n.....\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 5);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 0);
}

TEST(LifeFixture, life_exe_test2) {
  stringstream r("**...\n**...\n.....\n.....\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 5);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 4);
}

TEST(LifeFixture, life_exe_test3) {
  stringstream r(".....\n.....\n.....\n**...\n**...\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 5);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 4);
}

TEST(LifeFixture, life_exe_test4) {
  stringstream r("*.*.*\n.....\n*.*.*\n.....\n*.*.*\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 5);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 0);
}

TEST(LifeFixture, life_exe_test5) {
  stringstream r(".*...\n..*..\n***..\n.....\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 4);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 5);
}

TEST(LifeFixture, life_exe_test6) {
  stringstream r(".....\n.***.\n.***.\n.....\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 7);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 6);
}

TEST(LifeFixture, life_exe_test7) {
  stringstream r(".....\n.***.\n.*.*.\n.***.\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 3);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 12);
}

TEST(LifeFixture, life_exe_test8) {
  stringstream r(".....\n.***.\n.*.*.\n.***.\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 4);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 16);
}

TEST(LifeFixture, life_exe_test9) {
  stringstream r(".....\n.....\n*****\n.....\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 2);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 8);
}

TEST(LifeFixture, life_exe_test10) {
  stringstream r("*****\n*...*\n*...*\n*...*\n*****\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 10);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 0);
}

TEST(LifeFixture, life_exe_test11) {
  stringstream r("..**.\n.**..\n...*.\n.**..\n*****\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 4);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 6);
}

TEST(LifeFixture, life_exe_test12) {
  stringstream r(".....\n....*\n..*..\n.*...\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 5);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 0);
}

TEST(LifeFixture, life_exe_test13) {
  stringstream r("*..**\n.*..*\n..*.*\n.*...\n..*..\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 7);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 8);
}

TEST(LifeFixture, life_exe_test14) {
  stringstream r("*****\n.*..*\n..*..\n.*...\n..**.\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 6);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 13);
}

TEST(LifeFixture, life_exe_test15) {
  stringstream r("*....\n.*.**\n.**..\n.*..*\n.....\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 8);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 10);
}

TEST(LifeFixture, life_exe_test16) {
  stringstream r("*.*..\n....*\n.**.*\n.*.**\n..**.\n\n");

  vector<unsigned int> tmp;
  Life<ConwayCell> l(5, 5, 13);
  l.executeSim(r, false, false, -1, tmp);

  ASSERT_EQ(l.population, 2);
}
