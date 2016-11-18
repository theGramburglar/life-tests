// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "Life.h"

// ----
// main
// ----

int main() {
  using namespace std;

  // ----------------------
  // Life<ConwayCell> 21x13
  // ----------------------

  cout << "*** Life<ConwayCell> 21x13 ***" << endl;
  cout << endl;
  /*
  Simulate 12 evolutions.
  Print every grid (i.e. 0, 1, 2, 3, ... 12)
  */
  Life<ConwayCell> l1(cin);
  l1.printBoard(cout);
  for (int i = 0; i < 12; ++i) {
    l1.play();
    l1.printBoard(cout);
  }

  // ----------------------
  // Life<ConwayCell> 20x29
  // ----------------------

  cout << "*** Life<ConwayCell> 20x29 ***" << endl;
  cout << endl;
  /*
  Simulate 28 evolutions.
  Print every 4th grid (i.e. 0, 4, 8, ... 28)
  */
  Life<ConwayCell> l2(cin);
  l2.printBoard(cout);
  for (int i = 1; i < 29; i++) {
    l2.play();
    if (!(i % 4))
      l2.printBoard(cout);
  }

  // -----------------------
  // Life<ConwayCell> 109x69
  // -----------------------

  cout << "*** Life<ConwayCell> 109x69 ***" << endl;
  cout << endl;
  /*
  Simulate 283 evolutions.
  Print the first 10 grids (i.e. 0, 1, 2, ... 9).
  Print the 283rd grid.
  Simulate 40 evolutions.
  Print the 323rd grid.
  Simulate 2177 evolutions.
  Print the 2500th grid.
  */

  Life<ConwayCell> l3(cin);
  l3.printBoard(cout);
  for (int i = 1; i < 10; ++i) {
    l3.play();
    l3.printBoard(cout);
  }
  for (int i = 10; i < 284; ++i) {
    l3.play();
  }
  l3.printBoard(cout);
  for (int i = 0; i < 40; ++i) {
    l3.play();
  }
  l3.printBoard(cout);
  for (int i = 0; i < 2177; ++i) {
    l3.play();
  }
  l3.printBoard(cout);

  // -----------------------
  // Life<FredkinCell> 20x20
  // -----------------------

  cout << "*** Life<FredkinCell> 20x20 ***" << endl;
  cout << endl;
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */

  Life<FredkinCell> l4(cin);
  l4.printBoard(cout);
  for (int i = 0; i < 5; ++i) {
    l4.play();
    l4.printBoard(cout);
  }

  // ----------------
  // Life<Cell> 20x20
  // ----------------

  cout << "*** Life<Cell> 20x20 ***" << endl;
  cout << endl;
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */

  Life<Cell> l5(cin);
  l5.printBoard(cout);
  for (int i = 0; i < 5; ++i) {
    l5.play();
    l5.printBoard(cout);
  }

  return 0;
}