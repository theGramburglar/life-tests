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

// ----------
// ConwayTest
// ----------

TEST(ConwayFixture, test_write_1) {
    ostringstream out;
    ConwayCell c('*');
    c.write(out);
    ASSERT_EQ("*", out.str());
}


TEST(ConwayFixture, test_write_2) {
    ostringstream out;
    ConwayCell c('.');
    c.write(out);
    ASSERT_EQ(".", out.str());
}


TEST(ConwayFixture, test_write_3) {
    ostringstream out;
    ConwayCell c('*');
    ConwayCell c2('.');
    c.write(out);
    ASSERT_EQ("*", out.str());
    c2.write(out);
    ASSERT_EQ("*.", out.str()); 
}

TEST(ConwayFixture, test_print_1) {
    ostringstream in;
    ConwayCell c('*');
    in << c;
    ASSERT_EQ("*", in.str()); 
}

TEST(ConwayFixture, test_print_2) {
    ostringstream in;
    ConwayCell c('.');
    in << c;
    ASSERT_EQ(".", in.str()); 
}

TEST(ConwayFixture, test_print_3) {
    ostringstream in;
    ConwayCell c('*');
    ConwayCell c2('.');
    in << c;
    in << c2;
    ASSERT_EQ("*.", in.str()); 
}

TEST(ConwayFixture, test_print_4) {
    ostringstream in;
    ConwayCell c('*');
    ConwayCell c2('.');
    ConwayCell c3('.');
    in << c;
    in << c2;
    in << c3;
    ASSERT_EQ("*..", in.str()); 
}

TEST(ConwayFixture, test_alive_1) {
    ConwayCell c('*');
    ASSERT_FALSE(c.is_dead()); 
}

TEST(ConwayFixture, test_alive_2) {
    ConwayCell c('.');
    ASSERT_TRUE(c.is_dead()); 
}

// Test with less than 3 neighbors to see if 
// cell dies
TEST(ConwayFixture, test_update_1) {
    ostringstream out;
    ConwayCell c('*');
    c.update(1);
    c.write(out);
    ASSERT_EQ(".", out.str());
}

// Test with 3 neighbors to see if 
// cell becomes alive
TEST(ConwayFixture, test_update_2) {
    ostringstream out;
    ConwayCell c('.');
    c.update(3);
    c.write(out);
    ASSERT_EQ("*", out.str());
}

// Test with more than 3 neighbors to see if 
// cell dies
TEST(ConwayFixture, test_update_3) {
    ostringstream out;
    ConwayCell c('*');
    c.update(5);
    c.write(out);
    ASSERT_EQ(".", out.str());
}

TEST(ConwayFixture, test_count_neighbors_1) {
    ConwayCell c('*');
    vector<AbstractCell*> neighbors = {nullptr, nullptr, nullptr, nullptr,
					&c, &c, &c, &c};
    int num_alive = c.count_neighbors(neighbors);
    ASSERT_EQ(4, num_alive);
}

TEST(ConwayFixture, test_count_neighbors_2) {
    ConwayCell c('*');
    vector<AbstractCell*> neighbors = {nullptr, nullptr, &c, &c,
					&c, &c, &c, &c};
    int num_alive = c.count_neighbors(neighbors);
    ASSERT_EQ(6, num_alive);
}

TEST(ConwayFixture, test_count_neighbors_3) {
    ConwayCell c('*');
    vector<AbstractCell*> neighbors = {nullptr, nullptr, nullptr, nullptr,
				       nullptr, nullptr, nullptr, nullptr};
    int num_alive = c.count_neighbors(neighbors);
    ASSERT_EQ(0, num_alive);
}


TEST(ConwayFixture, test_count_neighbors_4) {
    ConwayCell c('*');
    vector<AbstractCell*> neighbors = { &c, &c, &c, &c,
					&c, &c, &c, &c};
    int num_alive = c.count_neighbors(neighbors);
    ASSERT_EQ(8, num_alive);
}

