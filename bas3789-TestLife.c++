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

#include <sstream>

using namespace std;

// ----
// ConwayCell Tests
// ----

TEST(ConwayCell, ccDefaultConstructor) {
  ConwayCell cc;
  ASSERT_TRUE(cc.symbol == '.');
  ASSERT_TRUE(!(cc.alive));
}

TEST(ConwayCell, ccCharConstructor1) {
  ConwayCell cc('s');
  ASSERT_TRUE(cc.symbol == 's');
  ASSERT_TRUE(cc.alive);
}

TEST(ConwayCell, ccCharConstructor2) {
  ConwayCell cc('d');
  ASSERT_TRUE(cc.symbol == 'd');
}

TEST(ConwayCell, ccCharConstructor3) {
  ConwayCell cc('3');
  ASSERT_TRUE(cc.symbol == '3');
}

TEST(ConwayCell, ccCopyConstructor1) {
  ConwayCell c1('1');
  ConwayCell c2(c1);
  ASSERT_TRUE(c1.symbol == c2.symbol);
  ASSERT_TRUE(c1.alive == c2.alive);
}

TEST(ConwayCell, ccCopyConstructor2) {
  ConwayCell c1;
  ConwayCell c2(c1);
  ASSERT_TRUE(c1.symbol == c2.symbol);
  ASSERT_TRUE(c1.alive == c2.alive);
}

TEST(ConwayCell, ccCopyConstructor3) {
  ConwayCell c1('3');
  ConwayCell c2(c1);
  ASSERT_TRUE(c1.symbol == c2.symbol);
  ASSERT_TRUE(c1.alive == c2.alive);
}

TEST(ConwayCell, deadStaysDead) {
  ConwayCell cc;
  ASSERT_TRUE(!(cc.alive));
  cc.evolve(2);
  ASSERT_TRUE(!(cc.alive));
}

TEST(ConwayCell, deadBecomesAlive) {
  ConwayCell cc;
  ASSERT_TRUE(!(cc.alive));
  cc.evolve(3);
  ASSERT_TRUE(cc.alive);
}

TEST(ConwayCell, aliveStaysAlive) {
  ConwayCell cc('s');
  ASSERT_TRUE(cc.alive);
  cc.evolve(3);
  ASSERT_TRUE(cc.alive);
}

TEST(ConwayCell, aliveBecomesDead) {
  ConwayCell cc('s');
  ASSERT_TRUE(cc.alive);
  cc.evolve(5);
  ASSERT_TRUE(!(cc.alive));
}

TEST(ConwayCell, getNeighbor1) {
  ConwayCell cc1;
  ConwayCell cc2;
  ASSERT_TRUE(cc1.getNeighbor(cc2, BOTTOM) == 0);
}

TEST(ConwayCell, getNeighbor2) {
  ConwayCell cc1;
  FredkinCell fc1('0');
  ASSERT_TRUE(cc1.getNeighbor(fc1, TOP) == 1);
}

TEST(ConwayCell, getNeighbor3) {
  ConwayCell cc1;
  ConwayCell cc2('*');
  ASSERT_TRUE(cc1.getNeighbor(cc2, BL) == 1);
}

TEST(ConwayCell, getNeighbor4) {
  ConwayCell cc1;
  FredkinCell fc1;
  ASSERT_TRUE(cc1.getNeighbor(fc1, TR) == 0);
}

TEST(ConwayCell, getNeighbor5) {
  ConwayCell cc1;
  FredkinCell fc1('0');
  ASSERT_TRUE(cc1.getNeighbor(fc1, LEFT) == 1);
}

TEST(ConwayCell, getNeighbor6) {
  ConwayCell cc1;
  FredkinCell fc1;
  ASSERT_TRUE(cc1.getNeighbor(fc1, BR) == 0);
}

TEST(ConwayCell, getNeighbor7) {
  ConwayCell cc1;
  ConwayCell fc1;
  ASSERT_TRUE(cc1.getNeighbor(fc1, RIGHT) == 0);
}

TEST(ConwayCell, getNeighbor8) {
  ConwayCell cc1;
  FredkinCell fc1;
  ASSERT_TRUE(cc1.getNeighbor(fc1, TL) == 0);
}

TEST(ConwayCell, equalsEqualsOperator1) {
  ConwayCell cc1('*');
  ConwayCell cc2('*');
  ASSERT_TRUE(cc1 == cc2);
}

TEST(ConwayCell, equalsEqualsOperator2) {
  ConwayCell cc1('*');
  ConwayCell cc2;
  ASSERT_TRUE(!(cc1 == cc2));
}

