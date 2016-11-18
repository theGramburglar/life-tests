// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <sstream> // istringtstream, ostringstream
#include "gtest/gtest.h"

#include "Life.h"

using namespace std;


/* Conway Cell Tests */
TEST(Conway_Constructor, default_1) {
    ConwayCell c;
    ASSERT_EQ(c._neighbors, NO_NEIGHBORS);
}
TEST(Conway_Constructor, default_2) {
    ConwayCell c;
    ASSERT_FALSE(c._alive);
}
TEST(Conway_Constructor, alive_1) {
    ConwayCell c(false);
    ASSERT_EQ(c._neighbors, NO_NEIGHBORS);
}
TEST(Conway_Constructor, alive_2) {
    ConwayCell c(false);
    ASSERT_FALSE(c._alive);
}
TEST(Conway_Constructor, alive_3) {
    ConwayCell c(true);
    ASSERT_EQ(c._neighbors, NO_NEIGHBORS);
}
TEST(Conway_Constructor, alive_4) {
    ConwayCell c(true);
    ASSERT_TRUE(c._alive);
}
TEST(Conway_Constructor, copy_1) {
    ConwayCell c(false);
    ConwayCell c2(c);
    ASSERT_EQ(c2._neighbors, NO_NEIGHBORS);
}
TEST(Conway_Constructor, copy_2) {
    ConwayCell c(false);
    ConwayCell c2(c);
    ASSERT_FALSE(c2._alive);
}
TEST(Conway_Constructor, copy_3) {
    ConwayCell c(true);
    ConwayCell c2(c);
    ASSERT_EQ(c2._neighbors, NO_NEIGHBORS);
}
TEST(Conway_Constructor, copy_4) {
    ConwayCell c(true);
    ConwayCell c2(c);
    ASSERT_TRUE(c2._alive);
}



TEST(Conway_Is_Alive, alive_1) {
    ConwayCell c;
    c._alive = false;
    ASSERT_FALSE(c.is_alive());
}
TEST(Conway_Is_Alive, alive_2) {
    ConwayCell c;
    c._alive = true;
    ASSERT_TRUE(c.is_alive());
}




TEST(Conway_Update, update_alive_1) {
    ConwayCell c;
    c._alive = true;
    c._neighbors = 1;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_FALSE(alive);
}
TEST(Conway_Update, update_alive_2) {
    ConwayCell c;
    c._alive = true;
    c._neighbors = 2;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_TRUE(alive);
}
TEST(Conway_Update, update_alive_3) {
    ConwayCell c;
    c._alive = true;
    c._neighbors = 3;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_TRUE(alive);
}
TEST(Conway_Update, update_alive_4) {
    ConwayCell c;
    c._alive = true;
    c._neighbors = 4;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_FALSE(alive);
}
TEST(Conway_Update, update_dead_1) {
    ConwayCell c;
    c._alive = false;
    c._neighbors = 1;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_FALSE(alive);
}
TEST(Conway_Update, update_dead_2) {
    ConwayCell c;
    c._alive = false;
    c._neighbors = 2;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_FALSE(alive);
}
TEST(Conway_Update, update_dead_3) {
    ConwayCell c;
    c._alive = false;
    c._neighbors = 3;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_TRUE(alive);
}


TEST(Conway_Neighbors, find_1) {
    ConwayCell c;
    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell c2(true);
    ConwayCell c3(true);
    c2.push(surroundings);
    c3.push(surroundings);
    c.find_neighbors(surroundings, corners);

    ASSERT_EQ(c._neighbors, 2);
}
TEST(Conway_Neighbors, find_2) {
    ConwayCell c;
    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    c2.push(surroundings);
    c3.push(surroundings);
    c4.push(corners);
    c5.push(corners);
    c.find_neighbors(surroundings, corners);

    ASSERT_EQ(c._neighbors, 4);
}
TEST(Conway_Neighbors, find_3) {
    ConwayCell c;
    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    FredkinCell c6(0, true);
    FredkinCell c7(0, true);
    c2.push(surroundings);
    c3.push(surroundings);
    c4.push(corners);
    c5.push(corners);
    c6.push(corners);
    c7.push(corners);
    c.find_neighbors(surroundings, corners);

    ASSERT_EQ(c._neighbors, 6);
}



