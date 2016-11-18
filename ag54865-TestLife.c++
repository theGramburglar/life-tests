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

// ------------
// Conway Tests
// ------------

//change state
TEST(LifeFixture, test_1) {
    ConwayCell c1('*');
    c1.numNeighborsAlive = 4;
    c1.changeState();
    ASSERT_FALSE(c1.isAlive);}

TEST(LifeFixture, test_2) {
    ConwayCell c1('*');
    c1.numNeighborsAlive = 1;
    c1.changeState();
    ASSERT_FALSE(c1.isAlive);}

TEST(LifeFixture, test_3) {
    ConwayCell c1('.');
    c1.numNeighborsAlive = 3;
    c1.changeState();
    ASSERT_TRUE(c1.isAlive);}

 TEST(LifeFixture, test_14) {
    ConwayCell c1('*');
    c1.numNeighborsAlive = 0;
    c1.changeState();
    ASSERT_FALSE(c1.isAlive);}

TEST(LifeFixture, test_15) {
    ConwayCell c1('*');
    c1.numNeighborsAlive = 5;
    c1.changeState();
    ASSERT_FALSE(c1.isAlive);}

TEST(LifeFixture, test_16) {
    ConwayCell c1('.');
    c1.numNeighborsAlive = -1;
    c1.changeState();
    ASSERT_FALSE(c1.isAlive);}


//getStatus
TEST(LifeFixture, test_4) {
	ConwayCell cell('.');

	ASSERT_FALSE(cell.getStatus());
}

TEST(LifeFixture, test_5) {
	ConwayCell cell('*');

	ASSERT_TRUE(cell.getStatus());
}

TEST(LifeFixture, test_6) {
	ConwayCell cell('*');

	ASSERT_TRUE(cell.getStatus());
}

//countNeighbors
TEST(LifeFixture, test_7) {
	ConwayCell  cell('*');
	vector<bool> neighborhood(8, false);
	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 0);
}

TEST(LifeFixture, test_8) {
	ConwayCell cell('.');
	vector<bool> neighborhood(8, false);
	neighborhood[0] = true;
	neighborhood[1] = true;
	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 2);
}

TEST(LifeFixture, test_9) {
	ConwayCell cell('.');
	vector<bool> neighborhood(8, false);
	neighborhood[1] = true;
	neighborhood[0] = true;
	neighborhood[3] = true;
	neighborhood[6] = true;
	neighborhood[4] = true;
	neighborhood[7] = true;

	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 6);
}

TEST(LifeFixture, test_10) {
	ConwayCell  cell('*');
	vector<bool> neighborhood(8, false);
	neighborhood[3] = true;
	neighborhood[4] = true;
	neighborhood[7] = true;
	cell.countNeighbors(neighborhood);

	
	ASSERT_TRUE(cell.numNeighborsAlive == 3);
}

TEST(LifeFixture, test_11) {
	ConwayCell cell('.');
	vector<bool> neighborhood(8, false);
	neighborhood[0] = true;
	neighborhood[1] = true;
	neighborhood[6] = true;
	neighborhood[7] = true;
	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 4);
}

TEST(LifeFixture, test_12) {
	ConwayCell cell('.');
	vector<bool> neighborhood(8, false);
	neighborhood[1] = true;
	neighborhood[0] = true;
	neighborhood[3] = true;
	neighborhood[6] = true;
	neighborhood[4] = true;

	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 5);
}

//evolve
TEST(LifeFixture, test_13) {
	ConwayCell cell('*');
	AbstractCell* result = cell.evolve();
	ASSERT_FALSE(result);
}

// ------------
// FredkinCell Tests
// ------------

//changeState
TEST(LifeFixture, f_test_1) {
    FredkinCell f1('0');
    f1.numNeighborsAlive = 2;
    f1.changeState();
    ASSERT_FALSE(f1.isAlive);}

TEST(LifeFixture, f_test_2) {
    FredkinCell f1('-');
    f1.numNeighborsAlive = 1;
    f1.changeState();
    ASSERT_TRUE(f1.isAlive);}

TEST(LifeFixture, f_test_3) {
    FredkinCell f1('0');
    f1.numNeighborsAlive = 0;
    f1.changeState();
    ASSERT_FALSE(f1.isAlive);}

//getStatus
TEST(LifeFixture, f_test_4) {
	FredkinCell cell('-');

	ASSERT_FALSE(cell.getStatus());
}

TEST(LifeFixture, f_test_5) {
	FredkinCell cell('0');

	ASSERT_TRUE(cell.getStatus());
}

TEST(LifeFixture, f_test_6) {
	FredkinCell cell('+');

	ASSERT_TRUE(cell.getStatus());
}

