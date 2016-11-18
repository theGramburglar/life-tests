// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <sstream>
#include <vector>

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, test) {

  istringstream s("2 2\n--\n--\n");
  Life<Cell> x(s);
  ASSERT_TRUE(x.dummy());
}

TEST(LifeFixture, conway_default_constructor_1) {
  ConwayCell c;
  ASSERT_EQ(c.state, '.');
}

TEST(LifeFixture, conway_state_constructor_1) {
  ConwayCell c('.');
  ASSERT_EQ(c.state, '.');
}

TEST(LifeFixture, conway_state_constructor_2) {
  ConwayCell c('*');
  ASSERT_EQ(c.state, '*');
}

TEST(LifeFixture, conway_copy_constructor_1) {
  ConwayCell c('*');
  ConwayCell o(c);
  ASSERT_EQ(o.state, '*');
}

TEST(LifeFixture, conway_copy_constructor_2) {
  ConwayCell c('.');
  ConwayCell o(c);
  ASSERT_EQ(o.state, '.');
}

TEST(LifeFixture, conway_copy_constructor_3) {
  ConwayCell c;
  ConwayCell o(c);
  ASSERT_EQ(o.state, '.');
}

TEST(LifeFixture, conway_count_1) {
  ConwayCell c;
  vector<vector<bool>> neighborhood = {
      {false, false, false}, {false, false, false}, {false, false, false}};
  int num_neighbors = c.count_neighbors(neighborhood);
  ASSERT_EQ(num_neighbors, 0);
}

TEST(LifeFixture, conway_count_2) {
  ConwayCell c;
  vector<vector<bool>> neighborhood = {
      {true, true, true}, {false, false, false}, {false, false, false}};
  int num_neighbors = c.count_neighbors(neighborhood);
  ASSERT_EQ(num_neighbors, 3);
}

TEST(LifeFixture, conway_count_3) {
  ConwayCell c;
  vector<vector<bool>> neighborhood = {
      {true, true, true}, {true, false, false}, {false, false, false}};
  int num_neighbors = c.count_neighbors(neighborhood);
  ASSERT_EQ(num_neighbors, 4);
}

TEST(LifeFixture, conway_count_4) {
  ConwayCell c;
  vector<vector<bool>> neighborhood = {
      {true, true, true}, {true, false, true}, {true, true, true}};
  int num_neighbors = c.count_neighbors(neighborhood);
  ASSERT_EQ(num_neighbors, 8);
}

TEST(LifeFixture, conway_update_1) {
  ConwayCell c;
  vector<vector<bool>> neighborhood = {
      {false, false, false}, {false, false, false}, {false, false, false}};
  c.update(neighborhood);
  ASSERT_EQ(c.state, '.');
}

TEST(LifeFixture, conway_update_2) {
  ConwayCell c;
  vector<vector<bool>> neighborhood = {
      {true, true, true}, {false, false, false}, {false, false, false}};
  c.update(neighborhood);
  ASSERT_EQ(c.state, '*');
}

TEST(LifeFixture, conway_update_3) {
  ConwayCell c('*');
  vector<vector<bool>> neighborhood = {
      {true, false, false}, {false, false, false}, {false, false, false}};
  c.update(neighborhood);
  ASSERT_EQ(c.state, '.');
}

TEST(LifeFixture, conway_update_4) {
  ConwayCell c('*');
  vector<vector<bool>> neighborhood = {
      {true, true, true}, {true, false, false}, {false, false, false}};
  c.update(neighborhood);
  ASSERT_EQ(c.state, '.');
}

TEST(LifeFixture, conway_update_5) {
  ConwayCell c('*');
  vector<vector<bool>> neighborhood = {
      {true, true, false}, {true, false, false}, {false, false, false}};
  c.update(neighborhood);
  ASSERT_EQ(c.state, '*');
}

TEST(LifeFixture, conway_alive_1) {
  ConwayCell c;
  ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, conway_alive_2) {
  ConwayCell c('.');
  ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, conway_alive_3) {
  ConwayCell c('*');
  ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, conway_clone_1) {
  ConwayCell c;
  AbstractCell *x = c.clone();
  ASSERT_EQ(x->state, c.state);
  ASSERT_NE(x, &c);
  delete x;
}

