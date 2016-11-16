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

// ----
// Life
// ----

TEST(LifeFixture, constructor1) {
  vector<vector<int>> p;

  Life<int> l(4, 4, p);
  ASSERT_EQ(4, l.height);
  ASSERT_EQ(4, l.width);
  ASSERT_EQ(0, l.gen);
  ASSERT_EQ(0, l.grid.size());
}

TEST(LifeFixture, constructor2) {
  vector<vector<int>> p;
  for (int i = 0; i < 3; ++i) {
    p.push_back(vector<int>());
    for (int j = 0; j < 3; ++j) {
      p[i].push_back(j);
    }
  }

  Life<int> l(3, 3, p);
  ASSERT_EQ(3, l.height);
  ASSERT_EQ(3, l.width);
  ASSERT_EQ(0, l.gen);
  ASSERT_EQ(3, l.grid.size());
  ASSERT_EQ(0, l.grid[0][0]);
}

TEST(LifeFixture, constructor3) {
  vector<vector<char>> p;
  for (int i = 0; i < 5; ++i) {
    p.push_back(vector<char>());
    for (int j = 0; j < 10; ++j) {
      p[i].push_back(j + '0');
    }
  }

  Life<char> l(5, 10, p);
  ASSERT_EQ(5, l.height);
  ASSERT_EQ(10, l.width);
  ASSERT_EQ(0, l.gen);
  ASSERT_EQ(5, l.grid.size());
  ASSERT_EQ('9', l.grid[0][9]);
}

// Empty grid -> prints empty string
TEST(LifeFixture, print1) {
  vector<vector<int>> p;
  Life<int> l(4, 4, p);

  ostringstream w;
  w << l;
  ASSERT_EQ("Generation = 0, Population = 0.\n", w.str());
}

// Fully filled grid
TEST(LifeFixture, print2) {
  vector<vector<int>> p;
  for (int i = 0; i < 3; ++i) {
    p.push_back(vector<int>());
    for (int j = 0; j < 3; ++j) {
      p[i].push_back(j);
    }
  }

  Life<int> l(3, 3, p);
  ostringstream w;
  w << l;
  ASSERT_EQ("Generation = 0, Population = 9.\n012\n012\n012\n\n", w.str());
}

TEST(LifeFixture, print3) {
  vector<vector<char>> p;
  p.push_back(vector<char>());
  for (int j = 0; j < 10; ++j) {
    p[0].push_back(j + '0');
  }

  Life<char> l(1, 10, p);
  ostringstream w;
  w << l;
  ASSERT_EQ("Generation = 0, Population = 10.\n0123456789\n\n", w.str());
}

TEST(LifeFixture, simulate1) {
  vector<vector<ConwayCell>> p;

  for (int i = 0; i < 4; ++i) {
    p.push_back(vector<ConwayCell>());
    for (int j = 0; j < 4; ++j) {
      ConwayCell cc(true, '*');
      p[i].push_back(cc);
    }
  }

  Life<ConwayCell> l(4, 4, p);

  l.simulate();
  ASSERT_EQ(1, l.gen);
  l.simulate();
  ASSERT_EQ(2, l.gen);
}

TEST(LifeFixture, simulate2) {
  vector<vector<ConwayCell>> p;

  for (int i = 0; i < 4; ++i) {
    p.push_back(vector<ConwayCell>());
    for (int j = 0; j < 4; ++j) {
      ConwayCell cc(true, '*');
      p[i].push_back(cc);
    }
  }

  Life<ConwayCell> l(4, 4, p);

  for (int i = 0; i < 100; ++i)
    l.simulate();

  ASSERT_EQ(100, l.gen);
}

// ----
// Cell
// ----

TEST(CellFixture, constructor1) {
  ConwayCell cc(false, '.');
  Cell c(&cc);
  ASSERT_EQ(&cc, c.ac);
}

TEST(CellFixture, constructor2) {
  ConwayCell cc(true, '*');
  Cell c(&cc);
  ASSERT_EQ(&cc, c.ac);
}

