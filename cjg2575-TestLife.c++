// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "Life.h"

using namespace std;

// -----
// tests
// -----

TEST(LifeFixture, cc_assign1) {
    ConwayCell c(true);
	ConwayCell c2 = c;
	ASSERT_TRUE(c2.alive());}

TEST(LifeFixture, cc_assign2) {
    ConwayCell* c = new ConwayCell(true);
	ConwayCell c2 = *c;
	delete c;
	ASSERT_TRUE(c2.alive());}

TEST(LifeFixture, cc_assign3) {
    ConwayCell c(true);
	ConwayCell c2, c3;
	c2 = c;
	c3 = c2;
	ASSERT_TRUE(c2.alive() && c3.alive());}

TEST(LifeFixture, fc_assign1){
	FredkinCell f(true);
	FredkinCell f2;
	f2 = f;
	ASSERT_TRUE(f2.alive());}

TEST(LifeFixture, fc_assign2){
	FredkinCell* f = new FredkinCell(true);
	FredkinCell f2 = *f;
	delete f;
	ASSERT_TRUE(f2.alive());
}

TEST(LifeFixture, fc_assign3){
	FredkinCell f(true);
	FredkinCell f2, f3;
	f2 = f;
	f3 = f2;
	ASSERT_TRUE(f2.alive() && f3.alive());}

TEST(LifeFixture, cc_output1){
	ConwayCell c(true);
	ostringstream os;
	os << c;
	ASSERT_EQ("*",os.str());}

TEST(LifeFixture, cc_output2){
	ConwayCell c(false);
	ostringstream os;
	os << c;
	ASSERT_EQ(".",os.str());}

TEST(LifeFixture, cc_output3){
	ConwayCell c(true);
	AbstractCell* p = c.clone();
	ostringstream os; 
	os << *p;
	delete p;
	ASSERT_EQ("*",os.str());}

TEST(LifeFixture, fc_output1){
	FredkinCell c(true);
	ostringstream os;
	os << c;
	ASSERT_EQ("0",os.str());}

TEST(LifeFixture, fc_output2){
	FredkinCell c(false);
	ostringstream os;
	os << c;
	ASSERT_EQ("-",os.str());}

TEST(LifeFixture, fc_output3){
	FredkinCell c(true);
	AbstractCell* p = c.clone();
	ostringstream os; 
	os << *p;
	delete p;
	ASSERT_EQ("0",os.str());}

// the tests for alive cover clone so I'm going to do a few extra tests on the other methods

TEST(LifeFixture, cc_alive1){
	ConwayCell c(true);
	ASSERT_TRUE(c.alive());}

TEST(LifeFixture, cc_alive2){
	ConwayCell c(false);
	ASSERT_FALSE(c.alive());}

TEST(LifeFixture, cc_alive3){
	ConwayCell c(true);
	AbstractCell* p = c.clone();
	bool temp = p->alive();
	delete p;
	ASSERT_TRUE(temp);}

TEST(LifeFixture, fc_alive1){
	FredkinCell c(true);
	ASSERT_TRUE(c.alive());}

TEST(LifeFixture, fc_alive2){
	FredkinCell c(false);
	ASSERT_FALSE(c.alive());}

TEST(LifeFixture, fc_alive3){
	FredkinCell c(true);
	AbstractCell* p = c.clone();
	bool temp = p->alive();
	delete p;
	ASSERT_TRUE(temp);}

TEST(LifeFixture, cc_live_neighbors_1){
	ConwayCell c(true);
	vector<bool> n(8, true);
	int i = c.live_neighbors(n);
	ASSERT_EQ(8, i);}

TEST(LifeFixture, cc_live_neighbors_2){
	ConwayCell c(true);
	vector<bool> n(8, false);
	int i = c.live_neighbors(n);
	ASSERT_EQ(0, i);}

TEST(LifeFixture, cc_live_neighbors_3){
	ConwayCell c(true);
	vector<bool> n(8, false);
	for(int i = 0; i < 4; ++i){
		n[i]=(true);}
	int i = c.live_neighbors(n);
	ASSERT_EQ(4, i);
	}

TEST(LifeFixture, fc_live_neighbors_1){
	FredkinCell c(true);
	vector<bool> n(8, true);
	int i = c.live_neighbors(n);
	ASSERT_EQ(4, i);}

TEST(LifeFixture, fc_live_neighbors_2){
	FredkinCell c(true);
	vector<bool> n(8, false);
	int i = c.live_neighbors(n);
	ASSERT_EQ(0, i);}

TEST(LifeFixture, fc_live_neighbors_3){
	FredkinCell c(true);
	vector<bool> n(8, false);
	for(int i = 0; i < 4; ++i){
		n[i]=(true);}
	int i = c.live_neighbors(n);
	ASSERT_EQ(2, i);
	}

