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

// ---------------------
// ConwayCellConstructor
// ---------------------

TEST(ConwayCellConstructor, test1) {
  // just validate fields set

  ConwayCell c(true);

  assert(c.alive);

  ConwayCell c2(false);

  assert(!c2.alive);
}

TEST(ConwayCellConstructor, test2) {
  // check basic behavior is correct

  ConwayCell c(true);
  ConwayCell d(false);

  ostringstream o;

  o << c;
  o << d;

  assert(o.str() == "*.");
}

// -------------------------
// ConwayCellCopyConstructor
// -------------------------

TEST(ConwayCellCopyConstructor, test1) {
  // just validate everything works correctly

  ConwayCell c(true);

  ConwayCell c2(c);

  assert(c2.alive);
}

TEST(ConwayCellCopyConstructor, test2) {
  // just validate everything works correctly

  ConwayCell c(false);

  ConwayCell c2(c);

  c.updateSelf(1, 2);

  ostringstream o;

  o << c;
  o << c2;

  assert(o.str() == "*.");
}

// ----------------------
// FredkinCellConstructor
// ----------------------

TEST(FredkinCellConstructor, test1) {
  // just validate everything works correctly

  FredkinCell c(true);

  assert(c.alive);
  assert(c.age == 0);

  FredkinCell c2(false);

  assert(!c2.alive);
  assert(c2.age == 0);
}

TEST(FredkinCellConstructor, test2) {
  // check basic behavior is correct

  FredkinCell c(true);
  FredkinCell d(false);

  ostringstream o;

  o << c;
  o << d;

  assert(o.str() == "0-");
}

// --------------------------
// FredkinCellCopyConstructor
// --------------------------

TEST(FredkinCellCopyConstructor, test1) {
  // just validate everything works correctly

  FredkinCell c(true);

  FredkinCell c2(c);

  assert(c2.alive);
  assert(c2.age == 0);
}

TEST(FredkinCellCopyConstructor, test2) {
  // validate live status copies with copy constructor

  FredkinCell c(true);
  c.updateSelf(0, 1);

  FredkinCell c2(c);

  assert(c2.age == 0 && !c2.alive);
}

TEST(FredkinCellCopyConstructor, test3) {
  // check age copies with copy constructor through updates

  FredkinCell c(true);
  c.updateSelf(1, 1);

  FredkinCell c2(c);

  assert(c2.age == 1);
}

// ---------------
// CellConstructor
// ---------------

TEST(CellConstructor, test1) {
  // basic test for pointer ref

  ConwayCell c(true);

  Cell c2(c);

  assert(c2.cell->alive);
}

TEST(CellConstructor, test2) {
  // check that update will go through

  FredkinCell c(false);

  Cell c2(c);

  assert(UpdateStatus::ALIVE == c2.updateSelf(1, 0));

  assert(c2.cell->alive);
}

TEST(CellConstructor, test3) {
  // check that initial non-zero age will propagate

  FredkinCell c(true);
  c.updateSelf(1, 1);

  Cell c2(c);

  ostringstream o;

  o << c2;

  assert(o.str() == "1");
}

// -------------------
// CellCopyConstructor
// -------------------

TEST(CellCopyConstructor, test1) {
  // basic case

  FredkinCell c(true);

  Cell c2(c);

  Cell c3(c2);

  assert(c3.cell != c2.cell && c2.cell->alive == c3.cell->alive);
}

TEST(CellCopyConstructor, test2) {
  // check with ConwayCell

  ConwayCell c(false);

  Cell c2(c);

  Cell c3(c2);

  assert(!c2.cell->alive && !c3.cell->alive);
}

TEST(CellCopyConstructor, test3) {
  // check works across update

  FredkinCell c(true);

  Cell c2(c);
  c2.updateSelf(0, 1);

  Cell c3(c2);

  assert(!c3.cell->alive);
}

// --------------
// CellCopyAssign
// --------------

TEST(CellCopyAssign, test1) {
  // basic case

  FredkinCell c(true);
  FredkinCell d(false);

  Cell c2(c);
  Cell c3(d);

  c3 = c2;

  assert(c3.cell != c2.cell && c2.cell->alive == c3.cell->alive);
}

TEST(CellCopyAssign, test2) {
  // check with ConwayCell

  ConwayCell c(false);
  ConwayCell d(true);

  Cell c2(c);
  Cell c3(d);

  c3 = c2;

  assert(!c2.cell->alive && !c3.cell->alive);
}