TEST(Conway_Print, print_1) {
	ostringstream w1;
    ConwayCell c(true);
    c.draw(w1);
    ASSERT_EQ("*", w1.str());
}
TEST(Conway_Print, print_2) {
	ostringstream w1;
    ConwayCell c(false);
    c.draw(w1);
    ASSERT_EQ(".", w1.str());
}



TEST(Conway_Push, push_1) {
    vector<AbstractCell*> surroundings;
    ConwayCell c2(true);
    c2.push(surroundings);

    ASSERT_EQ(surroundings.size(), 1);
}
TEST(Conway_Push, push_2) {
    vector<AbstractCell*> surroundings;
    ConwayCell c2(true);
    ConwayCell c3(true);
    c2.push(surroundings);
    c3.push(surroundings);

    ASSERT_EQ(surroundings.size(), 2);
}

TEST(Conway_Push, push_3) {
    vector<AbstractCell*> surroundings;
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    c2.push(surroundings);
    c3.push(surroundings);
    c4.push(surroundings);

    ASSERT_EQ(surroundings.size(), 3);
}

TEST(Conway_Clone, clone_1) {
    ConwayCell c(true);    
    ConwayCell* c2 = c.clone();
    bool alive = c2->_alive;
    delete c2;
    ASSERT_TRUE(alive);   
}
TEST(Conway_Clone, clone_2) {
    ConwayCell c(false);    
    ConwayCell* c2 = c.clone();
    bool alive = c2->_alive;
    delete c2;
    ASSERT_FALSE(alive);   
}
TEST(Conway_Clone, clone_3) {
    ConwayCell c(true);    
    ConwayCell* c2 = c.clone();
    bool alive = c2->_alive;
    int neighbors = c2->_neighbors;
    delete c2;
    ASSERT_TRUE(alive);
    ASSERT_EQ(neighbors, 0);  
}





/* Fredkin Cell Tests */

TEST(Fredkin_Constructor, construct_1) {
    FredkinCell c(0, false);
    ASSERT_EQ(c._age, 0);
    ASSERT_FALSE(c._alive);
}
TEST(Fredkin_Constructor, construct_2) {
    FredkinCell c(1, false);
    ASSERT_EQ(c._age, 1);
    ASSERT_FALSE(c._alive);
}
TEST(Fredkin_Constructor, construct_3) {
    FredkinCell c(2, false);
    ASSERT_EQ(c._age, 2);
    ASSERT_FALSE(c._alive);
}
TEST(Fredkin_Constructor, construct_4) {
    FredkinCell c(0, true);
    ASSERT_EQ(c._age, 0);
    ASSERT_TRUE(c._alive);
}
TEST(Fredkin_Constructor, construct_5) {
    FredkinCell c(1, true);
    ASSERT_EQ(c._age, 1);
    ASSERT_TRUE(c._alive);
}
TEST(Fredkin_Constructor, construct_6) {
    FredkinCell c(2, true);
    ASSERT_EQ(c._age, 2);
    ASSERT_TRUE(c._alive);
}
TEST(Fredkin_Constructor, copy_1) {
    FredkinCell c(0, false);
    FredkinCell c2(c);
    ASSERT_EQ(c._age, 0);
    ASSERT_FALSE(c._alive);
}
TEST(Fredkin_Constructor, copy_2) {
    FredkinCell c(1, false);
    FredkinCell c2(c);
    ASSERT_EQ(c._age, 1);
    ASSERT_FALSE(c._alive);
}
TEST(Fredkin_Constructor, copy_3) {
    FredkinCell c(0, true);
    FredkinCell c2(c);
    ASSERT_EQ(c._age, 0);
    ASSERT_TRUE(c._alive);
}

TEST(Fredkin_Is_Alive, alive_1) {
    FredkinCell c(0,false);
    c._alive = false;
    ASSERT_FALSE(c.is_alive());
}
TEST(Fredkin_Is_Alive, alive_2) {
    FredkinCell c(0,false);
    c._alive = true;
    ASSERT_TRUE(c.is_alive());
}

