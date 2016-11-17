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
#include <fstream>
#include <string>
#include <sstream>

#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, test_conway_constructor) {
    ConwayCell c;
    ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, test_conway_constructor1) {
    ConwayCell c;
    c.changeState();
    ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, test_conway_constructor2) {
    ConwayCell c;
    c.changeState();
    c.changeState();
    ASSERT_TRUE(!c.isAlive());
}


TEST(LifeFixture, test_conway_constructor3) {
    ConwayCell c('.');
    ASSERT_TRUE(!c.isAlive());
}


TEST(LifeFixture, test_conway_constructor4) {
    ConwayCell c('*');
    ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, test_conway_constructor5) {
 	ConwayCell c('*');
    c.changeState();
    ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, test_conway_constructor6) {
 	ConwayCell c('*');
    c.changeState();
    c.changeState();
    ASSERT_TRUE(c.isAlive());
}


TEST(LifeFixture, test_conway_copy) {
    ConwayCell c('*');
    ConwayCell d(c);

    ASSERT_TRUE(d.isAlive());
}

TEST(LifeFixture, test_conway_copy1) {
    ConwayCell c('*');
    c.changeState();
    ConwayCell d(c);

    ASSERT_TRUE(!d.isAlive());
}

TEST(LifeFixture, test_conway_copy2) {
    ConwayCell c('*');
    c.changeState();
    ConwayCell d(c);
    d.changeState();

    ASSERT_TRUE(d.isAlive());
}

TEST(LifeFixture, test_conway_copy3) {
    ConwayCell c('*');
    c.changeState();
    ConwayCell d(c);
    d.changeState();
    d.changeState();
    ASSERT_TRUE(!d.isAlive());
}


TEST(LifeFixture, test_conway_evolution) {
    ConwayCell c;
    
    ASSERT_TRUE(c.evolution(3));
}

TEST(LifeFixture, test_conway_evolution1) {
    ConwayCell c('*');
    
    ASSERT_FALSE(c.evolution(3));
}
TEST(LifeFixture, test_conway_evolution3) {
    ConwayCell c('.');
    
    ASSERT_TRUE(c.evolution(3));
}


TEST(LifeFixture, test_conway_evolution2) {
    ConwayCell c('*');
    
    ASSERT_TRUE(c.evolution(4));
}


TEST(LifeFixture, test_conway_findstate) {
    ConwayCell c('*');
    char d = c.findState();
    ASSERT_EQ(d, '*');
}


TEST(LifeFixture, test_conway_findstate1) {
    ConwayCell c('.');
    char d = c.findState();
    ASSERT_EQ(d, '.');
}

TEST(LifeFixture, test_conway_findstate2) {
    ConwayCell c('.');

    c.changeState();
    char d = c.findState();
    ASSERT_EQ(d, '*');
}


TEST(LifeFixture, test_conway_clone) {
    ConwayCell c('.');

    AbstractCell* d = c.clone();
    ConwayCell* f = dynamic_cast<ConwayCell*>(d);
     delete f;
     ASSERT_TRUE(f != nullptr);
}


TEST(LifeFixture, test_conway_clone1) {
    ConwayCell c('.');

    AbstractCell* d = c.clone();
    FredkinCell* f = dynamic_cast<FredkinCell*>(d);
     delete f;
     delete d;
     ASSERT_TRUE(f == nullptr);
}

TEST(LifeFixture, test_conway_clone2) {
    ConwayCell c('*');
    ConwayCell d(c);
    AbstractCell* e = d.clone();
    ConwayCell* f = dynamic_cast<ConwayCell*>(e);
   	delete f;
     ASSERT_TRUE(f != nullptr);
}

TEST(LifeFixture, test_fredkin_constructor) {
    FredkinCell c;
    ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, test_fredkin_constructor1) {
    FredkinCell c;
    c.changeState();
    ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, test_fredkin_constructor2) {
    FredkinCell c;
    c.changeState();
    c.changeState();
    ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, test_fredkin_constructor3) {
    FredkinCell c('+');
    ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, test_fredkin_constructor4) {
    FredkinCell c('8');
    ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, test_fredkin_constructor5) {
    FredkinCell c('/');
    ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, test_fredkin_constructor6) {
    FredkinCell c('0');
    ASSERT_TRUE(c.isAlive());
}


TEST(LifeFixture, test_fredkin_constructor7) {
    FredkinCell c('+');
    c.changeState();
    ASSERT_TRUE(!c.isAlive());
}

