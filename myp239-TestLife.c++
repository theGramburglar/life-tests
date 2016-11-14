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

#include <sstream>

using namespace std;

TEST(ConwayFixture, test_symbol1){
	ConwayCell c('.');
	char name = c.getSymbol();
	ASSERT_EQ(name, '.');

}

TEST(ConwayFixture, test_symbol2){
	ConwayCell c('*');
	char name = c.getSymbol();
	ASSERT_EQ(name, '*');
}

TEST(ConwayFixture,test_mutate1){
	ConwayCell c('*');
	ConwayCell dead('.');
	AbstractCell*neighbors[9] = {nullptr, &dead, &dead, &dead, &dead, nullptr, nullptr, nullptr, nullptr };
	ASSERT_EQ(c.needMutate(neighbors), true);

 }

TEST(ConwayFixture,test_mutate2){
	ConwayCell c('.');
	ConwayCell alive('*');
	AbstractCell*neighbors[9] = {nullptr, &alive, &alive, nullptr, &alive, nullptr, nullptr, nullptr, nullptr };
	ASSERT_EQ(c.needMutate(neighbors), true);
	
}

TEST(ConwayFixture,test_mutate3){
	ConwayCell c('.');
	ConwayCell alive('*');
	AbstractCell*neighbors[9] = {nullptr, &alive, &alive, &alive, &alive, nullptr, nullptr, nullptr, nullptr };
	ASSERT_EQ(c.needMutate(neighbors), false);
}

TEST(ConwayFixture, test_clone1){
	ConwayCell c('*');
	AbstractCell *clone = c.clone();
	ASSERT_TRUE(dynamic_cast<ConwayCell *>(clone));

}

TEST(ConwayFixture, test_clone2){
	ConwayCell c('.');
	AbstractCell*clone = c.clone();
	ASSERT_TRUE(dynamic_cast<ConwayCell*>(clone));
	
}


TEST(FredkinFixture, test_f_symbol1){
	FredkinCell c('0');
	char name = c.getSymbol();
	ASSERT_EQ(name, '0');

}

TEST(FredkinFixture, test_f_symbol2){
	FredkinCell c('2');
	char name = c.getSymbol();
	ASSERT_EQ(name, '2');
	
}

TEST(FredkinFixture, test_f_symbol3){
	FredkinCell c('3');
	char name = c.getSymbol();
	ASSERT_EQ(name, '3');
	
}

TEST(FredkinFixture, test_f_symbol4){
	FredkinCell c('-');
	char name = c.getSymbol();
	ASSERT_EQ(name, '-');
}

TEST(FredkinFixture, test_f_mutate1){
	FredkinCell c('-');
	FredkinCell alive('0');

	AbstractCell *neighbors[9] = {nullptr, &alive,  nullptr, nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

     ASSERT_TRUE(c.needMutate(neighbors));


}

TEST(FredkinFixture, test_f_mutate2){

	FredkinCell c('0');
	FredkinCell dead('-');

	AbstractCell *neighbors[9] = {nullptr, nullptr,  nullptr, nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr};

     ASSERT_TRUE(c.needMutate(neighbors));

	
}

TEST(FredkinFixture, test_f_mutate3){
	FredkinCell c('-');
	FredkinCell alive('0');

	AbstractCell *neighbors[9] = {nullptr, &alive,  nullptr, nullptr, nullptr,
                                      &alive, nullptr, nullptr, nullptr};

     ASSERT_FALSE(c.needMutate(neighbors));

	
}

TEST(FredkinFixture, test_f_clone1){

	FredkinCell c('-');
	AbstractCell *clone = c.clone();

	ASSERT_TRUE(dynamic_cast<FredkinCell*>(clone));

}

TEST(FredkinFixture, test_f_clone2){
	FredkinCell c('2');
	AbstractCell *clone = c.clone();

	ASSERT_TRUE(dynamic_cast<FredkinCell*>(clone));	
}
TEST(FredkinFixture, test_f_clone3){
	FredkinCell c('+');
	AbstractCell *clone = c.clone();

	ASSERT_TRUE(dynamic_cast<FredkinCell*>(clone));
}


// /*Tests for Cell*/

TEST(CellFixture, test_symbol_conway1){
	Cell c('.');
	char name = c.getSymbol();
	ASSERT_EQ(name, '.');

}

TEST(CellFixture, test_symbol_conway2){
	Cell c('*');
	char name = c.getSymbol();
	ASSERT_EQ(name, '*');
}

TEST(CellFixture, test_symbol_Fredrick1){
	Cell c ('-');
	char name = c.getSymbol();
	ASSERT_EQ(name, '-');

}

TEST(CellFixture, test_symbol_Fredrick2){
	Cell c('0');
	char name = c.getSymbol();
	ASSERT_EQ(name, '0');

}

TEST(CellFixture, test_mutate_conway6){
	Cell c('.');
	Cell dead('.');
	AbstractCell*neighbors[9] = {nullptr, &dead, &dead, &dead, &dead, nullptr, nullptr, nullptr, nullptr };
	ASSERT_EQ(c.isAlive(), false);
}

TEST(CellFixture, test_mutate_conway7){
	Cell c('*');
	Cell dead('.');
	AbstractCell*neighbors[9] = {nullptr, &dead, &dead, &dead, &dead, nullptr, nullptr, nullptr, nullptr };
	ASSERT_EQ(c.needMutate(neighbors), true);
}


TEST(CellFixture, test_mutate_fredkin_1) {
  Cell c('-');
  Cell c_alive('*');
  Cell f_alive('0');
  AbstractCell *neighbors[9] = {nullptr,&c_alive, &f_alive, &c_alive, nullptr,
                              nullptr,  nullptr,  nullptr,  nullptr};

  ASSERT_EQ(c.needMutate(neighbors), false);

}

TEST(CellFixture, test_mutate_fredkin_2) {
  Cell c('0');
  Cell c_alive('*');
  Cell f_alive('0');
  AbstractCell*neighbors[9] = {nullptr,&c_alive, &f_alive, &c_alive, &f_alive,
                              nullptr,  nullptr,  nullptr,  nullptr};

  ASSERT_EQ(c.needMutate(neighbors), true);
}

TEST(CellFixture, test_copy_constructor_1) {
  Cell c1('.');
  Cell c2(c1);

  ASSERT_EQ(c2.getSymbol(), '.');
}