TEST(Fredkin_Update, update_alive_1) {
    FredkinCell c(0,false);
    c._age = 0;
    c._alive = true;
    c._neighbors = 0;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_FALSE(alive);
}
TEST(Fredkin_Update, update_alive_2) {
    FredkinCell c(0,false);
    c._age = 0;
    c._alive = true;
    c._neighbors = 1;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_TRUE(alive);
}
TEST(Fredkin_Update, update_alive_3) {
    FredkinCell c(0,false);
    c._age = 0;
    c._alive = true;
    c._neighbors = 2;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_FALSE(alive);
}
TEST(Fredkin_Update, update_alive_4) {
    FredkinCell c(0,false);
    c._age = 0;
    c._alive = true;
    c._neighbors = 3;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_TRUE(alive);
}
TEST(Fredkin_Update, update_alive_5) {
    FredkinCell c(0,false);
    c._age = 0;
    c._alive = true;
    c._neighbors = 4;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_FALSE(alive);
}
TEST(Fredkin_Update, update_alive_6) {
    FredkinCell c(0,false);
    c._age = 1;
    c._alive = true;
    c._neighbors = 1;
    bool alive;
    
    ASSERT_TRUE(c.update(alive));
    ASSERT_TRUE(alive);
}

TEST(Fredkin_Update, update_dead_1) {
    FredkinCell c(0,false);
    c._alive = false;
    c._neighbors = 0;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_FALSE(alive);
}
TEST(Fredkin_Update, update_dead_2) {
    FredkinCell c(0,false);
    c._alive = false;
    c._neighbors = 1;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_TRUE(alive);
}
TEST(Fredkin_Update, update_dead_3) {
    FredkinCell c(0,false);
    c._alive = false;
    c._neighbors = 2;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_FALSE(alive);
}
TEST(Fredkin_Update, update_dead_4) {
    FredkinCell c(0,false);
    c._alive = false;
    c._neighbors = 3;
    bool alive;
    
    ASSERT_FALSE(c.update(alive));
    ASSERT_TRUE(alive);
}

TEST(Fredkin_Print, print_1) {
	ostringstream w1;
    FredkinCell c(0, false);
    c.draw(w1);
    ASSERT_EQ("-", w1.str());
}
TEST(Fredkin_Print, print_2) {
	ostringstream w1;
    FredkinCell c(1, true);
    c.draw(w1);
    ASSERT_EQ("1", w1.str());
}
TEST(Fredkin_Print, print_3) {
	ostringstream w1;
    FredkinCell c(2, true);
    c.draw(w1);
    ASSERT_EQ("2", w1.str());
}
TEST(Fredkin_Print, print_4) {
	ostringstream w1;
    FredkinCell c(20, true);
    c.draw(w1);
    ASSERT_EQ("+", w1.str());
}

TEST(Fredkin_Neighbors, find_1) {
    FredkinCell c(0, false);
    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    c2.push(surroundings);
    c3.push(surroundings);
    c4.push(corners);
    c5.push(corners);
    c.find_neighbors(surroundings, corners);

    ASSERT_EQ(c._neighbors, 2);
}
TEST(Fredkin_Neighbors, find_2) {
    FredkinCell c(0, false);
    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    c2.push(surroundings);
    c3.push(surroundings);
    c4.push(surroundings);
    c5.push(corners);
    c.find_neighbors(surroundings, corners);

    ASSERT_EQ(c._neighbors, 3);
}
TEST(Fredkin_Neighbors, find_3) {
    FredkinCell c(0, false);
    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    c2.push(corners);
    c3.push(corners);
    c4.push(corners);
    c5.push(corners);
    c.find_neighbors(surroundings, corners);

    ASSERT_EQ(c._neighbors, 0);
}

TEST(Fredkin_Push, push_1) {
    vector<AbstractCell*> surroundings;
    FredkinCell c2(0,true);
    c2.push(surroundings);

    ASSERT_EQ(surroundings.size(), 1);
}
TEST(Fredkin_Push, push_2) {
    vector<AbstractCell*> surroundings;
    FredkinCell c2(0,true);
    FredkinCell c3(0,true);
    c2.push(surroundings);
    c3.push(surroundings);

    ASSERT_EQ(surroundings.size(), 2);
}
TEST(Fredkin_Push, push_3) {
    vector<AbstractCell*> surroundings;
    FredkinCell c2(0,true);
    FredkinCell c3(0,true);
    FredkinCell c4(0,true);
    c2.push(surroundings);
    c3.push(surroundings);
    c4.push(surroundings);

    ASSERT_EQ(surroundings.size(), 3);
}

