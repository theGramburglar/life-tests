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

// ----------------------
// AbstractCell::is_alive
// ----------------------
TEST(AbstractCellFixture, is_alive_1) {
  ConwayCell cc;
  ASSERT_FALSE(cc.is_alive());
}
TEST(AbstractCellFixture, is_alive_2) {
  FredkinCell fc;
  ASSERT_FALSE(fc.is_alive());
}
TEST(AbstractCellFixture, is_alive_3) {
  ConwayCell cc(LIVE);
  ASSERT_TRUE(cc.is_alive());
  FredkinCell fc(LIVE);
  ASSERT_TRUE(fc.is_alive());
}

// -----------------------
// ConwayCell::constructor
// -----------------------
TEST(ConwayCellFixture, constructor_1) {
  ConwayCell cc;
  ASSERT_TRUE(cc._live == DEAD);
}
TEST(ConwayCellFixture, constructor_2) {
  ConwayCell cc1;
  ConwayCell cc2;
  ASSERT_TRUE(cc1._live == cc2._live);
}
TEST(ConwayCellFixture, constructor_3) {
  ConwayCell cc(LIVE);
  ASSERT_TRUE(cc._live);
}

// -----------------
// ConwayCell::clone
// -----------------
TEST(ConwayCellFixture, clone_1) {
  ConwayCell cc;
  AbstractCell* clone = cc.clone();
  ASSERT_TRUE(&cc != (ConwayCell*) clone);
}
TEST(ConwayCellFixture, clone_2) {
  ConwayCell cc;
  AbstractCell* clone = cc.clone();
  ASSERT_TRUE(cc.is_alive() == clone->is_alive());
}
TEST(ConwayCellFixture, clone_3) {
  ConwayCell cc(LIVE);
  AbstractCell* clone = cc.clone();
  ASSERT_TRUE(cc.is_alive() == clone->is_alive());
}

// ---------------------------
// ConwayCell::count_neighbers
// ---------------------------
TEST(ConwayCellFixture, count_neighbers_1) {
  ConwayCell cc;
  vector<bool> grid(9, false);
  int count = cc.count_neighbers(grid);
  ASSERT_EQ(count, 0);
}
TEST(ConwayCellFixture, count_neighbers_2) {
  ConwayCell cc;
  vector<bool> grid(9, true);
  int count = cc.count_neighbers(grid);
  ASSERT_EQ(count, 9);
}
TEST(ConwayCellFixture, count_neighbers_3) {
  ConwayCell cc;
  vector<bool> grid(9, false);
  grid[2] = true;
  grid[5] = true;
  int count = cc.count_neighbers(grid);
  ASSERT_EQ(count, 2);
}

// ------------------
// ConwayCell::evolve
// ------------------
TEST(ConwayCellFixture, evolve_1) {
  ConwayCell cc;
  cc.evolve(0);
  ASSERT_EQ(cc.is_alive(), DEAD);
}
TEST(ConwayCellFixture, evolve_2) {
  ConwayCell cc;
  cc.evolve(3);
  ASSERT_EQ(cc.is_alive(), LIVE);
}
TEST(ConwayCellFixture, evolve_3) {
  ConwayCell cc(LIVE);
  cc.evolve(1);
  ASSERT_EQ(cc.is_alive(), DEAD);
}

// ---------------------------
// ConwayCell::next_generation
// ---------------------------
TEST(ConwayCellFixture, next_generation_1) {
  ConwayCell cc;
  vector<bool> grid(9, false);
  cc.next_generation(grid);
  ASSERT_EQ(cc.is_alive(), DEAD);
}
TEST(ConwayCellFixture, next_generation_2) {
  ConwayCell cc;
  vector<bool> grid(9, false);
  grid[0] = true;
  grid[1] = true;
  grid[2] = true;
  cc.next_generation(grid);
  ASSERT_EQ(cc.is_alive(), LIVE);
}
TEST(ConwayCellFixture, next_generation_3) {
  ConwayCell cc(LIVE);
  vector<bool> grid(9, false);
  cc.next_generation(grid);
  ASSERT_EQ(cc.is_alive(), DEAD);
}

// -----------------
// ConwayCell::print
// -----------------
TEST(ConwayCellFixture, print_1) {
  ostringstream os;
  ConwayCell cc;
  cc.print(os);
  ASSERT_TRUE(os.str() == ".");
}
TEST(ConwayCellFixture, print_2) {
  ostringstream os;
  ConwayCell cc(LIVE);
  cc.print(os);
  ASSERT_TRUE(os.str() == "*");
}
TEST(ConwayCellFixture, print_3) {
  ostringstream os;
  ConwayCell cc;
  vector<bool> grid(9, false);
  grid[0] = true;
  grid[1] = true;
  grid[2] = true;
  cc.next_generation(grid);
  cc.print(os);
  ASSERT_TRUE(os.str() == "*");
}

