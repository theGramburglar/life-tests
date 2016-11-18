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
// test
// ----

TEST(ConwayFixture, constructor1) {
    ConwayCell x('*');
    ASSERT_TRUE(x.currentStateAlive);
    ASSERT_TRUE(x.nextStateAlive);
}

TEST(ConwayFixture, constructor2) {
    ConwayCell x('.');
    ASSERT_FALSE(x.currentStateAlive);
    ASSERT_FALSE(x.nextStateAlive);
}

TEST(ConwayFixture, constructor3) {
    ASSERT_THROW(ConwayCell x('?'), invalid_argument);
}

TEST(ConwayFixture, clone1) {
    ConwayCell x('*');
    AbstractCell* y = x.clone();
    ASSERT_NE(&x, y);
    delete y;
}

TEST(ConwayFixture, clone2) {
    ConwayCell x('*');
    AbstractCell* y = x.clone();
    ASSERT_EQ(x.currentStateAlive, y->currentStateAlive);
    ASSERT_EQ(x.nextStateAlive, y->nextStateAlive);
    delete y;
}

TEST(ConwayFixture, determineNext1) {
    ConwayCell x('*');

    ASSERT_TRUE(x.nextStateAlive);

    vector<bool> neighbors(9, true);
    neighbors[4] = false;
    x.determineNext(neighbors);

    ASSERT_FALSE(x.nextStateAlive);
}

TEST(ConwayFixture, determineNext2) {
    ConwayCell x('.');

    ASSERT_FALSE(x.nextStateAlive);

    vector<bool> neighbors(9, false);
    neighbors[0] = neighbors[1] = neighbors[2] = true;
    x.determineNext(neighbors);

    ASSERT_TRUE(x.nextStateAlive);
}

TEST(ConwayFixture, determineNext3) {
    ConwayCell x('*');

    ASSERT_TRUE(x.nextStateAlive);

    vector<bool> neighbors(9, false);
    neighbors[0] = neighbors[1] = neighbors[2] = true;
    x.determineNext(neighbors);

    ASSERT_TRUE(x.nextStateAlive);
}

TEST(ConwayFixture, determineNext4) {
    ConwayCell x('.');

    ASSERT_FALSE(x.nextStateAlive);

    vector<bool> neighbors(9, false);
    x.determineNext(neighbors);

    ASSERT_FALSE(x.nextStateAlive);
}

TEST(ConwayFixture, update1) {
    ConwayCell x('*');

    ASSERT_TRUE(x.currentStateAlive);

    x.nextStateAlive = false;
    x.update();

    ASSERT_FALSE(x.currentStateAlive);
}

TEST(ConwayFixture, update2) {
    ConwayCell x('*');

    ASSERT_TRUE(x.currentStateAlive);
    x.update();
    ASSERT_TRUE(x.currentStateAlive);
}

TEST(ConwayFixture, update3) {
    ConwayCell x('.');

    ASSERT_FALSE(x.currentStateAlive);

    x.nextStateAlive = true;
    x.update();

    ASSERT_TRUE(x.currentStateAlive);
}

TEST(ConwayFixture, update4) {
    ConwayCell x('.');

    ASSERT_FALSE(x.currentStateAlive);
    x.update();
    ASSERT_FALSE(x.currentStateAlive);
}

TEST(ConwayFixture, representation1) {
    ConwayCell x('*');
    ASSERT_EQ(x.representation(), '*');
}

TEST(ConwayFixture, representation2) {
    ConwayCell x('.');
    ASSERT_EQ(x.representation(), '.');
}

TEST(FredkinFixture, constructor1) {
    FredkinCell x('0');
    ASSERT_TRUE(x.currentStateAlive);
    ASSERT_TRUE(x.nextStateAlive);
    ASSERT_EQ(x.age, 0);
    ASSERT_EQ(x.age, 0);
}

TEST(FredkinFixture, constructor2) {
    FredkinCell x('-');
    ASSERT_FALSE(x.currentStateAlive);
    ASSERT_FALSE(x.nextStateAlive);
    ASSERT_EQ(x.age, 0);
    ASSERT_EQ(x.age, 0);
}

TEST(FredkinFixture, constructor3) {
    ASSERT_THROW(ConwayCell x('?'), invalid_argument);
}

TEST(FredkinFixture, clone1) {
    FredkinCell x('0');
    AbstractCell* y = x.clone();
    ASSERT_NE(&x, y);
    delete y;
}

TEST(FredkinFixture, clone2) {
    FredkinCell x('-');
    AbstractCell* y = x.clone();
    ASSERT_EQ(x.currentStateAlive, y->currentStateAlive);
    ASSERT_EQ(x.nextStateAlive, y->nextStateAlive);
    delete y;
}

