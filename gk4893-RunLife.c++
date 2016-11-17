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
#include <sstream>  // istringstream, ostringstream

#include "Life.h"

using namespace std;

// ----
// main
// ----

int main() {
  using namespace std;

  // ----------------------
  // Life<ConwayCell> 21x13
  // ----------------------

  cout << "*** Life<ConwayCell> 21x13 ***" << endl;
  /*
  Simulate 12 evolutions.
  Print every grid (i.e. 0, 1, 2, 3, ... 12)
  */
  vector<int> print_generation({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  make_grid(cin, cout, false, 12, print_generation);

  // ----------------------
  // Life<ConwayCell> 20x29
  // ----------------------

  cout << "*** Life<ConwayCell> 20x29 ***" << endl;
  /*
  Simulate 28 evolutions.
  Print every 4th grid (i.e. 0, 4, 8, ... 28)
  */
  print_generation = vector<int>({0, 4, 8, 12, 16, 20, 24, 28});
  make_grid(cin, cout, false, 28, print_generation);

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
  print_generation =
      vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 283, 323, 2500});
  make_grid(cin, cout, false, 2500, print_generation);

  // -----------------------
  // Life<FredkinCell> 20x20
  // -----------------------

  cout << "*** Life<FredkinCell> 20x20 ***" << endl;
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */
  print_generation = vector<int>({0, 1, 2, 3, 4, 5});
  make_grid(cin, cout, false, 5, print_generation);

  // ----------------
  // Life<Cell> 20x20
  // ----------------

  cout << "*** Life<Cell> 20x20 ***" << endl;
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */
  print_generation = vector<int>({0, 1, 2, 3, 4, 5});
  make_grid(cin, cout, true, 5, print_generation);

  return 0;
}