TEST(LifeFixture, conway_clone_2) {
  ConwayCell c('.');
  AbstractCell *x = c.clone();
  ASSERT_EQ(x->state, c.state);
  ASSERT_NE(x, &c);
  delete x;
}

TEST(LifeFixture, conway_clone_3) {
  ConwayCell c('*');
  AbstractCell *x = c.clone();
  ASSERT_EQ(x->state, c.state);
  ASSERT_NE(x, &c);
  delete x;
}

TEST(LifeFixture, conway_output_1) {
  ConwayCell c;
  ostringstream out;
  out << c;
  ASSERT_EQ(out.str(), ".");
}

TEST(LifeFixture, conway_output_2) {
  ConwayCell c('.');
  ostringstream out;
  out << c;
  ASSERT_EQ(out.str(), ".");
}

TEST(LifeFixture, conway_output_3) {
  ConwayCell c('*');
  ostringstream out;
  out << c;
  ASSERT_EQ(out.str(), "*");
}

TEST(LifeFixture, fredkin_default_constructor_1) {
  FredkinCell f;
  ASSERT_EQ(f.state, '-');
  ASSERT_EQ(f.age, 0);
}

TEST(LifeFixture, fredkin_state_constructor_1) {
  FredkinCell f('-');
  ASSERT_EQ(f.state, '-');
  ASSERT_EQ(f.age, 0);
}

TEST(LifeFixture, fredkin_state_constructor_2) {
  FredkinCell f('0');
  ASSERT_EQ(f.state, '0');
  ASSERT_EQ(f.age, 0);
}

TEST(LifeFixture, fredkin_state_constructor_3) {
  FredkinCell f('+');
  ASSERT_EQ(f.state, '+');
  ASSERT_EQ(f.age, 0);
}

TEST(LifeFixture, fredkin_copy_constructor_1) {
  FredkinCell f;
  FredkinCell o(f);
  ASSERT_EQ(o.state, '-');
  ASSERT_EQ(o.age, 0);
}

TEST(LifeFixture, fredkin_copy_constructor_2) {
  FredkinCell f('-');
  FredkinCell o(f);
  ASSERT_EQ(o.state, '-');
  ASSERT_EQ(o.age, 0);
}

TEST(LifeFixture, fredkin_copy_constructor_3) {
  FredkinCell f('4');
  f.age = 4;
  FredkinCell o(f);
  ASSERT_EQ(o.state, '4');
  ASSERT_EQ(o.age, 4);
}

TEST(LifeFixture, fredkin_copy_constructor_4) {
  FredkinCell f('+');
  f.age = 1618;
  FredkinCell o(f);
  ASSERT_EQ(o.state, '+');
  ASSERT_EQ(o.age, 1618);
}

TEST(LifeFixture, fredkin_count_1) {
  FredkinCell f;
  vector<vector<bool>> neighborhood = {
      {false, false, false}, {false, false, false}, {false, false, false}};
  int count = f.count_neighbors(neighborhood);
  ASSERT_EQ(count, 0);
}

TEST(LifeFixture, fredkin_count_2) {
  FredkinCell f;
  vector<vector<bool>> neighborhood = {
      {true, true, false}, {false, false, false}, {false, false, false}};
  int count = f.count_neighbors(neighborhood);
  ASSERT_EQ(count, 1);
}

TEST(LifeFixture, fredkin_count_3) {
  FredkinCell f;
  vector<vector<bool>> neighborhood = {
      {true, true, false}, {false, true, false}, {false, false, false}};
  int count = f.count_neighbors(neighborhood);
  ASSERT_EQ(count, 1);
}

TEST(LifeFixture, fredkin_count_4) {
  FredkinCell f;
  vector<vector<bool>> neighborhood = {
      {true, true, true}, {true, true, true}, {true, true, true}};
  int count = f.count_neighbors(neighborhood);
  ASSERT_EQ(count, 4);
}