TEST(ConwayCell, equalsEqualsOperator3) {
  ConwayCell cc1('*');
  ConwayCell cc2 = cc1;
  ASSERT_TRUE(cc1 == cc2);
}

TEST(ConwayCell, clone1) {
  ConwayCell cc1('0');
  ConwayCell *cc2 = dynamic_cast<ConwayCell *>(cc1.clone());
  ASSERT_TRUE(cc1 == *cc2);
  delete cc2;
}

TEST(ConwayCell, clone2) {
  ConwayCell cc1;
  ConwayCell *cc2 = dynamic_cast<ConwayCell *>(cc1.clone());
  ASSERT_TRUE(cc1 == *cc2);
  delete cc2;
}

TEST(ConwayCell, clone3) {
  ConwayCell cc1('5');
  ConwayCell *cc2 = dynamic_cast<ConwayCell *>(cc1.clone());
  ASSERT_TRUE(cc1 == *cc2);
  delete cc2;
}

TEST(ConwayCell, assignmentOperator1) {
  ConwayCell cc1;
  ConwayCell cc2('*');
  cc1 = cc2;
  ASSERT_TRUE(cc1.symbol == cc2.symbol);
  ASSERT_TRUE(cc1.alive == cc2.alive);
}

TEST(ConwayCell, assignmentOperator2) {
  ConwayCell cc1;
  ConwayCell cc2('*');
  cc2 = cc1;
  ASSERT_TRUE(cc1.symbol == cc2.symbol);
  ASSERT_TRUE(cc1.alive == cc2.alive);
}

TEST(ConwayCell, assignmentOperator3) {
  ConwayCell cc1('&');
  ConwayCell cc2('*');
  cc2 = cc1;
  ASSERT_TRUE(cc1.symbol == cc2.symbol);
  ASSERT_TRUE(cc1.alive == cc2.alive);
}

// ----
// FredkinCell Tests
// ----

TEST(FredkinCell, fcDefaultConstructor) {
  FredkinCell fc;
  ASSERT_TRUE(fc.age == 0);
  ASSERT_TRUE(!(fc.alive));
  ASSERT_TRUE(fc.symbol == '-');
}

TEST(FredkinCell, fcCharConstructor1) {
  FredkinCell fc('0');
  ASSERT_TRUE(fc.age == 0);
  ASSERT_TRUE(fc.alive);
  ASSERT_TRUE(fc.symbol == '0');
}

TEST(FredkinCell, fcCharConstructor2) {
  FredkinCell fc('f');
  ASSERT_TRUE(fc.age == 0);
  ASSERT_TRUE(fc.alive);
  ASSERT_TRUE(fc.symbol == 'f');
}

TEST(FredkinCell, fcCharConstructor3) {
  FredkinCell fc('a');
  ASSERT_TRUE(fc.age == 0);
  ASSERT_TRUE(fc.alive);
  ASSERT_TRUE(fc.symbol == 'a');
}

TEST(FredkinCell, fcCopyConstructor1) {
  FredkinCell fc1;
  FredkinCell fc2(fc1);
  ASSERT_TRUE(fc1.age == fc2.age);
  ASSERT_TRUE(fc1.alive == fc2.alive);
  ASSERT_TRUE(fc1.symbol == fc2.symbol);
}

TEST(FredkinCell, fcCopyConstructor2) {
  FredkinCell fc1('0');
  FredkinCell fc2(fc1);
  ASSERT_TRUE(fc1.age == fc2.age);
  ASSERT_TRUE(fc1.alive == fc2.alive);
  ASSERT_TRUE(fc1.symbol == fc2.symbol);
}

TEST(FredkinCell, fcCopyConstructor3) {
  FredkinCell fc1('&');
  FredkinCell fc2(fc1);
  ASSERT_TRUE(fc1.age == fc2.age);
  ASSERT_TRUE(fc1.alive == fc2.alive);
  ASSERT_TRUE(fc1.symbol == fc2.symbol);
}

TEST(FredkinCell, NeedToChangeAge1) {
  FredkinCell fc('0');
  ASSERT_TRUE(fc.alive);
  fc.evolve(3);
  fc.evolve(3);
  ASSERT_TRUE(fc.age == 2);
  ASSERT_TRUE(fc.needToChange());
}

TEST(FredkinCell, growAge2) {
  FredkinCell fc('0');
  ASSERT_TRUE(fc.alive);
  fc.evolve(1);
  fc.evolve(3);
  fc.evolve(1);
  fc.evolve(3);
  ASSERT_TRUE(fc.age == 4);
}

