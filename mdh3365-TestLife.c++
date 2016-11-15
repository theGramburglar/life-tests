// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#define TESTING

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, construct_width) {
    ConwayCell* ptr = new ConwayCell(true);
    vector<Cell> l(1);
    l[0] = Cell(ptr);
    vector<vector<Cell>> li(1);
    li[0] = l;

    Life<Cell> x(3,7, li);
    ASSERT_EQ(x.width, 3);
    delete ptr;
}
TEST(LifeFixture, construct_height) {
ConwayCell* ptr = new ConwayCell(true);
vector<Cell> l(1);
l[0] = Cell(ptr);
vector<vector<Cell>> li(1);
li[0] = l;

Life<Cell> x(4,9, li);
ASSERT_EQ(x.height, 9);
delete ptr;
}



//-------------------------
// Conway
//-------------------------


TEST(ConwayFixture, neighbors_right) {
ConwayCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(1, 0);

ASSERT_EQ(li[0], tested_neighbor);
}

TEST(ConwayFixture, neighbors_top_right) {
ConwayCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(1, -1);

ASSERT_EQ(li[6], tested_neighbor);
}

TEST(ConwayFixture, neighbors_bottom_right) {
ConwayCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(1, 1);

ASSERT_EQ(li[2], tested_neighbor);
}

TEST(ConwayFixture, neighbors_left) {
ConwayCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(-1, 0);

ASSERT_EQ(li[4], tested_neighbor);
}

TEST(ConwayFixture, neighbors_top_left) {
ConwayCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(-1, -1);

ASSERT_EQ(li[5], tested_neighbor);
}

TEST(ConwayFixture, neighbors_bottom_left) {
ConwayCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(-1, 1);

ASSERT_EQ(li[7], tested_neighbor);
}

TEST(ConwayFixture, neighbors_top) {
ConwayCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(0, -1);

ASSERT_EQ(li[3], tested_neighbor);
}

TEST(ConwayFixture, neighbors_bottom) {
ConwayCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(0, 1);

ASSERT_EQ(li[1], tested_neighbor);
}

TEST(ConwayFixture, alive_constructed_default_true) {
ConwayCell c;
ASSERT_TRUE(c.is_alive());
}

TEST(ConwayFixture, alive_constructed_true) {
ConwayCell c(true);
ASSERT_TRUE(c.is_alive());
}

TEST(ConwayFixture, alive_constructed_false) {
ConwayCell c(false);
ASSERT_FALSE(c.is_alive());
}

TEST(ConwayFixture, evolve_alive_min) {
ConwayCell c(true);
c.evolve(0);
ASSERT_FALSE(c.is_alive());
}
TEST(ConwayFixture, evolve_alive_less) {
ConwayCell c(true);
c.evolve(1);
ASSERT_FALSE(c.is_alive());
}
TEST(ConwayFixture, evolve_alive_two) {
ConwayCell c(true);
c.evolve(2);
ASSERT_TRUE(c.is_alive());
}
TEST(ConwayFixture, evolve_alive_three) {
ConwayCell c(true);
c.evolve(3);
ASSERT_TRUE(c.is_alive());
}
TEST(ConwayFixture, evolve_alive_more) {
ConwayCell c(true);
c.evolve(4);
ASSERT_FALSE(c.is_alive());
}
TEST(ConwayFixture, evolve_alive_max) {
ConwayCell c(true);
c.evolve(8);
ASSERT_FALSE(c.is_alive());
}

TEST(ConwayFixture, evolve_dead_min) {
ConwayCell c(false);
c.evolve(0);
ASSERT_FALSE(c.is_alive());
}
TEST(ConwayFixture, evolve_dead_less) {
ConwayCell c(false);
c.evolve(2);
ASSERT_FALSE(c.is_alive());
}
TEST(ConwayFixture, evolve_dead_three) {
ConwayCell c(false);
c.evolve(3);
ASSERT_TRUE(c.is_alive());
}
TEST(ConwayFixture, evolve_dead_more) {
ConwayCell c(false);
c.evolve(4);
ASSERT_FALSE(c.is_alive());
}
TEST(ConwayFixture, evolve_dead_max) {
ConwayCell c(false);
c.evolve(8);
ASSERT_FALSE(c.is_alive());
}

TEST(ConwayFixture, print_alive) {
ConwayCell c(true);
ASSERT_EQ("*", c.to_string());
}
TEST(ConwayFixture, print_dead) {
ConwayCell c(false);
ASSERT_EQ(".", c.to_string());
}

TEST(ConwayFixture, print_alive_to_dead) {
ConwayCell c(true);
ASSERT_EQ("*", c.to_string());

c.evolve(1);
ASSERT_EQ(".", c.to_string());
}

TEST(ConwayFixture, print_dead_to_alive) {
ConwayCell c(false);
ASSERT_EQ(".", c.to_string());

c.evolve(3);
ASSERT_EQ("*", c.to_string());
}