TEST(CellFixture, constructor3) {
  FredkinCell fc(false, '-');
  Cell c(&fc);
  ASSERT_EQ(&fc, c.ac);
}

TEST(CellFixture, constructor4) {
  FredkinCell fc(true, '3');
  Cell c(&fc);
  ASSERT_EQ(&fc, c.ac);
}

TEST(CellFixture, constructor5) {
  FredkinCell fc(true, '+');
  Cell c(&fc);
  ASSERT_EQ(&fc, c.ac);
}

TEST(CellFixture, alive1) {
  ConwayCell cc(true, '*');
  Cell c(&cc);
  ASSERT_EQ(true, c.isCellAlive());
}

TEST(CellFixture, alive2) {
  ConwayCell cc(false, '.');
  Cell c(&cc);
  ASSERT_EQ(false, c.isCellAlive());
}

TEST(CellFixture, alive3) {
  FredkinCell fc(true, '+');
  Cell c(&fc);
  ASSERT_EQ(true, c.isCellAlive());
}

TEST(CellFixture, alive4) {
  FredkinCell fc(false, '-');
  Cell c(&fc);
  ASSERT_EQ(false, c.isCellAlive());
}

TEST(CellFixture, evolve1) {
  ConwayCell cc(true, '*');
  Cell c(&cc);

  vector<bool> n;
  for (int i = 0; i < 8; ++i) {
    n.push_back(false);
  }
  c.evolve(n);
  ASSERT_EQ(&cc, c.ac);
}

TEST(CellFixture, evolve2) {
  ConwayCell cc(false, '-');
  Cell c(&cc);

  vector<bool> n;
  for (int i = 0; i < 3; ++i) {
    n.push_back(true);
  }
  for (int i = 0; i < 5; ++i) {
    n.push_back(false);
  }
  c.evolve(n);
  ASSERT_EQ(&cc, c.ac);
}

TEST(CellFixture, evolve3) {
  AbstractCell *fcp = new FredkinCell(true, '0');
  Cell c(fcp);

  vector<bool> n;
  n.push_back(true);
  n.push_back(true);
  for (int i = 0; i < 7; ++i) {
    n.push_back(false);
  }
  c.evolve(n);
  c.evolve(n);
  // delete fcp;
  ASSERT_NE(fcp, c.ac);
  delete fcp;
  delete c.ac;
}

TEST(CellFixture, evolve4) {
  FredkinCell *fcp = new FredkinCell(true, '0');
  Cell c(fcp);

  vector<bool> n;
  for (int i = 0; i < 6; ++i) {
    n.push_back(true);
  }
  for (int i = 0; i < 2; ++i) {
    n.push_back(false);
  }
  c.evolve(n);
  c.evolve(n);
  // delete fcp;
  ASSERT_NE(fcp, c.ac);
  delete fcp;
  delete c.ac;
}

TEST(CellFixture, evolve5) {
  FredkinCell fc(false, '-');
  Cell c(&fc);

  vector<bool> n;
  for (int i = 0; i < 3; ++i) {
    n.push_back(true);
  }
  for (int i = 0; i < 5; ++i) {
    n.push_back(false);
  }
  c.evolve(n);
  ASSERT_EQ(&fc, c.ac);
}

TEST(CellFixture, evolve6) {
  FredkinCell fc(true, '+');
  Cell c(&fc);

  vector<bool> n;
  for (int i = 0; i < 3; ++i) {
    n.push_back(true);
  }
  for (int i = 0; i < 5; ++i) {
    n.push_back(false);
  }
  c.evolve(n);
  ASSERT_EQ(&fc, c.ac);
}

TEST(CellFixture, evolve7) {
  FredkinCell fc(true, '0');
  Cell c(&fc);

  vector<bool> n;
  for (int i = 0; i < 3; ++i) {
    n.push_back(true);
  }
  for (int i = 0; i < 5; ++i) {
    n.push_back(false);
  }
  c.evolve(n);
  ASSERT_EQ(&fc, c.ac);
}