TEST(FredkinCell, dieComeBackAge3) {
  FredkinCell fc('0');
  ASSERT_TRUE(fc.alive);
  fc.evolve(1);
  fc.evolve(3);
  fc.evolve(2);
  fc.evolve(3);
  ASSERT_TRUE(fc.age == 2);
}

TEST(FredkinCell, comeAliveAge4) {
  FredkinCell fc;
  ASSERT_TRUE(!(fc.alive));
  fc.evolve(1);
  fc.evolve(3);
  fc.evolve(1);
  fc.evolve(3);
  ASSERT_TRUE(fc.age == 3);
}

TEST(FredkinCell, overTenAge5) {
  FredkinCell fc;
  for (int i = 0; i < 11; ++i) {
    fc.evolve(1);
  }
  ASSERT_TRUE(fc.age == 10);
  ASSERT_TRUE(fc.symbol == '+');
}

TEST(FredkinCell, assignmentOperator1) {
  FredkinCell fc1('3');
  FredkinCell fc2 = fc1;
  ASSERT_TRUE(fc1.alive == fc2.alive);
  ASSERT_TRUE(fc1.age == fc2.age);
  ASSERT_TRUE(fc1.symbol == fc2.symbol);
}

TEST(FredkinCell, assignmentOperator2) {
  FredkinCell fc1('5');
  fc1.evolve(3);
  fc1.evolve(1);
  FredkinCell fc2 = fc1;
  ASSERT_TRUE(fc1.alive == fc2.alive);
  ASSERT_TRUE(fc1.age == fc2.age);
  ASSERT_TRUE(fc1.symbol == fc2.symbol);
}

TEST(FredkinCell, assignmentOperator3) {
  FredkinCell fc1('1');
  FredkinCell fc2 = fc1;
  ASSERT_TRUE(fc1.alive == fc2.alive);
  ASSERT_TRUE(fc1.age == fc2.age);
  ASSERT_TRUE(fc1.symbol == fc2.symbol);
}

TEST(FredkinCell, getNeighbor1) {
  FredkinCell fc1;
  FredkinCell fc2('*');
  ASSERT_TRUE(fc1.getNeighbor(fc2, LEFT) == 1);
}

TEST(FredkinCell, getNeighbor2) {
  FredkinCell fc1;
  FredkinCell fc2('*');
  ASSERT_TRUE(fc1.getNeighbor(fc2, TL) == 0);
}

TEST(FredkinCell, getNeighbor3) {
  FredkinCell fc1;
  FredkinCell fc2;
  ASSERT_TRUE(fc1.getNeighbor(fc2, RIGHT) == 0);
}

TEST(FredkinCell, getNeighbor4) {
  FredkinCell fc1;
  ConwayCell cc1;
  ASSERT_TRUE(fc1.getNeighbor(fc1, RIGHT) == 0);
}

TEST(FredkinCell, getNeighbor5) {
  FredkinCell fc1;
  ConwayCell cc2('*');
  ASSERT_TRUE(fc1.getNeighbor(cc2, TOP) == 1);
}

TEST(FredkinCell, getNeighbor6) {
  FredkinCell fc1;
  FredkinCell fc2('1');
  ASSERT_TRUE(fc1.getNeighbor(fc2, TR) == 0);
}

TEST(FredkinCell, equalsEqualsOperator1) {
  FredkinCell fc1('0');
  FredkinCell fc2('0');
  ASSERT_TRUE(fc1 == fc2);
}

TEST(FredkinCell, equalsEqualsOperator2) {
  FredkinCell fc1('0');
  FredkinCell fc2;
  ASSERT_TRUE(!(fc1 == fc2));
}

TEST(FredkinCell, equalsEqualsOperator3) {
  FredkinCell fc1('0');
  FredkinCell fc2 = fc1;
  ASSERT_TRUE(fc1 == fc2);
}

TEST(FredkinCell, clone1) {
  FredkinCell fc1('0');
  FredkinCell *fc2 = dynamic_cast<FredkinCell *>(fc1.clone());
  ASSERT_TRUE(fc1 == *fc2);
  delete fc2;
}

TEST(FredkinCell, clone2) {
  FredkinCell fc1;
  FredkinCell *fc2 = dynamic_cast<FredkinCell *>(fc1.clone());
  ASSERT_TRUE(fc1 == *fc2);
  delete fc2;
}

TEST(FredkinCell, clone3) {
  FredkinCell fc1('5');
  FredkinCell *fc2 = dynamic_cast<FredkinCell *>(fc1.clone());
  ASSERT_TRUE(fc1 == *fc2);
  delete fc2;
}

// ----
// Cell Tests
// ----

