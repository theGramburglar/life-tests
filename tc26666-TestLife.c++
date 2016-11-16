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

/**
 * A testing class that provides access to
 * private data members inside Life.h
 */
class LifeFixture : public ::testing::Test {
protected:
  template <typename T> std::vector<T> &getGrid(Life<T> &l) { return l._grid; }
  unsigned int getAge(const FredkinCell &f) { return f._age; }
  bool isDead(const AbstractCell &a) { return a._alive ? false : true; }
  AbstractCell *getP(const Cell &c) { return c._p; }
};

/* Cell constructor, destructor, and copy assignment
 * check valgrind output for these */
TEST_F(LifeFixture, test_cell_1) {
  AbstractCell *p = new FredkinCell(true);
  Cell g(p);
  delete p;
}

TEST_F(LifeFixture, test_cell_2) {
  AbstractCell *p = new ConwayCell(true);
  Cell g(p);
  delete p;
}

TEST_F(LifeFixture, test_cell_3) {
  Cell c;
  Cell d(c);
}

TEST_F(LifeFixture, test_cell_4) {
  AbstractCell *p = new FredkinCell(true);
  Cell g(p);

  Cell d;
  d = g;
  delete p;
}

/* >>/<< overload */
TEST_F(LifeFixture, test_life_read_1) {
  Life<ConwayCell> x;
  istringstream i("3 3\n...\n***\n...\n");
  std::string s("...\n***\n...\n\n");
  ostringstream o("");
  i >> x;
  o << x;
  ASSERT_EQ(s, o.str());
}

TEST_F(LifeFixture, test_life_read_2) {
  Life<FredkinCell> x;
  istringstream i("3 3\n---\n000\n---\n");
  std::string s("---\n000\n---\n\n");
  ostringstream o("");
  i >> x;
  o << x;
  ASSERT_EQ(s, o.str());
}

TEST_F(LifeFixture, test_life_read_3) {
  Life<Cell> x;
  istringstream i("3 3\n---\n000\n---\n");
  std::string s("---\n000\n---\n\n");
  ostringstream o("");
  i >> x;
  o << x;
  ASSERT_EQ(s, o.str());
}

/* liveCells() */
TEST_F(LifeFixture, test_liveCells_1) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  ostringstream o("");
  i >> x;
  ASSERT_EQ(9, x.liveCells());
}

TEST_F(LifeFixture, test_liveCells_2) {
  Life<FredkinCell> x;
  istringstream i("3 3\n---\n000\n---\n");
  i >> x;
  ASSERT_EQ(3, x.liveCells());
}

TEST_F(LifeFixture, test_liveCells_3) {
  Life<FredkinCell> x;
  istringstream i("3 3\n0--\n000\n-0-\n");
  i >> x;
  ASSERT_EQ(5, x.liveCells());
}

