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
#include <sstream>	// string
#include <string>	// istreamstring, ostreamstring
#include "Life.h"

using namespace std;

//-----------------
//LifeConstructor
//-----------------

TEST(LifeConstructor, dimensions) {
	const string dimensions = "3 2\n..\n..\n..\n\n";
	istringstream in(dimensions);
	Life<Cell> life(in);
	bool test1 = (life.numOfRows == 3);
	bool test2 = (life.numOfColumns == 2);
	ASSERT_EQ(test1 && test2, true);
}

TEST(LifeConstructor, grid1) {
	const string game = "2 2\n..\n..\n\n";
	istringstream in(game);
	Life<Cell> life(in);
	bool test = ( (life.liveGrid[0])[0] == '.' && (life.liveGrid[0])[1] == '.' && (life.liveGrid[1])[0] == '.' && (life.liveGrid[1])[1] == '.' );
	ASSERT_EQ(test, true);
}

TEST(LifeConstructor, grid2) {
	const string game = "3 2\n-0\n0-\n00\n\n";
	istringstream in(game);
	Life<FredkinCell> life(in);
	bool test = ( (life.liveGrid[0])[0] == '-' && (life.liveGrid[0])[1] == '0' && (life.liveGrid[1])[0] == '0' && (life.liveGrid[1])[1] == '-' && (life.liveGrid[2])[0] == '0' && (life.liveGrid[2])[1] == '0');
	ASSERT_EQ(test, true);
}




//----------
//InitGrid
//----------


TEST(InitGrid, badInput) {

	try {
        const string badInput = "zomglol\n\n";
        istringstream in(badInput);
		Life<ConwayCell> life(in);
    	ASSERT_EQ(false, true);
    }
    catch(std::invalid_argument& e) {
        EXPECT_EQ(e.what(),string("Invalid argument"));
    }
}

TEST(InitGrid, goodInput1) {
	const string game = "2 2\n.-\n*0\n\n";
	istringstream in(game);
	Life<Cell> life(in);
	bool test = ( (life.liveGrid[0][0] == '.') && (life.liveGrid[0][1] == '-') && (life.liveGrid[1][0] == '*') && (life.liveGrid[1][1] == '0'));
	ASSERT_EQ(test, true);
}

TEST(InitGrid, goodInput2) {
	const string game = "1 1\n-\n\n";
	istringstream in(game);
	Life<FredkinCell> life(in);
	bool test = (life.liveGrid[0][0] == '-');
	ASSERT_EQ(test, true);
}






//---------
// Evolve
//---------

TEST(Evolve, test1) {
	const string game = "3 2\n0-\n00\n00\n\n";
	istringstream in(game);
	Life<FredkinCell> life(in);
	bool test = (life.liveGrid[1][0] == '0') && (life.liveGrid[1][1] == '0');
	life.saveGrid();
	life.evolve();
	test = test && (life.liveGrid[1][0] == '1') && (life.liveGrid[1][1] == '-');
	ASSERT_EQ(test, true);
}

TEST(Evolve, test2) {
	const string game = "3 2\n**\n**\n**\n\n";
	istringstream in(game);
	Life<ConwayCell> life(in);
	bool test = (life.liveGrid[0][0] == '*') && (life.liveGrid[1][1] == '*');
	life.saveGrid();
	life.evolve();
	test = test && (life.liveGrid[0][0] == '*') && (life.liveGrid[1][1] == '.');
	ASSERT_EQ(test, true);
}



//-----------
// simulate
//-----------

TEST(LifeSimulate, fredkinCell) {
	const string game = "3 2\n0-\n00\n00\n\n";
	istringstream in(game);
	ostringstream garbage;
	Life<FredkinCell> life(in);
	bool test = (life.liveGrid[1][0] == '0') && (life.liveGrid[1][1] == '0');
	life.simulate(1, 0, 0, garbage);
	test = test && (life.liveGrid[1][0] == '1') && (life.liveGrid[1][1] == '-');
	ASSERT_EQ(test, true);
}

TEST(LifeSimulate, conwayCell) {
	const string game = "3 2\n**\n**\n**\n\n";
	istringstream in(game);
	ostringstream garbage;
	Life<ConwayCell> life(in);
	bool test = (life.liveGrid[0][0] == '*') && (life.liveGrid[1][1] == '*');
	life.simulate(1, 0, 0, garbage);
	test = test && (life.liveGrid[0][0] == '*') && (life.liveGrid[1][1] == '.');
	ASSERT_EQ(test, true);
}