TEST(LifeFixture, fc_live_neighbors_4){
	FredkinCell c(true);
	vector<bool> n(8, false);
	for(int i = 0; i < 6; ++i){
		n[i]=(true);}
	int i = c.live_neighbors(n);
	ASSERT_EQ(3, i);}

TEST(LifeFixture, fc_live_neighbors_5){
	FredkinCell c(true);
	vector<bool> n(8, false);
	for(int i = 0; i < 2; ++i){
		n[i]=(true);}
	int i = c.live_neighbors(n);
	ASSERT_EQ(1, i);}

TEST(LifeFixture, cc_evolve1){
	ConwayCell c(true);
	c.evolve(4);
	ASSERT_FALSE(c.alive());}

TEST(LifeFixture, cc_evolve2){
	ConwayCell c(true);
	c.evolve(1);
	ASSERT_FALSE(c.alive());}

TEST(LifeFixture, cc_evolve3){
	ConwayCell c(false);
	c.evolve(3);
	ASSERT_TRUE(c.alive());}

TEST(LifeFixture, cc_evolve4){
	ConwayCell c(false);
	c.evolve(5);
	ASSERT_FALSE(c.alive());}

TEST(LifeFixture, fc_evolve1){
	FredkinCell c(true);
	c.evolve(2);
	ASSERT_FALSE(c.alive());}

TEST(LifeFixture, fc_evolve2){
	FredkinCell c(true);
	c.evolve(1);
	ostringstream os;
	os << c;
	ASSERT_EQ("1",os.str());
	ASSERT_TRUE(c.alive());}

TEST(LifeFixture, fc_evolve3){
	FredkinCell c(false);
	c.evolve(3);
	ASSERT_TRUE(c.alive());;}

TEST(LifeFixture, fc_evolve4){
	FredkinCell c(false);
	c.evolve(2);
	ASSERT_FALSE(c.alive());}

TEST(LifeFixture, fc_evolve5){
	FredkinCell c(true);
	c.evolve(1);
	AbstractCell* p = c.evolve(1);
	ostringstream os;
	os << (*p);
	delete p;
	ASSERT_EQ("*",os.str());
	ASSERT_TRUE(c.alive());}

TEST(LifeFixture, cc_print1){
	ConwayCell c(true);
	ostringstream os;
	c.print(os);
	ASSERT_EQ("*",os.str());}

TEST(LifeFixture, cc_print2){
	ConwayCell c(false);
	ostringstream os;
	c.print(os);
	ASSERT_EQ(".",os.str());}

TEST(LifeFixture, fc_print1){
	FredkinCell c(true);
	ostringstream os;
	c.print(os);
	ASSERT_EQ("0",os.str());}

TEST(LifeFixture, fc_print2){
	FredkinCell c(true);
	ostringstream os;
	for(int i = 0; i < 11; ++i){
		AbstractCell* p = c.evolve(1);
		if(p){delete p;}}
	c.print(os);
	ASSERT_EQ("+",os.str());}

TEST(LifeFixture, fc_print3){
	FredkinCell c(false);
	ostringstream os;
	c.print(os);
	ASSERT_EQ("-",os.str());}

TEST(LifeFixture, cell_alive1){
	ConwayCell c(true);
	Cell cell(c);
	ASSERT_TRUE(cell.alive());}

TEST(LifeFixture, cell_alive2){
	ConwayCell c(false);
	Cell cell(c);
	ASSERT_FALSE(cell.alive());}

TEST(LifeFixture, cell_alive3){
	FredkinCell c(true);
	Cell cell(c);
	ASSERT_TRUE(cell.alive());}

TEST(LifeFixture, cell_alive4){
	FredkinCell c(false);
	Cell cell(c);
	ASSERT_FALSE(cell.alive());}

TEST(LifeFixture, cell_live_neighbors1){
	ConwayCell c(true);
	Cell cell(c);
	vector<bool> v(8,true);
	int i = cell.live_neighbors(v);
	ASSERT_EQ(8,i);}

TEST(LifeFixture, cell_live_neighbors2){
	FredkinCell c(true);
	Cell cell(c);
	vector<bool> v(8,true);
	int i = cell.live_neighbors(v);
	ASSERT_EQ(4,i);}

TEST(LifeFixture, cell_live_neighbors3){
	Cell cell;
	vector<bool> v(8,true);
	int i = cell.live_neighbors(v);
	ASSERT_EQ(0,i);}

TEST(LifeFixture, cell_evolve1){
	ConwayCell c(true);
	Cell cell(c);
	cell.evolve(4);
	ASSERT_FALSE(cell.alive());}

