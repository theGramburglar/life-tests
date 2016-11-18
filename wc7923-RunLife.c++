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
    int r, c;
    cin >> r;
    cin >> c;
    Life<ConwayCell> b1 (r, c, cin);
    for (int i = 0; i < 13; i++) {
      b1.print_board(cout);
      b1.start();  
    }
    cout << endl;
    
    // b1.findNeighbors();


    // ----------------------
    // Life<ConwayCell> 20x29
    // ----------------------

    cout << "*** Life<ConwayCell> 20x29 ***" << endl;
    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */
    cin >> r;
    cin >> c;
    Life<ConwayCell> b2 (r, c, cin);
    for (int i = 0; i < 29; i++) {
      if (i % 4 == 0) {
        b2.print_board(cout);
      }
      b2.start();     
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
    cin >> r;
    cin >> c;
    Life<ConwayCell> b3 (r, c, cin);
    for (int i = 0; i < 2501; i++) {
      if (i < 10 || i == 283 || i == 323 || i == 2500) {
        b3.print_board(cout);
      }
      b3.start();
    }

    // -----------------------
    // Life<FredkinCell> 20x20
    // -----------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */
    cin >> r;
    cin >> c;
    Life<FredkinCell> b4 (r, c, cin);
    for (int i = 0; i < 6; i++) {
      b4.print_board(cout);
      b4.start();
    }

    // ----------------
    // Life<Cell> 20x20
    // ----------------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */
    cin >> r;
    cin >> c;
    Life<Cell> b5 (r, c, cin);
    for (int i = 0; i < 6; i++) {
      b5.print_board(cout);
      b5.start();
    }

    return 0;}