TEST(CellCopyAssign, test3) {
  // check works across update

  FredkinCell c(true);
  FredkinCell d(false);

  Cell c2(c);
  c2.updateSelf(0, 1);
  Cell c3(d);

  c3 = c2;

  assert(!c3.cell->alive);
}

// --------------------
// ConwayCellUpdateSelf
// --------------------

TEST(ConwayCellUpdateSelf, test1) {
  // basic update test

  ConwayCell c(true);

  assert(UpdateStatus::ALIVE == c.updateSelf(2, 0));

  assert(c.alive);
}

TEST(ConwayCellUpdateSelf, test2) {
  // check the dead to alive case works for 3 neighbors

  ConwayCell c(false);

  assert(UpdateStatus::ALIVE == c.updateSelf(2, 1));

  assert(c.alive);
}

TEST(ConwayCellUpdateSelf, test3) {
  // check that stays dead for cases where should be dead

  ConwayCell c(false);

  for (int x = 0; x < 9; ++x) {
    if (x != 3) {
      c.updateSelf(0, x);
      assert(!c.alive);
    }
  }
}

TEST(ConwayCellUpdateSelf, test4) {
  // checks stays alive for 2 or 3 neighbors

  ConwayCell c(true);

  c.updateSelf(2, 0);

  assert(c.alive);

  c.updateSelf(0, 3);

  assert(c.alive);
}

TEST(ConwayCellUpdateSelf, test5) {
  // checks that alive cell dies when it should

  for (int x = 0; x < 9; ++x) {
    if (x != 2 && x != 3) {
      ConwayCell c(true);
      c.updateSelf(0, x);

      assert(!c.alive);
    }
  }
}

TEST(ConwayCellUpdateSelf, test6) {
  // a comprehensive test

  ConwayCell c(true);

  c.updateSelf(1, 0);

  assert(!c.alive);

  c.updateSelf(1, 1);

  assert(!c.alive);

  c.updateSelf(2, 1);

  assert(c.alive);

  c.updateSelf(2, 0);

  assert(c.alive);

  c.updateSelf(4, 4);

  assert(!c.alive);
}

// ---------------------
// FredkinCellUpdateSelf
// ---------------------

TEST(FredkinCellUpdateSelf, test1) {
  // basic test, check age moves correctly

  FredkinCell c(true);

  assert(c.age == 0);

  c.updateSelf(1, 0);

  assert(c.age == 1);
}

TEST(FredkinCellUpdateSelf, test2) {
  // check the ConwayCell conversion case when Life initialized with Cell

  FredkinCell c(true);

  assert(c.age == 0);

  assert(UpdateStatus::ALIVE == c.updateSelf(1, 2));

  // if this is true, then Life will replace this FredkinCell object with a
  // ConwayCell object
  assert(UpdateStatus::CONVERT_CONWAY_ALIVE == c.updateSelf(1, 3));

  assert(c.age == 2);
}

TEST(FredkinCellUpdateSelf, test3) {
  // check dead to live conditions are correct

  FredkinCell c(false);

  c.updateSelf(1, 0);

  assert(c.alive);

  FredkinCell c2(false);

  c2.updateSelf(3, 1);

  assert(c2.alive);
}

TEST(FredkinCellUpdateSelf, test4) {
  // check stays dead conditions are correct

  FredkinCell c(false);

  for (int x = 0; x < 5; ++x) {
    if (x != 1 && x != 3)
      c.updateSelf(x, x);
    assert(!c.alive);
  }
}

TEST(FredkinCellUpdateSelf, test5) {
  // check that live to dead conditions are correct

  FredkinCell c(true);

  c.updateSelf(0, 1);

  assert(!c.alive);

  FredkinCell c1(true);

  c1.updateSelf(2, 1);

  assert(!c1.alive);

  FredkinCell c2(true);

  c2.updateSelf(4, 2);

  assert(!c2.alive);
}

TEST(FredkinCellUpdateSelf, test6) {
  // check that stay alive conditions are correct

  for (int x = 0; x < 5; ++x) {
    if (x != 0 && x != 2 && x != 4) {
      FredkinCell c(true);
      c.updateSelf(x, 2);

      assert(c.alive);
    }
  }
}