TEST(LifeFixture, test_fredkin_constructor8) {
    FredkinCell c('+');
    c.changeState();
    c.changeState();
    ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, test_fredkin_constructor9) {
    FredkinCell c('9');
    c.changeState();
    ASSERT_TRUE(!c.isAlive());
}


TEST(LifeFixture, test_fredkin_copy) {
    FredkinCell c('9');
    FredkinCell d(c);
    ASSERT_TRUE(d.isAlive());
}


TEST(LifeFixture, test_fredkin_copy1) {
    FredkinCell c('9');
    FredkinCell d(c);
    d.changeState();
    ASSERT_TRUE(!d.isAlive());
}


TEST(LifeFixture, test_fredkin_copy2) {
    FredkinCell c('9');
    c.changeState();
    FredkinCell d(c);
    ASSERT_TRUE(!d.isAlive());
}

TEST(LifeFixture, test_fredkin_copy3) {
    FredkinCell c('9');
    c.changeState();
    FredkinCell d(c);
    d.changeState();
    ASSERT_TRUE(d.isAlive());
}

TEST(LifeFixture, test_fredkin_evolution) {
    FredkinCell c('9');
   	
    ASSERT_FALSE(c.evolution(1));
}

TEST(LifeFixture, test_fredkin_evolution1) {
    FredkinCell c('9');
   	
    ASSERT_TRUE(c.evolution(2));
}


TEST(LifeFixture, test_fredkin_evolution2) {
    FredkinCell c('9');
   	
    ASSERT_FALSE(c.evolution(5));
}


TEST(LifeFixture, test_fredkin_age) {
    FredkinCell c('2');
   	
    ASSERT_TRUE(c.checkAge());
}

TEST(LifeFixture, test_fredkin_age1) {
    FredkinCell c('3');
   	
    ASSERT_TRUE(!c.checkAge());
}

TEST(LifeFixture, test_fredkin_age2) {
    FredkinCell c('+');
   	
    ASSERT_TRUE(!c.checkAge());
}

TEST(LifeFixture, test_fredkin_findstate) {
    FredkinCell c('6');
    char d = c.findState();
   	
    ASSERT_EQ(d, '6');
}

TEST(LifeFixture, test_fredkin_findstate1) {
    FredkinCell c('/');
    char d = c.findState();
    ASSERT_EQ(d, '-');
}

TEST(LifeFixture, test_fredkin_findstate2) {
    FredkinCell c('0');
    char d = c.findState();
    ASSERT_EQ(d, '0');
}

TEST(LifeFixture, test_fredkin_clone) {
    FredkinCell c('8');
    AbstractCell* d = c.clone();
    FredkinCell* f = dynamic_cast<FredkinCell*>(d);
    delete f;
    ASSERT_TRUE(f != nullptr);
}
TEST(LifeFixture, test_fredkin_clone1) {
    FredkinCell c('8');
    AbstractCell* d = c.clone();
    ConwayCell* f = dynamic_cast<ConwayCell*>(d);
    delete f;
    delete d;
    ASSERT_TRUE(f == nullptr);
}
TEST(LifeFixture, test_fredkin_clone2) {
    FredkinCell c('8');
    FredkinCell g(c);
    AbstractCell* d = g.clone();
    FredkinCell* f = dynamic_cast<FredkinCell*>(d);

    delete f;
    ASSERT_TRUE(f != nullptr);
}

TEST(LifeFixture, test_cell_constructor){
   ConwayCell c('*');
   AbstractCell* p = c.clone();
   Cell d(p);
   ASSERT_TRUE(d.isAlive());

}

TEST(LifeFixture, test_cell_constructor1){
   FredkinCell d('2');
   AbstractCell* p = d.clone();
   Cell f(p);
   ASSERT_TRUE(f.isAlive());

}

TEST(LifeFixture, test_cell_constructor2){
   ConwayCell c('.');
   AbstractCell* p = c.clone();
   Cell f(p);
   ASSERT_TRUE(!f.isAlive());

}


TEST(LifeFixture, test_cell_constructor3){
   FredkinCell d('/');
   AbstractCell* p = d.clone();
   Cell c(p);
   ASSERT_TRUE(!c.isAlive());

}

TEST(LifeFixture, test_cell_constructor4){
   FredkinCell d('/');
   AbstractCell* p = d.clone();
   p->changeState();
   Cell c(p);
   ASSERT_TRUE(c.isAlive());

}


TEST(LifeFixture, test_cell_constructor5){
   ConwayCell c('.');
   AbstractCell* p = c.clone();
   p->changeState();
   Cell f(p);
   ASSERT_TRUE(f.isAlive());

}