TEST(FredkinFixture, clone3) {
    FredkinCell x('0');
    FredkinCell* y = dynamic_cast<FredkinCell*>(x.clone());
    ASSERT_EQ(x.age, y->age);
    ASSERT_EQ(x.nextAge, y->nextAge);

    delete y;
}

TEST(FredkinFixture, determineNext1) {
    FredkinCell x('0');

    ASSERT_TRUE(x.nextStateAlive);

    vector<bool> neighbors(9, false);
    x.determineNext(neighbors);

    ASSERT_EQ(x.age, 0);
    ASSERT_FALSE(x.nextStateAlive);
}

TEST(FredkinFixture, determineNext2) {
    FredkinCell x('-');

    ASSERT_FALSE(x.nextStateAlive);

    vector<bool> neighbors(9, false);
    neighbors[1] = true;
    x.determineNext(neighbors);

    ASSERT_EQ(x.age, 0);
    ASSERT_TRUE(x.nextStateAlive);
}

TEST(FredkinFixture, determineNext3) {
    FredkinCell x('0');

    ASSERT_TRUE(x.nextStateAlive);

    vector<bool> neighbors(9, false);
    neighbors[1] = true;
    x.determineNext(neighbors);

    ASSERT_EQ(x.nextAge, 1);
    ASSERT_TRUE(x.nextStateAlive);
}

TEST(FredkinFixture, determineNext4) {
    FredkinCell x('-');

    ASSERT_FALSE(x.nextStateAlive);

    vector<bool> neighbors(9, false);
    x.determineNext(neighbors);

    ASSERT_EQ(x.age, 0);
    ASSERT_FALSE(x.nextStateAlive);
}

TEST(FredkinFixture, update1) {
    FredkinCell x('0');

    ASSERT_TRUE(x.currentStateAlive);

    x.nextStateAlive = false;
    x.update();

    ASSERT_EQ(x.age, 0);
    ASSERT_FALSE(x.currentStateAlive);
}

TEST(FredkinFixture, update2) {
    FredkinCell x('0');

    ASSERT_TRUE(x.currentStateAlive);
    x.nextAge = 1;
    x.update();
    ASSERT_EQ(x.age, 1);
    ASSERT_TRUE(x.currentStateAlive);
}

TEST(FredkinFixture, update3) {
    FredkinCell x('-');

    ASSERT_FALSE(x.currentStateAlive);

    x.nextStateAlive = true;
    x.update();
    ASSERT_EQ(x.age, 0);
    ASSERT_TRUE(x.currentStateAlive);
}

TEST(FredkinFixture, update4) {
    FredkinCell x('-');

    ASSERT_FALSE(x.currentStateAlive);
    x.update();
    ASSERT_EQ(x.age, 0);
    ASSERT_FALSE(x.currentStateAlive);
}

TEST(FredkinFixture, evolveToConway1) {
    FredkinCell x('0');
    ASSERT_FALSE(x.evolveToConway());
}

TEST(FredkinFixture, evolveToConway2) {
    FredkinCell x('0');
    x.age = 2;
    ASSERT_TRUE(x.evolveToConway());
}

TEST(FredkinFixture, representation1) {
    FredkinCell x('0');
    ASSERT_EQ(x.representation(), '0');
}

TEST(FredkinFixture, representation2) {
    FredkinCell x('-');
    ASSERT_EQ(x.representation(), '-');
}

TEST(FredkinFixture, representation3) {
    FredkinCell x('0');
    x.age = 15;
    ASSERT_EQ(x.representation(), '+');
}

TEST(CellFixture, constructor1) {
    Cell x('*');
    ConwayCell* y = dynamic_cast<ConwayCell*>(x._p);
    FredkinCell* z = dynamic_cast<FredkinCell*>(x._p);

    ASSERT_TRUE(y);
    ASSERT_FALSE(z);
    ASSERT_TRUE(x.isAlive());
}

TEST(CellFixture, constructor2) {
    Cell x('.');
    ConwayCell* y = dynamic_cast<ConwayCell*>(x._p);
    FredkinCell* z = dynamic_cast<FredkinCell*>(x._p);

    ASSERT_TRUE(y);
    ASSERT_FALSE(z);
    ASSERT_FALSE(x.isAlive());
}

TEST(CellFixture, constructor3) {
    Cell x('0');
    ConwayCell* y = dynamic_cast<ConwayCell*>(x._p);
    FredkinCell* z = dynamic_cast<FredkinCell*>(x._p);

    ASSERT_FALSE(y);
    ASSERT_TRUE(z);
    ASSERT_TRUE(x.isAlive());
}

TEST(CellFixture, constructor4) {
    Cell x('-');
    ConwayCell* y = dynamic_cast<ConwayCell*>(x._p);
    FredkinCell* z = dynamic_cast<FredkinCell*>(x._p);

    ASSERT_FALSE(y);
    ASSERT_TRUE(z);
    ASSERT_FALSE(x.isAlive());
}