TEST(LifeFixture, cell_evolve2){
	ConwayCell c(false);
	Cell cell(c);
	cell.evolve(3);
	ASSERT_TRUE(cell.alive());}

TEST(LifeFixture, cell_evolve3){
	FredkinCell c(true);
	Cell cell(c);
	cell.evolve(4);
	ASSERT_FALSE(cell.alive());}

TEST(LifeFixture, cell_evolve4){
	FredkinCell c(true);
	Cell cell(c);
	cell.evolve(3);
	ASSERT_TRUE(cell.alive());
	cell.evolve(3);
	ostringstream os;
	os << cell;
	ASSERT_EQ("*",os.str());}

TEST(LifeFixture, cell_output1){
	ConwayCell c(true);
	Cell cell(c);
	ostringstream os;
	os << cell;
	ASSERT_EQ("*",os.str());}

TEST(LifeFixture, cell_output2){
	FredkinCell c(true);
	Cell cell(c);
	ostringstream os;
	os << cell;
	ASSERT_EQ("0",os.str());}

TEST(LifeFixture, cell_output3){
	FredkinCell c(false);
	Cell cell(c);
	ostringstream os;
	os << c;
	ASSERT_EQ("-",os.str());}

TEST(LifeFixture, life_add_cell1){
	Life<ConwayCell> l(1,1);
	ConwayCell c(true);
	l.addCell(0,0,&c);
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 0, Population = 1.\n*\n",os.str());}

TEST(LifeFixture, life_add_cell2){
	Life<FredkinCell> l(1,1);
	FredkinCell c(true);
	l.addCell(0,0,&c);
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 0, Population = 1.\n0\n",os.str());}

TEST(LifeFixture, life_add_cell3){
	Life<Cell> l(1,1);
	ConwayCell c(true);
	Cell cell(c);
	l.addCell(0,0,&cell);
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 0, Population = 1.\n*\n",os.str());}

TEST(LifeFixture, life_add_cell4){
	Life<Cell> l(2,2);
	ConwayCell c(true);
	FredkinCell f(true);
	Cell cc(c);
	Cell fc(f);
	l.addCell(0,0,&cc);
	l.addCell(0,1,&cc);
	l.addCell(1,0,&fc);
	l.addCell(1,1,&fc);
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 0, Population = 4.\n**\n00\n",os.str());}

TEST(LifeFixture, life_next_gen1){
	Life<ConwayCell> l(1,1);
	ConwayCell c(true);
	l.addCell(0,0,&c);
	l.next_gen();
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 1, Population = 0.\n.\n",os.str());}

TEST(LifeFixture, life_next_gen2){
	Life<ConwayCell> l(3,3);
	ConwayCell c(true);
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			l.addCell(i,j,&c);}}
	l.next_gen();
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 1, Population = 4.\n*.*\n...\n*.*\n",os.str());}

TEST(LifeFixture, life_next_gen3){
	Life<FredkinCell> l(1,1);
	FredkinCell c(true);
	l.addCell(0,0,&c);
	l.next_gen();
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 1, Population = 0.\n-\n",os.str());}

TEST(LifeFixture, life_next_gen4){
	Life<FredkinCell> l(3,3);
	FredkinCell c(true);
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			l.addCell(i,j,&c);}}
	l.next_gen();
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 1, Population = 4.\n-1-\n1-1\n-1-\n",os.str());}

TEST(LifeFixture, life_next_gen5){
	Life<Cell> l(1,1);
	ConwayCell c(true);
	Cell cell(c);
	l.addCell(0,0,&cell);
	l.next_gen();
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 1, Population = 0.\n.\n",os.str());}

TEST(LifeFixture, life_next_gen6){
	Life<Cell> l(1,1);
	FredkinCell c(true);
	Cell cell(c);
	l.addCell(0,0,&cell);
	l.next_gen();
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 1, Population = 0.\n-\n",os.str());}

TEST(LifeFixture, life_next_gen7){
	Life<Cell> l(3,3);
	FredkinCell c(true);
	Cell cell(c);
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			l.addCell(i,j,&cell);}}
	l.next_gen();
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 1, Population = 4.\n-1-\n1-1\n-1-\n",os.str());}

TEST(LifeFixture, life_next_gen8){
	Life<Cell> l(3,3);
	FredkinCell c(true);
	Cell cell(c);
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			l.addCell(i,j,&cell);}}
	Cell cc(ConwayCell(true));
	l.addCell(0,0,&cc);
	l.next_gen();
	l.next_gen();
	ostringstream os;
	os << l;
	ASSERT_EQ("Generation = 2, Population = 4.\n**-\n*--\n---\n",os.str());}