TEST(CellFixture, print1) {
  ConwayCell cc(false, '.');
  Cell c(&cc);

  ostringstream w;
  w << c;
  ASSERT_EQ(".", w.str());
}

TEST(CellFixture, print2) {
  ConwayCell cc(true, '*');
  Cell c(&cc);

  ostringstream w;
  w << c;
  ASSERT_EQ("*", w.str());
}

TEST(CellFixture, print3) {
  FredkinCell fc(false, '-');
  Cell c(&fc);

  ostringstream w;
  w << c;
  ASSERT_EQ("-", w.str());
}

TEST(CellFixture, print4) {
  FredkinCell fc(true, '+');
  Cell c(&fc);

  ostringstream w;
  w << c;
  ASSERT_EQ("+", w.str());
}

TEST(CellFixture, print5) {
  FredkinCell fc(false, '0');
  Cell c(&fc);

  ostringstream w;
  w << c;
  ASSERT_EQ("0", w.str());
}

// ----
// ConwayCell Tests
// ----

vector<bool> alive = {false, true, false, true, true, false, false, false};
vector<bool> dead = {true, true, true, true, true, true, true, true};

/**
 * Test ConwayCell constructor
 */
TEST(ConwayFixture, test1) {
  ConwayCell c(true, '*');
  ASSERT_EQ(c.isCellAlive(), true);
}

/**
 * Test ConwayCell constructor
 */
TEST(ConwayFixture, test2) {
  ConwayCell c(false, '.');
  ASSERT_EQ(c.isCellAlive(), false);
}

/**
 * Test ConwayCell copy constructor
 */
TEST(ConwayFixture, test3) {
  ConwayCell c(false, '.');
  ConwayCell cc(c);

  ASSERT_EQ(c.isCellAlive(), cc.isCellAlive());
  ASSERT_NE(&c, &cc);
}

/**
 * Test ConwayCell copy constructor
 */
TEST(ConwayFixture, test4) {
  ConwayCell c(true, '*');
  ConwayCell cc(c);

  ASSERT_EQ(c.isCellAlive(), cc.isCellAlive());
  ASSERT_NE(&c, &cc);
}

/**
 * Test ConwayCell copy assignment
 */
TEST(ConwayFixture, test5) {
  ConwayCell c(false, '.');
  ConwayCell cc = c;

  ASSERT_EQ(c.isCellAlive(), cc.isCellAlive());
  ASSERT_NE(&c, &cc);
}

/**
 * Test ConwayCell copy assignment
 */
TEST(ConwayFixture, test6) {
  ConwayCell c(true, '*');
  ConwayCell cc = c;

  ASSERT_EQ(c.isCellAlive(), cc.isCellAlive());
  ASSERT_NE(&c, &cc);
}

/**
 * Test ConwayCell copy assignment
 */
TEST(ConwayFixture, test7) {
  ConwayCell c(false, '.');
  ConwayCell *cc = c.clone();

  ASSERT_EQ(c.isCellAlive(), cc->isCellAlive());
  ASSERT_NE(&c, cc);
  delete cc;
}

/**
 * Test ConwayCell copy assignment
 */
TEST(ConwayFixture, test8) {
  ConwayCell c(true, '*');
  ConwayCell *cc = c.clone();

  ASSERT_EQ(c.isCellAlive(), cc->isCellAlive());
  ASSERT_NE(&c, cc);
  delete cc;
}

/**
 * Test ConwayCell evolve. Cell should become alive
 */
TEST(ConwayFixture, test9) {
  ConwayCell c(false, '.');
  c.evolve(alive);

  ASSERT_EQ(c.isCellAlive(), true);
}

/**
 * Test ConwayCell evolve. Cell should become alive
 */
TEST(ConwayFixture, test10) {
  ConwayCell c(true, '*');
  c.evolve(alive);

  ASSERT_EQ(c.isCellAlive(), true);
}

/**
 * Test ConwayCell evolve twice.
 */
TEST(ConwayFixture, test11) {
  ConwayCell c(true, '*');
  c.evolve(alive);
  AbstractCell *tmp = c.evolve(alive);
  ASSERT_EQ(tmp, nullptr);
  ASSERT_EQ(c.isCellAlive(), true);
}