TEST(ConwayFixture, test_count_conway_neighbors_1) {
    ConwayCell c('*');
    vector<ConwayCell*> neighbors = {nullptr, nullptr, nullptr, nullptr,
					&c, &c, &c, &c};
    int num_alive = c.count_neighbors(neighbors);
    ASSERT_EQ(4, num_alive);
}

TEST(ConwayFixture, test_count_conway_neighbors_2) {
    ConwayCell c('*');
    vector<ConwayCell*> neighbors = {nullptr, nullptr, &c, &c,
					&c, &c, &c, &c};
    int num_alive = c.count_neighbors(neighbors);
    ASSERT_EQ(6, num_alive);
}

TEST(ConwayFixture, test_count_conway_neighbors_3) {
    ConwayCell c('*');
    vector<ConwayCell*> neighbors = {nullptr, nullptr, nullptr, nullptr,
				       nullptr, nullptr, nullptr, nullptr};
    int num_alive = c.count_neighbors(neighbors);
    ASSERT_EQ(0, num_alive);
}

// Test alive cell
TEST(ConwayFixture, test_clone_1) {
    ConwayCell c('*');
    ConwayCell* c2 = c.clone();
    char c_rep = c.rep;
    char c2_rep = c2->rep;
    delete c2;
    ASSERT_EQ(c_rep, c2_rep);
}

// Test dead cell
TEST(ConwayFixture, test_clone_2) {
    ConwayCell c('.');
    ConwayCell* c2 = c.clone();
    char c_rep = c.rep;
    char c2_rep = c2->rep;
    delete c2;
    ASSERT_EQ(c_rep, c2_rep);
}


// ----------
// FredkinTest
// ----------

TEST(FredkinFixture, test_print1) {
    FredkinCell f('4');
    ostringstream out;
    out << f;
    ASSERT_EQ("4", out.str());
}

TEST(FredkinFixture, test_print2) {
    FredkinCell f('-');
    ostringstream out;
    out << f;
    ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_print3) {
    FredkinCell f('+');
    ostringstream out;
    out << f;
    ASSERT_EQ("+", out.str());
}

TEST(FredkinFixture, test_write1) {
    FredkinCell f('9');
    ostringstream out;
    f.write(out);
    ASSERT_EQ("9", out.str());
}

TEST(FredkinFixture, test_write2) {
    FredkinCell f('-');
    ostringstream out;
    f.write(out);
    ASSERT_EQ("-", out.str());
}

TEST(FredkinFixture, test_write3) {
    FredkinCell f('+');
    ostringstream out;
    f.write(out);
    ASSERT_EQ("+", out.str());
}

TEST(FredkinFixture, test_dead1) {
    FredkinCell f('0');
    ASSERT_EQ(f.is_dead(), false);
}

TEST(FredkinFixture, test_dead2) {
    FredkinCell f('-');
    ASSERT_EQ(f.is_dead(), true);
}

TEST(FredkinFixture, test_dead3) {
    FredkinCell f('+');
    ASSERT_EQ(f.is_dead(), false);
}

TEST(FredkinFixture, test_update1) {
   FredkinCell f('0');
   AbstractCell* p = f.update(0);
   ASSERT_EQ(p, nullptr);
   ASSERT_EQ(f.is_dead(), true);
}

TEST(FredkinFixture, test_update2) {
   FredkinCell f('-');
   AbstractCell* p = f.update(1);
   ASSERT_EQ(p, nullptr);
   ASSERT_EQ(f.is_dead(), false);
}

TEST(FredkinFixture, test_update3) {
   FredkinCell f('+');
   AbstractCell* p = f.update(1);
   ASSERT_EQ(p, nullptr);
   ASSERT_EQ(f.is_dead(), false);
}

