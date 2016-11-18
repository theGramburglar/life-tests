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
#include <sstream> // istringtstream, ostringstream
#include <utility> // pair
#include "Life.h"

#include <string>
#include <sstream>
#include <utility>

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, test) {
    Life<ConwayCell, 5, 5> x;
    ASSERT_TRUE(x.dummy());
}

// ----
// ConwayCell Tests
// ----

TEST(LifeFixture, ConwayCell_1) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 10; i++){
  		for(int j = 0; j < 5; j++){
  			l.makeAlive(i,j);
  		}
  	}

    cout << l;

    string board = "\nGeneration = 0, Population = 50.\n*****.....\n*****.....\n*****.....\n*****.....\n*****.....\n*****.....\n*****.....\n*****.....\n*****.....\n*****.....\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_2) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 10; i++){
  		for(int j = 0; j < 5; j++){
  			l.makeAlive(i,j);
  		}
  	}

    l.nextGeneration();
    cout << l;

    string board = "\nGeneration = 1, Population = 12.\n*...*.....\n.....*....\n.....*....\n.....*....\n.....*....\n.....*....\n.....*....\n.....*....\n.....*....\n*...*.....\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_3) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 10; i++){
  		for(int j = 0; j < 5; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 2; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 2, Population = 22.\n..........\n....**....\n....***...\n....***...\n....***...\n....***...\n....***...\n....***...\n....**....\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_4) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 10; i++){
  		for(int j = 0; j < 5; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 3; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 3, Population = 14.\n..........\n....*.*...\n...*......\n...*...*..\n...*...*..\n...*...*..\n...*...*..\n...*......\n....*.*...\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_5) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 10; i++){
  		for(int j = 0; j < 5; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 4; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 4, Population = 22.\n..........\n..........\n...**.....\n..***.....\n..***.***.\n..***.***.\n..***.....\n...**.....\n..........\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_6) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 10; i++){
  		for(int j = 0; j < 5; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 5; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 5, Population = 12.\n..........\n..........\n..*.*.....\n.......*..\n.*....*.*.\n.*....*.*.\n.......*..\n..*.*.....\n..........\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_7) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 10; i++){
  		for(int j = 0; j < 5; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 6; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 6, Population = 6.\n..........\n..........\n..........\n.......*..\n......*.*.\n......*.*.\n.......*..\n..........\n..........\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_8) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 6; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 7; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 7, Population = 18.\n......**..\n....**.*..\n....*.....\n....*.**..\n...***.*..\n..***.....\n..........\n..**......\n..........\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_9) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}
  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 8; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 8, Population = 12.\n..........\n..........\n..........\n...*......\n.**.......\n.**.......\n..*.**....\n...**.....\n....**....\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_10) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 9; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 9, Population = 10.\n..........\n..........\n..........\n..*.......\n.*.*......\n..........\n.**.**....\n..........\n...***....\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_11) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 10; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 10, Population = 8.\n..........\n..........\n..........\n..*.......\n..*.......\n.*.**.....\n..........\n..*.......\n....*.....\n....*.....\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_12) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 11; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 11, Population = 7.\n..........\n..........\n..........\n..........\n.**.......\n..**......\n..**......\n..........\n...*......\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_13) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 12; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 12, Population = 7.\n..........\n..........\n..........\n..........\n.***......\n..........\n..**......\n..**......\n..........\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_14) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 13; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 13, Population = 7.\n..........\n..........\n..........\n..*.......\n..*.......\n.*........\n..**......\n..**......\n..........\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, ConwayCell_15) {
	Life<ConwayCell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    for(int i = 0; i < 14; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 14, Population = 8.\n..........\n..........\n..........\n..........\n.**.......\n.*.*......\n.*.*......\n..**......\n..........\n..........\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

// ----
// Cell Tests
// ----

TEST(LifeFixture, Cell_1) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    cout << l;

    string board = "\nGeneration = 0, Population = 62.\n0000000000\n0000000000\n0000000000\n0000000000\n0000000000\n000-------\n000-------\n000--0----\n----------\n-------0--\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_2) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

    l.nextGeneration();
 
    cout << l;

    string board = "\nGeneration = 1, Population = 45.\n-11111111-\n1--------1\n1--------1\n1--------1\n1--111111-\n1-1-000000\n1-10-0----\n-1-00-0---\n000--0-0--\n------0-0-\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_3) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 2; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 2, Population = 50.\n-*------*-\n*-000000-*\n-0------0-\n-0-00000-*\n-0-*****-0\n--*---1111\n*0---10000\n0*--1-----\n111-------\n000----0-0\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_4) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 3; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 3, Population = 51.\n-*-1111-*-\n*-1----1-*\n-1-----0-1\n1---111-0*\n110.....1-\n10*-00*-**\n*----*111-\n1.-0--0000\n*--00--0-0\n-1-0--0---\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_5) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 4; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 4, Population = 58.\n-*1*--*1*-\n*---00-*0*\n1---00-10-\n*000*-*0-*\n**-.....-0\n*1*-11.1.*\n*-10-.-**0\n-*01----1-\n*-11100101\n---1-0---0\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_6) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 5; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 5, Population = 49.\n-*-*--**.-\n*-1---0.-*\n--0-1-0*-1\n.1--*1*-0*\n..0....*1-\n.*.0****.*\n*-*--.1*.-\n1.-*-000-0\n.1---1--1-\n0--*01-0-1\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_7) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 6; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 6, Population = 44.\n-*1.11**.0\n.0*-00-.0.\n1-1-*01.0-\n.-00*-.--*\n.*-.....-0\n.*.1**....\n*0*00.*..-\n*.-.--1-1-\n*-1----1-1\n--0.----0-\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_8) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 7; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 7, Population = 41.\n0*-.-****-\n*-.-110.1*\n-1-0.1**1-\n.---*-.--*\n.*-..*..11\n...-.*....\n*1.1-.**.-\n*.-.10*0--\n.-*1------\n011.------\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_9) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 8; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 8, Population = 44.\n-*1.-...*-\n*0*-*-1.**\n----.-..-1\n.---*1.00*\n..0.**..*-\n***1**.**.\n**.--..*.-\n*.0.*-.-1-\n*-**-101--\n1--*------\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_10) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 9; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 9, Population = 51.\n-.-*1..**-\n*1*-.--***\n111-*1*.1-\n.-00*-*11*\n..1......-\n*..-.*.**.\n...1-***.-\n*.1.*-.0-0\n*-*.1*-*--\n*1-*0100--\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_11) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 10; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 10, Population = 52.\n0*-**..*.-\n**.-.1-..*\n-**0*-..-1\n.-1-*1*-**\n.**.**...1\n...1**.**.\n.*.-0*...0\n..*..0.---\n*1*.*.0*11\n**1*1*--0-\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_12) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 11; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board =  "\nGeneration = 11, Population = 39.\n-*-.*....0\n...-.-1.*.\n-..-.1*.--\n.1-0.**-**\n.**......*\n.*.*....**\n..*--...*-\n*.*..1.01-\n**....1***\n*.*.**--1-\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_13) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 12; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 12, Population = 37.\n0.1......-\n...-.-**..\n-..0*-..-1\n.*1-***-**\n**.**..*..\n.*.*....**\n..*--....-\n*.*..-.-*-\n*.***.*..*\n*....*--*-\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_14) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 13; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 13, Population = 40.\n-.-......-\n...0.1....\n-.*1*-..-*\n***-..*1**\n*.....**..\n**.**...*.\n..*--...*0\n..*..-.0.-\n*.****.***\n.*.***-0.-\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

