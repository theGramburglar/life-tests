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
// Abstract Cell Fixture
// ---------------------
TEST(AbstractFixture, Abstract_constructor_0) {
    ConwayCell c0(false);
    ASSERT_EQ(c0._alive, false);
}

TEST(AbstractFixture, Abstract_constructor_1) {
    ConwayCell c0(true);
    ASSERT_NE(c0._alive, false);
}

TEST(AbstractFixture, Abstract_constructor_2) {
    ConwayCell c0(true);
    ASSERT_EQ(c0._alive, true);
}

TEST(AbstractFixture, Abstract_constructor_3) {
    FredkinCell f0(false);
    ASSERT_EQ(f0._alive, false);
}

TEST(AbstractFixture, Abstract_constructor_4) {
    FredkinCell f0(true);
    ASSERT_NE(f0._alive, false);
}

//---------------------------------------
TEST(AbstractFixture, Abstract_die_0) {
    ConwayCell c0(false);
    c0.die();
    ASSERT_EQ(c0._alive, false);
}

TEST(AbstractFixture, Abstract_die_1) {
    ConwayCell c0(true);
    c0.die();
    ASSERT_EQ(c0._alive, false);
}

TEST(AbstractFixture, Abstract_die_2) {
    ConwayCell c0(true);
    c0.die();
    ASSERT_NE(c0._alive, true);
}

TEST(AbstractFixture, Abstract_die_3) {
    FredkinCell f0(false);
    f0.die();
    ASSERT_EQ(f0._alive, false);
}

TEST(AbstractFixture, Abstract_die_4) {
    FredkinCell f0(true);
    f0.die();
    ASSERT_EQ(f0._alive, false);
}

//--------------------------------------------
TEST(AbstractFixture, Abstract_live_0) {
    ConwayCell c0(false);
    c0.live();
    ASSERT_EQ(c0._alive, true);
}

TEST(AbstractFixture, Abstract_live_1) {
    ConwayCell c0(true);
    c0.live();
    ASSERT_EQ(c0._alive, true);
}

TEST(AbstractFixture, Abstract_live_2) {
    ConwayCell c0(true);
    c0.live();
    ASSERT_NE(c0._alive, false);
}

TEST(AbstractFixture, Abstract_live_3) {
    FredkinCell f0(false);
    f0.live();
    ASSERT_EQ(f0._alive, true);
}

TEST(AbstractFixture, Abstract_live_4) {
    FredkinCell f0(true);
    f0.live();
    ASSERT_EQ(f0._alive, true);
}

//--------------------------------------------
TEST(AbstractFixture, Abstract_isAlive_0) {
    ConwayCell c0(false);
    ASSERT_EQ(c0.isAlive(), false);
}

TEST(AbstractFixture, Abstract_isAlive_1) {
    ConwayCell c0(true);
    ASSERT_EQ(c0.isAlive(), true);
}

TEST(AbstractFixture, Abstract_isAlive_2) {
    ConwayCell c0(false);
    c0.live();
    ASSERT_EQ(c0.isAlive(), true);
}

TEST(AbstractFixture, Abstract_isAlive_3) {
    ConwayCell c0(true);
    c0.die();
    ASSERT_NE(c0.isAlive(), true);
}

TEST(AbstractFixture, Abstract_isAlive_4) {
    FredkinCell f0(true);
    f0.die();
    f0.live();
    ASSERT_EQ(f0.isAlive(), true);
}

//------------------------------------------
TEST(AbstractFixture, Abstract_update_0) {
    ConwayCell c0(false);
    c0.update('*');
    ASSERT_EQ(c0.isAlive(), true);
}

TEST(AbstractFixture, Abstract_update_1) {
    ConwayCell c0(false);
    c0.update('+');
    ASSERT_EQ(c0.isAlive(), true);
}

TEST(AbstractFixture, Abstract_update_2) {
    ConwayCell c0(false);
    c0.update('-');
    ASSERT_EQ(c0.isAlive(), false);
}

TEST(AbstractFixture, Abstract_update_3) {
    FredkinCell f0(false);
    f0.update('+');
    ASSERT_EQ(f0.isAlive(), true);
}

TEST(AbstractFixture, Abstract_update_4) {
    FredkinCell f0(false);
    f0.update('2');
    ASSERT_EQ(f0.isAlive(), true);
}