TEST(CellFixture, constructor5) {
    ASSERT_THROW(Cell x('?'), invalid_argument);
}

TEST(CellFixture, ACconstructor1) {
    ConwayCell x('*');
    Cell y(&x);
    ConwayCell* z = dynamic_cast<ConwayCell*>(y._p);

    ASSERT_TRUE(z);
    ASSERT_TRUE(y.isAlive());
}

TEST(CellFixture, ACconstructor2) {
    FredkinCell x('0');
    Cell y(&x);
    FredkinCell* z = dynamic_cast<FredkinCell*>(y._p);

    ASSERT_TRUE(z);
    ASSERT_TRUE(y.isAlive());
}

TEST(CellFixture, copyconstructor1) {
    Cell x('*');
    Cell y(x);

    ConwayCell* m = dynamic_cast<ConwayCell*>(x._p);
    ConwayCell* n = dynamic_cast<ConwayCell*>(y._p);

    ASSERT_TRUE(m);
    ASSERT_TRUE(n);
    ASSERT_TRUE(x.isAlive());
    ASSERT_TRUE(y.isAlive());
}

TEST(CellFixture, copyconstructor2) {
    Cell x('0');
    Cell y(x);

    FredkinCell* m = dynamic_cast<FredkinCell*>(x._p);
    FredkinCell* n = dynamic_cast<FredkinCell*>(y._p);

    ASSERT_TRUE(m);
    ASSERT_TRUE(n);
    ASSERT_TRUE(x.isAlive());
    ASSERT_TRUE(y.isAlive());
}

TEST(CellFixture, assignment1) {
    Cell x('*');
    Cell y('.');

    ASSERT_TRUE(x.isAlive());
    x = y;
    ASSERT_FALSE(x.isAlive());
}

TEST(CellFixture, assignment2) {
    Cell x('0');
    Cell y('-');

    ASSERT_TRUE(x.isAlive());
    x = y;
    ASSERT_FALSE(x.isAlive());
}

TEST(CellFixture, assignment3) {
    Cell x('*');
    Cell y('-');

    ConwayCell* atFirstConway = dynamic_cast<ConwayCell*>(x._p);

    ASSERT_TRUE(x.isAlive());
    ASSERT_TRUE(atFirstConway);
    x = y;
    FredkinCell* nowFredkin = dynamic_cast<FredkinCell*>(x._p);
    ASSERT_FALSE(x.isAlive());
    ASSERT_TRUE(nowFredkin);
}

TEST(CellFixture, determineNext1) {
    Cell x('*');

    ASSERT_TRUE(x._p->nextStateAlive);

    vector<bool> neighbors(9, false);
    x.determineNext(neighbors);

    ASSERT_FALSE(x._p->nextStateAlive);
}

TEST(CellFixture, determineNext2) {
    Cell x('.');

    ASSERT_FALSE(x._p->nextStateAlive);

    vector<bool> neighbors(9, false);
    neighbors[0] = neighbors[1] = neighbors[2] = true;
    x.determineNext(neighbors);

    ASSERT_TRUE(x._p->nextStateAlive);
}

TEST(CellFixture, determineNext3) {
    Cell x('0');

    ASSERT_TRUE(x._p->nextStateAlive);

    vector<bool> neighbors(9, false);
    x.determineNext(neighbors);

    ASSERT_FALSE(x._p->nextStateAlive);
}

TEST(CellFixture, determineNext4) {
    Cell x('-');

    ASSERT_FALSE(x._p->nextStateAlive);

    vector<bool> neighbors(9, false);
    neighbors[1] = true;
    x.determineNext(neighbors);

    ASSERT_TRUE(x._p->nextStateAlive);
}

TEST(CellFixture, update1) {
    Cell x('0');
    FredkinCell* y = dynamic_cast<FredkinCell*>(x._p);
    y->nextAge = 1;
    x.update();
    y = dynamic_cast<FredkinCell*>(x._p);
    ConwayCell* z = dynamic_cast<ConwayCell*>(x._p);

    ASSERT_TRUE(y);
    ASSERT_FALSE(z);
}

TEST(CellFixture, update2) {
    Cell x('0');
    FredkinCell* y = dynamic_cast<FredkinCell*>(x._p);
    y->nextAge = 2;
    x.update();
    y = dynamic_cast<FredkinCell*>(x._p);
    ConwayCell* z = dynamic_cast<ConwayCell*>(x._p);

    ASSERT_FALSE(y);
    ASSERT_TRUE(z);
}

TEST(CellFixture, representation1) {
    Cell x('*');
    Cell y('0');

    ASSERT_EQ(x.representation(), '*');
    ASSERT_EQ(y.representation(), '0');
}

