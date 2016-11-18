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
#include <string>

#include "Life.h"

using namespace std;

// ----
// Constructors
// ----

TEST(ConwayCell_const, test_1) {
  ConwayCell x = ConwayCell();
  ASSERT_FALSE(x.AbstractCell::is_alive());
}

TEST(ConwayCell_const, test_2) {
  ConwayCell x(false);
  ASSERT_FALSE(x.AbstractCell::is_alive());
}

TEST(ConwayCell_const, test_3) {
  ConwayCell x(true);
  ASSERT_TRUE(x.is_alive());
}

TEST(ConwayCell_const, test_4) {
  ConwayCell x(false);
  ASSERT_TRUE(!x.is_alive());
}

TEST(FredkinCell_const, test_1) {
  FredkinCell x = FredkinCell();
  ASSERT_FALSE(x.is_alive());
}

TEST(FredkinCell_const, test_2) {
  FredkinCell x(false);
  ASSERT_FALSE(x.is_alive());
}

TEST(FredkinCell_const, test_3) {
  FredkinCell x(true);
  ASSERT_TRUE(x.is_alive());
}

TEST(FredkinCell_const, test_4) {
  FredkinCell x = FredkinCell();
  ASSERT_TRUE(x.lifespan == 0);
}

TEST(AbstractCell_const, test_1) {
  AbstractCell *p = new ConwayCell();
  bool res = p->is_alive();
  delete p;
  ASSERT_FALSE(res);
}

TEST(AbstractCell_const, test_2) {
  AbstractCell *p = new ConwayCell(true);
  bool res = p->is_alive();
  delete p;
  ASSERT_TRUE(res);
}

TEST(AbstractCell_const, test_3) {
  AbstractCell *p = new FredkinCell();
  bool res = p->is_alive();
  delete p;
  ASSERT_FALSE(res);
}

TEST(AbstractCell_const, test_4) {
  AbstractCell *p = new FredkinCell(true);
  bool res = p->is_alive();
  delete p;
  ASSERT_TRUE(res);
}

TEST(ConwayCell_print, test_1) {
  ConwayCell x = ConwayCell();
  ostringstream out;
  x.print_cell(out);
  out.flush();

  string expected = ".";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_print, test_2) {
  ConwayCell x(true);
  ostringstream out;
  x.print_cell(out);
  out.flush();

  string expected = "*";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_print, test_3) {
  ConwayCell x(false);
  ostringstream out;
  x.print_cell(out);
  out.flush();

  string expected = ".";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_print, test_1) {
  FredkinCell x = FredkinCell();
  ostringstream out;
  x.print_cell(out);
  out.flush();

  string expected = "-";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_print, test_2) {
  FredkinCell x(true);
  ostringstream out;
  x.print_cell(out);
  out.flush();

  string expected = "0";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_print, test_3) {
  FredkinCell x(false);
  ostringstream out;
  x.print_cell(out);
  out.flush();

  string expected = "-";

  ASSERT_EQ(expected, out.str());
}

TEST(AbstractCell_print, test_1) {
  AbstractCell *x = new FredkinCell();
  ostringstream out;
  x->print_cell(out);
  out.flush();

  string expected = "-";

  delete x;
  ASSERT_EQ(expected, out.str());
}

TEST(AbstractCell_print, test_2) {
  AbstractCell *x = new FredkinCell(true);
  ostringstream out;
  x->print_cell(out);
  out.flush();

  string expected = "0";

  delete x;
  ASSERT_EQ(expected, out.str());
}

TEST(AbstractCell_print, test_3) {
  AbstractCell *x = new ConwayCell();
  ostringstream out;
  x->print_cell(out);
  out.flush();

  string expected = ".";

  delete x;
  ASSERT_EQ(expected, out.str());
}