/**
 * Test ConwayCell evolve 10 times.
 */
TEST(ConwayFixture, test12) {
  ConwayCell c(true, '*');
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);

  ostringstream s;
  s << c;
  ASSERT_EQ(s.str(), "*");
}

TEST(ConwayFixture, test13) {
  ConwayCell c(false, '-');
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);

  ostringstream s;
  s << c;
  ASSERT_EQ(s.str(), "*");
}

TEST(ConwayFixture, test14) {
  ConwayCell c(false, '-');
  c.evolve(alive);

  ostringstream s;
  s << c;
  ASSERT_EQ(s.str(), "*");
}

/**
 * Test ConwayCell. Cell should be dead after evolve
 */
TEST(ConwayFixture, test15) {
  ConwayCell c(true, '*');
  c.evolve(dead);

  ASSERT_EQ(c.isCellAlive(), false);
}

/**
 * Test ConwayCell. Cell should be dead after evolve the second evolve
 */
TEST(ConwayFixture, test16) {
  ConwayCell c(false, '.');
  c.evolve(alive);
  ASSERT_EQ(c.isCellAlive(), true);
  c.evolve(dead);
  ASSERT_EQ(c.isCellAlive(), false);
}

TEST(ConwayFixture, test17) {
  ConwayCell c1(true, '*');
  ConwayCell c2(c1);
  ASSERT_EQ(true, c2.isCellAlive());
  ASSERT_EQ('*', c2.rep);
}

TEST(ConwayFixture, test18) {
  ConwayCell c1(false, '.');
  ConwayCell c2(c1);
  ASSERT_EQ(false, c2.isCellAlive());
  ASSERT_EQ('.', c2.rep);
}

TEST(ConwayFixture, test19) {
  ConwayCell c1(true, '*');
  ConwayCell c2(false, '.');

  c2 = c1;
  ASSERT_EQ(true, c2.isCellAlive());
  ASSERT_EQ('*', c2.rep);
}

TEST(ConwayFixture, test20) {
  ConwayCell c1(false, '.');
  ConwayCell c2(true, '*');

  c2 = c1;
  ASSERT_EQ(false, c2.isCellAlive());
  ASSERT_EQ('.', c2.rep);
}

// ----
// FredkinCell Tests
// ----

/**
 * Test FredkinCell constructor
 */
TEST(FredkinFixture, test1) {
  FredkinCell c(true, '0');
  ASSERT_EQ(c.isCellAlive(), true);
  ASSERT_EQ(c.age, 0);
}

/**
 * Test FredkinCell constructor
 */
TEST(FredkinFixture, test2) {
  FredkinCell c(false, '-');
  ASSERT_EQ(c.isCellAlive(), false);
  ASSERT_EQ(c.age, 0);
}

/**
 * Test FredkinCell evolve. Cell should become alive and age shouldn't change
 */
TEST(FredkinFixture, test3) {
  FredkinCell c(false, '-');
  c.evolve(alive);

  ASSERT_EQ(c.isCellAlive(), true);
  ASSERT_EQ(c.age, 0);
}

/**
 * Test FredkinCell evolve. Cell should become alive and age should change
 */
TEST(FredkinFixture, test4) {
  FredkinCell c(true, '0');
  c.evolve(alive);

  ASSERT_EQ(c.isCellAlive(), true);
  ASSERT_EQ(c.age, 1);
}

/**
 * Test FredkinCell evolve twice. FredkinCell should try to evolve
 */
TEST(FredkinFixture, test5) {
  FredkinCell c(true, '0');
  c.evolve(alive);
  AbstractCell *tmp = c.evolve(alive);
  ASSERT_NE(tmp, nullptr);
  delete tmp;

  ASSERT_EQ(c.isCellAlive(), true);
  ASSERT_EQ(c.age, 2);
}

/**
 * Test FredkinCell clone method
 */
TEST(FredkinFixture, test6) {
  FredkinCell c(true, '0');
  ASSERT_EQ(c.clone(), nullptr);
}