TEST(Fredkin_Clone, clone_1) {
    FredkinCell c(0, true);    
    FredkinCell* c2 = c.clone();
    int age = c2->_age;
    bool alive = c2->_alive;
    delete c2;
    ASSERT_EQ(age, 0); 
    ASSERT_TRUE(alive);   
}
TEST(Fredkin_Clone, clone_2) {
    FredkinCell c(0, false);    
    FredkinCell* c2 = c.clone();
    int age = c2->_age;
    bool alive = c2->_alive;
    delete c2;
    ASSERT_EQ(age, 0); 
    ASSERT_FALSE(alive);   
}
TEST(Fredkin_Clone, clone_3) {
    FredkinCell c(1, true);    
    FredkinCell* c2 = c.clone();
    int age = c2->_age;
    bool alive = c2->_alive;
    delete c2;
    ASSERT_EQ(age, 1); 
    ASSERT_TRUE(alive);   
}

/* Cell Tests */
TEST(Cell_Constructor, construct_1) {
	FredkinCell c(0, true);    
    FredkinCell* c2 = c.clone();
    Cell c3(c2);
    delete c2;
    ASSERT_EQ(c3._ac, c2);
}
TEST(Cell_Constructor, construct_2) {
	FredkinCell c(0, false);    
    FredkinCell* c2 = c.clone();
    Cell c3(c2);
    delete c2;
    ASSERT_EQ(c3._ac, c2);
}
TEST(Cell_Constructor, construct_3) {
	FredkinCell c(5, false);    
    FredkinCell* c2 = c.clone();
    Cell c3(c2);
    delete c2;
    ASSERT_EQ(c3._ac, c2);
}
TEST(Cell_Neighbors, find_1) {
    ConwayCell c;
    ConwayCell* c2 = c.clone();
    Cell c3(c2);

    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell cc2(true);
    ConwayCell cc3(true);
    ConwayCell cc4(true);
    ConwayCell cc5(true);
    cc2.push(surroundings);
    cc3.push(surroundings);
    cc4.push(corners);
    cc5.push(corners);

    c3.find_neighbors(surroundings, corners);
    int neighbors = c2->_neighbors;
    delete(c2);

    ASSERT_EQ(neighbors, 4);
}
TEST(Cell_Neighbors, find_2) {
    ConwayCell c;
    ConwayCell* c2 = c.clone();
    Cell c3(c2);

    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell cc2(true);
    ConwayCell cc3(true);
    ConwayCell cc4(true);
    ConwayCell cc5(true);
    ConwayCell cc6(true);
    cc2.push(surroundings);
    cc3.push(surroundings);
    cc4.push(corners);
    cc5.push(corners);
    cc6.push(corners);

    c3.find_neighbors(surroundings, corners);
    int neighbors = c2->_neighbors;
    delete(c2);

    ASSERT_EQ(neighbors, 5);
}
TEST(Cell_Neighbors, find_3) {
    FredkinCell c(0, true);
    FredkinCell* c2 = c.clone();
    Cell c3(c2);

    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell cc2(true);
    ConwayCell cc3(true);
    ConwayCell cc4(true);
    ConwayCell cc5(true);
    ConwayCell cc6(true);
    cc2.push(surroundings);
    cc3.push(surroundings);
    cc4.push(corners);
    cc5.push(corners);
    cc6.push(corners);

    c3.find_neighbors(surroundings, corners);
    int neighbors = c2->_neighbors;
    delete(c2);

    ASSERT_EQ(neighbors, 2);
}
TEST(Cell_Neighbors, find_4) {
    FredkinCell c(0, true);
    FredkinCell* c2 = c.clone();
    Cell c3(c2);

    vector<AbstractCell*> surroundings;
    vector<AbstractCell*> corners;

    ConwayCell cc2(true);
    ConwayCell cc3(true);
    cc2.push(corners);
    cc3.push(corners);

    c3.find_neighbors(surroundings, corners);
    int neighbors = c2->_neighbors;
    delete(c2);

    ASSERT_EQ(neighbors, 0);
}