TEST(AbstractCell_print, test_4) {
  AbstractCell *x = new ConwayCell(true);
  ostringstream out;
  x->print_cell(out);
  out.flush();

  string expected = "*";

  delete x;
  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_change, test_1) {
  ConwayCell x(true);

  std::vector<bool> neighbors;
  for (int i = 0; i < 8; ++i)
    neighbors.push_back(true);
  x.change(neighbors);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = ".";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_change, test_2) {
  ConwayCell x = ConwayCell();

  std::vector<bool> neighbors;
  for (int i = 0; i < 8; ++i)
    neighbors.push_back(true);
  x.change(neighbors);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = ".";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_change, test_3) {
  ConwayCell x(true);

  std::vector<bool> neighbors;
  for (int i = 0; i < 3; ++i)
    neighbors.push_back(true);
  for (int i = 0; i < 5; ++i)
    neighbors.push_back(false);

  x.change(neighbors);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "*";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_change, test_4) {
  ConwayCell x = ConwayCell();

  std::vector<bool> neighbors;
  for (int i = 0; i < 3; ++i)
    neighbors.push_back(true);
  for (int i = 0; i < 5; ++i)
    neighbors.push_back(false);

  x.change(neighbors);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "*";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_change, test_1) {
  FredkinCell x(true);

  std::vector<bool> neighbors;
  for (int i = 0; i < 8; ++i)
    neighbors.push_back(false);
  x.change(neighbors);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "-";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_change, test_2) {
  FredkinCell x = FredkinCell();

  std::vector<bool> neighbors;
  for (int i = 0; i < 8; ++i)
    neighbors.push_back(false);
  x.change(neighbors);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "-";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_change, test_3) {
  FredkinCell x(true);

  std::vector<bool> neighbors;
  for (int i = 0; i < 6; ++i)
    neighbors.push_back(true);
  for (int i = 0; i < 2; ++i)
    neighbors.push_back(false);
  x.change(neighbors);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "1";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_change, test_4) {
  FredkinCell x = FredkinCell();

  std::vector<bool> neighbors;
  for (int i = 0; i < 6; ++i)
    neighbors.push_back(true);
  for (int i = 0; i < 2; ++i)
    neighbors.push_back(false);
  x.change(neighbors);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "0";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_change, test_5) {
  FredkinCell x(true);

  std::vector<bool> neighbors;
  for (int i = 0; i < 6; ++i)
    neighbors.push_back(true);
  for (int i = 0; i < 2; ++i)
    neighbors.push_back(false);
  x.change(neighbors);
  x.change(neighbors);
  x.change(neighbors);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "3";

  ASSERT_EQ(expected, out.str());
}

TEST(AbstractCell_change, test_1) {
  AbstractCell *x = new ConwayCell(true);

  std::vector<bool> neighbors;
  for (int i = 0; i < 8; ++i)
    neighbors.push_back(true);
  x->change(neighbors);

  ostringstream out;
  x->print_cell(out);
  out.flush();
  string expected = ".";

  delete x;
  ASSERT_EQ(expected, out.str());
}

TEST(AbstractCell_change, test_2) {
  AbstractCell *x = new ConwayCell();

  std::vector<bool> neighbors;
  for (int i = 0; i < 3; ++i)
    neighbors.push_back(true);
  for (int i = 0; i < 5; ++i)
    neighbors.push_back(false);

  x->change(neighbors);

  ostringstream out;
  x->print_cell(out);
  out.flush();
  string expected = "*";

  delete x;
  ASSERT_EQ(expected, out.str());
}

TEST(AbstractCell_change, test_3) {
  AbstractCell *x = new FredkinCell(true);

  std::vector<bool> neighbors;
  for (int i = 0; i < 8; ++i)
    neighbors.push_back(false);
  x->change(neighbors);

  ostringstream out;
  x->print_cell(out);
  out.flush();
  string expected = "-";

  delete x;
  ASSERT_EQ(expected, out.str());
}

TEST(AbstractCell_change, test_4) {
  AbstractCell *x = new FredkinCell();

  std::vector<bool> neighbors;
  for (int i = 0; i < 6; ++i)
    neighbors.push_back(true);
  for (int i = 0; i < 2; ++i)
    neighbors.push_back(false);
  x->change(neighbors);

  ostringstream out;
  x->print_cell(out);
  out.flush();
  string expected = "0";

  delete x;
  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_place, test_1) {
  ConwayCell x(true);

  string s = "*";
  istringstream in(s);
  x.place(in);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "*";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_place, test_2) {
  ConwayCell x(true);

  string s = ".";
  istringstream in(s);
  x.place(in);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = ".";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_place, test_3) {
  ConwayCell x = ConwayCell();

  string s = "*";
  istringstream in(s);
  x.place(in);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "*";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_place, test_4) {
  ConwayCell x = ConwayCell();

  string s = ".";
  istringstream in(s);
  x.place(in);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = ".";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_place, test_1) {
  FredkinCell x(true);

  string s = "0";
  istringstream in(s);
  x.place(in);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "0";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_place, test_2) {
  FredkinCell x(true);

  string s = "9";
  istringstream in(s);
  x.place(in);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "9";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_place, test_3) {
  FredkinCell x = FredkinCell();

  string s = "+";
  istringstream in(s);
  x.place(in);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "+";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_place, test_4) {
  FredkinCell x = FredkinCell();

  string s = "HELLO";
  istringstream in(s);
  x.place(in);

  ostringstream out;
  x.print_cell(out);
  out.flush();
  string expected = "-";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_clone, test_1) {
  AbstractCell *p = new ConwayCell();
  Cell x = Cell(p);

  string s = "*";
  istringstream in(s);
  x.place(in);

  Cell y = x;
  ostringstream out;
  y.print_cell(out);
  out.flush();
  string expected = "*";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_clone, test_2) {
  AbstractCell *p = new ConwayCell();
  Cell x = Cell(p);

  string s = ".";
  istringstream in(s);
  x.place(in);

  Cell y = x;
  ostringstream out;
  y.print_cell(out);
  out.flush();
  string expected = ".";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_clone, test_3) {
  ConwayCell x = ConwayCell(true);

  string s = "*";
  istringstream in(s);
  x.place(in);

  Cell y = x.clone();
  ostringstream out;
  y.print_cell(out);
  out.flush();
  string expected = "*";

  ASSERT_EQ(expected, out.str());
}