TEST(LifeFixture, fredkin_update_1) {
  FredkinCell f;
  vector<vector<bool>> neighborhood = {
      {false, false, false}, {false, false, false}, {false, false, false}};
  f.update(neighborhood);
  ASSERT_EQ(f.state, '-');
}

TEST(LifeFixture, fredkin_update_2) {
  FredkinCell f;
  f.age = 6;
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  f.update(neighborhood);
  ASSERT_EQ(f.state, '6');
}

TEST(LifeFixture, fredkin_update_3) {
  FredkinCell f;
  f.age = 1618;
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {true, false, false}, {false, true, false}};
  f.update(neighborhood);
  ASSERT_EQ(f.state, '+');
}

TEST(LifeFixture, fredkin_update_4) {
  FredkinCell f('3');
  f.age = 3;
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  f.update(neighborhood);
  ASSERT_EQ(f.state, '4');
  ASSERT_EQ(f.age, 4);
}

TEST(LifeFixture, fredkin_update_5) {
  FredkinCell f('9');
  f.age = 9;
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, true}, {false, true, false}};
  f.update(neighborhood);
  ASSERT_EQ(f.state, '+');
  ASSERT_EQ(f.age, 10);
}

TEST(LifeFixture, fredkin_update_6) {
  FredkinCell f('6');
  f.age = 6;
  vector<vector<bool>> neighborhood = {
      {false, false, false}, {false, false, false}, {false, false, false}};
  f.update(neighborhood);
  ASSERT_EQ(f.state, '-');
  ASSERT_EQ(f.age, 6);
}

TEST(LifeFixture, fredkin_update_7) {
  FredkinCell f('8');
  f.age = 8;
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {true, false, false}, {false, false, false}};
  f.update(neighborhood);
  ASSERT_EQ(f.state, '-');
  ASSERT_EQ(f.age, 8);
}

TEST(LifeFixture, fredkin_update_8) {
  FredkinCell f('0');
  f.age = 0;
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {true, false, true}, {false, true, false}};
  f.update(neighborhood);
  ASSERT_EQ(f.state, '-');
  ASSERT_EQ(f.age, 0);
}

TEST(LifeFixture, fredkin_alive_1) {
  FredkinCell f;
  ASSERT_FALSE(f.alive());
}

TEST(LifeFixture, fredkin_alive_2) {
  FredkinCell f('-');
  ASSERT_FALSE(f.alive());
}

TEST(LifeFixture, fredkin_alive_3) {
  FredkinCell f('6');
  ASSERT_TRUE(f.alive());
}

TEST(LifeFixture, fredkin_alive_4) {
  FredkinCell f('+');
  ASSERT_TRUE(f.alive());
}

TEST(LifeFixture, fredkin_clone_1) {
  FredkinCell f;
  FredkinCell *c = dynamic_cast<FredkinCell *>(f.clone());
  ASSERT_EQ(f.state, c->state);
  ASSERT_EQ(f.age, c->age);
  ASSERT_NE(&f, c);
  delete c;
}

TEST(LifeFixture, fredkin_clone_2) {
  FredkinCell f('-');
  FredkinCell *c = dynamic_cast<FredkinCell *>(f.clone());
  ASSERT_EQ(f.state, c->state);
  ASSERT_EQ(f.age, c->age);
  ASSERT_NE(&f, c);
  delete c;
}

TEST(LifeFixture, fredkin_clone_3) {
  FredkinCell f('6');
  f.age = 6;
  FredkinCell *c = dynamic_cast<FredkinCell *>(f.clone());
  ASSERT_EQ(f.state, c->state);
  ASSERT_EQ(f.age, c->age);
  ASSERT_NE(&f, c);
  delete c;
}

TEST(LifeFixture, fredkin_clone_4) {
  FredkinCell f('+');
  f.age = 1618;
  FredkinCell *c = dynamic_cast<FredkinCell *>(f.clone());
  ASSERT_EQ(f.state, c->state);
  ASSERT_EQ(f.age, c->age);
  ASSERT_NE(&f, c);
  delete c;
}