TEST(Cell_Update, update_1) {
    ConwayCell c;
    c._alive = true;
    c._neighbors = 1;
    ConwayCell* c2 = c.clone();
    Cell c3(c2);

    bool alive;
   	c3.update(alive);
   	delete c2;

    ASSERT_FALSE(alive);
}
TEST(Cell_Update, update_2) {
    ConwayCell c;
    c._alive = true;
    c._neighbors = 2;
    ConwayCell* c2 = c.clone();
    Cell c3(c2);

    bool alive;
   	c3.update(alive);
   	delete c2;

    ASSERT_TRUE(alive);
}
TEST(Cell_Update, update_3) {
    ConwayCell c;
    c._alive = true;
    c._neighbors = 4;
    ConwayCell* c2 = c.clone();
    Cell c3(c2);

    bool alive;
   	c3.update(alive);
   	delete c2;

    ASSERT_FALSE(alive);
}

TEST(Cell_Print, print_1) {
	ostringstream w1;
    ConwayCell c(true);
    ConwayCell* c2 = c.clone();
    Cell c3(c2);
    c3.draw(w1);
    delete c2;
    ASSERT_EQ("*", w1.str());
}
TEST(Cell_Print, print_2) {
	ostringstream w1;
    ConwayCell c(false);
    ConwayCell* c2 = c.clone();
    Cell c3(c2);
    c3.draw(w1);
    delete c2;
    ASSERT_EQ(".", w1.str());
}
TEST(Cell_Print, print_3) {
	ostringstream w1;
    FredkinCell c(2, true);
    FredkinCell* c2 = c.clone();
    Cell c3(c2);
    c3.draw(w1);
    delete c2;
    ASSERT_EQ("2", w1.str());
}

TEST(Cell_Push, push_1) {
    vector<AbstractCell*> surroundings;

    FredkinCell c(2, true);
    FredkinCell* c2 = c.clone();
    Cell c3(c2);
    c3.push(surroundings);

    int size = surroundings.size();
    delete c2;

    ASSERT_EQ(size, 1);
}
TEST(Cell_Push, push_2) {
    vector<AbstractCell*> surroundings;

    FredkinCell c(2, true);
    FredkinCell* c2 = c.clone();
    Cell c3(c2);
    c3.push(surroundings);
    FredkinCell c4(2, true);
    FredkinCell* c5 = c.clone();
    Cell c6(c2);
    c6.push(surroundings);

    int size = surroundings.size();
    delete c2;
    delete c5;

    ASSERT_EQ(size, 2);
}
TEST(Cell_Push, push_3) {
    vector<AbstractCell*> surroundings;

    FredkinCell c(2, true);
    FredkinCell* c2 = c.clone();
    Cell c3(c2);
    c3.push(surroundings);
    FredkinCell c4(2, true);
    FredkinCell* c5 = c.clone();
    Cell c6(c2);
    c6.push(surroundings);
    FredkinCell c7(2, true);
    FredkinCell* c8 = c.clone();
    Cell c9(c2);
    c9.push(surroundings);

    int size = surroundings.size();
    delete c2;
    delete c5;
    delete c8;

    ASSERT_EQ(size, 3);
}

/* Life Tests */
TEST(Life_Constructor, construct_1) {
    Life<Cell> l(1,1);
    ASSERT_EQ(l._height, 1);
    ASSERT_EQ(l._width, 1);
}
TEST(Life_Constructor, construct_2) {
    Life<Cell> l(2,2);
    ASSERT_EQ(l._height, 2);
    ASSERT_EQ(l._width, 2);
}
TEST(Life_Constructor, construct_3) {
    Life<Cell> l(3,3);
    ASSERT_EQ(l._height, 3);
    ASSERT_EQ(l._width, 3);
}
TEST(Life_Is_Valid, valid_1) {
    Life<Cell> l(3,3);
    ASSERT_TRUE(l.is_valid(2,2));
}
TEST(Life_Is_Valid, valid_2) {
    Life<Cell> l(3,3);
    ASSERT_TRUE(l.is_valid(2,1));
}
TEST(Life_Is_Valid, valid_3) {
    Life<Cell> l(3,3);
    ASSERT_FALSE(l.is_valid(3,5));
}

