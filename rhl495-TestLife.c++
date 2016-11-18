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

// ----
// test
// ----

// 30 functions and methods. 93 tests...

TEST(Life, constructor1) {
  Life<ConwayCell> x;
  ASSERT_EQ(x._height, 0);
  ASSERT_EQ(x._width, 0);
}
TEST(Life, constructor2) {
  Life<ConwayCell> x(100, 100);
  ASSERT_EQ(x._height, 100);
  ASSERT_EQ(x._width, 100);
}
TEST(Life, constructor3) {
  Life<ConwayCell> x(20, 20);
  ASSERT_EQ(x._height, 20);
  ASSERT_EQ(x._width, 20);
}
TEST(Life, updateCell1) {
  Life<ConwayCell> x(2, 2);
  x.updateCell(-1, 1, Direction::north);
}
TEST(Life, updateCell2) {
  Life<ConwayCell> x(2, 2);
  x.updateCell(1, -1, Direction::north);
}
TEST(Life, updateCell3) {
  Life<ConwayCell> x(2, 2);
  x.updateCell(5, 0, Direction::north);
}
TEST(Life, updateCell4) {
  Life<ConwayCell> x(2, 2);
  x.updateCell(0, 0, Direction::north);
  ASSERT_EQ(x._board[0]._livingNeighbors, 1);
}
TEST(Life, alive1) {
  Life<ConwayCell> x(2, 2);
  ASSERT_EQ(x.alive(), 0);
}
TEST(Life, alive2) {
  Life<ConwayCell> x(2, 2);
  x.addCell(0, 0, ConwayCell(Status::alive));
  ASSERT_EQ(x.alive(), 1);
}
TEST(Life, alive3) {
  Life<ConwayCell> x(2, 2);
  x.addCell(0, 0, ConwayCell(Status::alive));
  x.addCell(0, 1, ConwayCell(Status::alive));
  ASSERT_EQ(x.alive(), 2);
}
TEST(Life, step1) {
  Life<ConwayCell> x(2, 2);
  ASSERT_EQ(x._step, 0);
  x.step();
  ASSERT_EQ(x._step, 1);
}
TEST(Life, step2) {
  Life<ConwayCell> x(2, 2);
  ASSERT_EQ(x._step, 0);
  x.step();
  x.step();
  ASSERT_EQ(x._step, 2);
}
TEST(Life, step3) {
  Life<ConwayCell> x(2, 2);
  ASSERT_EQ(x._step, 0);
  x.step();
  x.step();
  x.step();
  ASSERT_EQ(x._step, 3);
}
TEST(Life, addCell1) {
  Life<ConwayCell> x(2, 2);
  x.addCell(0, 0, ConwayCell(Status::alive));
  ASSERT_TRUE(x._board[0].isAlive());
}
TEST(Life, addCell2) {
  Life<FredkinCell> x(2, 2);
  x.addCell(0, 0, FredkinCell(Status::alive));
  ASSERT_TRUE(x._board[0].isAlive());
}
TEST(Life, addCell3) {
  Life<Cell> x(2, 2);
  x.addCell(0, 0, new ConwayCell(Status::alive));
  ASSERT_TRUE(x._board[0].isAlive());
}
TEST(ConwayCell, print1) {
  ConwayCell x(Status::alive);
  std::stringstream cell;
  cell << x;
  ASSERT_EQ(cell.str(), "*");
}
TEST(ConwayCell, print2) {
  ConwayCell x(Status::dead);
  std::stringstream cell;
  cell << x;
  ASSERT_EQ(cell.str(), ".");
}
TEST(ConwayCell, print3) {
  ConwayCell x;
  std::stringstream cell;
  cell << x;
  ASSERT_EQ(cell.str(), ".");
}
TEST(ConwayCell, constructor1) {
  ConwayCell x;
  ASSERT_EQ(x._status, Status::dead);
}
TEST(ConwayCell, constructor2) {
  ConwayCell x(Status::alive);
  ASSERT_EQ(x._status, Status::alive);
}
TEST(ConwayCell, constructor3) {
  ConwayCell x(Status::dead);
  ASSERT_EQ(x._status, Status::dead);
}
TEST(ConwayCell, constructor4) {
  ConwayCell x(Status::alive);
  ConwayCell y(x);
  ASSERT_EQ(y._status, Status::alive);
}
TEST(ConwayCell, constructor5) {
  ConwayCell x(Status::dead);
  ConwayCell y(x);
  ASSERT_EQ(y._status, Status::dead);
}
TEST(ConwayCell, constructor6) {
  ConwayCell x;
  ConwayCell y(x);
  ASSERT_EQ(y._status, Status::dead);
}
TEST(ConwayCell, act1) {
  ConwayCell x;
  for (int i = 0; i < 3; ++i) {
    x._livingNeighbors = i;
    x.act();
    ASSERT_EQ(x._status, Status::dead);
  }
  for (int i = 4; i < 9; ++i) {
    x._livingNeighbors = i;
    x.act();
    ASSERT_EQ(x._status, Status::dead);
  }
}
TEST(ConwayCell, act2) {
  ConwayCell x;
  x._livingNeighbors = 3;
  x.act();
  ASSERT_EQ(x._status, Status::alive);
}
TEST(ConwayCell, act3) {
  ConwayCell x(Status::alive);
  for (int i = 0; i < 2; ++i) {
    x._livingNeighbors = i;
    x.act();
    ASSERT_EQ(x._status, Status::dead);
    x._status = Status::alive;
  }
  for (int i = 4; i < 9; ++i) {
    x._livingNeighbors = i;
    x.act();
    ASSERT_EQ(x._status, Status::dead);
    x._status = Status::alive;
  }
}
TEST(ConwayCell, act4) {
  ConwayCell x(Status::alive);
  for (int i = 2; i < 4; ++i) {
    x._livingNeighbors = i;
    x.act();
    ASSERT_EQ(x._status, Status::alive);
  }
}
TEST(ConwayCell, clone1) {
  ConwayCell x;
  ConwayCell *p = static_cast<ConwayCell *>(x.clone());
  ASSERT_EQ(p->_status, x._status);
  delete p;
}
TEST(ConwayCell, clone2) {
  ConwayCell x(Status::alive);
  ConwayCell *p = static_cast<ConwayCell *>(x.clone());
  ASSERT_EQ(p->_status, x._status);
  delete p;
}
TEST(ConwayCell, clone3) {
  AbstractCell *ap = new ConwayCell();
  ConwayCell *cp = static_cast<ConwayCell *>(ap->clone());
  ASSERT_EQ(ap->_status, cp->_status);
  delete ap;
  delete cp;
}
TEST(ConwayCell, clone4) {
  AbstractCell *ap = new ConwayCell(Status::alive);
  ConwayCell *cp = static_cast<ConwayCell *>(ap->clone());
  ASSERT_EQ(ap->_status, cp->_status);
  delete ap;
  delete cp;
}
TEST(ConwayCell, updateNeighborCount1) {
  ConwayCell x;
  x.updateNeighborCount(Direction::northwest);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(ConwayCell, updateNeighborCount2) {
  ConwayCell x;
  x.updateNeighborCount(Direction::north);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(ConwayCell, updateNeighborCount3) {
  ConwayCell x;
  x.updateNeighborCount(Direction::northeast);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(ConwayCell, updateNeighborCount4) {
  ConwayCell x;
  x.updateNeighborCount(Direction::east);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(ConwayCell, updateNeighborCount5) {
  ConwayCell x;
  x.updateNeighborCount(Direction::southeast);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(ConwayCell, updateNeighborCount6) {
  ConwayCell x;
  x.updateNeighborCount(Direction::south);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(ConwayCell, updateNeighborCount7) {
  ConwayCell x;
  x.updateNeighborCount(Direction::southwest);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(ConwayCell, updateNeighborCount8) {
  ConwayCell x;
  x.updateNeighborCount(Direction::west);
  ASSERT_EQ(1, x._livingNeighbors);
}
#ifdef ISALIVE
TEST(ConwayCell, isAlive1) {
  ConwayCell x;
  ASSERT_FALSE(x.isAlive());
}
TEST(ConwayCell, isAlive2) {
  ConwayCell x(Status::dead);
  ASSERT_FALSE(x.isAlive());
}
TEST(ConwayCell, isAlive3) {
  ConwayCell x(Status::alive);
  ASSERT_TRUE(x.isAlive());
}
#endif
TEST(FredkinCell, print1) {
  FredkinCell x(Status::alive);
  std::stringstream cell;
  cell << x;
  ASSERT_EQ(cell.str(), "0");
}
TEST(FredkinCell, print2) {
  FredkinCell x(Status::dead);
  std::stringstream cell;
  cell << x;
  ASSERT_EQ(cell.str(), "-");
}
TEST(FredkinCell, print3) {
  FredkinCell x;
  std::stringstream cell;
  cell << x;
  ASSERT_EQ(cell.str(), "-");
}
TEST(FredkinCell, print4) {
  FredkinCell x(Status::alive);
  x._age = 5;
  std::stringstream cell;
  cell << x;
  ASSERT_EQ(cell.str(), "5");
}
TEST(FredkinCell, print5) {
  FredkinCell x(Status::alive);
  x._age = 10;
  std::stringstream cell;
  cell << x;
  ASSERT_EQ(cell.str(), "+");
}
TEST(FredkinCell, constructor1) {
  FredkinCell x;
  ASSERT_EQ(x._status, Status::dead);
  ASSERT_EQ(x._age, 0);
}
TEST(FredkinCell, constructor2) {
  FredkinCell x(Status::dead);
  ASSERT_EQ(x._status, Status::dead);
  ASSERT_EQ(x._age, 0);
}
TEST(FredkinCell, constructor3) {
  FredkinCell x(Status::alive);
  ASSERT_EQ(x._status, Status::alive);
  ASSERT_EQ(x._age, 0);
}
TEST(FredkinCell, constructor4) {
  FredkinCell y;
  FredkinCell x(y);
  ASSERT_EQ(x._status, Status::dead);
  ASSERT_EQ(x._age, 0);
}
TEST(FredkinCell, constructor5) {
  FredkinCell y(Status::dead);
  FredkinCell x(y);
  ASSERT_EQ(x._status, Status::dead);
  ASSERT_EQ(x._age, 0);
}
TEST(FredkinCell, constructor6) {
  FredkinCell y(Status::alive);
  FredkinCell x(y);
  ASSERT_EQ(x._status, Status::alive);
  ASSERT_EQ(x._age, 0);
}
TEST(FredkinCell, act1) {
  FredkinCell x;
  for (int i = 0; i < 5; i += 2) {
    x._livingNeighbors = i;
    x.act();
    ASSERT_EQ(x._status, Status::dead);
  }
}
TEST(FredkinCell, act2) {
  FredkinCell x;
  x._livingNeighbors = 3;
  x.act();
  ASSERT_EQ(x._status, Status::alive);
  x._status = Status::dead;
  x._livingNeighbors = 1;
  x.act();
  ASSERT_EQ(x._status, Status::alive);
}
TEST(FredkinCell, act3) {
  FredkinCell x(Status::alive);
  for (int i = 0; i < 5; i += 2) {
    x._livingNeighbors = i;
    x.act();
    ASSERT_EQ(x._status, Status::dead);
    x._status = Status::alive;
  }
}
TEST(FredkinCell, act4) {
  FredkinCell x(Status::alive);
  for (int i = 1; i < 5; i += 2) {
    x._livingNeighbors = i;
    x.act();
    ASSERT_EQ(x._status, Status::alive);
  }
}
TEST(FredkinCell, clone1) {
  FredkinCell x;
  FredkinCell *p = static_cast<FredkinCell *>(x.clone());
  ASSERT_EQ(p->_status, x._status);
  delete p;
}
TEST(FredkinCell, clone2) {
  FredkinCell x(Status::alive);
  FredkinCell *p = static_cast<FredkinCell *>(x.clone());
  ASSERT_EQ(p->_status, x._status);
  delete p;
}
TEST(FredkinCell, clone3) {
  AbstractCell *ap = new FredkinCell();
  FredkinCell *fp = static_cast<FredkinCell *>(ap->clone());
  ASSERT_EQ(ap->_status, fp->_status);
  delete ap;
  delete fp;
}
TEST(FredkinCell, clone4) {
  AbstractCell *ap = new FredkinCell(Status::alive);
  FredkinCell *fp = static_cast<FredkinCell *>(ap->clone());
  ASSERT_EQ(ap->_status, fp->_status);
  delete ap;
  delete fp;
}
TEST(FredkinCell, updateNeighborCount1) {
  FredkinCell x;
  x.updateNeighborCount(Direction::northwest);
  ASSERT_EQ(0, x._livingNeighbors);
}
TEST(FredkinCell, updateNeighborCount2) {
  FredkinCell x;
  x.updateNeighborCount(Direction::north);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(FredkinCell, updateNeighborCount3) {
  FredkinCell x;
  x.updateNeighborCount(Direction::northeast);
  ASSERT_EQ(0, x._livingNeighbors);
}
TEST(FredkinCell, updateNeighborCount4) {
  FredkinCell x;
  x.updateNeighborCount(Direction::east);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(FredkinCell, updateNeighborCount5) {
  FredkinCell x;
  x.updateNeighborCount(Direction::southeast);
  ASSERT_EQ(0, x._livingNeighbors);
}
TEST(FredkinCell, updateNeighborCount6) {
  FredkinCell x;
  x.updateNeighborCount(Direction::south);
  ASSERT_EQ(1, x._livingNeighbors);
}
TEST(FredkinCell, updateNeighborCount7) {
  FredkinCell x;
  x.updateNeighborCount(Direction::southwest);
  ASSERT_EQ(0, x._livingNeighbors);
}
TEST(FredkinCell, updateNeighborCount8) {
  FredkinCell x;
  x.updateNeighborCount(Direction::west);
  ASSERT_EQ(1, x._livingNeighbors);
}
#ifdef ISALIVE
TEST(FredkinCell, isAlive1) {
  FredkinCell x;
  ASSERT_FALSE(x.isAlive());
}
TEST(FredkinCell, isAlive2) {
  FredkinCell x(Status::dead);
  ASSERT_FALSE(x.isAlive());
}
TEST(FredkinCell, isAlive3) {
  FredkinCell x(Status::alive);
  ASSERT_TRUE(x.isAlive());
}
#endif
TEST(Cell, constructor1) {
  Cell x;
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(x._ac));
}
TEST(Cell, constructor2) {
  Cell x(new ConwayCell);
  ASSERT_TRUE(dynamic_cast<ConwayCell *>(x._ac));
}
TEST(Cell, constructor3) {
  Cell x(new FredkinCell);
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(x._ac));
}
TEST(Cell, constructor4) {
  Cell w;
  Cell x(w);
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(x._ac));
}
TEST(Cell, constructor5) {
  Cell w(new ConwayCell);
  Cell x(w);
  ASSERT_TRUE(dynamic_cast<ConwayCell *>(x._ac));
}
TEST(Cell, constructor6) {
  Cell w(new FredkinCell);
  Cell x(w);
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(x._ac));
}
#ifdef ISALIVE
TEST(Cell, isAlive1) {
  Cell x;
  ASSERT_FALSE(x.isAlive());
}
TEST(Cell, isAlive2) {
  Cell x(new FredkinCell(Status::dead));
  ASSERT_FALSE(x.isAlive());
}
TEST(Cell, isAlive3) {
  Cell x(new FredkinCell(Status::alive));
  ASSERT_TRUE(x.isAlive());
}
TEST(Cell, isAlive4) {
  Cell x(new ConwayCell(Status::dead));
  ASSERT_FALSE(x.isAlive());
}
TEST(Cell, isAlive5) {
  Cell x(new ConwayCell(Status::alive));
  ASSERT_TRUE(x.isAlive());
}
#endif
TEST(Cell, act1) {
  Cell x;
  FredkinCell *p = dynamic_cast<FredkinCell *>(x._ac);
  p->_age = 1;
  p->_livingNeighbors = 1;
  x.act();
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(x._ac));
  ASSERT_EQ(p->_age, 1);
}
TEST(Cell, act2) {
  Cell x(new FredkinCell(Status::alive));
  FredkinCell *p = dynamic_cast<FredkinCell *>(x._ac);
  p->_age = 0;
  p->_livingNeighbors = 1;
  x.act();
  ASSERT_TRUE(p = dynamic_cast<FredkinCell *>(x._ac));
  ASSERT_EQ(p->_age, 1);
}
TEST(Cell, act3) {
  Cell x(new FredkinCell(Status::alive));
  FredkinCell *p = dynamic_cast<FredkinCell *>(x._ac);
  p->_age = 1;
  p->_livingNeighbors = 1;
  x.act();
  ASSERT_TRUE(dynamic_cast<ConwayCell *>(x._ac));
}
TEST(Cell, updateNeighborCount1) {
  Cell x(new FredkinCell);
  x.updateNeighborCount(Direction::northwest);
  ASSERT_EQ(0, x._ac->_livingNeighbors);
}
TEST(Cell, updateNeighborCount2) {
  Cell x(new FredkinCell);
  x.updateNeighborCount(Direction::north);
  ASSERT_EQ(1, x._ac->_livingNeighbors);
}
TEST(Cell, updateNeighborCount3) {
  Cell x(new FredkinCell);
  x.updateNeighborCount(Direction::northeast);
  ASSERT_EQ(0, x._ac->_livingNeighbors);
}
TEST(Cell, updateNeighborCount4) {
  Cell x(new FredkinCell);
  x.updateNeighborCount(Direction::east);
  ASSERT_EQ(1, x._ac->_livingNeighbors);
}
TEST(Cell, updateNeighborCount5) {
  Cell x(new ConwayCell);
  x.updateNeighborCount(Direction::southeast);
  ASSERT_EQ(1, x._ac->_livingNeighbors);
}
TEST(Cell, updateNeighborCount6) {
  Cell x(new ConwayCell);
  x.updateNeighborCount(Direction::south);
  ASSERT_EQ(1, x._ac->_livingNeighbors);
}
TEST(Cell, updateNeighborCount7) {
  Cell x(new ConwayCell);
  x.updateNeighborCount(Direction::southwest);
  ASSERT_EQ(1, x._ac->_livingNeighbors);
}
TEST(Cell, updateNeighborCount8) {
  Cell x(new ConwayCell);
  x.updateNeighborCount(Direction::west);
  ASSERT_EQ(1, x._ac->_livingNeighbors);
}
TEST(Cell, copyAssignment1) {
  Cell x(new ConwayCell(Status::alive));
  Cell y;
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(y._ac));
  ASSERT_EQ(y._ac->_status, Status::dead);
  y = x;
  ASSERT_TRUE(dynamic_cast<ConwayCell *>(y._ac));
  ASSERT_EQ(y._ac->_status, Status::alive);
}
TEST(Cell, copyAssignment2) {
  Cell x;
  Cell y;
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(y._ac));
  y = x;
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(y._ac));
}
TEST(Cell, copyAssignment3) {
  Cell x(new FredkinCell);
  Cell y(new ConwayCell);
  ASSERT_TRUE(dynamic_cast<ConwayCell *>(y._ac));
  y = x;
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(y._ac));
}