TEST(LifeFixture, fredkin_mutate_1) {
  FredkinCell f;
  AbstractCell *o = f.mutate();
  ASSERT_EQ(o, &f);
}

TEST(LifeFixture, fredkin_mutate_2) {
  FredkinCell f('2');
  f.age = 2;
  AbstractCell *o = f.mutate();
  ConwayCell *c = dynamic_cast<ConwayCell *>(o);
  ASSERT_NE(c, nullptr);
  ASSERT_NE(o, &f);
  delete c;
}

TEST(LifeFixture, fredkin_mutate_3) {
  FredkinCell f('1');
  f.age = 1;
  AbstractCell *o = f.mutate();
  ASSERT_EQ(o, &f);
}

TEST(LifeFixture, fredkin_output_1) {
  FredkinCell f;
  ostringstream out;
  out << f;
  ASSERT_EQ(out.str(), "-");
}

TEST(LifeFixture, fredkin_output_2) {
  FredkinCell f('-');
  ostringstream out;
  out << f;
  ASSERT_EQ(out.str(), "-");
}

TEST(LifeFixture, fredkin_output_3) {
  FredkinCell f('6');
  f.age = 6;
  ostringstream out;
  out << f;
  ASSERT_EQ(out.str(), "6");
}

TEST(LifeFixture, fredkin_output_4) {
  FredkinCell f('+');
  f.age = 1618;
  ostringstream out;
  out << f;
  ASSERT_EQ(out.str(), "+");
}

TEST(LifeFixture, cell_default_constructor_1) {
  Cell c;
  FredkinCell *f = dynamic_cast<FredkinCell *>(c.cell);
  ASSERT_NE(f, nullptr);
  ASSERT_EQ(f->state, '-');
  ASSERT_EQ(f->age, 0);
}

TEST(LifeFixture, cell_state_constructor_1) {
  Cell c('-');
  FredkinCell *f = dynamic_cast<FredkinCell *>(c.cell);
  ASSERT_NE(f, nullptr);
  ASSERT_EQ(f->state, '-');
  ASSERT_EQ(f->age, 0);
}

TEST(LifeFixture, cell_state_constructor_2) {
  Cell c('0');
  FredkinCell *f = dynamic_cast<FredkinCell *>(c.cell);
  ASSERT_NE(f, nullptr);
  ASSERT_EQ(f->state, '0');
  ASSERT_EQ(f->age, 0);
}

TEST(LifeFixture, cell_copy_constructor_1) {
  Cell c;
  Cell o(c);
  FredkinCell *f = dynamic_cast<FredkinCell *>(c.cell);
  FredkinCell *of = dynamic_cast<FredkinCell *>(o.cell);
  ASSERT_NE(f, nullptr);
  ASSERT_EQ(f->state, of->state);
  ASSERT_EQ(f->age, of->age);
}

TEST(LifeFixture, cell_copy_constructor_2) {
  Cell c('-');
  Cell o(c);
  FredkinCell *f = dynamic_cast<FredkinCell *>(c.cell);
  FredkinCell *of = dynamic_cast<FredkinCell *>(o.cell);
  ASSERT_NE(f, nullptr);
  ASSERT_EQ(f->state, of->state);
  ASSERT_EQ(f->age, of->age);
}

TEST(LifeFixture, cell_copy_constructor_3) {
  Cell c('0');
  Cell o(c);
  FredkinCell *f = dynamic_cast<FredkinCell *>(c.cell);
  FredkinCell *of = dynamic_cast<FredkinCell *>(o.cell);
  ASSERT_NE(f, nullptr);
  ASSERT_EQ(f->state, of->state);
  ASSERT_EQ(f->age, of->age);
}