TEST(ConwayCell_clone, test_4) {
  ConwayCell x = ConwayCell();

  string s = ".";
  istringstream in(s);
  x.place(in);

  Cell y = x.clone();
  ostringstream out;
  y.print_cell(out);
  out.flush();
  string expected = ".";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_clone, test_1) {
  AbstractCell *p = new FredkinCell();
  Cell x = Cell(p);

  string s = "0";
  istringstream in(s);
  x.place(in);

  Cell y = x;
  ostringstream out;
  y.print_cell(out);
  out.flush();
  string expected = "0";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_clone, test_2) {
  AbstractCell *p = new FredkinCell();
  Cell x = Cell(p);

  string s = "-";
  istringstream in(s);
  x.place(in);

  Cell y = x;
  ostringstream out;
  y.print_cell(out);
  out.flush();
  string expected = "-";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_clone, test_3) {
  FredkinCell x = FredkinCell(true);

  string s = "0";
  istringstream in(s);
  x.place(in);

  Cell y = x.clone();
  ostringstream out;
  y.print_cell(out);
  out.flush();
  string expected = "0";

  ASSERT_EQ(expected, out.str());
}

TEST(FredkinCell_clone, test_4) {
  FredkinCell x = FredkinCell();

  string s = "-";
  istringstream in(s);
  x.place(in);

  Cell y = x.clone();
  ostringstream out;
  y.print_cell(out);
  out.flush();
  string expected = "-";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_1) {

  string input = "2 13\n.............\n.............";
  istringstream in(input);
  Life<ConwayCell> life1(in);

  ostringstream out;
  life1.simulate(1, -1);
  life1.simulate(0);
  out << life1;
  out.flush();
  string expected =
      "\nGeneration = 1, Population = 0.\n.............\n.............\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_2) {

  string input = "1 10\n..........";
  istringstream in(input);
  Life<ConwayCell> life1(in);

  ostringstream out;
  life1.simulate(1);
  out << life1;
  out.flush();
  string expected = "\nGeneration = 1, Population = 0.\n..........\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_3) {

  string input = "2 13\n.............\n.............";
  istringstream in(input);
  Life<ConwayCell> life1(in);

  ostringstream out;
  life1.simulate(3, -1);
  life1.simulate(1);
  out << life1;
  out.flush();
  string expected =
      "\nGeneration = 4, Population = 0.\n.............\n.............\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_4) {

  string input = "2 13\n.....*.*..***\n.....***..*..";
  istringstream in(input);
  Life<ConwayCell> life1(in);

  ostringstream out;
  life1.simulate(3, -1);
  life1.simulate(1);
  out << life1;
  out.flush();
  string expected =
      "\nGeneration = 4, Population = 4.\n..........**.\n..........**.\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_5) {

  string input = "2 20\n--------------------\n--------------------";
  istringstream in(input);
  Life<FredkinCell> life1(in);

  ostringstream out;
  life1.simulate(0);
  out << life1;
  out.flush();
  string expected = "\nGeneration = 0, Population = "
                    "0.\n--------------------\n--------------------\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_6) {

  string input = "1 10\n----------";
  istringstream in(input);
  Life<FredkinCell> life1(in);

  ostringstream out;
  life1.simulate(0);
  out << life1;
  out.flush();
  string expected = "\nGeneration = 0, Population = 0.\n----------\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_7) {

  string input = "2 13\n-----0000---0\n----0000----0";
  istringstream in(input);
  Life<FredkinCell> life1(in);

  ostringstream out;
  life1.simulate(3, -1);
  life1.simulate(1);
  out << life1;
  out.flush();
  string expected =
      "\nGeneration = 4, Population = 20.\n-0002111-3-0-\n01211111-2-11\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_8) {

  string input = "5 5\n-----\n--0--\n-000-\n--0--\n-----";
  istringstream in(input);
  Life<FredkinCell> life1(in);

  ostringstream out;
  life1.simulate(3, -1);
  life1.simulate(1);
  out << life1;
  out.flush();
  string expected = "\nGeneration = 4, Population = "
                    "16.\n-232-\n2-4-2\n34-43\n2-4-2\n-232-\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_9) {

  string input = "2 13\n.............\n.............";
  istringstream in(input);
  Life<Cell> life1(in);

  ostringstream out;
  life1.simulate(3, -1);
  life1.simulate(1);
  out << life1;
  out.flush();
  string expected =
      "\nGeneration = 4, Population = 0.\n-------------\n-------------\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_10) {

  string input = "2 13\n.....*.*..***\n.....***..*..";
  istringstream in(input);
  Life<Cell> life1(in);

  ostringstream out;
  life1.simulate(3, -1);
  life1.simulate(1);
  out << life1;
  out.flush();
  string expected =
      "\nGeneration = 4, Population = 0.\n-------------\n-------------\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_11) {

  string input = "2 20\n--------------------\n--------------------";
  istringstream in(input);
  Life<Cell> life1(in);

  ostringstream out;
  life1.simulate(0);
  out << life1;
  out.flush();
  string expected = "\nGeneration = 0, Population = "
                    "0.\n--------------------\n--------------------\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_simulator, test_12) {

  string input = "1 10\n----------";
  istringstream in(input);
  Life<Cell> life1(in);

  ostringstream out;
  life1.simulate(0);
  out << life1;
  out.flush();
  string expected = "\nGeneration = 0, Population = 0.\n----------\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_generation, test_1) {

  string input = "2 13\n.............\n.............";
  istringstream in(input);
  Life<ConwayCell> life1(in);

  ostringstream out;
  life1.simulate(1, -1);
  life1.simulate(0);
  life1.next_generation();
  out << life1;
  out.flush();
  string expected =
      "\nGeneration = 2, Population = 0.\n.............\n.............\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_generation, test_2) {

  string input = "1 10\n..........";
  istringstream in(input);
  Life<ConwayCell> life1(in);

  ostringstream out;
  life1.simulate(1);
  life1.next_generation();
  out << life1;
  out.flush();
  string expected = "\nGeneration = 2, Population = 0.\n..........\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_generation, test_3) {

  string input = "2 13\n.............\n.............";
  istringstream in(input);
  Life<ConwayCell> life1(in);

  ostringstream out;
  life1.simulate(3, -1);
  life1.simulate(1);
  life1.next_generation();
  out << life1;
  out.flush();
  string expected =
      "\nGeneration = 5, Population = 0.\n.............\n.............\n\n";

  ASSERT_EQ(expected, out.str());
}