// ------------------------
// FredkinCell::constructor
// ------------------------
TEST(FredkinCellFixture, constructor_1) {
  FredkinCell fc;
  ASSERT_FALSE(fc._live);
  ASSERT_FALSE(fc._mutated);
  ASSERT_FALSE(fc._called_from_cell);
  ASSERT_TRUE(fc._age == 0);
}
TEST(FredkinCellFixture, constructor_2) {
  FredkinCell fc(LIVE);
  ASSERT_TRUE(fc._live);
  ASSERT_FALSE(fc._mutated);
  ASSERT_FALSE(fc._called_from_cell);
  ASSERT_TRUE(fc._age == 0);
}
TEST(FredkinCellFixture, constructor_3) {
  FredkinCell fc(LIVE, 0, true, true);
  ASSERT_TRUE(fc._live);
  ASSERT_TRUE(fc._mutated);
  ASSERT_TRUE(fc._called_from_cell);
  ASSERT_TRUE(fc._age == 0);
}

// ------------------
// FredkinCell::clone
// ------------------
TEST(FredkinCellFixture, clone_1) {
  FredkinCell fc;
  AbstractCell* abs = fc.clone();
  ASSERT_TRUE((FredkinCell*)abs != &fc);
  ASSERT_TRUE(abs->is_alive() == fc.is_alive());
}
TEST(FredkinCellFixture, clone_2) {
  FredkinCell fc(LIVE);
  AbstractCell* abs = fc.clone();
  ASSERT_TRUE((FredkinCell*)abs != &fc);
  ASSERT_TRUE(abs->is_alive() == fc.is_alive());
}
TEST(FredkinCellFixture, clone_3) {
  FredkinCell fc(LIVE, 0, true, true);
  AbstractCell* abs = fc.clone();
  FredkinCell* ptr = dynamic_cast<FredkinCell*>(abs);
  ASSERT_TRUE(ptr != nullptr);
}

// ----------------------------
// FredkinCell::count_neighbers
// ----------------------------
TEST(FredkinCellFixture, count_neighbers_1) {
  FredkinCell fc;
  vector<bool> grid(9, false);
  ASSERT_EQ(0, fc.count_neighbers(grid));
}
TEST(FredkinCellFixture, count_neighbers_2) {
  FredkinCell fc;
  vector<bool> grid(9, true);
  ASSERT_EQ(4, fc.count_neighbers(grid));
}
TEST(FredkinCellFixture, count_neighbers_3) {
  FredkinCell fc;
  vector<bool> grid(9, false);
  grid[1] = true;
  grid[2] = true;
  grid[3] = true;
  ASSERT_EQ(2, fc.count_neighbers(grid));
}

// -------------------
// FredkinCell::evolve
// -------------------
TEST(FredkinCellFixture, evolve_1) {
  FredkinCell fc;
  fc.evolve(1);
  ASSERT_TRUE(fc.is_alive());
}
TEST(FredkinCellFixture, evolve_2) {
  FredkinCell fc;
  fc.evolve(2);
  ASSERT_FALSE(fc.is_alive());
}
TEST(FredkinCellFixture, evolve_3) {
  FredkinCell fc(LIVE);
  fc.evolve(0);
  ASSERT_FALSE(fc.is_alive());
}

// ----------------------------
// FredkinCell::next_generation
// ----------------------------
TEST(FredkinCellFixture, next_generation_1) {
 FredkinCell fc;
 vector<bool> grid(9, false);
 fc.next_generation(grid);
 ASSERT_FALSE(fc.is_alive());
}
TEST(FredkinCellFixture, next_generation_2) {
  FredkinCell fc;
  vector<bool> grid(9, false);
  grid[1] = true;
  fc.next_generation(grid);
  ASSERT_TRUE(fc.is_alive());
}
TEST(FredkinCellFixture, next_generation_3) {
  FredkinCell fc(LIVE);
  vector<bool> grid(9, false);
  fc.next_generation(grid);
  ASSERT_FALSE(fc.is_alive());
}

// ------------------
// FredkinCell::print
// ------------------
TEST(FredkinCellFixture, print_1) {
  ostringstream os;
  FredkinCell fc;
  fc.print(os);
  ASSERT_TRUE(os.str() == "-");
}
TEST(FredkinCellFixture, print_2) {
  ostringstream os;
  FredkinCell fc(LIVE);
  fc.print(os);
  ASSERT_TRUE(os.str() == "0");
}
TEST(FredkinCellFixture, print_3) {
  ostringstream os;
  FredkinCell fc(LIVE);
  fc.evolve(3);
  fc.print(os);
  ASSERT_TRUE(os.str() == "1");
}