/* Vote */
TEST_F(LifeFixture, test_vote_1) {
  Life<FredkinCell> x;
  istringstream i("2 2\n00\n00\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[0];
  const unsigned int v = f.vote();
  ASSERT_EQ(v, 1);
}

TEST_F(LifeFixture, test_vote_2) {
  Life<ConwayCell> x;
  istringstream i("2 2\n*.\n..\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[1];
  const unsigned int v = f.vote();
  ASSERT_EQ(v, 0);
}

TEST_F(LifeFixture, test_vote_3) {
  Life<Cell> x;
  istringstream i("2 2\n-0\n00\n");
  i >> x;
  std::vector<Cell> &t = getGrid(x);
  Cell &f = t[1];
  const unsigned int v = f.vote();
  ASSERT_EQ(v, 1);
}

/* Sight */
TEST_F(LifeFixture, test_sight_1) {
  Life<FredkinCell> x;
  istringstream i("2 2\n00\n00\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[0];
  const unsigned int v = f.sight();
  ASSERT_EQ(v, 4);
}

TEST_F(LifeFixture, test_sight_2) {
  Life<ConwayCell> x;
  istringstream i("2 2\n*.\n..\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[0];
  const unsigned int v = f.sight();
  ASSERT_EQ(v, 8);
}

TEST_F(LifeFixture, test_sight_3) {
  Life<Cell> x;
  istringstream i("2 2\n-0\n00\n");
  i >> x;
  std::vector<Cell> &t = getGrid(x);
  Cell &f = t[2];
  const unsigned int v = f.sight();
  ASSERT_EQ(v, 4);
}

/* Neighborhood */
TEST_F(LifeFixture, test_neighborhood_1) {
  Life<FredkinCell> x;
  istringstream i("2 2\n00\n00\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[0];
  const unsigned int v = x.neighborhood(f, 0);
  ASSERT_EQ(v, 2);
}

TEST_F(LifeFixture, test_neighborhood_2) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[1];
  const unsigned int v = x.neighborhood(f, 1);
  ASSERT_EQ(v, 3);
}

TEST_F(LifeFixture, test_neighborhood_3) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[2];
  const unsigned int v = x.neighborhood(f, 2);
  ASSERT_EQ(v, 2);
}

TEST_F(LifeFixture, test_neighborhood_4) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[3];
  const unsigned int v = x.neighborhood(f, 3);
  ASSERT_EQ(v, 3);
}

TEST_F(LifeFixture, test_neighborhood_5) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[4];
  const unsigned int v = x.neighborhood(f, 4);
  ASSERT_EQ(v, 4);
}

TEST_F(LifeFixture, test_neighborhood_6) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[5];
  const unsigned int v = x.neighborhood(f, 5);
  ASSERT_EQ(v, 3);
}

TEST_F(LifeFixture, test_neighborhood_7) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[6];
  const unsigned int v = x.neighborhood(f, 6);
  ASSERT_EQ(v, 2);
}

TEST_F(LifeFixture, test_neighborhood_8) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[7];
  const unsigned int v = x.neighborhood(f, 7);
  ASSERT_EQ(v, 3);
}

TEST_F(LifeFixture, test_neighborhood_9) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[8];
  const unsigned int v = x.neighborhood(f, 8);
  ASSERT_EQ(v, 2);
}

TEST_F(LifeFixture, test_neighborhood_10) {
  Life<FredkinCell> x;
  istringstream i("3 3\n0-0\n000\n0-0\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[4];
  const unsigned int v = x.neighborhood(f, 4);
  ASSERT_EQ(v, 2);
}

TEST_F(LifeFixture, test_neighborhood_11) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[0];
  const unsigned int v = x.neighborhood(f, 0);
  ASSERT_EQ(v, 3);
}

TEST_F(LifeFixture, test_neighborhood_12) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[1];
  const unsigned int v = x.neighborhood(f, 1);
  ASSERT_EQ(v, 5);
}

TEST_F(LifeFixture, test_neighborhood_13) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[2];
  const unsigned int v = x.neighborhood(f, 2);
  ASSERT_EQ(v, 3);
}

TEST_F(LifeFixture, test_neighborhood_14) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[3];
  const unsigned int v = x.neighborhood(f, 3);
  ASSERT_EQ(v, 5);
}

TEST_F(LifeFixture, test_neighborhood_15) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[4];
  const unsigned int v = x.neighborhood(f, 4);
  ASSERT_EQ(v, 8);
}

TEST_F(LifeFixture, test_neighborhood_16) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[5];
  const unsigned int v = x.neighborhood(f, 5);
  ASSERT_EQ(v, 5);
}

TEST_F(LifeFixture, test_neighborhood_17) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[6];
  const unsigned int v = x.neighborhood(f, 6);
  ASSERT_EQ(v, 3);
}

TEST_F(LifeFixture, test_neighborhood_18) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[7];
  const unsigned int v = x.neighborhood(f, 7);
  ASSERT_EQ(v, 5);
}

TEST_F(LifeFixture, test_neighborhood_19) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n***\n***\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[8];
  const unsigned int v = x.neighborhood(f, 8);
  ASSERT_EQ(v, 3);
}