TEST(FredkinFixture, test_update4) {
   FredkinCell f('0');
   f.update(1);
   ConwayCell* p = dynamic_cast<ConwayCell*>(f.update(1));
   ostringstream out;
   out << (*p);
   delete p;
   ASSERT_EQ("*", out.str()); 
   ASSERT_EQ(f.is_dead(), false);
}

TEST(FredkinFixture, test_update5) {
   FredkinCell f('-');
   AbstractCell* p = f.update(0);
   ASSERT_EQ(p, nullptr);
   ASSERT_EQ(f.is_dead(), true);
}

TEST(FredkinFixture, test_count_ac_neighbors1) {
    FredkinCell f('0');
    vector<AbstractCell*> ac(8);
    ASSERT_EQ(0, f.count_neighbors(ac));
}


TEST(FredkinFixture, test_count_ac_neighbors2) {
    FredkinCell f('0');
    FredkinCell a('0');
    FredkinCell d('-');
    vector<AbstractCell*> ac = {&a, &d, &d, &d, &d, &d, &a, &a}; 
    ASSERT_EQ(1, f.count_neighbors(ac));
}


TEST(FredkinFixture, test_count_ac_neighbors3) {
    FredkinCell f('0');
    FredkinCell a('0');
    FredkinCell d('-');
    vector<AbstractCell*> ac = {&a, &a, &a, &a, &a, &a, &a, &a};
    ASSERT_EQ(4, f.count_neighbors(ac));
}

TEST(FredkinFixture, test_count_fc_neighbors1) {
    FredkinCell f('0');
    vector<FredkinCell*> ac(8);
    ASSERT_EQ(0, f.count_neighbors(ac));
}


TEST(FredkinFixture, test_count_fc_neighbors2) {
    FredkinCell f('0');
    FredkinCell a('0');
    FredkinCell d('-');
    vector<FredkinCell*> ac = {&a, &a, &d, &d, &d, &d, &a, &a}; 
    ASSERT_EQ(2, f.count_neighbors(ac));
}


TEST(FredkinFixture, test_count_fc_neighbors3) {
    FredkinCell f('0');
    FredkinCell a('0');
    FredkinCell d('-');
    vector<FredkinCell*> ac = {&a, &d, &a, &a, &a, &a, &a, &a};
    ASSERT_EQ(3, f.count_neighbors(ac));
}

TEST(FredkinFixture, test_clone1) {
    FredkinCell f('4');
    FredkinCell* f_clone = f.clone();
    char clone_rep = f_clone->rep;
    int clone_age = f_clone->age;
    delete f_clone;
    ASSERT_EQ(f.rep, clone_rep);
    ASSERT_EQ(f.age, clone_age);
}

TEST(FredkinFixture, test_clone2) {
    FredkinCell f('-');
    FredkinCell* f_clone = f.clone();
    char clone_rep = f_clone->rep;
    int clone_age = f_clone->age;
    delete f_clone;
    ASSERT_EQ(f.rep, clone_rep);
    ASSERT_EQ(f.age, clone_age);
}

TEST(FredkinFixture, test_clone3) {
    FredkinCell f('+');
    FredkinCell* f_clone = f.clone();
    char clone_rep = f_clone->rep;
    int clone_age = f_clone->age;
    delete f_clone;
    ASSERT_EQ(f.rep, clone_rep);
    ASSERT_EQ(f.age, clone_age);
}


// ---------
// CellTest
// ---------

TEST(CellFixture, test_print_1) {
    Cell c = new FredkinCell('0');
    ostringstream out;
    out << c;
    ASSERT_EQ("0", out.str());
}

TEST(CellFixture, test_print_2) {
    Cell c = new FredkinCell('+');
    ostringstream out;
    out << c;
    ASSERT_EQ("+", out.str());
}

TEST(CellFixture, test_print_3) {
    Cell c = new ConwayCell('*');
    ostringstream out;
    out << c;
    ASSERT_EQ("*", out.str());
}