/**
 * Test FredkinCell evolve 10 times. << should return a '+'
 */
TEST(FredkinFixture, test7) {
  FredkinCell c(true, '0');
  c.evolve(alive);
  AbstractCell *tmp = c.evolve(alive);
  delete tmp;
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);

  ostringstream s;
  s << c;
  ASSERT_EQ(s.str(), "+");
}

/**
 * Test FredkinCell evolve 10 times. Age should be 10
 */
TEST(FredkinFixture, test8) {
  FredkinCell c(true, '0');
  c.evolve(alive);
  AbstractCell *tmp = c.evolve(alive);
  delete tmp;
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);

  ASSERT_EQ(c.age, 10);
}

/**
 * Test FredkinCell. Cell should be dead after evolve
 */
TEST(FredkinFixture, test9) {
  FredkinCell c(true, '0');
  c.evolve(dead);

  ASSERT_EQ(c.isCellAlive(), false);
}

/**
 * Test FredkinCell. Cell should be dead after evolve the second evolve
 */
TEST(FredkinFixture, test10) {
  FredkinCell c(false, '-');
  c.evolve(alive);
  ASSERT_EQ(c.isCellAlive(), true);
  c.evolve(dead);
  ASSERT_EQ(c.isCellAlive(), false);
}

vector<bool> deadFredkin = {true, false, true, false, false, true, false, true};

/**
 * Test FredkinCell.  FredkinCell shouldn't count top-left, top-right,
 * bottom-left, bottom-right eighbors
 */
TEST(FredkinFixture, test11) {
  FredkinCell c(false, '-');
  c.evolve(alive);
  ASSERT_EQ(c.isCellAlive(), true);
  c.evolve(deadFredkin);
  ASSERT_EQ(c.isCellAlive(), false);
}

vector<bool> deadFredkin2 = {false, false, true,  true,
                             true,  true,  false, false};

/**
 * Test FredkinCell.  FredkinCell shouldn't count top-left, top-right,
 * bottom-left, bottom-right eighbors
 */
TEST(FredkinFixture, test12) {
  FredkinCell c(false, '-');
  c.evolve(alive);
  ASSERT_EQ(c.isCellAlive(), true);
  c.evolve(deadFredkin2);
  ASSERT_EQ(c.isCellAlive(), false);
}

// vector<bool> deadFredkin = {true, true, false  , true, true, false  , true,
// true};

/**
 * Test FredkinCell.  FredkinCell shouldn't count top-left, top-right,
 * bottom-left, bottom-right eighbors
 */
TEST(FredkinFixture, test13) {
  FredkinCell c(false, '-');
  c.evolve(alive);
  ASSERT_EQ(c.isCellAlive(), true);
  c.evolve(deadFredkin);
  ASSERT_EQ(c.isCellAlive(), false);
}

TEST(FredkinFixture, test14) {
  FredkinCell c(true, '+');
  c.evolve(alive);
  AbstractCell *tmp = c.evolve(alive);
  delete tmp;
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);

  ostringstream s;
  s << c;
  ASSERT_EQ(s.str(), "+");
}

TEST(FredkinFixture, test15) {
  FredkinCell c(true, '-');
  c.evolve(alive);
  AbstractCell *tmp = c.evolve(alive);
  delete tmp;
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);

  ostringstream s;
  s << c;
  ASSERT_EQ(s.str(), "9");
}

TEST(FredkinFixture, test16) {
  FredkinCell c(true, '-');
  c.evolve(alive);
  AbstractCell *tmp = c.evolve(alive);
  delete tmp;
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);

  ostringstream s;
  s << c;
  ASSERT_EQ(s.str(), "+");
}

/**
 * Test FredkinCell evolve 9 times. << should return a '9'
 */
TEST(FredkinFixture, test17) {
  FredkinCell c(true, '0');
  c.evolve(alive);
  AbstractCell *tmp = c.evolve(alive);
  delete tmp;
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);
  c.evolve(alive);

  ostringstream s;
  s << c;
  ASSERT_EQ(s.str(), "9");
}