// ---------------------
// Conway Cell Fixture
// ---------------------
TEST(ConwayFixture, ConwayCell_constructor_0) {
    ConwayCell c0(false);
}

TEST(ConwayFixture, ConwayCell_constructor_1) {
    ConwayCell c0(false);
    ConwayCell c1(false);
}

TEST(ConwayFixture, ConwayCell_constructor_2) {
    ConwayCell c0(true);
    ConwayCell c1(true);
    ConwayCell c2(true);
}

TEST(ConwayFixture, ConwayCell_constructor_3) {
    ConwayCell c0(false);
    ConwayCell c1(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
}

//--------------------------
TEST(ConwayFixture, ConwayCell_clone_0) {
  ConwayCell c0(true);
  AbstractCell *ac_clone = c0.clone();
  ASSERT_NE(dynamic_cast<ConwayCell*>(ac_clone), nullptr);
  delete ac_clone;
}

TEST(ConwayFixture, ConwayCell_clone_1) {
  ConwayCell c0(false);
  AbstractCell *ac_clone = c0.clone();
  ASSERT_NE(dynamic_cast<ConwayCell*>(ac_clone), nullptr);
  delete ac_clone;
}

TEST(ConwayFixture, ConwayCell_clone_2) {
  ConwayCell c0(true);
  AbstractCell *ac_clone = c0.clone();
  ASSERT_TRUE(dynamic_cast<ConwayCell*>(ac_clone));
  delete ac_clone;
}

TEST(ConwayFixture, ConwayCell_clone_3) {
  ConwayCell c0(true);
  AbstractCell *ac_clone = c0.clone();
  ASSERT_TRUE(dynamic_cast<ConwayCell*>(ac_clone) -> isAlive());
  delete ac_clone;
}

TEST(ConwayFixture, ConwayCell_clone_4) {
  ConwayCell c0(true);
  AbstractCell *ac_clone = c0.clone();
  ASSERT_NE(dynamic_cast<ConwayCell*>(ac_clone) -> isAlive(), false);
  delete ac_clone;
}

//--------------------------
TEST(ConwayFixture, ConwayCell_isConwayCell_0) {
    ConwayCell c0(false);
    ASSERT_EQ(c0.isConwayCell(), true);
}

TEST(ConwayFixture, ConwayCell_isConwayCell_1) {
    ConwayCell c1(true);
    ASSERT_EQ(c1.isConwayCell(), true);
}

TEST(ConwayFixture, ConwayCell_isConwayCell_2) {
    ConwayCell c2(false);
    ASSERT_EQ(c2.isConwayCell(), true);
}

TEST(ConwayFixture, ConwayCell_isConwayCell_3) {
    ConwayCell c3(true);
    ASSERT_EQ(c3.isConwayCell(), true);
}

//-----------------------------
TEST(ConwayFixture, ConwayCell_isFredkinCell_0) {
    ConwayCell c0(false);
    ASSERT_EQ(c0.isFredkinCell(), false);
}

TEST(ConwayFixture, ConwayCell_isFredkinCell_1) {
    ConwayCell c1(true);
    ASSERT_EQ(c1.isFredkinCell(), false);
}

TEST(ConwayFixture, ConwayCell_isFredkinCell_2) {
    ConwayCell c2(false);
    ASSERT_EQ(c2.isFredkinCell(), false);
}

TEST(ConwayFixture, ConwayCell_isFredkinCell_3) {
    ConwayCell c3(true);
    ASSERT_EQ(c3.isFredkinCell(), false);
}

//------------------------------
TEST(ConwayFixture, ConwayCell_getAge_0) {
    ConwayCell c0(false);
    ASSERT_EQ(c0.getAge(), 0);
}

TEST(ConwayFixture, ConwayCell_getAge_1) {
    ConwayCell c1(true);
    ASSERT_EQ(c1.getAge(), 0);
}

TEST(ConwayFixture, ConwayCell_getAge_2) {
    ConwayCell c2(false);
    ASSERT_EQ(c2.getAge(), 0);
}

TEST(ConwayFixture, ConwayCell_getAge_3) {
    ConwayCell c3(true);
    ASSERT_EQ(c3.getAge(), 0);
}

// ---------------------
// Fredkin Cell Fixture
// ---------------------
TEST(FredkinFixture, FredkinCell_constructor_0) {
    FredkinCell f0(false);
    ASSERT_EQ(f0.isAlive(), false);
}

TEST(FredkinFixture, FredkinCell_constructor_1) {
    FredkinCell f0(true);
    ASSERT_EQ(f0.isAlive(), true);
}

TEST(FredkinFixture, FredkinCell_constructor_2) {
    FredkinCell f0(false);
    ASSERT_NE(f0.isAlive(), true);
}

TEST(FredkinFixture, FredkinCell_constructor_3) {
    FredkinCell f0(true);
    ASSERT_NE(f0.isAlive(), false);
}

//--------------------------------------
TEST(FredkinFixture, FredkinCell_clone_0) {
  FredkinCell f0(true);
  AbstractCell *ac_clone = f0.clone();
  ASSERT_NE(dynamic_cast<FredkinCell*>(ac_clone), nullptr);
  delete ac_clone;
}

TEST(FredkinFixture, FredkinCell_clone_1) {
  FredkinCell f0(true);
  AbstractCell *ac_clone = f0.clone();
  ASSERT_TRUE(dynamic_cast<FredkinCell*>(ac_clone) -> isAlive());
  delete ac_clone;
}

TEST(FredkinFixture, FredkinCell_clone_2) {
  FredkinCell f0(false);
  AbstractCell *ac_clone = f0.clone();
  ASSERT_FALSE(dynamic_cast<FredkinCell*>(ac_clone) -> isAlive());
  delete ac_clone;
}

TEST(FredkinFixture, FredkinCell_clone_3) {
  FredkinCell f0(false);
  AbstractCell *ac_clone = f0.clone();
  ASSERT_TRUE(!(dynamic_cast<FredkinCell*>(ac_clone) -> isAlive()));
  delete ac_clone;
}

//------------------------------------
TEST(FredkinFixture, FredkinCell_incrementAge_0) {
    FredkinCell f0(false);
    f0.incrementAge();
    ASSERT_EQ(f0.getAge(), 1);
}

TEST(FredkinFixture, FredkinCell_incrementAge_1) {
    FredkinCell f0(false);
    f0.incrementAge();
    f0.incrementAge();
    ASSERT_EQ(f0.getAge(), 2);
}

TEST(FredkinFixture, FredkinCell_incrementAge_2) {
    FredkinCell f0(false);
    f0.incrementAge();
    ASSERT_NE(f0.getAge(), -1);
}

TEST(FredkinFixture, FredkinCell_incrementAge_3) {
    FredkinCell f0(false);
    f0.incrementAge();
    f0.incrementAge();
    f0.incrementAge();
    ASSERT_EQ(f0.getAge(), 3);
}

//---------------------------------------
TEST(FredkinFixture, FredkinCell_isConwayCell_0) {
    FredkinCell f0(false);
    ASSERT_EQ(f0.isConwayCell(), false);
}

TEST(FredkinFixture, FredkinCell_isConwayCell_1) {
    FredkinCell f0(true);
    ASSERT_EQ(f0.isConwayCell(), false);
}

TEST(FredkinFixture, FredkinCell_isConwayCell_2) {
    ConwayCell c0(false);
    ASSERT_EQ(c0.isConwayCell(), true);
}


//-----------------------------
TEST(FredkinFixture, FredkinCell_isFredkinCell_0) {
    FredkinCell f0(false);
    ASSERT_EQ(f0.isFredkinCell(), true);
}

TEST(FredkinFixture, FredkinCell_isFredkinCell_1) {
    FredkinCell f0(true);
    ASSERT_EQ(f0.isFredkinCell(), true);
}

TEST(FredkinFixture, FredkinCell_isFredkinCell_2) {
    ConwayCell c0(false);
    ASSERT_EQ(c0.isFredkinCell(), false);
}

//-----------------------------
TEST(FredkinFixture, FredkinCell_getAge_0) {
    FredkinCell f0(false);
    ASSERT_EQ(f0.getAge(), 0);
}

TEST(FredkinFixture, FredkinCell_getAge_1) {
    FredkinCell f0(false);
    f0.incrementAge();
    f0.incrementAge();
    ASSERT_EQ(f0.getAge(), 2);
}

TEST(FredkinFixture, FredkinCell_getAge_2) {
    FredkinCell f0(false);
    f0.incrementAge();
    ASSERT_NE(f0.getAge(), -1);
}


// ---------------------
// Cell Fixture
// ---------------------
TEST(CellFixture, Cell_constructor_0) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);

    ASSERT_NE(ce0._ac, nullptr);
}