TEST(Cell, defaultConstructor1) {
  Cell c;
  ASSERT_TRUE(c._p == nullptr);
}

TEST(Cell, fredkinCellConstructor1) {
  FredkinCell fc;
  Cell c(&fc);
  ASSERT_TRUE(c._p == &fc);
}

TEST(Cell, fredkinCellConstructor2) {
  FredkinCell fc('*');
  Cell c(&fc);
  ASSERT_TRUE((*(c._p)).alive);
  ASSERT_TRUE(c._p == &fc);
}

TEST(Cell, conwayCellConstructor1) {
  ConwayCell cc('*');
  Cell c(&cc);
  ASSERT_TRUE((*(c._p)).alive);
  ASSERT_TRUE(c._p == &cc);
}

TEST(Cell, conwayCellConstructor2) {
  ConwayCell cc;
  Cell c(&cc);
  ASSERT_FALSE((*(c._p)).alive);
  ASSERT_TRUE(c._p == &cc);
}

TEST(Cell, assignmentOperator1) {
  FredkinCell fc;
  Cell cf(&fc);
  ConwayCell cc;
  Cell ccc(&cc);
  cf = ccc;
  ASSERT_TRUE(cf._p == ccc._p);
}

TEST(Cell, isAlive1) {
  ConwayCell c1;
  Cell cell(&c1);
  ASSERT_FALSE(cell.isAlive());
}

TEST(Cell, isAlive2) {
  ConwayCell c1('*');
  Cell cell(&c1);
  ASSERT_TRUE(cell.isAlive());
}

TEST(Cell, isAlive3) {
  FredkinCell f1;
  Cell cell(&f1);
  ASSERT_FALSE(cell.isAlive());
}

TEST(Cell, isAlive4) {
  FredkinCell f1('0');
  Cell cell(&f1);
  ASSERT_TRUE(cell.isAlive());
}

// ----------
// Life Tests
// ----------

TEST(Life, constructorFC) {
  Life<FredkinCell> fc(3, 3);
  ostringstream w;
  w << fc;
  string expected = "\nGeneration = 0, Population = 0.\n---\n---\n---\n";
  ASSERT_EQ(expected, w.str());
}

TEST(Life, constructorCC) {
  Life<ConwayCell> cc(3, 3);
  ostringstream w;
  w << cc;
  string expected = "\nGeneration = 0, Population = 0.\n...\n...\n...\n";
  ASSERT_EQ(expected, w.str());
}

TEST(Life, constructorFC2) {
  Life<FredkinCell> fc(12, 4);
  ostringstream w;
  w << fc;
  string expected = "\nGeneration = 0, Population = "
                    "0.\n----\n----\n----\n----\n----\n----\n----\n----\n----"
                    "\n----\n----\n----\n";
  ASSERT_EQ(expected, w.str());
}

TEST(Life, addCellCC) {
  Life<ConwayCell> cc(3, 3);
  ostringstream w;
  ConwayCell cell('*');
  cc.addCell(1, 1, cell);
  w << cc;
  string expected = "\nGeneration = 0, Population = 1.\n...\n.*.\n...\n";
  ASSERT_EQ(expected, w.str());
}

TEST(Life, addCellFC) {
  Life<FredkinCell> fc(3, 3);
  ostringstream w;
  FredkinCell cell('0');
  fc.addCell(1, 1, cell);
  w << fc;
  string expected = "\nGeneration = 0, Population = 1.\n---\n-0-\n---\n";
  ASSERT_EQ(expected, w.str());
}

TEST(Life, addCellCell) {
  Life<Cell> c(3, 3);
  ostringstream w;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      FredkinCell fc;
      Cell cell(&fc);
      c.addCell(i, j, cell);
    }
  }
  w << c;
  string expected = "\nGeneration = 0, Population = 0.\n---\n---\n---\n";
  ASSERT_EQ(expected, w.str());
}

TEST(Life, updateNCC) {
  Life<ConwayCell> cc(3, 3);
  ostringstream w;
  cc.printNeighbors(w);
  string expected = "000\n000\n000\n";
  ASSERT_EQ(expected, w.str());
  ConwayCell c1('*');
  ConwayCell c2('*');
  ConwayCell c3('*');
  cc.addCell(0, 1, c1);
  cc.addCell(1, 1, c2);
  cc.addCell(1, 2, c3);
  cc.updateNeighbors();
  expected = "223\n222\n122\n";
  ostringstream o;
  cc.printNeighbors(o);
  ASSERT_EQ(expected, o.str());
}

