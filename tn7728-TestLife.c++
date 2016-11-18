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
#include <sstream>
#include <string>

#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, life_constructor_1) {

    vector<vector<ConwayCell*>> temp_grid;

    istringstream testinput("2 5\n"
						   ".....\n"
						   "*****\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<ConwayCell> CC_LifeTest1;
    for(int i = 0; i<r; ++i)
    {
        temp_grid.push_back(vector<ConwayCell*>());
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            CC_LifeTest1.push_back(ConwayCell(temp));
        }
    }

    Life<ConwayCell> LifeTest1(r, c, &CC_LifeTest1);
    LifeTest1.print_grid(testoutput);

    ASSERT_EQ(r, 2);
    ASSERT_EQ(c, 5);
    ASSERT_EQ(testoutput.str(), "\n.....\n"
    							"*****\n\n");

}

TEST(LifeFixture, life_constructor_2) {

    vector<vector<ConwayCell*>> temp_grid2;

    istringstream testinput("5 5\n"
                           ".....\n"
                           "**.**\n"
                           "*...*\n"
                           "**.**\n"
                           ".....\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<ConwayCell> CC_LifeTest2;
    for(int i = 0; i<r; ++i)
    {
        temp_grid2.push_back(vector<ConwayCell*>());
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            CC_LifeTest2.push_back(ConwayCell(temp));
        }
    }

    Life<ConwayCell> LifeTest2(r, c, &CC_LifeTest2);
    LifeTest2.print_grid(testoutput);

    ASSERT_EQ(r, 5);
    ASSERT_EQ(c, 5);
    ASSERT_EQ(testoutput.str(),  "\n.....\n"
                                 "**.**\n"
                                 "*...*\n"
                                 "**.**\n"
                                 ".....\n\n");

}

TEST(LifeFixture, life_constructor_3) {

    istringstream testinput("2 5\n"
                           "--0--\n"
                           "00-00\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<FredkinCell> FC_LifeTest3;
    for(int i = 0; i<r; ++i)
    {
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            FC_LifeTest3.push_back(FredkinCell(temp));
        }
    }

    Life<FredkinCell> LifeTest3(r, c, &FC_LifeTest3);
    LifeTest3.print_grid(testoutput);

    ASSERT_EQ(r, 2);
    ASSERT_EQ(c, 5);
    ASSERT_EQ(testoutput.str(), "\n--0--\n"
                                "00-00\n\n");

}

TEST(LifeFixture, life_turn_life_1) {

    vector<vector<ConwayCell*>> temp_grid;

    istringstream testinput("2 5\n"
                           ".....\n"
                           "*****\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<ConwayCell> CC_LifeTest1;
    for(int i = 0; i<r; ++i)
    {
        temp_grid.push_back(vector<ConwayCell*>());
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            CC_LifeTest1.push_back(ConwayCell(temp));
        }
    }

    Life<ConwayCell> LifeTest1(r, c, &CC_LifeTest1);
    LifeTest1.turn_life();
    LifeTest1.print_grid(testoutput);

    ASSERT_EQ(r, 2);
    ASSERT_EQ(c, 5);
    ASSERT_EQ(testoutput.str(), "\n.***.\n"
                                ".***.\n\n");

}


TEST(LifeFixture, life_turn_life_2) {

    vector<vector<ConwayCell*>> temp_grid2;

    istringstream testinput("5 5\n"
                           ".....\n"
                           "**.**\n"
                           "*...*\n"
                           "**.**\n"
                           ".....\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<ConwayCell> CC_LifeTest2;
    for(int i = 0; i<r; ++i)
    {
        temp_grid2.push_back(vector<ConwayCell*>());
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            CC_LifeTest2.push_back(ConwayCell(temp));
        }
    }

    Life<ConwayCell> LifeTest2(r, c, &CC_LifeTest2);
    LifeTest2.turn_life();
    LifeTest2.print_grid(testoutput);

    ASSERT_EQ(r, 5);
    ASSERT_EQ(c, 5);
    ASSERT_EQ(testoutput.str(),  "\n.....\n"
                                 "**.**\n"
                                 ".....\n"
                                 "**.**\n"
                                 ".....\n\n");

}