TEST(LifeFixture, cell_alive_1) {
  Cell c;
  ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, cell_alive_2) {
  Cell c('-');
  ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, cell_alive_3) {
  Cell c('0');
  ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, cell_update_1) {
  Cell c;
  vector<vector<bool>> neighborhood = {
      {false, false, false}, {false, false, false}, {false, false, false}};
  c.update(neighborhood);
  ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, cell_update_2) {
  Cell c('-');
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  c.update(neighborhood);
  ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, cell_update_3) {
  Cell c('-');
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  c.update(neighborhood);
  c.update(neighborhood);
  c.update(neighborhood);
  ConwayCell *o = dynamic_cast<ConwayCell *>(c.cell);
  ASSERT_NE(o, nullptr);
  ASSERT_TRUE(c.alive());
  ASSERT_EQ(o->state, '*');
}

TEST(LifeFixture, cell_update_4) {
  Cell c('-');
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  c.update(neighborhood);
  c.update(neighborhood);
  FredkinCell *o = dynamic_cast<FredkinCell *>(c.cell);
  ASSERT_NE(o, nullptr);
  ASSERT_TRUE(c.alive());
  ASSERT_EQ(o->state, '1');
}

TEST(LifeFixture, cell_update_5) {
  Cell c('-');
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  c.update(neighborhood);
  c.update(neighborhood);
  c.update(neighborhood);
  ConwayCell *o = dynamic_cast<ConwayCell *>(c.cell);
  ASSERT_NE(o, nullptr);
  ASSERT_TRUE(c.alive());
  ASSERT_EQ(o->state, '*');
}

TEST(LifeFixture, cell_update_6) {
  Cell c('-');
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  c.update(neighborhood);
  c.update(neighborhood);
  c.update(neighborhood);
  neighborhood[0][0] = true;
  c.update(neighborhood);
  ConwayCell *o = dynamic_cast<ConwayCell *>(c.cell);
  ASSERT_NE(o, nullptr);
  ASSERT_TRUE(c.alive());
  ASSERT_EQ(o->state, '*');
}

TEST(LifeFixture, cell_output_1) {
  Cell c;
  ostringstream out;
  out << c;
  ASSERT_EQ(out.str(), "-");
}

TEST(LifeFixture, cell_output_2) {
  Cell c('0');
  ostringstream out;
  out << c;
  ASSERT_EQ(out.str(), "0");
}

TEST(LifeFixture, cell_output_3) {
  Cell c('0');
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  ostringstream out;
  c.update(neighborhood);
  out << c;
  ASSERT_EQ(out.str(), "1");
}

TEST(LifeFixture, cell_output_4) {
  Cell c('0');
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  ostringstream out;
  c.update(neighborhood);
  c.update(neighborhood);
  out << c;
  ASSERT_EQ(out.str(), "*");
}

TEST(LifeFixture, cell_output_5) {
  Cell c('0');
  vector<vector<bool>> neighborhood = {
      {false, true, false}, {false, false, false}, {false, false, false}};
  ostringstream out;
  c.update(neighborhood);
  c.update(neighborhood);
  c.update(neighborhood);
  out << c;
  ASSERT_EQ(out.str(), ".");
}

TEST(LifeFixture, life_constructor_1) {
  istringstream in("3 3\n---\n---\n---");
  Life<Cell> l(in);
  ASSERT_EQ(l.board.size(), 3);
  ASSERT_EQ(l.board[0].size(), 3);
  ASSERT_EQ(l.population, 0);
}

TEST(LifeFixture, life_constructor_2) {
  istringstream in("3 4\n----\n-0--\n0---");
  Life<Cell> l(in);
  ASSERT_EQ(l.board.size(), 3);
  ASSERT_EQ(l.board[0].size(), 4);
  ASSERT_EQ(l.population, 2);
}

TEST(LifeFixture, life_constructor_3) {
  istringstream in("3 4\n0000\n0000\n0000");
  Life<Cell> l(in);
  ASSERT_EQ(l.board.size(), 3);
  ASSERT_EQ(l.board[0].size(), 4);
  ASSERT_EQ(l.population, 12);
}

TEST(LifeFixture, life_generate_alive_board_1) {
  istringstream in("3 3\n---\n---\n---");
  Life<Cell> l(in);
  l.generate_alive_board();
  vector<vector<bool>> ab = {
      {false, false, false}, {false, false, false}, {false, false, false}};
  ASSERT_EQ(l.alive_board, ab);
}