TEST(CellFixture, test_copy_construct_1) {
    Cell c1 = new FredkinCell('-');
    Cell c2(c1);
    ostringstream out;
    out << c1 << c2;
    ASSERT_EQ("--", out.str());
}

TEST(CellFixture, test_copy_construct_2) {
    Cell c1 = new ConwayCell('.');
    Cell c2(c1);
    ostringstream out;
    out << c1 << c2;
    ASSERT_EQ("..", out.str());
}

TEST(CellFixture, test_copy_construct_3) {
    Cell c1 = new FredkinCell('0');
    Cell c2(c1);
    ostringstream out;
    out << c1 << c2;
    ASSERT_EQ("00", out.str());
}

TEST(CellFixture, test_assign_1) {
    Cell c1 = new FredkinCell('0');
    Cell c2 = new ConwayCell('*');
    c1 = c2;
    ostringstream out;
    out << c1 << c2;
    ASSERT_EQ("**", out.str());
}

TEST(CellFixture, test_assign_2) {
    Cell c1 = new FredkinCell('0');
    Cell c2 = new ConwayCell('*');
    c2 = c1;
    ostringstream out;
    out << c1 << c2;
    ASSERT_EQ("00", out.str());
}

TEST(CellFixture, test_assign_3) {
    Cell c1 = new FredkinCell('-');
    Cell c2 = new ConwayCell('.');
    c1 = c2;
    ostringstream out;
    out << c1 << c2;
    ASSERT_EQ("..", out.str());
}

TEST(CellFixture, test_is_dead_1) {
    Cell c = new FredkinCell('-');
    ASSERT_TRUE(c.is_dead());
}

TEST(CellFixture, test_is_dead_2) {
    Cell c = new FredkinCell('0');
    ASSERT_FALSE(c.is_dead());
}

TEST(CellFixture, test_is_dead_3) {
    Cell c = new ConwayCell('*');
    ASSERT_FALSE(c.is_dead());
}

TEST(CellFixture, test_update_1) {
    Cell c = new FredkinCell('0');
    AbstractCell* ac1 = c.update(1);
    ASSERT_EQ(nullptr, ac1);
}

TEST(CellFixture, test_update_2) {
    Cell c = new FredkinCell('0');
    AbstractCell* ac1 = c.update(1);
    ASSERT_EQ(nullptr, ac1);
    ac1 = c.update(1);
    ASSERT_EQ(nullptr, ac1);
    ostringstream out;
    out << c;
    ASSERT_EQ("*", out.str());
}

TEST(CellFixture, test_update_3) {
    Cell c = new FredkinCell('-');
    AbstractCell* ac1 = c.update(0);
    ASSERT_EQ(nullptr, ac1);
    ac1 = c.update(0);
    ASSERT_EQ(nullptr, ac1);
    ostringstream out;
    out << c;
    ASSERT_EQ("-", out.str());
}

TEST(CellFixture, test_count_neigh_1) {
    Cell c = new ConwayCell('*');
    Cell cc = new ConwayCell('.');
    Cell fc = new FredkinCell('0');
    vector<Cell*> neighbors = {nullptr, nullptr, &cc, nullptr, &fc, nullptr, &cc, &cc};
    ASSERT_EQ(1, c.count_neighbors(neighbors));
}

TEST(CellFixture, test_count_neigh_2) {
    Cell c = new ConwayCell('*');
    Cell cc = new ConwayCell('*');
    Cell fc = new FredkinCell('-');
    vector<Cell*> neighbors = {nullptr, nullptr, &cc, nullptr, &fc, nullptr, &cc, &cc};
    ASSERT_EQ(3, c.count_neighbors(neighbors));
}

TEST(CellFixture, test_count_neigh_3) {
    Cell c = new FredkinCell('-');
    Cell cc = new ConwayCell('*');
    Cell fc = new FredkinCell('0');
    vector<Cell*> neighbors = {&cc, nullptr, &cc, &fc, &fc, &cc, nullptr, &cc};
    ASSERT_EQ(2, c.count_neighbors(neighbors));
}