TEST(LifeFixture, Cell_15) {
	Life<Cell, 10, 10> l;

	stringstream ss;
  	auto old_buf = cout.rdbuf(ss.rdbuf());

  	l.makeAlive(9, 7);
    l.makeAlive(2, 6);
    l.makeAlive(7, 5);

    for(int i = 0; i < 5; i++){
  		for(int j = 0; j < 10; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 5; i < 8; i++){
  		for(int j = 0; j < 3; j++){
  			l.makeAlive(i,j);
  		}
  	}

  	for(int i = 0; i < 14; i++){
    	l.nextGeneration();
    }

    cout << l;

    string board = "\nGeneration = 14, Population = 41.\n-.-......-\n..*1.-....\n1..**-**-*\n*.*-.***.*\n...*.**..*\n****....**\n..*-0..**1\n..*.*1*1.-\n.....*.*..\n.*...*-1.1\n\n";

  	cout.rdbuf(old_buf);
  	ASSERT_EQ(board, ss.str());
}

// ----------
// life_setup
// ----------

TEST(LifeSetupFixture, test1) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n**********\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(0, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test2) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n..........\n**********\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(1, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test3) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n..........\n..........\n**********\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(2, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test4) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n..........\n..........\n..........\n**********\n..........\n..........\n..........\n..........\n..........\n..........\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(3, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test5) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n..........\n..........\n..........\n..........\n**********\n..........\n..........\n..........\n..........\n..........\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(4, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test6) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n..........\n..........\n..........\n..........\n..........\n**********\n..........\n..........\n..........\n..........\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(5, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test7) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n..........\n..........\n..........\n..........\n..........\n..........\n**********\n..........\n..........\n..........\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(6, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test8) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n**********\n..........\n..........\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(7, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test9) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n**********\n..........\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(8, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test10) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 10.\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n**********\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(9, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test11) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 20.\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n**********\n**********\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(8, i);
    	x.makeAlive(9, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test12) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 30.\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n**********\n**********\n**********\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(7, i);
    	x.makeAlive(8, i);
    	x.makeAlive(9, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test13) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 40.\n..........\n..........\n..........\n..........\n..........\n..........\n**********\n**********\n**********\n**********\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(6, i);
    	x.makeAlive(7, i);
    	x.makeAlive(8, i);
    	x.makeAlive(9, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test14) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 50.\n..........\n..........\n..........\n..........\n..........\n**********\n**********\n**********\n**********\n**********\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(5, i);
    	x.makeAlive(6, i);
    	x.makeAlive(7, i);
    	x.makeAlive(8, i);
    	x.makeAlive(9, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeSetupFixture, test15) {
    Life<ConwayCell, 10, 10> x;
    string board = "\nGeneration = 0, Population = 60.\n..........\n..........\n..........\n..........\n**********\n**********\n**********\n**********\n**********\n**********\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    for (int i = 0; i < 10; ++i) {
    	x.makeAlive(4, i);
    	x.makeAlive(5, i);
    	x.makeAlive(6, i);
    	x.makeAlive(7, i);
    	x.makeAlive(8, i);
    	x.makeAlive(9, i);
    }
    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

// -----------
// life_fredkin
// -----------

TEST(LifeFredkinFixture, test1) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 1, Population = 44.\n000-0-----------\n1------0--------\n----0-0-0-------\n-0--0-00--0-----\n--010010-010----\n---0-010-010----\n------0---0-----\n-------0-------0\n------0-0-----01\n-------0--------\n-------------0-1\n-------------0--\n--------------00\n----------------\n----------------\n----------------\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 1; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test2) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 2, Population = 48.\n--1--0-0--------\n2-0-------------\n00-01-1--00-----\n0----01---1-----\n--1211-1----0---\n---10-------0---\n---0--10--1----0\n------0---0----1\n-----0---0---01-\n-------------00-\n-------0----01--\n------------01--\n--------------11\n--------------00\n----------------\n----------------\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 2; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test3) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 3, Population = 86.\n00200---0-------\n301-0000-00-----\n1101202001-0----\n1-0-0-----200---\n00232-1-0-1010--\n---2--1---1010-0\n--01-0-100200-01\n---0--1---10-0-2\n----0---0---0---\n-----0-0-0---1-0\n------0-0--0-2--\n-------0---0---0\n------------0---\n-------------0--\n--------------00\n----------------\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 3; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test4) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 4, Population = 61.\n-13---0---0-----\n4-2-111---1-----\n22---131---1----\n-------0--------\n--34--2---2---00\n000---2---2---01\n-012---2------12\n---1----------03\n------0---0--0--\n------0---00-2--\n----------01-30-\n----------01-10-\n-------0-------1\n---------------0\n--------------11\n--------------00\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 4; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test5) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 5, Population = 97.\n-2-00-10-010----\n5-3-222--02-----\n-3----4-0---0---\n1000-0110-20--00\n0--5213--030-0--\n1112-03--030-012\n--2-0---0-2--023\n-0-20-10--1-----\n---0-010-01-01-1\n-----010-01-----\n------0--012-4-1\n-------0-0------\n------0-0-00-0-2\n-------0--------\n-------------0-2\n-------------0--\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 5; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test6) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 6, Population = 86.\n--31-0-1--210---\n---0--3-----0---\n240121-11----000\n-1--0----0----11\n-036--4----1-10-\n--2----0-----12-\n003-1----0--0-3-\n0-0--0-----00-0-\n-0010--1--2-12--\n---00----12-0---\n------100123----\n------0-010-----\n-----0---011----\n----------00----\n-------0----01--\n------------0100\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 6; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test7) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 7, Population = 105.\n-24---1-003--0--\n503--2-00-2-1-00\n35-232422----11-\n--001-11--20-02-\n0-47-1---03---1-\n11--0---00-0--32\n--4----20-2-10-3\n1---0-10-0-11013\n-112--1-0-3023--\n-0---01---301---\n---000--1--4----\n------10--11----\n----0-------0---\n-----0-0-----0--\n------0-0-0----2\n-------0---0-2-1\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 7; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test8) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 8, Population = 54.\n---1---1---1---0\n-----3--103----1\n----435--1-1--2-\n-----------1--31\n10-----1---1----\n-22-------------\n---2------------\n----------------\n---3---1-0-----1\n01-----0-1------\n-001--1--12-----\n---0--21-12-----\n---0--0---1-----\n------0---0---00\n--------------13\n---------------2\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 8; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test9) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 9, Population = 100.\n--4-001--0--0-01\n---0-4--2140---2\n---25462-2020130\n11--1011-02-00-2\n2-----4-0-321-10\n--3----0---0----\n-0--1-----------\n-------0-0-----3\n011-0-12-13---1-\n1------1-------0\n----002012-4----\n-0--0032--31----\n--0100-----1--12\n---0-010-010-0--\n------0---0--1-4\n---------------3\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 9; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test10) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 10, Population = 115.\n-2-11121-1----1-\n---1--3-3-5-100-\n350-6-7-23-312-1\n-20--1--0-3-1---\n3-4-2-5--0-3-12-\n1--20------1--32\n0--2-0---0-0---3\n1-0----1-1------\n--2---23--40-3-1\n2-0--01---30----\n00-1-13--3250--1\n0---1-4---420-00\n--12110--01-0-23\n---10-21-12--1--\n---0--1---1-02-5\n------0---0--204\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 10; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test11) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 11, Population = 128.\n0-----320---0-21\n5--22--04--0-1--\n46-2-48-34-4--3-\n1-101-111---2032\n405731-1--3412--\n-2----3---3-1---\n-0-31-1201-11--4\n2-1--0-2-2---0--\n-1-3----0-------\n311-0-2---41-2--\n110-0-4014---4-2\n1-002--2-1531--1\n0023--1-0-2110--\n---2-032--3002--\n--01-0------1316\n---0-010-010----\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 11; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test12) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 12, Population = 128.\n12-11143-1---032\n--3-3-3-5-511-02\n570--5--45-5-24-\n-------2--31-143\n-16842-2-0-----0\n------400-4----2\n-14420-3--22--3-\n---2--13-311--13\n02---02---40----\n---01-3---52-300\n2211---1--2--5-3\n--11-043--64-102\n--34--2--03---23\n000---43-1-1-3-0\n-012--1--0-0-4-7\n---1---1-1-1-204\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 12; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test13) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 13, Population = 132.\n23422-540--1-14-\n-0424-406-622-1-\n6--2-----6--1-51\n1--01-13-04---5-\n42---35-0-34-2--\n-----05-105----3\n02-5-1----3-1044\n2--3-0---4-210-4\n132--13---5123--\n----204--16-----\n3-22-14214-50---\n1-22-15-0-75--13\n0-4-1--00--1-0-4\n1112-054--32-40-\n--2-00200-----1-\n-0-20----2-2----\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 13; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test14) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 14, Population = 117.\n3453---5-1-202-2\n5-5----1-173-1--\n7---6----70-2-62\n--1-21-41---2-6-\n-368--621-45---0\n---201----6-1--4\n-3-6----0142-1-5\n-0-4----0----115\n--3--2-3-1-23-11\n-1--3-5----2-3--\n4---02--2---1503\n--3-2----186--2-\n-0---12--03--1-5\n---3--65014-----\n003--1311-1---27\n0-03--11----0-0-\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 14; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}