TEST(Life, updateNFC) {
  Life<FredkinCell> cc(3, 3);
  ostringstream w;
  cc.printNeighbors(w);
  string expected = "000\n000\n000\n";
  ASSERT_EQ(expected, w.str());
  FredkinCell f1('0');
  FredkinCell f2('0');
  FredkinCell f3('0');
  cc.addCell(0, 1, f1);
  cc.addCell(1, 1, f2);
  cc.addCell(1, 2, f3);
  cc.updateNeighbors();
  expected = "112\n121\n011\n";
  ostringstream o;
  cc.printNeighbors(o);
  ASSERT_EQ(expected, o.str());
}

TEST(Life, GetNeighborsCC) {
  Life<ConwayCell> cc(3, 3);
  ConwayCell c1('*');
  ConwayCell c2('*');
  ConwayCell c3('*');
  cc.addCell(0, 1, c1);
  cc.addCell(1, 1, c2);
  cc.addCell(1, 2, c3);
  int expected = 3;
  ASSERT_EQ(expected, cc.getNumNeighbors(0, 2));
}

TEST(Life, GetNeighborsFC) {
  Life<FredkinCell> cc(3, 3);
  FredkinCell f1('0');
  FredkinCell f2('0');
  FredkinCell f3('0');
  cc.addCell(0, 1, f1);
  cc.addCell(1, 1, f2);
  cc.addCell(1, 2, f3);
  int expected = 2;
  ASSERT_EQ(expected, cc.getNumNeighbors(0, 2));
}

TEST(Life, printNeighborsCC) {
  Life<ConwayCell> cc(3, 3);
  ostringstream w;
  ConwayCell c1('*');
  ConwayCell c2('*');
  ConwayCell c3('*');
  cc.addCell(0, 1, c1);
  cc.addCell(2, 1, c2);
  cc.addCell(1, 2, c3);
  cc.updateNeighbors();
  string expected = "112\n232\n112\n";
  cc.printNeighbors(w);
  ASSERT_EQ(expected, w.str());
}

TEST(Life, printNeighborsFC) {
  Life<FredkinCell> cc(3, 3);
  ostringstream w;
  FredkinCell f1('0');
  FredkinCell f2('0');
  FredkinCell f3('0');
  cc.addCell(0, 0, f1);
  cc.addCell(1, 1, f2);
  cc.addCell(1, 2, f3);
  cc.updateNeighbors();
  string expected = "021\n211\n011\n";
  cc.printNeighbors(w);
  ASSERT_EQ(expected, w.str());
}

TEST(Life, nextTurnCC) {
  Life<ConwayCell> cc(3, 3);
  ConwayCell c1('*');
  ConwayCell c2('*');
  ConwayCell c3('*');
  cc.addCell(0, 1, c1);
  cc.addCell(1, 1, c2);
  cc.addCell(1, 2, c3);
  string expected = "\nGeneration = 0, Population = 4.\n.**\n.**\n...\n";
  cc.nextTurn();
  ostringstream w;
  w << cc;
  ASSERT_EQ(expected, w.str());
}

TEST(Life, nextTurnFC) {
  Life<FredkinCell> cc(3, 3);
  ostringstream w;
  FredkinCell f1('0');
  FredkinCell f2('0');
  FredkinCell f3('0');
  cc.addCell(0, 0, f1);
  cc.addCell(1, 1, f2);
  cc.addCell(1, 2, f3);
  string expected = "\nGeneration = 0, Population = 5.\n--0\n-11\n-00\n";
  cc.nextTurn();
  w << cc;
  ASSERT_EQ(expected, w.str());
}

TEST(Life, SimulateCC) {
  Life<ConwayCell> cc(3, 3);
  ConwayCell c1('*');
  ConwayCell c2('*');
  ConwayCell c3('*');
  cc.addCell(0, 1, c1);
  cc.addCell(1, 1, c2);
  cc.addCell(1, 2, c3);
  string expected = "\nGeneration = 3, Population = 4.\n.**\n.**\n...\n";
  ostringstream w;
  cc.simulate(3, 1);
  w << cc;
  ASSERT_EQ(expected, w.str());
}

TEST(Life, SimulateFC) {
  Life<FredkinCell> cc(3, 3);
  ostringstream w;
  FredkinCell f1('0');
  FredkinCell f2('0');
  FredkinCell f3('0');
  cc.addCell(0, 0, f1);
  cc.addCell(1, 1, f2);
  cc.addCell(1, 2, f3);
  string expected = "\nGeneration = 5, Population = 0.\n---\n---\n---\n";
  cc.simulate(5, 2);
  w << cc;
  ASSERT_EQ(expected, w.str());
}