TEST(Life_Surroundings, test_1) {
    Life<ConwayCell> l(3,3);

    ConwayCell c1(true);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c4 = c1.clone();
    l.add_cell(c4, 0, 2);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    ConwayCell* c7 = c1.clone();
    l.add_cell(c7, 1, 2);

    ConwayCell* c8 = c1.clone();
    l.add_cell(c8, 2, 0);

    ConwayCell* c9 = c1.clone();
    l.add_cell(c9, 2, 1);

    ConwayCell* c10 = c1.clone();
    l.add_cell(c10, 2, 2);

    int num = l.get_surroundings(1,1).size();
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete c6;
    delete c7;
    delete c8;
    delete c9;
    delete c10;

    ASSERT_EQ(num, 4);
}

TEST(Life_Surroundings, test_2) {
    Life<ConwayCell> l(3,3);

    ConwayCell c1(true);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c4 = c1.clone();
    l.add_cell(c4, 0, 2);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    ConwayCell* c7 = c1.clone();
    l.add_cell(c7, 1, 2);

    ConwayCell* c8 = c1.clone();
    l.add_cell(c8, 2, 0);

    ConwayCell* c9 = c1.clone();
    l.add_cell(c9, 2, 1);

    ConwayCell* c10 = c1.clone();
    l.add_cell(c10, 2, 2);

    int num = l.get_surroundings(0,1).size();
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete c6;
    delete c7;
    delete c8;
    delete c9;
    delete c10;

    ASSERT_EQ(num, 3);
}

TEST(Life_Surroundings, test_3) {
    Life<ConwayCell> l(3,3);

    ConwayCell c1(true);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c4 = c1.clone();
    l.add_cell(c4, 0, 2);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    ConwayCell* c7 = c1.clone();
    l.add_cell(c7, 1, 2);

    ConwayCell* c8 = c1.clone();
    l.add_cell(c8, 2, 0);

    ConwayCell* c9 = c1.clone();
    l.add_cell(c9, 2, 1);

    ConwayCell* c10 = c1.clone();
    l.add_cell(c10, 2, 2);

    int num = l.get_surroundings(0,0).size();
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete c6;
    delete c7;
    delete c8;
    delete c9;
    delete c10;

    ASSERT_EQ(num, 2);
}

TEST(Life_Corners, test_1) {
    Life<ConwayCell> l(3,3);

    ConwayCell c1(true);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c4 = c1.clone();
    l.add_cell(c4, 0, 2);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    ConwayCell* c7 = c1.clone();
    l.add_cell(c7, 1, 2);

    ConwayCell* c8 = c1.clone();
    l.add_cell(c8, 2, 0);

    ConwayCell* c9 = c1.clone();
    l.add_cell(c9, 2, 1);

    ConwayCell* c10 = c1.clone();
    l.add_cell(c10, 2, 2);

    int num = l.get_corners(1,1).size();
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete c6;
    delete c7;
    delete c8;
    delete c9;
    delete c10;

    ASSERT_EQ(num, 4);
}

TEST(Life_Corners, test_2) {
    Life<ConwayCell> l(3,3);

    ConwayCell c1(true);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c4 = c1.clone();
    l.add_cell(c4, 0, 2);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    ConwayCell* c7 = c1.clone();
    l.add_cell(c7, 1, 2);

    ConwayCell* c8 = c1.clone();
    l.add_cell(c8, 2, 0);

    ConwayCell* c9 = c1.clone();
    l.add_cell(c9, 2, 1);

    ConwayCell* c10 = c1.clone();
    l.add_cell(c10, 2, 2);

    int num = l.get_corners(0,1).size();
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete c6;
    delete c7;
    delete c8;
    delete c9;
    delete c10;

    ASSERT_EQ(num, 2);
}

TEST(Life_Corners, test_3) {
    Life<ConwayCell> l(3,3);

    ConwayCell c1(true);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c4 = c1.clone();
    l.add_cell(c4, 0, 2);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    ConwayCell* c7 = c1.clone();
    l.add_cell(c7, 1, 2);

    ConwayCell* c8 = c1.clone();
    l.add_cell(c8, 2, 0);

    ConwayCell* c9 = c1.clone();
    l.add_cell(c9, 2, 1);

    ConwayCell* c10 = c1.clone();
    l.add_cell(c10, 2, 2);

    int num = l.get_corners(0,0).size();
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete c6;
    delete c7;
    delete c8;
    delete c9;
    delete c10;

    ASSERT_EQ(num, 1);
}