TEST_F(LifeFixture, test_neighborhood_20) {
  Life<ConwayCell> x;
  istringstream i("3 3\n.*.\n.**\n**.\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[4];
  const unsigned int v = x.neighborhood(f, 4);
  ASSERT_EQ(v, 4);
}

TEST_F(LifeFixture, test_neighborhood_21) {
  Life<Cell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<Cell> &t = getGrid(x);
  Cell &f = t[0];
  const unsigned int v = x.neighborhood(f, 0);
  ASSERT_EQ(v, 2);
}

/* Mutate */
TEST_F(LifeFixture, test_mutate_1) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[2];
  ASSERT_FALSE(f.mutate());
}

TEST_F(LifeFixture, test_mutate_2) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[1];
  unsigned int v = x.neighborhood(f, 1);
  f.evolve(v);
  f.evolve(v);
  ASSERT_TRUE(f.mutate());
}

/* Evolve */
TEST_F(LifeFixture, test_evolve_1) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n000\n000\n");
  i >> x;
  std::vector<FredkinCell> &t = getGrid(x);
  FredkinCell &f = t[0];
  unsigned int v = x.neighborhood(f, 0);
  f.evolve(v);
  AbstractCell &a = static_cast<AbstractCell &>(f);
  ASSERT_TRUE(isDead(a));
  ASSERT_EQ(getAge(f), 0);
}

TEST_F(LifeFixture, test_evolve_2) {
  Life<ConwayCell> x;
  istringstream i("3 3\n.*.\n***\n.*.\n");
  i >> x;
  std::vector<ConwayCell> &t = getGrid(x);
  ConwayCell &f = t[0];
  unsigned int v = x.neighborhood(f, 0);
  f.evolve(v);
  AbstractCell &a = static_cast<AbstractCell &>(f);
  ASSERT_FALSE(isDead(a));
}

TEST_F(LifeFixture, test_evolve_3) {
  Life<Cell> x;
  istringstream i("3 3\n000\n0--\n000\n");
  i >> x;
  std::vector<Cell> &t = getGrid(x);
  Cell &f = t[2];
  unsigned int v = x.neighborhood(f, 4);
  f.evolve(v);
  AbstractCell *a = getP(f);
  ASSERT_FALSE(isDead(*a));
  FredkinCell *f1 = dynamic_cast<FredkinCell *>(a);
  ASSERT_EQ(getAge(*f1), 1);
}
/* Generate */
TEST_F(LifeFixture, test_generate_1) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n0-0\n000\n");
  ostringstream o("");
  std::string s("---\n---\n---\n\n");
  i >> x;
  x.generate();
  o << x;
  ASSERT_EQ(o.str(), s);
}

TEST_F(LifeFixture, test_generate_2) {
  Life<FredkinCell> x;
  istringstream i("3 3\n000\n0--\n000\n");
  ostringstream o("");
  std::string s("--1\n-0-\n--1\n\n");
  i >> x;
  x.generate();
  o << x;
  ASSERT_EQ(o.str(), s);
}

TEST_F(LifeFixture, test_generate_3) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n*.*\n***\n");
  ostringstream o("");
  std::string s("*.*\n...\n*.*\n\n");
  i >> x;
  x.generate();
  o << x;
  ASSERT_EQ(o.str(), s);
}

TEST_F(LifeFixture, test_generate_4) {
  Life<ConwayCell> x;
  istringstream i("3 3\n***\n*.*\n***\n");
  ostringstream o("");
  std::string s("*.*\n...\n*.*\n\n");
  i >> x;
  x.generate();
  o << x;
  ASSERT_EQ(o.str(), s);
}

TEST_F(LifeFixture, test_generate_5) {
  Life<ConwayCell> x;
  istringstream i("3 3\n.*.\n***\n.*.\n");
  ostringstream o("");
  std::string s("***\n*.*\n***\n\n");
  i >> x;
  x.generate();
  o << x;
  ASSERT_EQ(o.str(), s);
}