TEST(FredkinCellUpdateSelf, test7) {
  // a final comprehensive test, checking progression of time

  FredkinCell c(true);

  assert(UpdateStatus::ALIVE == c.updateSelf(1, 2));
  assert(c.alive);
  assert(c.age == 1);

  assert(UpdateStatus::DEAD == c.updateSelf(0, 0));
  assert(!c.alive);
  assert(c.age == 1);

  assert(UpdateStatus::DEAD == c.updateSelf(2, 1));
  assert(!c.alive);
  assert(c.age == 1);

  assert(UpdateStatus::ALIVE == c.updateSelf(3, 2));
  assert(c.alive);
  assert(c.age == 1);

  assert(UpdateStatus::CONVERT_CONWAY_ALIVE == c.updateSelf(3, 3));
  assert(c.alive);
  assert(c.age == 2);

  assert(UpdateStatus::ALIVE == c.updateSelf(1, 0));
  assert(c.alive);
  assert(c.age == 3);
}

// ----------------------
// AbstractCellUpdateSelf
// ----------------------

TEST(AbstractCellUpdateSelf, test1) {
  // simple test, should work if compiles

  ConwayCell c(true);

  AbstractCell *ac = &c;

  assert(UpdateStatus::ALIVE == ac->updateSelf(1, 1));
}

TEST(AbstractCellUpdateSelf, test2) {
  // test field accesses via pointer and works for Fredkin

  FredkinCell c(true);

  AbstractCell *ac = &c;

  assert(ac->alive);

  ac->updateSelf(0, 2);

  assert(!c.alive);
}

// --------------
// CellUpdateSelf
// --------------

TEST(CellUpdateSelf, test1) {
  // ConwayCell

  ConwayCell c(false);
  Cell c2 = c;

  c2.updateSelf(1, 2);

  assert(c2.cell->alive);
}

TEST(CellUpdateSelf, test2) {
  // FredkinCell

  FredkinCell c(false);
  Cell c2 = c;

  c2.updateSelf(1, 2);

  assert(c2.cell->alive);
}

TEST(CellUpdateSelf, test3) {
  // ConwayCell

  ConwayCell c(true);
  Cell c2 = c;

  c2.updateSelf(2, 2);

  assert(!c2.cell->alive);
}

TEST(CellUpdateSelf, test4) {
  // FredkinCell

  FredkinCell c(true);
  Cell c2 = c;

  c2.updateSelf(2, 0);

  assert(!c2.cell->alive);
}

TEST(CellUpdateSelf, test5) {
  // FredkinCell to ConwayCell conversion

  FredkinCell c(true);
  Cell c2 = c;

  c2.updateSelf(1, 2);
  c2.updateSelf(1, 0);

  ostringstream o;

  o << c2;

  assert(o.str() == "*");
}

TEST(CellUpdateSelf, test6) {
  // no FredkinCell to ConwayCell conversion when dies instead of going to 2

  FredkinCell c(true);
  Cell c2 = c;

  c2.updateSelf(1, 2);
  c2.updateSelf(2, 0);

  ostringstream o;

  o << c2;

  assert(o.str() == "-");
}

// -------------
// ConwayDisplay
// -------------

TEST(ConwayDisplay, test1) {
  // basic test

  ConwayCell c(true);

  ostringstream o;

  c.display(o);

  assert(o.str() == "*");
}

TEST(ConwayDisplay, test2) {
  // check for dead

  ConwayCell c(false);

  ostringstream o;

  c.display(o);

  assert(o.str() == ".");
}

TEST(ConwayDisplay, test3) {
  // check after modify

  ConwayCell c(true);

  c.updateSelf(0, 0);

  ostringstream o;

  c.display(o);

  assert(o.str() == ".");
}

TEST(ConwayDisplay, test4) {
  // check with Abstract call

  ConwayCell c(true);

  AbstractCell *c2 = &c;

  ostringstream o;

  c2->display(o);

  assert(o.str() == "*");
}

TEST(ConwayDisplay, test5) {
  // check with Cell

  ConwayCell c(true);

  Cell c2 = c;

  ostringstream o;

  c2.cell->display(o);

  assert(o.str() == "*");
}

// --------------
// FredkinDisplay
// --------------

TEST(FredkinDisplay, test1) {
  // basic test

  FredkinCell c(true);

  ostringstream o;

  c.display(o);

  assert(o.str() == "0");
}

TEST(FredkinDisplay, test2) {
  // check for dead

  FredkinCell c(false);

  ostringstream o;

  c.display(o);

  assert(o.str() == "-");
}