TEST(LifeFixture, life_turn_life_3) {

    istringstream testinput("2 5\n"
                           "--0--\n"
                           "00-00\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<FredkinCell> FC_LifeTest3;
    for(int i = 0; i<r; ++i)
    {
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            FC_LifeTest3.push_back(FredkinCell(temp));
        }
    }

    Life<FredkinCell> LifeTest3(r, c, &FC_LifeTest3);
    LifeTest3.turn_life();
    LifeTest3.turn_life();
    LifeTest3.print_grid(testoutput);

    ASSERT_EQ(r, 2);
    ASSERT_EQ(c, 5);
    ASSERT_EQ(testoutput.str(), "\n1-0-1\n"
                                "-----\n\n");

}

TEST(LifeFixture, life_print_grid_1) {

    vector<vector<ConwayCell*>> temp_grid;

    istringstream testinput("5 10\n"
                           "..........\n"
                           "**********\n"
                           "..........\n"
                           "**********\n"
                           "..........\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<ConwayCell> CC_LifePrint1;
    for(int i = 0; i<r; ++i)
    {
        temp_grid.push_back(vector<ConwayCell*>());
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            CC_LifePrint1.push_back(ConwayCell(temp));
        }
    }

    Life<ConwayCell> LifePrint1(r, c, &CC_LifePrint1);
    LifePrint1.print_grid(testoutput);

    ASSERT_EQ(r, 5);
    ASSERT_EQ(c, 10);
    ASSERT_EQ(testoutput.str(),  "\n..........\n"
                                 "**********\n"
                                 "..........\n"
                                 "**********\n"
                                 "..........\n\n");

}

TEST(LifeFixture, life_print_grid_2) {

    vector<vector<ConwayCell*>> temp_grid;

    istringstream testinput("10 1\n"
                           ".\n"
                           ".\n"
                           ".\n"
                           ".\n"
                           ".\n"
                           ".\n"
                           ".\n"
                           ".\n"
                           ".\n"
                           ".\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<ConwayCell> CC_LifePrint2;
    for(int i = 0; i<r; ++i)
    {
        temp_grid.push_back(vector<ConwayCell*>());
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            CC_LifePrint2.push_back(ConwayCell(temp));
        }
    }

    Life<ConwayCell> LifePrint1(r, c, &CC_LifePrint2);
    LifePrint1.print_grid(testoutput);

    ASSERT_EQ(r, 10);
    ASSERT_EQ(c, 1);
    ASSERT_EQ(testoutput.str(),  "\n.\n"
                                 ".\n"
                                 ".\n"
                                 ".\n"
                                 ".\n"
                                 ".\n"
                                 ".\n"
                                 ".\n"
                                 ".\n"
                                 ".\n\n");
}

TEST(LifeFixture, life_print_grid_3) {

    vector<vector<ConwayCell*>> temp_grid;

    istringstream testinput("1 10\n"
                           "..........\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<ConwayCell> CC_LifePrint2;
    for(int i = 0; i<r; ++i)
    {
        temp_grid.push_back(vector<ConwayCell*>());
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            CC_LifePrint2.push_back(ConwayCell(temp));
        }
    }

    Life<ConwayCell> LifePrint1(r, c, &CC_LifePrint2);
    LifePrint1.print_grid(testoutput);

    ASSERT_EQ(r, 1);
    ASSERT_EQ(c, 10);
    ASSERT_EQ(testoutput.str(),  "\n..........\n\n");

}

TEST(LifeFixture, life_count_alive_cells_1) {

    vector<vector<ConwayCell*>> temp_grid;

    istringstream testinput("2 5\n"
                           ".....\n"
                           "*****\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<ConwayCell> CC_AliveTest1;
    for(int i = 0; i<r; ++i)
    {
        temp_grid.push_back(vector<ConwayCell*>());
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            CC_AliveTest1.push_back(ConwayCell(temp));
        }
    }

    Life<ConwayCell> LifeTest1(r, c, &CC_AliveTest1);

    ASSERT_EQ(r, 2);
    ASSERT_EQ(c, 5);
    ASSERT_EQ(LifeTest1.count_alive_cells(), 5);

}