TEST(Life_Print, print_1) {
	ostringstream w1;

	Life<ConwayCell> l(2,2);

    ConwayCell c1(true);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    l.print(w1, 0, 0);
    delete c2;
    delete c3;
    delete c5;
    delete c6;

    
    ASSERT_EQ("\nGeneration = 0, Population = 0.\n**\n**\n", w1.str());
}

TEST(Life_Print, print_2) {
	ostringstream w1;

	Life<ConwayCell> l(2,2);

    ConwayCell c1(true);
    ConwayCell c1b(false);
    ConwayCell* c2 = c1b.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1b.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    l.print(w1, 0, 0);
    delete c2;
    delete c3;
    delete c5;
    delete c6;

    
    ASSERT_EQ("\nGeneration = 0, Population = 0.\n..\n**\n", w1.str());
}

TEST(Life_Print, print_3) {
	ostringstream w1;

	Life<ConwayCell> l(2,2);

    ConwayCell c1(true);
    ConwayCell c1b(false);
    ConwayCell* c2 = c1b.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1b.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c5 = c1b.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1b.clone();
    l.add_cell(c6, 1, 1);

    l.print(w1, 0, 0);
    delete c2;
    delete c3;
    delete c5;
    delete c6;

    
    ASSERT_EQ("\nGeneration = 0, Population = 0.\n..\n..\n", w1.str());
}

TEST(Life_Play, play_game_1) {

	Life<ConwayCell> l(2,2);

    ConwayCell c1(true);
    ConwayCell c1b(false);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1b.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1b.clone();
    l.add_cell(c6, 1, 1);

    int population = l.play_game();
    delete c2;
    delete c3;
    delete c5;
    delete c6;

    
    ASSERT_EQ(population, 0);
}

TEST(Life_Play, play_game_2) {

	Life<ConwayCell> l(2,2);

    ConwayCell c1(true);
    ConwayCell c1b(false);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    int population = l.play_game();
    delete c2;
    delete c3;
    delete c5;
    delete c6;

    
    ASSERT_EQ(population, 4);
}


TEST(Life_Play, play_game_3) {

	Life<ConwayCell> l(2,2);

    ConwayCell c1(true);
    ConwayCell c1b(false);
    ConwayCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    ConwayCell* c3 = c1b.clone();
    l.add_cell(c3, 0, 1);

    ConwayCell* c5 = c1b.clone();
    l.add_cell(c5, 1, 0);

    ConwayCell* c6 = c1b.clone();
    l.add_cell(c6, 1, 1);

    int population = l.play_game();
    delete c2;
    delete c3;
    delete c5;
    delete c6;

    
    ASSERT_EQ(population, 0);
}

TEST(Life_Play, play_game_4) {

	Life<FredkinCell> l(2,2);

    FredkinCell c1(0, true);
    FredkinCell c1b(0, false);
    FredkinCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    FredkinCell* c3 = c1b.clone();
    l.add_cell(c3, 0, 1);

    FredkinCell* c5 = c1b.clone();
    l.add_cell(c5, 1, 0);

    FredkinCell* c6 = c1b.clone();
    l.add_cell(c6, 1, 1);

    int population = l.play_game();
    delete c2;
    delete c3;
    delete c5;
    delete c6;

    
    ASSERT_EQ(population, 2);
}


TEST(Life_Play, play_game_5) {

	Life<FredkinCell> l(2,2);

    FredkinCell c1(0,true);
    FredkinCell c1b(0,false);
    FredkinCell* c2 = c1.clone();
    l.add_cell(c2, 0, 0);

    FredkinCell* c3 = c1.clone();
    l.add_cell(c3, 0, 1);

    FredkinCell* c5 = c1.clone();
    l.add_cell(c5, 1, 0);

    FredkinCell* c6 = c1.clone();
    l.add_cell(c6, 1, 1);

    int population = l.play_game();
    delete c2;
    delete c3;
    delete c5;
    delete c6;

    
    ASSERT_EQ(population, 0);
}

