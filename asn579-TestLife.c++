// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------
#include <sstream>
#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, constructor_1) 
{
	Life<ConwayCell> life;
	ASSERT_EQ(life.gen,0);
	ASSERT_EQ(life.pop,0);

}
TEST(LifeFixture, constructor_2) 
{
	Life<FredkinCell> life;
	ASSERT_EQ(life.gen,0);
	ASSERT_EQ(life.pop,0);

}
TEST(LifeFixture, constructor_3) 
{
	Life<Cell> life;
	ASSERT_EQ(life.gen,0);
	ASSERT_EQ(life.pop,0);

}
TEST(LifeFixture, read_in_1)
{
	istringstream r("1 1\n1");
	Life<ConwayCell>life;
	life.read_in(r);
	ASSERT_EQ(life.world.size(),1);
	ASSERT_EQ(life.world[0].size(),1);
}
TEST(LifeFixture, read_in_2)
{
	istringstream r("2 2\n*.\n.*");
	Life<ConwayCell>life;
	life.read_in(r);
	ASSERT_EQ(life.gen,0);
	ASSERT_EQ(life.pop,2);
}
TEST(LifeFixture, read_in_3)
{
	istringstream r("2 2\n**\n**");
	Life<ConwayCell>life;
	life.read_in(r);
	ASSERT_EQ(life.gen,0);
	ASSERT_EQ(life.pop,4);
}
TEST(LifeFixture, turn_1)
{
	istringstream r("3 3\n.*.\n.*.\n.*.");
	Life<ConwayCell>life;
	life.read_in(r);
	life.turn();
	ASSERT_EQ(life.gen,1);
	ASSERT_EQ(life.pop,3);
}
TEST(LifeFixture, turn_2)
{
	istringstream r("3 3\n---\n-1-\n---");
	Life<FredkinCell>life;
	life.read_in(r);
	life.turn();
	ASSERT_EQ(life.gen,1);
	ASSERT_EQ(life.pop,4);
}
TEST(LifeFixture,turn_3)
{
	istringstream r("3 3\n-1-\n-1-\n-1-");
	Life<Cell>life;
	life.read_in(r);
	life.turn();
	ASSERT_EQ(life.gen,1);
	ASSERT_EQ(life.pop,8);
}
TEST(LifeFixture, print_1)
{
	istringstream r("3 3\n---\n-1-\n---");
	ostringstream w;
	Life<FredkinCell>life;
	life.read_in(r);
	life.turn();
	life.print(w);
	ASSERT_EQ("\nGeneration = 1, Population = 4.\n-0-\n0-0\n-0-\n",w.str());
}
TEST(LifeFixture, print_2)
{
	istringstream r("3 3\n.*.\n.*.\n.*.");
	ostringstream w;
	Life<ConwayCell>life;
	life.read_in(r);
	life.turn();
	life.print(w);
	ASSERT_EQ("\nGeneration = 1, Population = 3.\n...\n***\n...\n",w.str());
}
TEST(LifeFixture,print_3)
{
	istringstream r("3 3\n-1-\n-1-\n-1-");
	ostringstream w;
	Life<Cell>life;
	life.read_in(r);
	life.turn();
	life.print(w);
	ASSERT_EQ("\nGeneration = 1, Population = 8.\n0*0\n0-0\n0*0\n",w.str());
}
TEST(ConwayCellFixture,constructor_1)
{
	ConwayCell c(true);
	ASSERT_TRUE(c.am_alive());
}
TEST(ConwayCellFixture,constructor_2)
{
	ConwayCell c(false);
	ASSERT_FALSE(c.am_alive());
}
TEST(ConwayCellFixture,read_1)
{
	ConwayCell c(false);
	ASSERT_FALSE(c.am_alive());
	istringstream r("*");
	c.read(r);
	ASSERT_TRUE(c.am_alive());
}
TEST(ConwayCellFixture,read_2)
{
	ConwayCell c(true);
	ASSERT_TRUE(c.am_alive());
	istringstream r(".");
	c.read(r);
	ASSERT_FALSE(c.am_alive());
}
TEST(ConwayCellFixture,write_1)
{
	ConwayCell c(true);
	ostringstream w;
	c.write(w);
	ASSERT_EQ("*",w.str());
}
TEST(ConwayCellFixture,write_2)
{
	ConwayCell c(false);
	ostringstream w;
	c.write(w);
	ASSERT_EQ(".",w.str());
}
TEST(ConwayCellFixture,clone)
{
	ConwayCell a(true);
	ConwayCell b = a.clone();
	ASSERT_TRUE(b.am_alive());
}
TEST(ConwayCellFixture, evolve_1)
{
	bool b[] = {0,1,0,1,0,1,0,1};
	ConwayCell a(true);
	bool temp = a.evolve(b);
	ASSERT_FALSE(a.am_alive());
}
TEST(ConwayCellFixture, evolve_2)
{
	bool b[] = {0,1,0,1,0,1,0,0};
	ConwayCell a(false);
	bool temp = a.evolve(b);
	ASSERT_TRUE(a.am_alive());
}
TEST(FredkinCellFixture, constructor_1)
{
	FredkinCell a(true);
	ASSERT_TRUE(a.am_alive());
}
TEST(FredkinCellFixture, constructor_2)
{
	FredkinCell a(false);
	ASSERT_FALSE(a.am_alive());
}
TEST(FredkinCellFixture, read_1)
{
	FredkinCell a(false);
	istringstream r("9");
	a.read(r);
	ASSERT_TRUE(a.am_alive());
}
TEST(FredkinCellFixture, read_2)
{
	FredkinCell a(false);
	istringstream r("+");
	a.read(r);
	ASSERT_TRUE(a.am_alive());
}
TEST(FredkinCellFixture, read_3)
{
	FredkinCell a(true);
	istringstream r("-");
	a.read(r);
	ASSERT_FALSE(a.am_alive());
}
TEST(FredkinCellFixture, write_1)
{
	FredkinCell a(false);
	ostringstream w;
	a.write(w);
	ASSERT_EQ("-",w.str());
}
TEST(FredkinCellFixture, write_2)
{
	FredkinCell a(true);
	ostringstream w;
	a.write(w);
	ASSERT_EQ("0",w.str());
}
TEST(FredkinCellFixture, write_3)
{
	FredkinCell a(true);
	a.age = 10;
	ostringstream w;
	a.write(w);
	ASSERT_EQ("+",w.str());
}
TEST(FredkinCellFixture,clone)
{
	FredkinCell a(true);
	FredkinCell b = a.clone();
	ASSERT_TRUE(b.am_alive());
}
TEST(FredkinCellFixture,evolve_1)
{
	FredkinCell a(true);
	bool b[] = {1,1,1,1,1,1,1,1};
	a.evolve(b);
	ASSERT_FALSE(a.am_alive());
}
TEST(FredkinCellFixture,evolve_2)
{
	FredkinCell a(false);
	bool b[] = {0,1,0,0,0,0,0,0};
	a.evolve(b);
	ASSERT_TRUE(a.am_alive());
}







