TEST(CellFixture, representation2) {
    Cell x('.');
    Cell y('-');

    ASSERT_EQ(x.representation(), '.');
    ASSERT_EQ(y.representation(), '-');
}

TEST(CellFixture, isAlive1) {
    Cell x('*');
    Cell y('0');

    ASSERT_TRUE(x.isAlive());
    ASSERT_TRUE(x.isAlive());
}

TEST(CellFixture, isAlive2) {
    Cell x('.');
    Cell y('-');

    ASSERT_FALSE(x.isAlive());
    ASSERT_FALSE(x.isAlive());
}

TEST(LifeFixture, constructor1) {
    Life<ConwayCell> x;
    ASSERT_EQ(x.rows, 0);
    ASSERT_EQ(x.cols, 0);
    ASSERT_EQ(x.generation, 0);
}

TEST(LifeFixture, constructor2) {
    Life<ConwayCell> x(3, 3, "...\n...\n...");
    ASSERT_EQ(x.rows, 3);
    ASSERT_EQ(x.cols, 3);
    ASSERT_EQ(x.generation, 0);
    ASSERT_EQ(x.grid.size(), 3);
    ASSERT_EQ(x.grid[0].size(), 3);
}

TEST(LifeFixture, constructor3) {
    ASSERT_THROW(Life<ConwayCell> x(3, 3, "...\n..."), invalid_argument);
    ASSERT_THROW(Life<ConwayCell> x(3, 3, "...\n..\n..."), invalid_argument);
}

TEST(LifeFixture, constructor4) {
    ASSERT_THROW(Life<ConwayCell> x(3, 3, "...\n.-.\n..."), invalid_argument);
    ASSERT_THROW(Life<FredkinCell> x(3, 3, "---\n-*-\n---"), invalid_argument);
}

TEST(LifeFixture, evolve1) {
    Life<ConwayCell> x(3, 3, "*..\n...\n*.*");
    x.evolve();
    stringstream s;
    s << x;
    ASSERT_EQ(s.str(), "Generation = 1, Population = 1.\n...\n.*.\n...\n");
}

TEST(LifeFixture, evolve2) {
    Life<FredkinCell> x(3, 4, "0--0\n----\n0--0");
    x.evolve();
    stringstream s;
    s << x;
    ASSERT_EQ(s.str(), "Generation = 1, Population = 4.\n-00-\n----\n-00-\n");

    x.evolve();
    x.evolve();
    x.evolve();
    x.evolve();
    x.evolve();
    x.evolve();
    x.evolve();
    x.evolve();
    x.evolve();

    s.str(string());
    s.clear();
    s << x;
    ASSERT_EQ(s.str(), "Generation = 10, Population = 4.\n-33-\n----\n-33-\n");
}

TEST(LifeFixture, evolve3) {
    Life<Cell> x(3, 3, "0*0\n.-.\n0*0");
    x.evolve();
    stringstream s;
    s << x;
    ASSERT_EQ(s.str(), "Generation = 1, Population = 6.\n1*1\n.-.\n1*1\n");
}

TEST(LifeFixture, evolve4) {
    Life<Cell> x(3, 4, "0--0\n-00-\n0--0");
    x.evolve();
    x.evolve();
    x.evolve();
    x.evolve();
    x.evolve();
    stringstream s;
    s << x;
    ASSERT_EQ(s.str(), "Generation = 5, Population = 2.\n----\n*..*\n----\n");
}

TEST(LifeFixture, evolve5) {
    Life<ConwayCell> x(3, 3, ".*.\n*.*\n.*.");
    for(int i = 0; i < 10; ++i)
        x.evolve();
    stringstream s;
    s << x;
    ASSERT_EQ(s.str(), "Generation = 10, Population = 4.\n.*.\n*.*\n.*.\n");
}

TEST(LifeFixture, print1) {
    Life<ConwayCell> x(3, 3, "***\n...\n***");
    stringstream s;
    s << x;
    ASSERT_EQ(s.str(), "Generation = 0, Population = 6.\n***\n...\n***\n");
}

TEST(LifeFixture, print2) {
    Life<FredkinCell> x(3, 3, "0-0\n-0-\n0-0");
    stringstream s;
    s << x;
    ASSERT_EQ(s.str(), "Generation = 0, Population = 5.\n0-0\n-0-\n0-0\n");
}

TEST(LifeFixture, print3) {
    Life<Cell> x(3, 3, "0*0\n.-.\n0*0");
    stringstream s;
    s << x;
    ASSERT_EQ(s.str(), "Generation = 0, Population = 6.\n0*0\n.-.\n0*0\n");
}

TEST(LifeFixture, print4) {
    Life<Cell> x;
    stringstream s;
    s << x;
    ASSERT_EQ(s.str(), "Generation = 0, Population = 0.\n");
}