// -----------------
// Cell::constructor
// -----------------
TEST(CellFixture, constructor_1) {
  Cell c;
  ASSERT_TRUE(c._cell);
  ASSERT_FALSE(c._cell->is_alive());
}
TEST(CellFixture, constructor_2) {
  Cell c(LIVE);
  ASSERT_TRUE(c._cell != nullptr);
  ASSERT_TRUE(c._cell->is_alive());
}
TEST(CellFixture, constructor_3) {
  Cell c(LIVE);
  ASSERT_TRUE(c._cell);
  ASSERT_TRUE(c._cell->is_alive());
  vector<bool> grid(9, false);
  c._cell->next_generation(grid);
  ASSERT_FALSE(c._cell->is_alive());
}

// -------------------------
// Cell::assignment_operator
// -------------------------
TEST(CellFixture, assignment_operator_1) {
  Cell c1(LIVE);
  Cell c2;
  c2 = c1;
  ASSERT_TRUE(c2._cell->is_alive());
}
TEST(CellFixture, assignment_operator_2) {
  Cell c1;
  Cell c2;
  c2 = c1;
  ASSERT_FALSE(c2._cell->is_alive());
}
TEST(CellFixture, assignment_operator_3) {
  Cell c1;
  Cell c2(LIVE);
  c2 = c1;
  ASSERT_FALSE(c2._cell->is_alive());
}

// -------------
// Cell:is_alive
// -------------
TEST(CellFixture, is_alive_1) {
  Cell c1;
  ASSERT_FALSE(c1.is_alive());
}
TEST(CellFixture, is_alive_2) {
  Cell c1(LIVE);
  ASSERT_TRUE(c1.is_alive());
}
TEST(CellFixture, is_alive_3) {
  Cell c1(LIVE);
  vector<bool> grid(9, false);
  c1._cell->next_generation(grid);
  ASSERT_FALSE(c1.is_alive());
}

// -----------
// Cell::clone
// -----------
TEST(CellFixture, clone_1) {
  Cell c;
  Cell* d = c.clone();
  ASSERT_FALSE(d->is_alive());
}
TEST(CellFixture, clone_2) {
  Cell c(LIVE);
  Cell* d = c.clone();
  ASSERT_TRUE(d->is_alive());
}
TEST(CellFixture, clone_3) {
  Cell c(LIVE);
  Cell* d = c.clone();
  ASSERT_TRUE((long) d == (long)&c);
}

// -----------
// Cell::print
// -----------
TEST(CellFixture, print_1) {
  ostringstream os;
  Cell c;
  c.print(os);
  ASSERT_TRUE(os.str() == "-");
}
TEST(CellFixture, print_2) {
  ostringstream os;
  Cell c(LIVE);
  c.print(os);
  ASSERT_TRUE(os.str() == "0");
}
TEST(CellFixture, print_3) {
  ostringstream os;
  Cell c(LIVE);
  vector<bool> grid(9, false);
  grid[1] = true;
  c._cell->next_generation(grid);
  c._cell->next_generation(grid);
  c.print(os);
  ASSERT_TRUE(os.str() == "*");
}

// ---------------------
// Cell::next_generation
// ---------------------
TEST(CellFixture, next_generation_1) {
  Cell c;
  vector<bool> grid(9, false);
  c.next_generation(grid);
  ASSERT_FALSE(c.is_alive());
}
TEST(CellFixture, next_generation_2) {
  Cell c(LIVE);
  vector<bool> grid(9, false);
  c.next_generation(grid);
  ASSERT_FALSE(c.is_alive());
}
TEST(CellFixture, next_generation_3) {
  Cell c(LIVE);
  vector<bool> grid(9, false);
  grid[1] = true;
  c.next_generation(grid);
  ASSERT_TRUE(c.is_alive());
}

// ----------------
// Life:consturctor
// ----------------
TEST(LifeFixture, constructor_1) {
  Life<ConwayCell> lives;
  vector<ConwayCell> grid = lives._grid;
  ASSERT_TRUE(grid.size() == 1);
  ASSERT_TRUE(grid[0].is_alive() == DEAD);
}
TEST(LifeFixture, constructor_2) {
  Life<FredkinCell> lives(2, 4);
  vector<FredkinCell> grid = lives._grid;
  ASSERT_TRUE(grid.size() == 8);
  for (int i = 0; i < 8; ++i) {
    ASSERT_TRUE(grid[i].is_alive() == DEAD);
  }
}
TEST(LifeFixture, constructor_3) {
  Life<Cell> lives;
  vector<Cell> grid = lives._grid;
  ASSERT_TRUE(grid[0].is_alive() == DEAD);
}