TEST(ConwayFixture, clone) {
  ConwayCell c(true);
  AbstractCell * clo = c.clone();

  ASSERT_NE(nullptr, dynamic_cast<ConwayCell *>(clo));
  delete clo;
}
TEST(ConwayFixture, clone_alive) {
  ConwayCell c(true);
  AbstractCell * clo = c.clone();

  ASSERT_TRUE(dynamic_cast<ConwayCell *>(clo)->is_alive());
  delete clo;
}
TEST(ConwayFixture, clone_dead) {
  ConwayCell c(false);
  AbstractCell * clo = c.clone();

  ASSERT_FALSE(dynamic_cast<ConwayCell *>(clo)->is_alive());
  delete clo;
}
TEST(ConwayFixture, clone_diff) {
  ConwayCell c(false);
  AbstractCell * clo = c.clone();

  ASSERT_NE(&c, dynamic_cast<ConwayCell *>(clo));
  delete clo;
}

//-------------------------
// Fredkin
//-------------------------


TEST(FredkinFixture, neighbors_right) {
FredkinCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(1, 0);

ASSERT_EQ(li[0], tested_neighbor);
}


TEST(FredkinFixture, neighbors_left) {
FredkinCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(-1, 0);

ASSERT_EQ(li[2], tested_neighbor);
}

TEST(FredkinFixture, neighbors_top) {
FredkinCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(0, -1);

ASSERT_EQ(li[3], tested_neighbor);
}

TEST(FredkinFixture, neighbors_bottom) {
FredkinCell c;
vector<pair<int, int>> li = c.neighbors(pair<int,int>(0,0));

pair<int, int> tested_neighbor(0, 1);

ASSERT_EQ(li[1], tested_neighbor);
}

TEST(FredkinFixture, alive_constructed_default_true) {
FredkinCell c;
ASSERT_TRUE(c.is_alive());
}

TEST(FredkinFixture, alive_constructed_true) {
FredkinCell c(true);
ASSERT_TRUE(c.is_alive());
}

TEST(FredkinFixture, alive_constructed_false) {
FredkinCell c(false);
ASSERT_FALSE(c.is_alive());
}

TEST(FredkinFixture, evolve_born_alone) {
  FredkinCell c(true, 0);
  
  c.evolve(0);

  ASSERT_FALSE(c.is_alive());
  ASSERT_EQ(c.age, 0);
}
TEST(FredkinFixture, evolve_born_neighbor) {
FredkinCell c(true, 0);

c.evolve(1);

ASSERT_TRUE(c.is_alive());
ASSERT_EQ(c.age, 1);
}

TEST(FredkinFixture, evolve_born_dead_alone) {
FredkinCell c(false, 0);

c.evolve(0);

ASSERT_FALSE(c.is_alive());
ASSERT_EQ(c.age, 0);
}

TEST(FredkinFixture, evolve_born_dead_neighbor) {
FredkinCell c(false, 0);

c.evolve(1);

ASSERT_TRUE(c.is_alive());
ASSERT_EQ(c.age, 0);
}

TEST(FredkinFixture, evolve_dead_age_four_neighbors) {
FredkinCell c(false, 0);

c.evolve(4);

ASSERT_FALSE(c.is_alive());
ASSERT_EQ(c.age, 0);
}
TEST(FredkinFixture, evolve_born_age_four_neighbors) {
FredkinCell c(true, 0);

c.evolve(4);

ASSERT_FALSE(c.is_alive());
ASSERT_EQ(c.age, 0);
}

TEST(FredkinFixture, evolve_dead_age_three_neighbors) {
FredkinCell c(false, 0);

c.evolve(3);

ASSERT_TRUE(c.is_alive());
ASSERT_EQ(c.age, 0);
}
TEST(FredkinFixture, evolve_born_age_three_neighbors) {
FredkinCell c(true, 0);

c.evolve(3);

ASSERT_TRUE(c.is_alive());
ASSERT_EQ(c.age, 1);
}

TEST(FredkinFixture, evolve_alive_aged_increment_three) {
FredkinCell c(true, 1);

c.evolve(3);

ASSERT_TRUE(c.is_alive());
ASSERT_EQ(c.age, 2);
}

TEST(FredkinFixture, evolve_dead_age_stay) {
FredkinCell c(false, 1);

c.evolve(1);

ASSERT_TRUE(c.is_alive());
ASSERT_EQ(c.age, 1);
}

TEST(FredkinFixture, evolve_into_conway) {
  FredkinCell c(true,1);

  ASSERT_NE(nullptr, c.evolve(3));
}
TEST(FredkinFixture, evolve_not_into_conway_dead) {
FredkinCell c(false,1);

ASSERT_EQ(nullptr, c.evolve(3));
}