TEST(LifeSimulate, cell) {
	const string game = "3 2\n00\n00\n0-\n\n";
	istringstream in(game);
	ostringstream garbage;
	Life<Cell> life(in);
	bool test = (life.liveGrid[1][0] == '0') && (life.liveGrid[0][1] == '0');
	life.simulate(2, 0, 0, garbage);
	test = test && (life.liveGrid[1][0] == '*') && (life.liveGrid[0][1] == '-');
	ASSERT_EQ(test, true);
}




//----------
// SaveGrid
//----------


TEST(SaveGrid, test1) {
	const string game = "1 2\n..\n\n";
	istringstream in(game);
	Life<Cell> life(in);
	life.saveGrid();
	ASSERT_EQ(life.staticGrid[0][1], '.');
}

TEST(SaveGrid, test2) {
	const string game = "2 1\n-\n0\n\n";
	istringstream in(game);
	Life<FredkinCell> life(in);
	life.saveGrid();
	ASSERT_EQ(life.staticGrid[1][0], '0');
}



//------------
// PrintGrid
//------------


TEST(PrintGrid, test1) {
	const string game = "2 1\n-\n0\n\n";
	istringstream in(game);
	ostringstream w;
	Life<FredkinCell> life(in);
	life.printGrid(w);
	ASSERT_EQ(w.str(), "\nGeneration = 0, Population = 1.\n-\n0\n\n");
}

TEST(PrintGrid, test2) {
	const string game = "2 2\n-0\n00\n\n";
	istringstream in(game);
	ostringstream w;
	Life<Cell> life(in);
	life.printGrid(w);
	ASSERT_EQ(w.str(), "\nGeneration = 0, Population = 3.\n-0\n00\n\n");
}



//-------------------
// LivingPopulation
//-------------------

TEST(LivingPopulation, test1) {
	const string game = "2 2\n-0\n00\n\n";
	istringstream in(game);
	Life<Cell> life(in);
	life.saveGrid();
	ASSERT_EQ(life.livingPopulation(), 3);
}

TEST(LivingPopulation, test2) {
	const string game = "2 2\n**\n00\n\n";
	istringstream in(game);
	Life<Cell> life(in);
	life.saveGrid();
	ASSERT_EQ(life.livingPopulation(), 4);	
}

TEST(LivingPopulation, test3){
	const string game = "2 2\n--\n..\n";
	istringstream in(game);
	Life<Cell> life(in);
	life.saveGrid();
	ASSERT_EQ(life.livingPopulation(), 0);
}




//--------
// Split
//--------

TEST(Split, test1) {
	const string game = "1 1\n0\n\n";
	istringstream in(game);
	Life<Cell> life(in);
	const string test = "Hello World!";
	vector<string> answer = life.split(test, ' ');
	ASSERT_EQ(answer[1], "World!");
}

TEST(Split, test2) {
	const string game = "1 1\n0\n\n";
	istringstream in(game);
	Life<Cell> life(in);
	const string test = "Hello World!";
	vector<string> answer = life.split(test, 'e');
	ASSERT_EQ(answer[1], "llo World!");
}

TEST(Split, test3) {
	const string game = "1 1\n0\n\n";
	istringstream in(game);
	Life<Cell> life(in);
	const string test = "Hello World!";
	vector<string> answer = life.split(test, '7');
	ASSERT_EQ(answer[0], "Hello World!");
}


//-----------
// PrintCell
//-----------

TEST(PrintCell, test1) {
	char temp = '9';
	int temp1 = 1;
	int temp2 = 0;
	AbstractCell cell(temp, temp1, temp2);
	ostringstream w;
	cell.print(w);
	ASSERT_EQ(w.str(), "9");
}

TEST(PrintCell, test2) {
	char temp = 'Q';
	int temp1 = 1;
	int temp2 = 0;
	AbstractCell cell(temp, temp1, temp2);
	ostringstream w;
	cell.print(w);
	ASSERT_EQ(w.str(), "Q");
}



//-----------
// CopyInto
//-----------

TEST(CopyInto, test1) {
	char temp = '4';
	int tmp1 = 1;
	int tmp2 = 0;
	AbstractCell cell(temp, tmp1, tmp2);
	char w = 'F';
	cell.copyInto(w);
	ASSERT_EQ(w, '4');
}

TEST(CopyInto, test2) {
	char temp = 'Q';
	int temp1 = 1;
	int temp2 = 0;
	AbstractCell cell(temp, temp1, temp2);
	char w = 'F';
	cell.copyInto(w);
	ASSERT_EQ(w, 'Q');
}






//----------------
// FindNeighbors
//----------------