// ----------------------
// Life::instantiate_cell
// ----------------------
TEST(LifeFixture, instantiate_cell_1) {
  Life<ConwayCell> lives;
  lives.instantiate_cell(0, LIVE);
  ASSERT_TRUE(lives._grid[0].is_alive());
}
TEST(LifeFixture, instantiate_cell_2) {
  Life<FredkinCell> lives;
  lives.instantiate_cell(0, LIVE);
  ASSERT_TRUE(lives._grid[0].is_alive());
}
TEST(LifeFixture, instantiate_cell_3) {
  Life<Cell> lives;
  lives.instantiate_cell(0, LIVE);
  ASSERT_TRUE(lives._grid[0].is_alive());
}

// ---------------------
// Life::next_generation
// ---------------------
TEST(LifeFixture, next_generation_1) {
  Life<ConwayCell> lives(2, 2);
  lives.instantiate_cell(1, LIVE);
  lives.instantiate_cell(2, LIVE);
  lives.instantiate_cell(3, LIVE);
  lives.next_generation();
  for(int i = 0; i < 4; ++i) {
    ASSERT_TRUE(lives._grid[i].is_alive());
  }
}
TEST(LifeFixture, next_generation_2) {
  Life<FredkinCell> lives(2, 2);
  lives.instantiate_cell (1, LIVE);
  lives.next_generation();
  for (int i = 0; i < 4; ++i) {
    if (i == 0 || i == 3)
      ASSERT_TRUE(lives._grid[i].is_alive());
    else
      ASSERT_FALSE(lives._grid[i].is_alive());
  }
}
TEST(LifeFixture, next_generation_3) {
  Life<Cell> lives(2, 2);
  lives.instantiate_cell (1, LIVE);
  lives.next_generation();
  for (int i = 0; i < 4; ++i) {
    if (i == 0 || i == 3)
      ASSERT_TRUE(lives._grid[i].is_alive());
    else
      ASSERT_FALSE(lives._grid[i].is_alive());
  }
}

// -----------
// Life::print
// -----------
TEST(LifeFixture, print_1) {
  string correct = "..\n..\n";
  ostringstream os;
  Life<ConwayCell> lives(2,2);
  lives.print(os);
  ASSERT_TRUE(correct == os.str());
}
TEST(LifeFixture, print_2) {
  string correct = "--\n--\n";
  ostringstream os;
  Life<FredkinCell> lives(2,2);
  lives.print(os);
  ASSERT_TRUE(correct == os.str());
}
TEST(LifeFixture, print_3) {
  string correct = "--\n--\n";
  ostringstream os;
  Life<Cell> lives(2,2);
  lives.print(os);
  ASSERT_TRUE(correct == os.str());
}

// ----------
// count_live
// ----------
TEST(RunLifeFixture, count_live_1) {
  string grid = "--------------\n\n----------------78645645.............**18490...35798.......................";
  ASSERT_EQ(count_live(grid), 20);
}
TEST(RunLifeFixture, count_live_2) {
  string grid = "1234567890";
  ASSERT_EQ(count_live(grid), 10);
}
TEST(RunLifeFixture, count_live_3) {
  string grid = "*****+++++";
  ASSERT_EQ(count_live(grid), 10);
}

// ---------
// make_grid
// ---------
TEST(RunLifeFixture, make_grid_1) {
  string grid = "2 2\n**\n**\n";
  string result = "\nGeneration = 0, Population == 4.\n**\n**\n\n";
  istringstream is(grid);
  ostringstream os;
  vector<int>print({0});
  make_grid(is, os, false, 5, print);
  ASSERT_EQ(os.str(), result);
}
TEST(RunLifeFixture, make_grid_2) {
  string grid = "2 2\n--\n--\n";
  string result = "\nGeneration = 0, Population == 0.\n--\n--\n\n";
  istringstream is(grid);
  ostringstream os;
  vector<int>print({0});
  make_grid(is, os, false, 5, print);
  ASSERT_EQ(os.str(), result);
}
TEST(RunLifeFixture, make_grid_3) {
  string grid = "2 2\n00\n00\n";
  string result = "\nGeneration = 0, Population == 4.\n00\n00\n\n";
  istringstream is(grid);
  ostringstream os;
  vector<int>print({0});
  make_grid(is, os, true, 5, print);
  ASSERT_EQ(os.str(), result);
}