TEST(FredkinDisplay, test3) {
  // check after modify

  FredkinCell c(false);

  c.updateSelf(1, 0);

  ostringstream o;

  c.display(o);

  assert(o.str() == "0");
}

TEST(FredkinDisplay, test4) {
  // check with Abstract call

  FredkinCell c(false);

  AbstractCell *c2 = &c;

  ostringstream o;

  c2->display(o);

  assert(o.str() == "-");
}

TEST(FredkinDisplay, test5) {
  // check with Cell

  FredkinCell c(false);

  Cell c2 = c;

  ostringstream o;

  c2.cell->display(o);

  assert(o.str() == "-");
}

TEST(FredkinDisplay, test6) {
  // check nums then dead

  FredkinCell c(true);

  ostringstream o;

  c.display(o);

  c.updateSelf(1, 1);

  c.display(o);

  c.updateSelf(0, 0);

  c.display(o);

  assert(o.str() == "01-");
}

TEST(FredkinDisplay, test7) {
  // check all nums and exceed 10

  FredkinCell c(true);

  ostringstream o;

  for (int x = 0; x < 9; ++x)
    c.updateSelf(1, 1);

  c.display(o);

  c.updateSelf(1, 0);

  c.display(o);

  assert(o.str() == "9+");
}

// ---------------
// OutAbstractCell
// ---------------

TEST(OutAbstractCell, test1) {
  // basic case checks

  ConwayCell c(false);

  ostringstream o;

  o << c;

  assert(o.str() == ".");

  ConwayCell c1(true);

  ostringstream o1;

  o1 << c1;

  assert(o1.str() == "*");
}

TEST(OutAbstractCell, test2) {
  // test print when life status of cell changes

  ConwayCell c(false);

  c.updateSelf(1, 2);

  ostringstream o;

  o << c;

  assert(o.str() == "*");
}

TEST(OutAbstractCell, test3) {
  // basic case checks

  FredkinCell c(false);

  ostringstream o;

  o << c;

  assert(o.str() == "-");

  FredkinCell c1(true);

  ostringstream o1;

  o1 << c1;

  assert(o1.str() == "0");
}

TEST(OutAbstractCell, test4) {
  // test print when life status of cell changes

  FredkinCell c(false);

  c.updateSelf(3, 1);

  ostringstream o;

  o << c;

  assert(o.str() == "0");
}

TEST(OutAbstractCell, test5) {
  // test numerical outputs

  FredkinCell c(true);

  c.updateSelf(3, 4);

  ostringstream o;

  o << c;

  assert(o.str() == "1");

  c.updateSelf(3, 2);

  ostringstream o1;

  o1 << c;

  assert(o1.str() == "2");
}

TEST(OutAbstractCell, test6) {
  // test the + case

  FredkinCell c(true);

  for (int x = 0; x < 9; x++)
    c.updateSelf(3, 0);

  ostringstream o;

  o << c;

  assert(o.str() == "9");

  c.updateSelf(3, 2);

  ostringstream o1;

  o1 << c;

  assert(o1.str() == "+");
}

// -------
// OutCell
// -------

TEST(OutCell, test1) {
  // test with Fredkin

  FredkinCell c(true);

  Cell c2(c);

  ostringstream o;

  o << c2;

  assert(o.str() == "0");
}

TEST(OutCell, test2) {
  // test with Conway

  ConwayCell c(false);

  Cell c2(c);

  ostringstream o;

  o << c2;

  assert(o.str() == ".");
}

TEST(OutCell, test3) {
  // test with Fredkin

  FredkinCell c(false);

  Cell c2(c);

  ostringstream o;

  o << c2;

  assert(o.str() == "-");
}

TEST(OutCell, test4) {
  // test with Conway

  ConwayCell c(true);

  Cell c2(c);

  ostringstream o;

  o << c2;

  assert(o.str() == "*");
}

TEST(OutCell, test5) {
  // test with Fredkin convert case

  FredkinCell c(true);

  Cell c2(c);

  c2.updateSelf(1, 0);
  c2.updateSelf(1, 0);

  ostringstream o;

  o << c2;

  assert(o.str() == "*");
}

// ---------------
// LifeConstructor
// ---------------

TEST(LifeConstructor, test1) {
  // basic test for size

  Life<ConwayCell> c(4, 5);

  assert(c.rows == 4);
  assert(c.columns == 5);
}