TEST(CellFixture, Cell_constructor_1) {
    ConwayCell c0(false);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);

    ASSERT_NE(ce0._ac, nullptr);
}

TEST(CellFixture, Cell_constructor_2) {
    ConwayCell c0(false);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);

    ASSERT_TRUE(ce0._ac);
}

//-------------------------
TEST(CellFixture, Cell_isAlive_0) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isAlive(), false);
}

TEST(CellFixture, Cell_isAlive_1) {
    FredkinCell f0(true);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isAlive(), true);
}

TEST(CellFixture, Cell_isAlive_2) {
    ConwayCell c0(false);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isAlive(), false);
}

TEST(CellFixture, Cell_isAlive_3) {
    ConwayCell c0(true);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isAlive(), true);
}

TEST(CellFixture, Cell_isAlive_4) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_NE(ce0.isAlive(), true);
}

TEST(CellFixture, Cell_isAlive_5) {
    FredkinCell f0(true);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_TRUE(ce0.isAlive());
}

//-------------------------------
TEST(CellFixture, Cell_isConwayCell_0) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isConwayCell(), false);
}

TEST(CellFixture, Cell_isConwayCell_1) {
    FredkinCell f0(true);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isConwayCell(), false);
}

TEST(CellFixture, Cell_isConwayCell_2) {
    ConwayCell c0(false);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isConwayCell(), true);
}