// ---------
// LifeTest
// ---------

TEST(LifeFixture, test_print_1) {
    ostringstream out;
    Life<ConwayCell> li(1, 1);
    ConwayCell c1('*');
    li.add_cell(c1);
    out << li;
    ASSERT_EQ("Generation = 0, Population = 1.\n*\n\n", out.str());
}

TEST(LifeFixture, test_print_2) {
    ostringstream out;
    Life<FredkinCell> li(1, 1);
    FredkinCell c1('0');
    li.add_cell(c1);
    out << li;
    ASSERT_EQ("Generation = 0, Population = 1.\n0\n\n", out.str());
}

TEST(LifeFixture, test_print_3) {
    ostringstream out;
    Life<Cell> li(1, 2);
    Cell c1 = new FredkinCell('0'); 
    Cell c2 = new FredkinCell('0');
    li.add_cell(c1);
    li.add_cell(c2);
    out << li;
    ASSERT_EQ("Generation = 0, Population = 2.\n00\n\n", out.str());
}

TEST(LifeFixture, test_print_4) {
    ostringstream out;
    Life<Cell> li(1, 2);
    Cell c1 = new ConwayCell('*'); 
    Cell c2 = new ConwayCell('*');
    li.add_cell(c1);
    li.add_cell(c2);
    li.do_generation();
    out << li;
    ASSERT_EQ("Generation = 1, Population = 0.\n..\n\n", out.str());
}

TEST(LifeFixture, test_get_neighbors_1) {
    Life<FredkinCell> li(1, 1);
    FredkinCell c1('0');
    li.add_cell(c1);
    vector<FredkinCell*> neigh = li.get_neighbors(0, 0);
    for(unsigned int i = 0; i < neigh.size(); ++i) {
	ASSERT_EQ(nullptr, neigh[i]);
    }
}

TEST(LifeFixture, test_get_neighbors_2) {
    Life<FredkinCell> li(2, 2);
    FredkinCell c1('0');
    FredkinCell c2('-');
    li.add_cell(c2);
    li.add_cell(c1);
    li.add_cell(c1);
    li.add_cell(c1);
    vector<FredkinCell*> neigh = li.get_neighbors(0, 0);
    for(unsigned int i = 0; i < neigh.size(); ++i) {
	if (i < 4 || i == 5) {
	    ASSERT_EQ(nullptr, neigh[i]);
	} else
	    ASSERT_EQ(c1.rep, (neigh[i])->rep);
    }
}

TEST(LifeFixture, test_get_neighbors_3) {
    Life<ConwayCell> li(2, 2);
    ConwayCell c1('*');
    ConwayCell c2('.');
    li.add_cell(c2);
    li.add_cell(c1);
    li.add_cell(c1);
    li.add_cell(c1);
    vector<ConwayCell*> neigh = li.get_neighbors(0, 0);
    for(unsigned int i = 0; i < neigh.size(); ++i) {
	if (i < 4 || i == 5) {
	    ASSERT_EQ(nullptr, neigh[i]);
	} else
	    ASSERT_EQ(c1.rep, (neigh[i])->rep);
    }
}

TEST(LifeFixture, test_copy_construct_1) {
  Life<ConwayCell> life(1, 1);
  ConwayCell c('*');
  life.add_cell(c);
  
  ostringstream out1;
  ostringstream out2;

  Life<ConwayCell> life2(life);
  out1 << life;
  out2 << life2;

  ASSERT_EQ(out1.str(), out2.str());
}

TEST(LifeFixture, test_copy_construct_2) {
  Life<ConwayCell> life(1, 1);
  ConwayCell c('*');
  life.add_cell(c);
  
  ostringstream out1;
  ostringstream out2;

  Life<ConwayCell> life2(life);
  out1 << life;
  life2.do_generation();
  out2 << life2;

  ASSERT_NE(out1.str(), out2.str());
}