TEST(LifeConstructor, test2) {
  // basic test for gen and pop

  Life<ConwayCell> c(1, 1);

  assert(c.gen == 0);
  assert(c.pop == 0);
}

// ------
// LifeIn
// ------

TEST(LifeIn, test1) {
  // basic test to check that input works

  Life<ConwayCell> l(2, 2);

  istringstream i("..\n..\n");

  i >> l;

  assert(l.cells.size() == 4);
}

TEST(LifeIn, test2) {
  // check that if input is smaller than input size, still pads the internal
  // vector

  Life<ConwayCell> l(3, 3);

  istringstream i("..\n..\n\0");

  i >> l;

  assert(l.cells.size() == 9);
}

TEST(LifeIn, test3) {
  // check population is set correctly

  Life<ConwayCell> l(2, 2);

  istringstream i("..\n**\n");

  i >> l;

  assert(l.pop == 2);
}

TEST(LifeIn, test4) {
  // bigger grid, rectangle

  Life<ConwayCell> l(5, 3);

  istringstream i("*..\n*..\n...\n*.*\n...\n");

  i >> l;

  assert(l.cells.size() == 15);
  assert(l.pop == 4);
}

TEST(LifeIn, test5) {
  // empty Fredkin

  Life<FredkinCell> l(2, 2);

  istringstream i("--\n--\n");

  i >> l;

  assert(!l.cells[0].alive);
}

TEST(LifeIn, test6) {
  // Fredkin populated

  Life<FredkinCell> l(4, 4);

  istringstream i("--0-\n0---\n0---\n-0--\n");

  i >> l;

  assert(l.cells.size() == 16);
  assert(l.pop == 4);
}

TEST(LifeIn, test7) {
  // Cell with only Conway

  Life<Cell> l(3, 3);

  istringstream i(".*.\n...\n...\n");

  i >> l;

  assert(l.cells.size() == 9);
  assert(l.pop == 1);
}

TEST(LifeIn, test8) {
  // mixed grid

  Life<Cell> l(3, 3);

  istringstream i("-.0\n000\n**.");

  i >> l;

  assert(l.cells.size() == 9);
  assert(l.pop == 6);
}

// --------------
// LifeFindNearby
// --------------

TEST(LifeFindNearby, test1) {
  // test that findNearby works for basic cases

  Life<ConwayCell> l(5, 5);

  int *locations[8];
  vector<int> end(50, 0);

  l.findNearby(22, locations, end);

  assert(locations[1] == &(end[34]));
}

TEST(LifeFindNearby, test2) {
  // test that findNearby works on edge

  Life<ConwayCell> l(5, 5);

  int *locations[8];
  vector<int> end(50, 0);

  l.findNearby(20, locations, end);

  assert(locations[0] == 0); // no left corner location

  assert(locations[1] == &(end[30]));
}

TEST(LifeFindNearby, test3) {
  // test that findNearby works on top corner

  Life<ConwayCell> l(5, 5);

  int *locations[8];
  vector<int> end(50, 0);

  l.findNearby(0, locations, end);

  assert(locations[0] == 0); // no left corner location

  assert(locations[3] == 0); // no left location
}

TEST(LifeFindNearby, test4) {
  // test that findNearby works with values on all sides

  Life<ConwayCell> l(5, 5);

  int *locations[8];
  vector<int> end(50, 0);

  l.findNearby(18, locations, end);

  assert(locations[0] == &(end[24]));
  assert(locations[1] == &(end[26]));
  assert(locations[2] == &(end[28]));
  assert(locations[3] == &(end[34]));
  assert(locations[4] == &(end[38]));
  assert(locations[5] == &(end[44]));
  assert(locations[6] == &(end[46]));
  assert(locations[7] == &(end[48]));
}

TEST(LifeFindNearby, test5) {
  // test that all nearby null for single cell grid

  Life<ConwayCell> l(1, 1);

  int *locations[8];

  vector<int> end(2, 0);

  l.findNearby(0, locations, end);

  for (int x = 0; x < 8; ++x)
    assert(locations[x] == NULL);
}

// -------------------------
// AbstractCellTellNeighbors
// -------------------------

TEST(AbstractCellTellNeighbors, test1) {
  // basic test for dead cell

  ConwayCell c(false);

  int p[2] = {10, 12};

  int *locations[8];
  for (int x = 0; x < 8; ++x)
    locations[x] = NULL;
  locations[0] = p;

  c.tellNeighbors(locations);

  assert(p[1] == 12);
}