TEST(CellFixture, Cell_isConwayCell_3) {
    ConwayCell c0(true);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isConwayCell(), true);
}

TEST(CellFixture, Cell_isConwayCell_4) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_FALSE(ce0.isConwayCell());
}

TEST(CellFixture, Cell_isConwayCell_5) {
    ConwayCell c0(true);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ASSERT_TRUE(ce0.isConwayCell());
}

//--------------------------------------
TEST(CellFixture, Cell_isFredkinCell_0) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isFredkinCell(), true);
}

TEST(CellFixture, Cell_isFredkinCell_1) {
    FredkinCell f0(true);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isFredkinCell(), true);
}

TEST(CellFixture, Cell_isFredkinCell_2) {
    ConwayCell c0(false);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isFredkinCell(), false);
}

TEST(CellFixture, Cell_isFredkinCell_3) {
    ConwayCell c0(true);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.isFredkinCell(), false);
}

TEST(CellFixture, Cell_isFredkinCell_4) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_TRUE(ce0.isFredkinCell());
}

TEST(CellFixture, Cell_isFredkinCell_5) {
    ConwayCell c0(true);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ASSERT_FALSE(ce0.isFredkinCell());
}

//---------------------------------------
TEST(CellFixture, Cell_die_0) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ce0.die();
    ASSERT_EQ(ce0.isAlive(), false);
}

TEST(CellFixture, Cell_die_2) {
    FredkinCell f0(true);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ce0.die();
    ASSERT_EQ(ce0.isAlive(), false);
}

TEST(CellFixture, Cell_die_1) {
    ConwayCell c0(true);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ce0.die();
    ASSERT_EQ(ce0.isAlive(), false);
}

TEST(CellFixture, Cell_die_3) {
    ConwayCell c0(false);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ce0.die();
    ASSERT_EQ(ce0.isAlive(), false);
}

TEST(CellFixture, Cell_die_4) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ce0.die();
    ASSERT_FALSE(ce0.isAlive());
}

TEST(CellFixture, Cell_die_5) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ce0.die();
    ASSERT_NE(ce0.isAlive(), 1);
}

//--------------------------------------
TEST(CellFixture, Cell_live_0) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ce0.live();
    ASSERT_EQ(ce0.isAlive(), true);
}

TEST(CellFixture, Cell_live_2) {
    FredkinCell f0(true);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ce0.live();
    ASSERT_EQ(ce0.isAlive(), true);
}

TEST(CellFixture, Cell_live_1) {
    ConwayCell c0(true);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ce0.live();
    ASSERT_EQ(ce0.isAlive(), 1);
}

TEST(CellFixture, Cell_live_3) {
    ConwayCell c0(false);
    AbstractCell* ac = c0.clone();
    Cell ce0(ac);
    ce0.live();
    ASSERT_EQ(ce0.isAlive(), 1);
}

TEST(CellFixture, Cell_live_4) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ce0.live();
    ASSERT_FALSE(!(ce0.isAlive()));
}