TEST(LifeFixture, life_generate_alive_board_2) {
  istringstream in("3 4\n-0--\n----\n0-0-");
  Life<Cell> l(in);
  l.generate_alive_board();
  vector<vector<bool>> ab = {{false, true, false, false},
                             {false, false, false, false},
                             {true, false, true, false}};
  ASSERT_EQ(l.alive_board, ab);
}

TEST(LifeFixture, life_generate_alive_board_3) {
  istringstream in("3 4\n0000\n0000\n0000");
  Life<Cell> l(in);
  l.generate_alive_board();
  vector<vector<bool>> ab = {{true, true, true, true},
                             {true, true, true, true},
                             {true, true, true, true}};
  ASSERT_EQ(l.alive_board, ab);
}

TEST(LifeFixture, life_fetch_neighborhood_board_1) {
  istringstream in("3 3\n---\n---\n---");
  Life<Cell> l(in);
  vector<vector<bool>> neighborhood = {
      {false, false, false}, {false, false, false}, {false, false, false}};
  l.generate_alive_board();
  vector<vector<bool>> actual = l.fetch_neighborhood(1, 1);
  ASSERT_EQ(actual, neighborhood);
}

TEST(LifeFixture, life_fetch_neighborhood_board_2) {
  istringstream in("3 3\n0-0\n---\n-0-");
  Life<Cell> l(in);
  vector<vector<bool>> neighborhood = {
      {true, false, true}, {false, false, false}, {false, true, false}};
  l.generate_alive_board();
  vector<vector<bool>> actual = l.fetch_neighborhood(1, 1);
  ASSERT_EQ(actual, neighborhood);
}

TEST(LifeFixture, life_fetch_neighborhood_board_3) {
  istringstream in("3 3\n0-0\n---\n-0-");
  Life<Cell> l(in);
  vector<vector<bool>> neighborhood = {
      {false, false, false}, {false, false, false}, {false, false, false}};
  l.generate_alive_board();
  vector<vector<bool>> actual = l.fetch_neighborhood(0, 0);
  ASSERT_EQ(actual, neighborhood);
}

TEST(LifeFixture, life_fetch_neighborhood_board_4) {
  istringstream in("3 3\n0-0\n---\n-0-");
  Life<Cell> l(in);
  vector<vector<bool>> neighborhood = {
      {false, false, false}, {true, false, true}, {false, false, false}};
  l.generate_alive_board();
  vector<vector<bool>> actual = l.fetch_neighborhood(0, 1);
  ASSERT_EQ(actual, neighborhood);
}

TEST(LifeFixture, life_simulate_turn_1) {
  istringstream in("3 3\n---\n-0-\n---");
  Life<Cell> l(in);
  l.simulate_turn();
  ASSERT_EQ(l.population, 4);
  ASSERT_EQ(l.generation, 1);
}

TEST(LifeFixture, life_simulate_turn_2) {
  istringstream in("3 3\n0-0\n-0-\n---");
  Life<Cell> l(in);
  l.simulate_turn();
  ASSERT_EQ(l.population, 2);
  ASSERT_EQ(l.generation, 1);
}

TEST(LifeFixture, life_simulate_turn_3) {
  istringstream in("3 3\n0-0\n-0-\n---");
  Life<Cell> l(in);
  l.simulate_turn();
  l.simulate_turn();
  ASSERT_EQ(l.population, 4);
  ASSERT_EQ(l.generation, 2);
}

TEST(LifeFixture, life_output_1) {
  istringstream in("3 3\n0-0\n-0-\n---");
  Life<Cell> l(in);
  ostringstream out;
  out << l;
  ASSERT_EQ(out.str(), "Generation = 0, Population = 3.\n0-0\n-0-\n---\n");
}

TEST(LifeFixture, life_output_2) {
  istringstream in("3 4\n---0\n-0-0\n0000");
  Life<Cell> l(in);
  ostringstream out;
  out << l;
  ASSERT_EQ(out.str(), "Generation = 0, Population = 7.\n---0\n-0-0\n0000\n");
}