//countNeighbors
TEST(LifeFixture, f_test_7) {
	FredkinCell cell('-');
	vector<bool> neighborhood(8, false);
	neighborhood[1] = true;
	neighborhood[3] = true;
	neighborhood[4] = true;
	neighborhood[6] = true;
	neighborhood[7] = true;

	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 4);
}

TEST(LifeFixture, f_test_8) {
	FredkinCell cell('-');
	vector<bool> neighborhood(8, false);
	neighborhood[0] = true;
	neighborhood[2] = true;
	neighborhood[5] = true;
	neighborhood[7] = true;

	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 0);
}

TEST(LifeFixture, f_test_9) {
	FredkinCell cell('-');
	vector<bool> neighborhood(8, false);
	neighborhood[1] = true;
	neighborhood[3] = true;
	neighborhood[4] = true;
	neighborhood[6] = true;
	neighborhood[7] = true;

	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 4);
}

TEST(LifeFixture, f_test_10) {
	FredkinCell cell('-');
	vector<bool> neighborhood(8, false);
	neighborhood[0] = true;
	neighborhood[1] = true;
	neighborhood[2] = true;
	neighborhood[3] = true;

	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 2);
}

TEST(LifeFixture, f_test_11) {
	FredkinCell cell('-');
	vector<bool> neighborhood(8, false);
	neighborhood[6] = true;

	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 1);
}

TEST(LifeFixture, f_test_12) {
	FredkinCell cell('-');
	vector<bool> neighborhood(8, false);
	neighborhood[5] = true;

	cell.countNeighbors(neighborhood);
	
	ASSERT_TRUE(cell.numNeighborsAlive == 0);
}

//evolve
TEST(LifeFixture, f_test_13) {
	FredkinCell cell('0');
	AbstractCell* result = cell.evolve();
	ASSERT_FALSE(result);
	delete result;
}

TEST(LifeFixture, f_test_14) {
	FredkinCell cell('0');
	cell.turnsAlive = 2;
	AbstractCell* result = cell.evolve();
	ASSERT_TRUE(result);
	delete result;
}

TEST(LifeFixture, f_test_15) {
	FredkinCell cell('-');
	AbstractCell* result = cell.evolve();
	ASSERT_FALSE(result);
	delete result;
}

// ------------
// Cell Tests
// ------------

//changeState
TEST(LifeFixture, c_test_1) {
    Cell c1('0');
    c1.changeState();
    ASSERT_FALSE(c1.getStatus());}

TEST(LifeFixture, c_test_2) {
    Cell c1('*');
    c1.changeState();
    ASSERT_FALSE(c1.getStatus());}

TEST(LifeFixture, c_test_3) {
    Cell c1('.');
    c1.changeState();
    ASSERT_FALSE(c1.getStatus());}

//getStatus
TEST(LifeFixture, c_test_4) {
	Cell cell('*');

	ASSERT_TRUE(cell.getStatus());
}

TEST(LifeFixture, c_test_5) {
	Cell cell('.');

	ASSERT_FALSE(cell.getStatus());
}

TEST(LifeFixture, c_test_6) {
	Cell cell('+');

	ASSERT_TRUE(cell.getStatus());
}

TEST(LifeFixture, c_test_7) {
	Cell cell('-');

	ASSERT_FALSE(cell.getStatus());
}

TEST(LifeFixture, c_test_8) {
	Cell cell('0');

	ASSERT_TRUE(cell.getStatus());
}

//countNeighbors
TEST(LifeFixture, c_test_9) {
	Cell cell('-');
	vector<bool> neighborhood(8, false);
	neighborhood[1] = true;

	cell.countNeighbors(neighborhood);
	AbstractCell* ac = cell.p;
	ASSERT_TRUE((*ac).numNeighborsAlive == 1);
}

TEST(LifeFixture, c_test_10) {
	Cell cell('*');
	vector<bool> neighborhood(8, false);
	neighborhood[1] = true;

	cell.countNeighbors(neighborhood);
	AbstractCell* ac = cell.p;
	ASSERT_TRUE((*ac).numNeighborsAlive == 1);
}

TEST(LifeFixture, c_test_11) {
	Cell cell('-');
	vector<bool> neighborhood(8, false);
	neighborhood[0] = true;

	cell.countNeighbors(neighborhood);
	AbstractCell* ac = cell.p;
	ASSERT_TRUE((*ac).numNeighborsAlive == 0);
}

// ------------
// Life Tests
// ------------

//ReadInt
TEST(LifeFixture, read) {
    istringstream r("1\n");
    Life<ConwayCell> c;
    int           i;
    const bool b = c.readInt(r, i);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
}