TEST(CellFixture, Cell_live_5) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ce0.live();
    ASSERT_NE(ce0.isAlive(), 0);
}

//------------------------------------------
TEST(CellFixture, Cell_getAge_0) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.getAge(), 0);
}

TEST(CellFixture, Cell_getAge_1) {
    FredkinCell f0(true);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_EQ(ce0.getAge(), 0);
}

TEST(CellFixture, Cell_getAge_2) {
    FredkinCell f0(false);
    AbstractCell* ac = f0.clone();
    Cell ce0(ac);
    ASSERT_FALSE(ce0.getAge());
}

TEST(CellFixture, Cell_getAge_3) {
    FredkinCell f0(false);
    f0.incrementAge();
    AbstractCell* ac = f0.clone();

    Cell ce0(ac);
    ASSERT_TRUE(ce0.getAge());
}

TEST(CellFixture, Cell_getAge_4) {
    FredkinCell f0(false);
    f0.incrementAge();
    f0.incrementAge();
    AbstractCell* ac = f0.clone();

    Cell ce0(ac);
    ASSERT_EQ(ce0.getAge(), 2);
}

TEST(CellFixture, Cell_getAge_5) {
    FredkinCell f0(false);
    f0.incrementAge();
    f0.incrementAge();
    f0.incrementAge();
    f0.incrementAge();
    f0.incrementAge();
    f0.incrementAge();
    AbstractCell* ac = f0.clone();

    Cell ce0(ac);
    ASSERT_EQ(ce0.getAge(), 6);
}

// ---------------------
// Life Fixture
// ---------------------
TEST(LifeFixture, Life_checkEightNeighbors_0){
    string sim = ".*..";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    
    ASSERT_EQ(x0.checkEightNeighbors(0, 1), 0);
}

TEST(LifeFixture, Life_checkEightNeighbors_1){
    string sim = ".**.";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    
    ASSERT_EQ(x0.checkEightNeighbors(0, 1), 1);
}

TEST(LifeFixture, Life_checkEightNeighbors_2){
    string sim = "****";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    
    ASSERT_EQ(x0.checkEightNeighbors(0, 1), 2);
}

TEST(LifeFixture, Life_checkEightNeighbors_3){
    string sim = "2---";
    Life<FredkinCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    
    ASSERT_EQ(x0.checkEightNeighbors(0, 0), 0);
}

//----------------------------------
TEST(LifeFixture, Life_checkFourNeighbors_0){
    string sim = ".*..";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    
    ASSERT_EQ(x0.checkFourNeighbors(0, 1), 0);
}

TEST(LifeFixture, Life_checkFourNeighbors_1){
    string sim = ".**.";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    
    ASSERT_EQ(x0.checkFourNeighbors(0, 1), 1);
}

TEST(LifeFixture, Life_checkFourNeighbors_2){
    string sim = "****";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    
    ASSERT_EQ(x0.checkFourNeighbors(0, 1), 2);
}

TEST(LifeFixture, Life_checkFourNeighbors_3){
    string sim = "2---";
    Life<FredkinCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    
    ASSERT_EQ(x0.checkFourNeighbors(0, 0), 0);
}

//----------------------------------
TEST(LifeFixture, Life_execute_0){
    string sim = "2---";
    Life<FredkinCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    x0.execute(1, -1, false);
    ASSERT_EQ(x0._pop, 1);
}

TEST(LifeFixture, Life_execute_1){
    string sim = "*...";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    x0.execute(1, -1, false);
    ASSERT_EQ(x0._pop, 0);
}

TEST(LifeFixture, Life_execute_2){
    string sim = "2345";
    Life<FredkinCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    x0.execute(1, -1, false);
    ASSERT_EQ(x0._pop, 2);
}

TEST(LifeFixture, Life_execute_3){
    string sim = "****";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    x0.execute(1, -1, false);
    ASSERT_EQ(x0._pop, 2);
}

//------------------------------------
TEST(LifeFixture, Life_printGrid_0){
    string sim = "*..*";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    x0.execute(1, 1, false);
}

TEST(LifeFixture, Life_printGrid_1){
    string sim = "0--0";
    Life<FredkinCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    x0.execute(1, 1, false);
}

TEST(LifeFixture, Life_printGrid_2){
    string sim = "...*";
    Life<ConwayCell> x0(1, 4);
    istringstream iss(sim);
    x0.parse(iss);
    x0.execute(1, 1, false);
}