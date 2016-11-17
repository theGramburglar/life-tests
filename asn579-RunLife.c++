// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <fstream>   //

#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // ----------------------
    // Life<ConwayCell> 21x13
    // ----------------------

    cout << "*** Life<ConwayCell> 21x13 ***" << endl;
    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */
    Life<ConwayCell> life_1;
    life_1.read_in(cin);
    for(unsigned int i=0;i<13;++i)
    {
        life_1.print(cout);
        life_1.turn();
    }

    // ----------------------
    // Life<ConwayCell> 20x29
    // ----------------------

    cout << "*** Life<ConwayCell> 20x29 ***" << endl;
    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */
    
    Life<ConwayCell> life_2;
    life_2.read_in(cin);
    for(unsigned int i=0;i<29;++i)
    {
        if(i%4==0)
            life_2.print(cout);
        life_2.turn();
    }
    

    // -----------------------
    // Life<ConwayCell> 109x69
    // -----------------------

    cout << "*** Life<ConwayCell> 109x69 ***" << endl;
    /*
    Simulate 283 evolutions.
    Print the first 10 grids (i.e. 0, 1, 2, ... 9).
    Print the 283rd grid.
    Simulate 40 evolutions.
    Print the 323rd grid.
    Simulate 2177 evolutions.
    Print the 2500th grid.
    */
    
    Life<ConwayCell> life_3;
    life_3.read_in(cin);
    for(unsigned int i=0;i<=2500;++i)
    {
        if((i>=0&&i<10)||i==283||i==323||i==2500)
            life_3.print(cout);
        life_3.turn();
    }

    // -----------------------
    // Life<FredkinCell> 20x20
    // -----------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */
    
    Life<FredkinCell>life_4;
    life_4.read_in(cin);
    for(unsigned int i=0;i<=5;++i)
    {
        life_4.print(cout);
        life_4.turn();
    }

    // ----------------
    // Life<Cell> 20x20
    // ----------------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */
    Life<Cell> life_5;
    life_5.read_in(cin);
    //assert(false);
    for(unsigned int i=0;i<=5;++i)
    {
        life_5.print(cout);
        life_5.turn();
    }

    return 0;}