TEST(AbstractCellTellNeighbors, test2) {
  // basic test for alive cell

  ConwayCell c(true);

  int p[2] = {10, 12};
  int q[2] = {17, 19};

  int *locations[8];
  for (int x = 0; x < 8; ++x)
    locations[x] = NULL;
  locations[1] = p;
  locations[5] = q;

  c.tellNeighbors(locations);
  assert(p[0] == 11);

  assert(q[1] == 20);
}

TEST(AbstractCellTellNeighbors, test3) {
  // basic test for dead cell

  FredkinCell c(false);

  int p[2] = {10, 14};

  int *locations[8];
  for (int x = 0; x < 8; ++x)
    locations[x] = NULL;
  locations[7] = p;

  c.tellNeighbors(locations);

  assert(p[0] == 10);
  assert(p[1] == 14);
}

TEST(AbstractCellTellNeighbors, test4) {
  // basic test for alive cell

  FredkinCell c(true);

  int p[2] = {1, 3};
  int q[2] = {8, 10};

  int *locations[16];
  for (int x = 0; x < 16; ++x)
    locations[x] = NULL;
  locations[3] = p;
  locations[2] = q;

  c.tellNeighbors(locations);

  assert(p[0] == 2);

  assert(q[1] == 11);
}

// -------
// LifeOut
// -------

TEST(LifeOut, test1) {
  // basic test that output matches input

  Life<ConwayCell> l(2, 2);

  istringstream i("..\n..\n");

  i >> l;

  ostringstream o;

  o << l;

  assert(o.str() == "Generation = 0, Population = 0.\n..\n..\n");
}

TEST(LifeOut, test2) {
  // multiple turns correct

  Life<ConwayCell> l(2, 2);

  istringstream i("..\n..\n");

  i >> l;

  ostringstream o;

  o << l;

  l.run(1, o);

  assert(o.str() == "Generation = 0, Population = 0.\n..\n..\n\nGeneration = "
                    "1, Population = 0.\n..\n..\n");
}

TEST(LifeOut, test3) {
  // empty doesn't break

  Life<FredkinCell> l(0, 0);

  istringstream i("");

  i >> l;

  ostringstream o;

  o << l;

  assert(o.str() == "Generation = 0, Population = 0.\n");
}

// -------
// LifeRun
// -------

TEST(LifeRun, test1) {
  // basic test with ConwayCell

  Life<ConwayCell> l(2, 2);

  istringstream i(".*\n..\n");

  i >> l;

  ostringstream q;

  l.run(2, q);

  ostringstream o;

  o << l;

  assert(o.str() == "Generation = 2, Population = 0.\n..\n..\n");
}

TEST(LifeRun, test2) {
  // basic test with FredkinCell

  Life<FredkinCell> l(2, 2);

  istringstream i("-0\n--\n");

  i >> l;

  ostringstream dummy;

  l.run(1, dummy);

  ostringstream o;

  o << l;

  assert(o.str() == "Generation = 1, Population = 2.\n0-\n-0\n");
}

TEST(LifeRun, test3) {
  // basic test with Cell

  Life<Cell> l(2, 2);

  istringstream i("*0.-");

  i >> l;

  ostringstream o;

  o << l;

  ostringstream dummy;

  l.run(1, dummy);

  o << l;

  assert(o.str() == "Generation = 0, Population = 2.\n*0\n.-\nGeneration = 1, "
                    "Population = 2.\n.1\n.0\n");
}

TEST(LifeRun, test4) {
  // all dead stay dead, check population

  Life<Cell> l(4, 4);

  istringstream i("................");

  i >> l;

  ostringstream dummy;

  l.run(100, dummy);

  assert(l.pop == 0);
}

TEST(LifeRun, test5) {
  // no issues with single cell grid

  Life<Cell> l(1, 1);

  istringstream i("0");

  i >> l;

  assert(l.pop == 1);

  ostringstream dummy;

  l.run(100, dummy);

  assert(l.pop == 0);
}

TEST(LifeRun, test6) {
  // a general case

  Life<FredkinCell> l(3, 3);

  istringstream i("-0-000-0-");

  i >> l;

  assert(l.pop == 5);

  ostringstream dummy;

  l.run(1, dummy);

  assert(l.pop == 4);

  l.run(1, dummy);

  assert(l.pop == 0);
}