TEST(LifeFixture, life_count_alive_cells_2) {

    vector<vector<ConwayCell*>> temp_grid;

    istringstream testinput("2 5\n"
                           ".....\n"
                           "*****\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<ConwayCell> CC_AliveTest1;
    for(int i = 0; i<r; ++i)
    {
        temp_grid.push_back(vector<ConwayCell*>());
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            CC_AliveTest1.push_back(ConwayCell(temp));
        }
    }

    Life<ConwayCell> LifeTest1(r, c, &CC_AliveTest1);
    LifeTest1.turn_life();

    ASSERT_EQ(r, 2);
    ASSERT_EQ(c, 5);
    ASSERT_EQ(LifeTest1.count_alive_cells(), 6);

}

TEST(LifeFixture, life_count_alive_cells_3) {

    istringstream testinput("2 5\n"
                           "--0--\n"
                           "00-00\n");

    ostringstream testoutput;

    int r, c;
    testinput >> r >> c;
    vector<FredkinCell> FC_LifeTest3;
    for(int i = 0; i<r; ++i)
    {
        for(int j = 0; j<c; ++j)
        {
            char temp;
            testinput >> temp;
            FC_LifeTest3.push_back(FredkinCell(temp));
        }
    }

    Life<FredkinCell> LifeTest3(r, c, &FC_LifeTest3);
    LifeTest3.turn_life();
    LifeTest3.turn_life();

    ASSERT_EQ(r, 2);
    ASSERT_EQ(c, 5);
    ASSERT_EQ(LifeTest3.count_alive_cells(), 3);

}

TEST(CellFixture, cell_constructor_1) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

	Cell c(&fred_alive);
	
	ostringstream testoutput;

	c.print(testoutput);

	ASSERT_EQ(testoutput.str(), "0");

}

TEST(CellFixture, cell_constructor_2) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell c2(&con_alive);
    
    ostringstream testoutput;

    c2.print(testoutput);

    ASSERT_EQ(testoutput.str(), "*");

}

TEST(CellFixture, cell_constructor_3) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell c3(&con_dead);
    Cell c4(&fred_dead);
    
    ostringstream testoutput;

    c3.print(testoutput);
    c4.print(testoutput);

    ASSERT_EQ(testoutput.str(), ".-");

}

TEST(CellFixture, cell_print_1) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell c5(&con_dead);
    Cell c6(&con_dead);
    Cell c7(&con_dead);
    Cell c8(&con_dead);
    Cell c9(&con_dead);
    Cell c10(&con_dead);
    
    ostringstream testoutput;

    c5.print(testoutput);
    c6.print(testoutput);
    c7.print(testoutput);
    c8.print(testoutput);
    c9.print(testoutput);
    c10.print(testoutput);

    ASSERT_EQ(testoutput.str(), "......");

}

TEST(CellFixture, cell_print_2) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell c11(&con_alive);
    Cell c12(&con_alive);
    Cell c13(&con_alive);
    Cell c14(&con_alive);
    Cell c15(&con_alive);
    Cell c16(&con_alive);
    
    ostringstream testoutput;

    c11.print(testoutput);
    c12.print(testoutput);
    c13.print(testoutput);
    c14.print(testoutput);
    c15.print(testoutput);
    c16.print(testoutput);

    ASSERT_EQ(testoutput.str(), "******");

}

TEST(CellFixture, cell_print_3) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell c17(&con_dead);
    Cell c18(&con_dead);
    Cell c19(&con_dead);
    Cell c20(&fred_dead);
    Cell c21(&fred_dead);
    Cell c22(&fred_dead);
    
    ostringstream testoutput;

    c17.print(testoutput);
    c18.print(testoutput);
    c19.print(testoutput);
    c20.print(testoutput);
    c21.print(testoutput);
    c22.print(testoutput);

    ASSERT_EQ(testoutput.str(), "...---");

}

TEST(CellFixture, cell_evolution_1) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell ce1(&con_dead);
    bool neighbors[] = {0, 0, 0, 0, 1, 1, 1, 0};

    ce1.evolution(neighbors);

    ostringstream testoutput;

    ce1.print(testoutput);

    ASSERT_EQ(testoutput.str(), "*");
}