TEST(FindNeighbors, test1) {
	int tmp1 = 1;
	int tmp2 = 0;
	vector<char> temp{'*','*'};
	vector<vector<char>> grid;
	grid.push_back(temp);
	grid.push_back(temp);
	grid.push_back(temp);



	AbstractCell* cell = new ConwayCell(grid[1][0], tmp1, tmp2);
	ASSERT_EQ(cell->findLivingNeighbors(grid), 5);
}
	
TEST(FindNeighbors, test2) {
	int tmp1 = 1;
	int tmp2 = 1;
	vector<char> temp{'*','0'};
	vector<vector<char>> grid;
	grid.push_back(temp);
	grid.push_back(temp);
	grid.push_back(temp);

	AbstractCell* cell = new FredkinCell(grid[1][1], tmp1, tmp2);
	ASSERT_EQ(cell->findLivingNeighbors(grid), 3);
}

TEST(FindNeigbors, test3) {
	int tmp1 = 1;
	int tmp2 = 1;
	vector<char> temp{'.','.'};
	vector<char> temp2{'.','*'};
	vector<vector<char>> grid;
	grid.push_back(temp);
	grid.push_back(temp2);
	grid.push_back(temp);

	AbstractCell* cell = new ConwayCell(grid[0][1], tmp1, tmp2);
	ASSERT_EQ(cell->findLivingNeighbors(grid), 0);
}

TEST(FindNeighbors, test4) {
	int tmp1 = 1;
	int tmp2 = 0;
	vector<char> temp{'.','.'};
	vector<char> temp2{'0','.'};
	vector<vector<char>> grid;
	grid.push_back(temp);
	grid.push_back(temp2);
	grid.push_back(temp);

	AbstractCell* cell = new FredkinCell(grid[1][0], tmp1, tmp2);
	ASSERT_EQ(cell->findLivingNeighbors(grid), 0);
}




//--------
// Evolve
//--------

TEST(CellEvolve, test1) {
	int tmp1 = 1;
	int tmp2 = 0;
	vector<char> temp{'-','-'};
	vector<char> temp2{'0','0'};
	vector<vector<char>> grid;
	grid.push_back(temp);
	grid.push_back(temp2);
	grid.push_back(temp);

	AbstractCell* cell = new FredkinCell(grid[1][0], tmp1, tmp2);
	cell->evolve(grid);
	cell->evolve(grid);
	ASSERT_EQ(cell->symbol, '2');
}

TEST(CellEvolve, test2) {
	int tmp1 = 1;
	int tmp2 = 0;
	vector<char> temp{'-','-'};
	vector<char> temp2{'0','-'};
	vector<vector<char>> grid;
	grid.push_back(temp);
	grid.push_back(temp2);
	grid.push_back(temp);

	AbstractCell* cell = new FredkinCell(grid[1][0], tmp1, tmp2);
	cell->evolve(grid);
	cell->evolve(grid);
	ASSERT_EQ(cell->symbol, '-');
}

TEST(CellEvolve, test3) {
	int tmp1 = 1;
	int tmp2 = 0;
	vector<char> temp{'*','.'};
	vector<char> temp2{'*','.'};
	vector<vector<char>> grid;
	grid.push_back(temp);
	grid.push_back(temp2);
	grid.push_back(temp);

	AbstractCell* cell = new ConwayCell(grid[1][0], tmp1, tmp2);
	cell->evolve(grid);
	cell->evolve(grid);
	ASSERT_EQ(cell->symbol, '*');
}

TEST(CellEvolve, test4) {
	int tmp1 = 1;
	int tmp2 = 0;
	vector<char> temp{'-','-'};
	vector<char> temp2{'1','0'};
	vector<vector<char>> grid;
	grid.push_back(temp);
	grid.push_back(temp2);
	grid.push_back(temp);

	AbstractCell* cell = new FredkinCell(grid[1][0], tmp1, tmp2);
	((FredkinCell*)cell)->age = 1;
	ASSERT_EQ(cell->cellEvolve(grid), true);
}

TEST(CellClone, test1) {
	int tmp1 = 1;
	int tmp2 = 0;
	vector<char> temp{'-','-'};
	vector<char> temp2{'1','0'};
	vector<vector<char>> grid;
	grid.push_back(temp);
	grid.push_back(temp2);
	grid.push_back(temp);

	AbstractCell* cell = new FredkinCell(grid[1][0], tmp1, tmp2);
	AbstractCell* answer = ((FredkinCell*)cell)->clone();
	ASSERT_EQ(answer->symbol, '*');
}