TEST(LifeFredkinFixture, test15) {
    Life<FredkinCell, 16, 16> x;
    string board = "\nGeneration = 15, Population = 131.\n--642-56-23-----\n-06-4-42-28--2--\n87-27------532-3\n1-20-21-----3-73\n447-4373---61--1\n---3-2-0------3-\n04---1-3--53124-\n211500--141---26\n-3----3-0---4---\n---04---0163-40-\n--2213-2--252614\n1---315---97-133\n0--4-2---14-1-2-\n1---00761252-40-\n---202---02014-8\n10-40-----12--1-\n\n";

    stringstream ss;
    auto old_buf = cout.rdbuf(ss.rdbuf());

    x.makeAlive(8, 7);
    x.makeAlive(2, 2);
    x.makeAlive(2, 3);
    x.makeAlive(1, 0);
    x.makeAlive(10, 15);
    x.makeAlive(11, 15);
    x.makeAlive(11, 14);
    x.makeAlive(5, 6);
    x.makeAlive(4, 6);
    x.makeAlive(4, 3);

    x.makeAlive(2, 7);
    x.makeAlive(2, 1);
    x.makeAlive(3, 3);
    x.makeAlive(1, 1);
    x.makeAlive(8, 15);
    x.makeAlive(9, 15);
    x.makeAlive(10, 14);
    x.makeAlive(5, 10);
    x.makeAlive(4, 10);
    x.makeAlive(0, 3);

    for (int i = 0; i < 15; ++i) {
    	x.nextGeneration();
    }

    cout << x;

    cout.rdbuf(old_buf);

    ASSERT_EQ(board, ss.str());
}