TEST(CellFixture, cell_evolution_2) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell ce2(&fred_dead);
    bool neighbors[] = {0, 1, 0, 0, 0, 0, 0, 0};

    ce2.evolution(neighbors);

    ostringstream testoutput;

    ce2.print(testoutput);

    ASSERT_EQ(testoutput.str(), "0");

}

TEST(CellFixture, cell_evolution_3) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell ce3(&fred_dead);
    bool neighbors[] = {0, 1, 0, 0, 0, 0, 0, 0};

    ce3.evolution(neighbors);
    ce3.evolution(neighbors);
    ce3.evolution(neighbors);

    ostringstream testoutput;

    ce3.print(testoutput);

    ASSERT_EQ(testoutput.str(), "*");

}

TEST(CellFixture, cell_is_alive_1) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell ca1(&fred_dead);

    ASSERT_EQ(ca1.isAlive(), false);

}

TEST(CellFixture, cell_is_alive_2) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell ca2(&con_dead);

    ASSERT_EQ(ca2.isAlive(), false);

}

TEST(CellFixture, cell_is_alive_3) {

    FredkinCell fred_alive('0');
    FredkinCell fred_dead('-');
    ConwayCell con_alive('*');
    ConwayCell con_dead('.');

    Cell ca3(&fred_alive);
    Cell ca4(&con_alive);

    ASSERT_EQ(ca3.isAlive(), true);
    ASSERT_EQ(ca4.isAlive(), true);

}

TEST(ConwayCellFixture, conway_cell_constructor_1) {
    ConwayCell CC1('*');

    ostringstream testoutput;

    CC1.print(testoutput);

    ASSERT_EQ(testoutput.str(), "*");
}

TEST(ConwayCellFixture, conway_cell_constructor_2) {
    ConwayCell CC2('.');

    ostringstream testoutput;

    CC2.print(testoutput);

    ASSERT_EQ(testoutput.str(), ".");

}

TEST(ConwayCellFixture, conway_cell_constructor_3) {

    ConwayCell CC3('*');
    ConwayCell CC4('.');

    ostringstream testoutput;

    CC3.print(testoutput);
    CC4.print(testoutput);
    ASSERT_EQ(testoutput.str(), "*.");
}

TEST(ConwayCellFixture, conway_cell_print_1) {

    ConwayCell CC3('.');
    ConwayCell CC4('.');
    ConwayCell CC5('.');

    ostringstream testoutput;

    CC3.print(testoutput);
    CC4.print(testoutput);
    CC5.print(testoutput);
    ASSERT_EQ(testoutput.str(), "...");
}

TEST(ConwayCellFixture, conway_cell_print_2) {

    ConwayCell CC3('*');
    ConwayCell CC4('*');
    ConwayCell CC5('*');
    ostringstream testoutput;

    CC3.print(testoutput);
    CC4.print(testoutput);
    CC5.print(testoutput);
    ASSERT_EQ(testoutput.str(), "***");

}

TEST(ConwayCellFixture, conway_cell_print_3) {

    ConwayCell CC3('*');
    ConwayCell CC4('.');
    ConwayCell CC5('*');

    ostringstream testoutput;

    CC3.print(testoutput);
    CC4.print(testoutput);
    CC5.print(testoutput);
    ASSERT_EQ(testoutput.str(), "*.*");

}

TEST(ConwayCellFixture, conway_cell_evolution_1) {

    ConwayCell CC('*');

    bool neighbors[] = {0, 1, 1, 1, 1, 1, 1, 0};

    CC.evolution(neighbors);

    ostringstream testoutput;

    CC.print(testoutput);

    ASSERT_EQ(testoutput.str(), ".");
}

TEST(ConwayCellFixture, conway_cell_evolution_2) {

    ConwayCell CC('.');

    bool neighbors[] = {0, 1, 1, 1, 0, 0, 0, 0};

    CC.evolution(neighbors);

    ostringstream testoutput;

    CC.print(testoutput);

    ASSERT_EQ(testoutput.str(), "*");
}

TEST(ConwayCellFixture, conway_cell_evolution_3) {

    ConwayCell CC('*');

    bool neighbors[] = {0, 0, 0, 0, 0, 0, 1, 0};

    CC.evolution(neighbors);

    ostringstream testoutput;

    CC.print(testoutput);

    ASSERT_EQ(testoutput.str(), ".");

}