TEST(LifeFixture, test_copy_construct_3) {
  Life<FredkinCell> life(2, 2);
  FredkinCell c('0');
  life.add_cell(c);
  life.add_cell(c);
  life.add_cell(c);
  life.add_cell(c);

  ostringstream out1;
  ostringstream out2;

  Life<FredkinCell> life2(life);
  life.do_generation();
  out1 << life;
  life2.do_generation();
  out2 << life2;

  ASSERT_EQ(out1.str(), out2.str());
}

TEST(LifeFixture, test_assign_1) {
  Life<FredkinCell> life(1, 1);
  FredkinCell c('-');
  life.add_cell(c);

  ostringstream out1;
  ostringstream out2;

  Life<FredkinCell> life2(life);

  out1 << life;
  out2 << life2;

  ASSERT_EQ(out1.str(), out2.str());
}

TEST(LifeFixture, test_assign_2) {
  Life<FredkinCell> life(1, 1);
  FredkinCell c('-');
  life.add_cell(c);

  ostringstream out1;
  ostringstream out2;

  Life<FredkinCell> life2(life);

  out1 << life;
  life2.do_generation();
  out2 << life2;

  ASSERT_NE(out1.str(), out2.str());
}

TEST(LifeFixture, test_assign_3) {
  Life<ConwayCell> life(2, 2);
  ConwayCell c('.');
  life.add_cell(c);
  life.add_cell(c);
  life.add_cell(c);
  life.add_cell(c);  

  ostringstream out1;
  ostringstream out2;
  
  life.do_generation();
  Life<ConwayCell> life2(life);

  out1 << life;
  life2.do_generation();
  out2 << life2;

  ASSERT_NE(out1.str(), out2.str());
}

// Tests whether a cell dies if there are 
// only dead cells around it
TEST(LifeFixture, test_do_generation_1) {
    Life<ConwayCell> life(2, 2);
    ConwayCell c1('*');
    ConwayCell c2('.');
    life.add_cell(c1);
    life.add_cell(c2);
    life.add_cell(c2);
    life.add_cell(c2);
    life.do_generation();
    
    ostringstream out;
    out << life;
    
    ASSERT_EQ("Generation = 1, Population = 0.\n..\n..\n\n", out.str()); 
}

// Tests whether a cell becomes a life if it
// has three neighbors around it
TEST(LifeFixture, test_do_generation_2) {
    Life<ConwayCell> life(2, 2);
    ConwayCell c1('.');
    ConwayCell c2('*');
    life.add_cell(c1);
    life.add_cell(c2);
    life.add_cell(c2);
    life.add_cell(c2);
    life.do_generation();
    
    ostringstream out;
    out << life;
    
    ASSERT_EQ("Generation = 1, Population = 4.\n**\n**\n\n", out.str()); 
}

// Tests whether a fredkin cell becomes dead if 
// two neighbors are dead
TEST(LifeFixture, test_do_generation_3) {
    Life<ConwayCell> life(2, 2);
    ConwayCell c1('*');
    ConwayCell c2('.');
    ConwayCell c3('.');
    ConwayCell c4('.');
    life.add_cell(c1);
    life.add_cell(c2);
    life.add_cell(c3);
    life.add_cell(c4);
    life.do_generation();
    
    ostringstream out;
    out << life;
    
    ASSERT_EQ("Generation = 1, Population = 0.\n..\n..\n\n", out.str());
}

TEST(LifeFixture, test_do_generation_4) {
    Life<FredkinCell> life(2, 2);
    FredkinCell c1('-');
    FredkinCell c2('0');
    FredkinCell c3('0');
    FredkinCell c4('0');
    life.add_cell(c1);
    life.add_cell(c2);
    life.add_cell(c3);
    life.add_cell(c4);
    life.do_generation();
    
    ostringstream out;
    out << life;
    
    ASSERT_EQ("Generation = 1, Population = 2.\n-1\n1-\n\n", out.str());
}