TEST(LifeFixture, test_cell_constructor6){
   Cell f('*');
   ASSERT_TRUE(f.isAlive());

}


TEST(LifeFixture, test_cell_constructor7){
   Cell f('.');
   ASSERT_TRUE(!f.isAlive());

}

TEST(LifeFixture, test_cell_constructor8){
   Cell f('8');
   ASSERT_TRUE(f.isAlive());

}


TEST(LifeFixture, test_cell_constructor9){
   Cell f('/');
   ASSERT_TRUE(!f.isAlive());

}

TEST(LifeFixture, test_cell_constructor10){
   Cell f('*');
   f.changeState();
   ASSERT_TRUE(!f.isAlive());

}


TEST(LifeFixture, test_cell_constructor11){
   Cell f('2');
   f.changeState();
   ASSERT_TRUE(!f.isAlive());

}


TEST(LifeFixture, test_cell_copy_constructor){
   Cell f('*');
   Cell d(f);
   ASSERT_TRUE(d.isAlive());

}


TEST(LifeFixture, test_cell_copy_constructor1){
   Cell f('2');
   Cell d(f);
   ASSERT_TRUE(d.isAlive());

}


TEST(LifeFixture, test_cell_copy_constructor2){
   Cell f('/');
   Cell d(f);
   ASSERT_TRUE(!d.isAlive());

}


TEST(LifeFixture, test_cell_copy_assignment){
   Cell f('*');
   Cell d('.');
   d = f;
   ASSERT_TRUE(d.isAlive());

}


TEST(LifeFixture, test_cell_copy_assignment1){
   Cell f('*');
   Cell d('.');
   d = f;
   d.changeState();
   ASSERT_TRUE(!d.isAlive());

}


TEST(LifeFixture, test_cell_copy_assignment2){
   Cell f('*');
   Cell d('.');
   Cell e('*');
   d = f;
   d = e;
   ASSERT_TRUE(d.isAlive());

}

TEST(LifeFixture, test_cell_evolution){
   Cell f('*');
   ASSERT_FALSE(f.evolution(3));

}


TEST(LifeFixture, test_cell_evolution2){
   Cell f('.');
   ASSERT_TRUE(f.evolution(3));

}

TEST(LifeFixture, test_cell_evolution3){
   Cell f('2');
   ASSERT_TRUE(f.evolution(2));

}

TEST(LifeFixture, test_cell_isalive){
   Cell f('2');
   ASSERT_TRUE(f.isAlive());

}

TEST(LifeFixture, test_cell_isalive1){
   Cell f('*');
   ASSERT_TRUE(f.isAlive());

}

TEST(LifeFixture, test_cell_isalive2){
   Cell f('/');
   ASSERT_TRUE(!f.isAlive());

}

TEST(LifeFixture, test_cell_findstate){
   Cell f('2');
   char d = f.findState();
   ASSERT_EQ(d, '2');

}

TEST(LifeFixture, test_cell_findstate1){
   Cell f('*');
   char d = f.findState();
   ASSERT_EQ(d, '*');

}

TEST(LifeFixture, test_cell_findstate2){
   Cell f('-');
   char d = f.findState();
   ASSERT_EQ(d, '-');

}


TEST(LifeFixture, test_cell_changestate){
   Cell f('.');
   f.changeState();
   ASSERT_TRUE(f.isAlive());

}

TEST(LifeFixture, test_cell_changestate1){
   Cell f('*');
   f.changeState();
   ASSERT_TRUE(!f.isAlive());

}

TEST(LifeFixture, test_cell_changestate2){
   Cell f('2');
   f.changeState();
   f.changeState();
   ASSERT_TRUE(f.isAlive());

}


TEST(LifeFixture, test_life_constructor){
  istringstream s("1 5\n -----");
   Life<Cell> d(s);
   ASSERT_EQ(d.population, 0);
}


TEST(LifeFixture, test_life_constructor1){
  istringstream s("1 5\n *****");
   Life<Cell> d(s);
   ASSERT_EQ(d.population, 5);
}


TEST(LifeFixture, test_life_constructor2){
  istringstream s("1 5\n --*--");
   Life<Cell> d(s);
   ASSERT_EQ(d.grid.size(), 1);
}

TEST(LifeFixture, test_life_constructor3){
  istringstream s("1 5\n -**--");
   Life<Cell> d(s);
   ASSERT_EQ(d.population, 2);
}