TEST(ConwayCellFixture, conway_cell_is_alive_1) {

    ConwayCell CC('*');

    ASSERT_EQ(CC.isAlive(), true);

}

TEST(ConwayCellFixture, conway_cell_is_alive_2) {

    ConwayCell CC('.');

    ASSERT_EQ(CC.isAlive(), false);

}

TEST(ConwayCellFixture, conway_cell_is_alive_3) {

    ConwayCell CC('*');

    bool neighbors[] = {0, 0, 0, 0, 0, 0, 1, 0};

    CC.evolution(neighbors);

    ASSERT_EQ(CC.isAlive(), false);

}

TEST(FredkinCellFixture, fredkin_cell_constructor_1) {

    FredkinCell FC1('-');

    ostringstream testoutput;

    FC1.print(testoutput);

    ASSERT_EQ(testoutput.str(), "-");
}

TEST(FredkinCellFixture, fredkin_cell_constructor_2) {

    FredkinCell FC1('0');

    ostringstream testoutput;

    FC1.print(testoutput);

    ASSERT_EQ(testoutput.str(), "0");

}

TEST(FredkinCellFixture, fredkin_cell_constructor_3) {

    FredkinCell FC1('-');
    FredkinCell FC2('0');


    ostringstream testoutput;

    FC1.print(testoutput);
    FC2.print(testoutput);


    ASSERT_EQ(testoutput.str(), "-0");

}

TEST(FredkinCellFixture, fredkin_cell_print_1) {

    FredkinCell FC1('-');
    FredkinCell FC2('-');
    FredkinCell FC3('-');

    ostringstream testoutput;

    FC1.print(testoutput);
    FC2.print(testoutput);
    FC3.print(testoutput);

    ASSERT_EQ(testoutput.str(), "---");
}

TEST(FredkinCellFixture, fredkin_cell_print_2) {

    FredkinCell FC1('0');
    FredkinCell FC2('0');
    FredkinCell FC3('0');

    ostringstream testoutput;

    FC1.print(testoutput);
    FC2.print(testoutput);
    FC3.print(testoutput);

    ASSERT_EQ(testoutput.str(), "000");

}

TEST(FredkinCellFixture, fredkin_cell_print_3) {

    FredkinCell FC1('0');
    FredkinCell FC2('-');
    FredkinCell FC3('0');

    ostringstream testoutput;

    FC1.print(testoutput);
    FC2.print(testoutput);
    FC3.print(testoutput);

    ASSERT_EQ(testoutput.str(), "0-0");

}

TEST(FredkinCellFixture, fredkin_cell_evolution_1) {

    FredkinCell FC('0');

    bool neighbors[] = {1, 1, 1, 1, 1, 1, 1, 1};

    FC.evolution(neighbors);

    ostringstream testoutput;

    FC.print(testoutput);

    ASSERT_EQ(testoutput.str(), "-");

}

TEST(FredkinCellFixture, fredkin_cell_evolution_2) {

    FredkinCell FC('-');

    bool neighbors[] = {0, 1, 0, 0, 0, 0, 0, 0};

    FC.evolution(neighbors);

    ostringstream testoutput;

    FC.print(testoutput);

    ASSERT_EQ(testoutput.str(), "0");

}

TEST(FredkinCellFixture, fredkin_cell_evolution_3) {

    FredkinCell FC('0');

    bool neighbors[] = {0, 1, 0, 1, 0, 0, 0, 0};

    FC.evolution(neighbors);

    ostringstream testoutput;

    FC.print(testoutput);

    ASSERT_EQ(testoutput.str(), "-");

}

TEST(FredkinCellFixture, fredkin_cell_is_alive_1) {

    FredkinCell FC('0');

    ASSERT_EQ(FC.isAlive(), true);

}

TEST(FredkinCellFixture, fredkin_cell_is_alive_2) {

    FredkinCell FC('-');

    ASSERT_EQ(FC.isAlive(), false);

}

TEST(FredkinCellFixture, fredkin_cell_is_alive_3) {

    FredkinCell FC('-');

    bool neighbors[] = {0, 1, 0, 0, 0, 0, 0, 0};

    FC.evolution(neighbors);

    ASSERT_EQ(FC.isAlive(), true);

}