TEST(LifeFixture, read1) {
    istringstream r("10\n");
    Life<ConwayCell> c;
    int           i;
    const bool b = c.readInt(r, i);
    ASSERT_TRUE(b);
    ASSERT_EQ( 10, i);
}

TEST(LifeFixture, read2) {
    istringstream r("100\n");
    Life<ConwayCell> c;
    int           i;
    const bool b = c.readInt(r, i);
    ASSERT_TRUE(b);
    ASSERT_EQ( 100, i);
}

TEST(LifeFixture, read3) {
    istringstream r("c\n");
    Life<ConwayCell> c;
    int           i;
    const bool b = c.readInt(r, i);
    ASSERT_FALSE(b);
}

TEST(LifeFixture, read4) {
    istringstream r("string\n");
    Life<ConwayCell> c;
    int           i;
    const bool b = c.readInt(r, i);
    ASSERT_FALSE(b);
}

TEST(LifeFixture, read5) {
    istringstream r("507\n");
    Life<ConwayCell> c;
    int           i;
    const bool b = c.readInt(r, i);
    ASSERT_TRUE(b);
    ASSERT_EQ( 507, i);
}

//readGrid
TEST(LifeFixture, life) {
    istringstream r("21 13\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	"....*****....\n"
    	".......*.....\n"
    	"......*......\n"
    	".....*.......\n"
    	"....*****....\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n");

    Life<ConwayCell> c;
    c.readGrid(r);
    int height = c.height;
    int width = c.width;
    ASSERT_EQ( height, 21);
    ASSERT_EQ(width, 13);
}

TEST(LifeFixture, life2) {
    istringstream r("21 13\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	"....*****....\n"
    	".......*.....\n"
    	"......*......\n"
    	".....*.......\n"
    	"....*****....\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n");

    Life<ConwayCell> c;
    c.readGrid(r);
    ASSERT_FALSE(c.cellBoard[0][0].getStatus());
}

TEST(LifeFixture, life3) {
    istringstream r("21 13\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	"....*****....\n"
    	".......*.....\n"
    	"......*......\n"
    	".....*.......\n"
    	"....*****....\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n");

    Life<ConwayCell> c;
    c.readGrid(r);
    ASSERT_TRUE(c.cellBoard[8][4].getStatus());
}

//updateNeighbors
TEST(LifeFixture, life4) {
    istringstream r("21 13\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	"....*****....\n"
    	".......*.....\n"
    	"......*......\n"
    	".....*.......\n"
    	"....*****....\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n");

    Life<ConwayCell> c;
    c.readGrid(r);
    c.updateNeighbors();
    ASSERT_EQ(c.cellBoard[8][4].numNeighborsAlive, 1);
}

TEST(LifeFixture, life5) {
    istringstream r("21 13\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	"....*****....\n"
    	".......*.....\n"
    	"......*......\n"
    	".....*.......\n"
    	"....*****....\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n");

    Life<ConwayCell> c;
    c.readGrid(r);
    c.updateNeighbors();
    ASSERT_EQ(c.cellBoard[8][5].numNeighborsAlive, 2);
}

TEST(LifeFixture, life6) {
    istringstream r("21 13\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	"....*****....\n"
    	".......*.....\n"
    	"......*......\n"
    	".....*.......\n"
    	"....*****....\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n");

    Life<ConwayCell> c;
    c.readGrid(r);
    c.updateNeighbors();
    ASSERT_EQ(c.cellBoard[8][6].numNeighborsAlive, 3);
}

//runSimulation
TEST(LifeFixture, life7) {
    istringstream r("21 13\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	"....*****....\n"
    	".......*.....\n"
    	"......*......\n"
    	".....*.......\n"
    	"....*****....\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n");

    Life<ConwayCell> c;
    c.readGrid(r);
    c.runSimulation(4, false);
    ASSERT_EQ(c.population, 16);
}

TEST(LifeFixture, life8) {
    istringstream r("21 13\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	"....*****....\n"
    	".......*.....\n"
    	"......*......\n"
    	".....*.......\n"
    	"....*****....\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n");

    Life<ConwayCell> c;
    c.readGrid(r);
    c.runSimulation(8, false);
    ASSERT_EQ(c.population, 18);
}

TEST(LifeFixture, life9) {
    istringstream r("21 13\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	"....*****....\n"
    	".......*.....\n"
    	"......*......\n"
    	".....*.......\n"
    	"....*****....\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n"
    	".............\n");

    Life<ConwayCell> c;
    c.readGrid(r);
    c.runSimulation(12, false);
    ASSERT_EQ(c.population, 10);
}