TEST(Life_generation, test_4) {

  string input = "2 13\n.....*.*..***\n.....***..*..";
  istringstream in(input);
  Life<ConwayCell> life1(in);

  ostringstream out;
  life1.simulate(3, -1);
  life1.simulate(1);
  life1.next_generation();
  out << life1;
  out.flush();
  string expected =
      "\nGeneration = 5, Population = 4.\n..........**.\n..........**.\n\n";

  ASSERT_EQ(expected, out.str());
}

/*TEST(ConwayCell_change, test_1) {
    ConwayCell x(true);

    std::vector<bool> neighbors;
    for(int i = 0; i < 8; ++i)
        neighbors.push_back(true);
    x.change(neighbors);

    ostringstream out;
    x.print_cell(out);
    out.flush();
    string expected = ".";

    ASSERT_EQ(expected, out.str());}*/
/*TEST(FredkinCell_print, test_2) {

        istringstream in;
        in << "21 13
.............
.............
.............
.............
.............
.............
.............
.............
....*****....
.......*.....
......*......
.....*.......
....*****....
.............
.............
.............
.............
.............
.............
.............
.............";

        Life<FredkinCell>

    FredkinCell x(true);
    ostringstream out;
    x.print_cell(out);
    out.flush();

    string expected = "0";

    ASSERT_EQ(expected, out.str());}*/