TEST(LifeFixture, test_life_constructor4){
  istringstream s("1 5\n --1--");
   Life<Cell> d(s);
   ASSERT_EQ(d.population, 1);
}

TEST(LifeFixture, test_life_constructor5){
  istringstream s("1 5\n -----");
   Life<Cell> d(s);
   ASSERT_EQ(d.population, 0);
}


TEST(LifeFixture, test_life_copyconstructor){
  istringstream s("1 5\n --*--");
   Life<Cell> d(s);
   Life<Cell> f(d);
   ASSERT_EQ(f.grid.size(), 1);
}


TEST(LifeFixture, test_life_copyconstructor2){
  istringstream s("1 5\n --**-");
   Life<Cell> d(s);
   Life<Cell> f(d);
   ASSERT_EQ(f.population, 2);
}


TEST(LifeFixture, test_life_copyconstructor3){
  istringstream s("1 5\n -123-");
   Life<Cell> d(s);
   Life<Cell> f(d);
   ASSERT_EQ(f.population, 3);
}


TEST(LifeFixture, test_life_copyconstructor4){
  istringstream s("1 5\n --*--");
   Life<Cell> d(s);
   Life<Cell> f(d);
   ASSERT_EQ(f.grid.size(), 1);
}


TEST(LifeFixture, test_life_copyconstructor5){
  istringstream s("1 5\n -----");
   Life<Cell> d(s);
   Life<Cell> f(d);
   ASSERT_EQ(f.population, 0);
}

TEST(LifeFixture, test_life_copyassignment){
  istringstream s("1 5\n -----");
   istringstream e("1 5\n -**--");
   Life<Cell> d(s);
   Life<Cell> f(e);
   f = d;
   ASSERT_EQ(f.population, 0);
}
TEST(LifeFixture, test_life_copyassignment1){
  istringstream s("1 5\n -----");
   istringstream e("1 5\n -**--");
   Life<Cell> d(s);
   Life<Cell> f(e);
   f = d;
   ASSERT_EQ(f.population, 0);
}

TEST(LifeFixture, test_life_copyassignment2){
  istringstream s("1 5\n -**--");
   istringstream e("1 5\n -----");
   Life<Cell> d(s);
   Life<Cell> f(e);
   f = d;
   ASSERT_EQ(f.population, 2);
}

TEST(LifeFixture, test_life_countneighbors){
  istringstream s("2 5\n -**--\n-----");
    Life<Cell> d(s);
    int neighbors = d.countNeighbors(0, 2, 2, 5);
   ASSERT_EQ(neighbors, 1);
}

TEST(LifeFixture, test_life_countneighbors1){
  istringstream s("2 5\n -*---\n-----");
    Life<Cell> d(s);
    int neighbors = d.countNeighbors(0, 1, 2, 5);
   ASSERT_EQ(neighbors, 0);
}
TEST(LifeFixture, test_life_countneighbors2){
  istringstream s("2 5\n -**--\n-*---");
    Life<Cell> d(s);
    int neighbors = d.countNeighbors(0, 2, 2, 5);
   ASSERT_EQ(neighbors, 2);
}

TEST(LifeFixture, test_life_executeboard){
  istringstream s("1 5\n .**..");
    Life<ConwayCell> d(s);
    d.executeBoard(1);
  //  cout << d;
   ASSERT_EQ(d.population, 0);
}

TEST(LifeFixture, test_life_executeboard1){
  istringstream s("1 5\n --2--");
    Life<FredkinCell> d(s);
    d.executeBoard(1);
  //  cout << d;
   ASSERT_EQ(d.population, 2);
}

TEST(LifeFixture, test_life_executeboard2){
  istringstream s("1 5\n -**--");
    Life<Cell> d(s);
    d.executeBoard(1);
  //  cout << d;

   ASSERT_EQ(d.population, 2);
}
TEST(LifeFixture, test_life_executeboard3){
  istringstream s("1 5\n -**--");
    Life<Cell> d(s);
    d.executeBoard(2);
  //  cout << d;

   ASSERT_EQ(d.population, 1);
}

TEST(LifeFixture, test_life_executeboard4){
  istringstream s("1 5\n .**-.");
    Life<Cell> d(s);
    d.executeBoard(5);
  //  cout << d;

   ASSERT_EQ(d.population, 0);
}

TEST(LifeFixture, test_life_executeboard5){
  istringstream s("1 5\n -**3-");
    Life<Cell> d(s);
    d.executeBoard(7);
  //  cout << d;

   ASSERT_EQ(d.population, 1);
}