TEST(FredkinFixture, evolve_not_into_conway_dies) {
FredkinCell c(false,1);

ASSERT_EQ(nullptr, c.evolve(1));
}
TEST(FredkinFixture, evolve_not_into_conway_low) {
FredkinCell c(true,0);

ASSERT_EQ(nullptr, c.evolve(3));
}

TEST(FredkinFixture, print_alive_new) {
FredkinCell c(true);

ASSERT_EQ("0", c.to_string());
}

TEST(FredkinFixture, print_alive_nine) {
FredkinCell c(true, 9);

ASSERT_EQ("9", c.to_string());
}

TEST(FredkinFixture, print_alive_ten) {
FredkinCell c(true, 10);

ASSERT_EQ("+", c.to_string());
}

TEST(FredkinFixture, print_alive_big) {
FredkinCell c(true, 300);

ASSERT_EQ("+", c.to_string());
}

TEST(FredkinFixture, print_dead_new) {
FredkinCell c(false);

ASSERT_EQ("-", c.to_string());
}

TEST(FredkinFixture, print_dead_nine) {
FredkinCell c(false, 9);

ASSERT_EQ("-", c.to_string());
}

TEST(FredkinFixture, print_dead_ten) {
FredkinCell c(false, 10);

ASSERT_EQ("-", c.to_string());
}

TEST(FredkinFixture, print_dead_big) {
FredkinCell c(false, 300);

ASSERT_EQ("-", c.to_string());
}

TEST(FredkinFixture, clone) {
  FredkinCell c(true);
  AbstractCell * clo = c.clone();

  ASSERT_NE(nullptr, dynamic_cast<FredkinCell *>(clo));
  delete clo;
}
TEST(FredkinFixture, clone_alive) {
  FredkinCell c(true);
  AbstractCell * clo = c.clone();

  ASSERT_TRUE(dynamic_cast<FredkinCell *>(clo)->is_alive());
  delete clo;
}
TEST(FredkinFixture, clone_dead) {
  FredkinCell c(false);
  AbstractCell * clo = c.clone();

  ASSERT_FALSE(dynamic_cast<FredkinCell *>(clo)->is_alive());
  delete clo;
}
TEST(FredkinFixture, clone_diff) {
  FredkinCell c(false);
  AbstractCell * clo = c.clone();

  ASSERT_NE(&c, dynamic_cast<FredkinCell *>(clo));
  delete clo;
}
TEST(FredkinFixture, clone_age) {
  FredkinCell c(true, 3);
  AbstractCell * clo = c.clone();

  ASSERT_EQ(3, dynamic_cast<FredkinCell *>(clo)->age);
  delete clo;
}

//----------
// CELL
//----------

TEST(CellFixture, neighbors_conway) {
  ConwayCell w;
  Cell c(&w);

  vector<pair<int, int>> li_w = w.neighbors(pair<int,int>(0,0));
  vector<pair<int, int>> li_c = w.neighbors(pair<int,int>(0,0));

  ASSERT_EQ(li_w, li_c);
}
TEST(CellFixture, neighbors_fredkin) {
FredkinCell w;
Cell c(&w);

vector<pair<int, int>> li_w = w.neighbors(pair<int,int>(0,0));
vector<pair<int, int>> li_c = w.neighbors(pair<int,int>(0,0));

ASSERT_EQ(li_w, li_c);
}

TEST(CellFixture, is_alive_fredkin) {
FredkinCell w;
Cell c(&w);

bool li_w = w.is_alive();
bool li_c = c.is_alive();

ASSERT_EQ(li_w, li_c);
}
TEST(CellFixture, is_alive_conway) {
ConwayCell w;
Cell c(&w);

bool li_w = w.is_alive();
bool li_c = c.is_alive();

ASSERT_EQ(li_w, li_c);
}
TEST(CellFixture, evolve_conway) {
ConwayCell w;
Cell c(&w);

c.evolve(2);

ASSERT_NE(nullptr, dynamic_cast<ConwayCell *>(c.p));
ASSERT_EQ(nullptr, dynamic_cast<FredkinCell *>(c.p));
}
TEST(CellFixture, evolve_fredkin_to_conway) {
FredkinCell w(true,1);
Cell c(&w);

c.evolve(3);

ASSERT_NE(nullptr, dynamic_cast<ConwayCell *>(c.p));
ASSERT_EQ(nullptr, dynamic_cast<FredkinCell *>(c.p));
}
TEST(CellFixture, evolve_fredkin) {
FredkinCell w(true);
Cell c(&w);

c.evolve(3);

ASSERT_EQ(nullptr, dynamic_cast<ConwayCell *>(c.p));
ASSERT_NE(nullptr, dynamic_cast<FredkinCell *>(c.p));
}

TEST(CellFixture, copy_constructor) {
  ConwayCell * ptr = new ConwayCell();
  Cell c(ptr);
  Cell copy(c);

  ASSERT_NE(copy.p, c.p);
  ASSERT_NE(copy.p, nullptr);
  delete ptr;
}