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

// // ------------
// // Conway tests
// // ------------

TEST(LifeFixture, test_1) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "1 1\n.";
	l.lifeSetup(input);
    cout.rdbuf(old_buf);
    ASSERT_TRUE(output.str().compare(
    	"\nGeneration = 0, Population = 0.\n.\n") == 0);
}

TEST(LifeFixture, test_2) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "10 10\n..........\n..........\n..........\n..........\n"
			"..........\n..........\n..........\n..........\n..........\n"
			"..........\n";
	l.lifeSetup(input);
    cout.rdbuf(old_buf);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population ="
   		" 0.\n..........\n..........\n..........\n..........\n..........\n"
   		"..........\n..........\n..........\n..........\n..........\n") == 0);
}

TEST(LifeFixture, test_3) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "1 1\n.";
	l.lifeSetup(input);
	l.runTurn();
	l.printGrid();
    cout.rdbuf(old_buf);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 0.\n.\n"
    	"\nGeneration = 1, Population = 0.\n.\n") == 0);
}

TEST(LifeFixture, test_4) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "1 1\n*";
	l.lifeSetup(input);

	for(int i = 0; i < 2; i++) {
		l.runTurn();
		l.printGrid();
	}

    cout.rdbuf(old_buf);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 1.\n*\n"
    	"\nGeneration = 1, Population = 0.\n.\n"
    	"\nGeneration = 2, Population = 0.\n.\n") == 0);
}

/****************
 *Life::life_read
 ****************/
TEST(LifeFixture, test_5) {

	Life<ConwayCell> l;

	istringstream input("1 1\n*");
	string line = "";

    ASSERT_TRUE(l.life_read(input, line));
}

TEST(LifeFixture, test_6) {

	Life<ConwayCell> l;

	istringstream input("1");
	string line = "";

    ASSERT_TRUE(l.life_read(input, line));
}

TEST(LifeFixture, test_7) {

	Life<ConwayCell> l;

	istringstream input("alpha");
	string line = "";

    ASSERT_TRUE(l.life_read(input, line));
}

TEST(LifeFixture, test_8) {

	Life<ConwayCell> l;

	istringstream input("");
	string line = "";

    ASSERT_FALSE(l.life_read(input, line));
}

/************************
 *Life::collectNeighboors
 ************************/

TEST(LifeFixture, test_9) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[0].printCell();

	cout.rdbuf(old_buf);

    
    ASSERT_TRUE(output.str().compare("*") == 0);

}

TEST(LifeFixture, test_10) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[1].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare(".") == 0);

}

TEST(LifeFixture, test_11) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[2].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare("*") == 0);

}

TEST(LifeFixture, test_12) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[3].printCell();

	cout.rdbuf(old_buf);

    
    ASSERT_TRUE(output.str().compare(".") == 0);

}

TEST(LifeFixture, test_13) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[4].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare(".") == 0);

}

TEST(LifeFixture, test_14) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[5].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare("*") == 0);

}

TEST(LifeFixture, test_15) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[6].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare(".") == 0);

}

TEST(LifeFixture, test_16) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[7].printCell();

	cout.rdbuf(old_buf);

    
    ASSERT_TRUE(output.str().compare("*") == 0);

}

TEST(LifeFixture, test_17) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[4].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare(".") == 0);

}

TEST(LifeFixture, test_18) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(0, 0);

	neighboors[6].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare(".") == 0);

}

TEST(LifeFixture, test_19) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(0, 0);

	neighboors[7].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare("*") == 0);

}

TEST(LifeFixture, test_20) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[3].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare("*") == 0);

}
TEST(LifeFixture, test_21) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[4].printCell();

	cout.rdbuf(old_buf);

    
    ASSERT_TRUE(output.str().compare("*") == 0);

}

TEST(LifeFixture, test_22) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[5].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare(".") == 0);

}

TEST(LifeFixture, test_23) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[6].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare("*") == 0);

}

TEST(LifeFixture, test_24) {

	Life<ConwayCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
	l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[7].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare(".") == 0);

}

TEST(LifeFixture, test_25) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
    l.populateObjGrid();

	int turn = l.runTurn();

    ASSERT_TRUE(turn == 1);
}

TEST(LifeFixture, test_26) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
    l.populateObjGrid();

	int turn = 0;

	while (turn != 5)
		turn = l.runTurn();

    ASSERT_TRUE(turn == 5);
}

TEST(LifeFixture, test_27) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
    l.populateObjGrid();

	int turn = 0;

	while (turn != 10)
		turn = l.runTurn();

    ASSERT_TRUE(turn == 10);
}

TEST(LifeFixture, test_28) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
    l.populateObjGrid();

	int turn = 0;

	while (turn != 100)
		turn = l.runTurn();

    ASSERT_TRUE(turn == 100);
}

TEST(LifeFixture, test_29) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
    l.populateObjGrid();

    vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);
    vector<ConwayCell> neighboorsT = l.collectNeighboors(0, 0);

	int count = neighboorsT[7].countLivingNeighboors (neighboors);

    ASSERT_TRUE(count == 4);
}

TEST(LifeFixture, test_30) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
    l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(0, 0);
    vector<ConwayCell> neighboorsT = l.collectNeighboors(1, 1);

	int count = neighboorsT[0].countLivingNeighboors (neighboors);

    ASSERT_TRUE(count == 1);
}

TEST(LifeFixture, test_31) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
    l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(1, 0);
	vector<ConwayCell> neighboorsT = l.collectNeighboors(1, 1);

	int count = neighboorsT[3].countLivingNeighboors (neighboors);

    ASSERT_TRUE(count == 3);
}

TEST(LifeFixture, test_32) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";
	l.readInput(input);
    l.populateObjGrid();

	vector<ConwayCell> neighboors = l.collectNeighboors(0, 1);
	vector<ConwayCell> neighboorsT = l.collectNeighboors(1, 1);

	int count = neighboorsT[1].countLivingNeighboors (neighboors);

    ASSERT_TRUE(count == 3);
}

TEST(LifeFixture, test_33) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[0].killCell();

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_34) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[1].killCell();

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_35) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[2].killCell();

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_36) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[3].killCell();

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_37) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[4].killCell();

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_38) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[5].killCell();

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_39) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[6].killCell();

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_40) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[7].killCell();

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_41) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[0].breathLife('-');

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_42) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[1].breathLife('*');

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_43) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[2].breathLife('-');

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_44) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[3].breathLife('*');

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_45) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[4].breathLife('*');

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_46) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[5].breathLife('-');

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_47) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[6].breathLife('*');

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

TEST(LifeFixture, test_48) {

	Life<ConwayCell> l;

	stringstream input;
	input << "3 3\n*.*"
				"\n.*."
				"\n*.*";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<ConwayCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[7].breathLife('-');

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5.\n*.*"
				"\n.*.\n*.*\n") == 0);
}

// -------------
// Fredkin tests
// -------------

TEST(LifeFixture, test_49) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "1 1\n.";
	l.lifeSetup(input);
    cout.rdbuf(old_buf);

    ASSERT_TRUE(output.str().compare(
    	"\nGeneration = 0, Population = 0.\n-\n") == 0);
}

TEST(LifeFixture, test_50) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "10 10\n----------\n----------\n----------\n----------\n"
			"----------\n----------\n----------\n----------\n----------\n"
			"----------\n";
	l.lifeSetup(input);
    cout.rdbuf(old_buf);

    ASSERT_TRUE(output.str().compare(
    	"\nGeneration = 0, Population = 0.\n----------\n"
    	"----------\n----------\n----------\n----------\n"
    	"----------\n----------\n----------\n----------\n----------\n") == 0);
}

TEST(LifeFixture, test_51) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "1 1\n.";
	l.lifeSetup(input);
	l.runTurn();
	l.printGrid();
    cout.rdbuf(old_buf);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 0.\n-\n"
    	"\nGeneration = 1, Population = 0.\n-\n") == 0);
}

TEST(LifeFixture, test_52) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "1 1\n0";
	l.lifeSetup(input);

	for(int i = 0; i < 2; i++) {
		l.runTurn();
		l.printGrid();
	}

    cout.rdbuf(old_buf);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 1.\n0\n"
    	"\nGeneration = 1, Population = 0.\n-\n"
    	"\nGeneration = 2, Population = 0.\n-\n") == 0);
}

/****************
 *Life::life_read
 ****************/
TEST(LifeFixture, test_53) {

	Life<FredkinCell> l;

	istringstream input("1 1\n0");
	string line = "";

    ASSERT_TRUE(l.life_read(input, line));
}

TEST(LifeFixture, test_54) {

	Life<FredkinCell> l;

	istringstream input("1");
	string line = "";

    ASSERT_TRUE(l.life_read(input, line));
}

TEST(LifeFixture, test_55) {

	Life<FredkinCell> l;

	istringstream input("alpha");
	string line = "";

    ASSERT_TRUE(l.life_read(input, line));
}

TEST(LifeFixture, test_56) {

	Life<FredkinCell> l;

	istringstream input("");
	string line = "";

    ASSERT_FALSE(l.life_read(input, line));
}

/************************
 *Life::collectNeighboors
 ************************/

TEST(LifeFixture, test_57) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[0].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare("0") == 0);

}

TEST(LifeFixture, test_58) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[1].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare("-") == 0);

}

TEST(LifeFixture, test_59) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[2].printCell();

	cout.rdbuf(old_buf);

    
    ASSERT_TRUE(output.str().compare("0") == 0);

}

TEST(LifeFixture, test_60) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[3].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare("-") == 0);

}

TEST(LifeFixture, test_61) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[4].printCell();

	cout.rdbuf(old_buf);


    ASSERT_TRUE(output.str().compare("-") == 0);

}

TEST(LifeFixture, test_62) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[5].printCell();

	cout.rdbuf(old_buf);

    
    ASSERT_TRUE(output.str().compare("0") == 0);

}

TEST(LifeFixture, test_63) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[6].printCell();

	cout.rdbuf(old_buf);

   

    ASSERT_TRUE(output.str().compare("-") == 0);

}

TEST(LifeFixture, test_64) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[7].printCell();

	cout.rdbuf(old_buf);


    ASSERT_TRUE(output.str().compare("0") == 0);

}

TEST(LifeFixture, test_65) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	neighboors[4].printCell();

	cout.rdbuf(old_buf);

    

    ASSERT_TRUE(output.str().compare("-") == 0);

}

TEST(LifeFixture, test_66) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(0, 0);

	neighboors[6].printCell();

	cout.rdbuf(old_buf);


    ASSERT_TRUE(output.str().compare("-") == 0);

}

TEST(LifeFixture, test_67) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(0, 0);

	neighboors[7].printCell();

	cout.rdbuf(old_buf);


    ASSERT_TRUE(output.str().compare("0") == 0);

}

TEST(LifeFixture, test_68) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[3].printCell();

	cout.rdbuf(old_buf);


    ASSERT_TRUE(output.str().compare("0") == 0);

}
TEST(LifeFixture, test_69) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[4].printCell();

	cout.rdbuf(old_buf);

    ASSERT_TRUE(output.str().compare("0") == 0);

}

TEST(LifeFixture, test_70) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[5].printCell();

	cout.rdbuf(old_buf);


    ASSERT_TRUE(output.str().compare("-") == 0);

}

TEST(LifeFixture, test_71) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[6].printCell();

	cout.rdbuf(old_buf);

    ASSERT_TRUE(output.str().compare("0") == 0);

}

TEST(LifeFixture, test_72) {

	Life<FredkinCell> l;

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
	l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(0, 1);

	neighboors[7].printCell();

	cout.rdbuf(old_buf);


    ASSERT_TRUE(output.str().compare("-") == 0);

}

TEST(LifeFixture, test_73) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
    l.populateObjGrid();

	int turn = l.runTurn();

    ASSERT_TRUE(turn == 1);
}

TEST(LifeFixture, test_74) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
    l.populateObjGrid();

	int turn = 0;

	while (turn != 5)
		turn = l.runTurn();

    ASSERT_TRUE(turn == 5);
}

TEST(LifeFixture, test_75) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
    l.populateObjGrid();

	int turn = 0;

	while (turn != 10)
		turn = l.runTurn();

    ASSERT_TRUE(turn == 10);
}

TEST(LifeFixture, test_76) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
    l.populateObjGrid();

	int turn = 0;

	while (turn != 100)
		turn = l.runTurn();

    ASSERT_TRUE(turn == 100);
}

TEST(LifeFixture, test_77) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
    l.populateObjGrid();

    vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);
    vector<FredkinCell> neighboorsT = l.collectNeighboors(0, 0);

	int count = neighboorsT[7].countLivingNeighboors (neighboors);

    ASSERT_TRUE(count == 0);
}

TEST(LifeFixture, test_78) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
    l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(0, 0);
    vector<FredkinCell> neighboorsT = l.collectNeighboors(1, 1);

	int count = neighboorsT[0].countLivingNeighboors (neighboors);

    ASSERT_TRUE(count == 0);
}

TEST(LifeFixture, test_79) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
    l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(1, 0);
	vector<FredkinCell> neighboorsT = l.collectNeighboors(1, 1);

	int count = neighboorsT[3].countLivingNeighboors (neighboors);

    ASSERT_TRUE(count == 3);
}

TEST(LifeFixture, test_80) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";
	l.readInput(input);
    l.populateObjGrid();

	vector<FredkinCell> neighboors = l.collectNeighboors(0, 1);
	vector<FredkinCell> neighboorsT = l.collectNeighboors(1, 1);

	int count = neighboorsT[1].countLivingNeighboors (neighboors);

    ASSERT_TRUE(count == 3);
}

TEST(LifeFixture, test_81) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[0].killCell();

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_82) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[1].killCell();

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_83) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[2].killCell();

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_84) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[3].killCell();

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_85) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[4].killCell();

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_86) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[5].killCell();

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_87) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[6].killCell();

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_88) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[7].killCell();

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_89) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[0].breathLife('-');

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_90) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[1].breathLife('0');

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_91) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[2].breathLife('-');

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_92) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[3].breathLife('0');

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_93) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[4].breathLife('0');

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_94) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[5].breathLife('-');

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_95) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[6].breathLife('0');

    cout.rdbuf(old_buf);

    ASSERT_TRUE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

TEST(LifeFixture, test_96) {

	Life<FredkinCell> l;

	stringstream input;
	input << "3 3\n0-0"
				"\n-0-"
				"\n0-0";

	stringstream output;
    auto old_buf = cout.rdbuf(output.rdbuf());
	l.lifeSetup(input);
	vector<FredkinCell> neighboors = l.collectNeighboors(1, 1);

	bool result = neighboors[7].breathLife('-');

    cout.rdbuf(old_buf);

    ASSERT_FALSE(result);
    ASSERT_TRUE(output.str().compare("\nGeneration = 0, Population = 5."
    			"\n0-0"
				"\n-0-"
				"\n0-0\n") == 0);
}

//-----
// Cell
//-----

TEST(LifeFixture, test_97) {

  Life<Cell> l;

  stringstream input;
  input << "3 3\n0-0"
           "\n-0-"
           "\n0-0";
  l.readInput(input);
  l.populateObjGrid();

  vector<Cell> neighboors = l.collectNeighboors(1, 1);
  vector<Cell> neighboorsT = l.collectNeighboors(0, 0);

  int count = neighboorsT[7].countLivingNeighboors(neighboors);

  ASSERT_TRUE(count == 0);
}

TEST(LifeFixture, test_98) {

  Life<Cell> l;

  stringstream input;
  input << "3 3\n0-0"
           "\n-0-"
           "\n0-0";
  l.readInput(input);
  l.populateObjGrid();

  vector<Cell> neighboors = l.collectNeighboors(0, 0);
  vector<Cell> neighboorsT = l.collectNeighboors(1, 1);

  int count = neighboorsT[0].countLivingNeighboors(neighboors);

  ASSERT_TRUE(count == 0);
}

TEST(LifeFixture, test_99) {

  Life<Cell> l;

  stringstream input;
  input << "3 3\n0-0"
           "\n-0-"
           "\n0-0";
  l.readInput(input);
  l.populateObjGrid();

  vector<Cell> neighboors = l.collectNeighboors(1, 0);
  vector<Cell> neighboorsT = l.collectNeighboors(1, 1);

  int count = neighboorsT[3].countLivingNeighboors(neighboors);

  ASSERT_TRUE(count == 3);
}

TEST(LifeFixture, test_100) {

  Life<Cell> l;

  stringstream input;
  input << "3 3\n0-0"
           "\n-0-"
           "\n0-0";
  l.readInput(input);
  l.populateObjGrid();

  vector<Cell> neighboors = l.collectNeighboors(0, 1);
  vector<Cell> neighboorsT = l.collectNeighboors(1, 1);

  int count = neighboorsT[1].countLivingNeighboors(neighboors);

  ASSERT_TRUE(count == 3);
}

TEST(LifeFixture, test_101) {

  Life<Cell> l;

  stringstream output;
  auto old_buf = cout.rdbuf(output.rdbuf());
  stringstream input;
  input << "1 1\n.";
  l.lifeSetup(input);
  cout.rdbuf(old_buf);
  ASSERT_TRUE(output.str().compare(
  	"\nGeneration = 0, Population = 0.\n-\n") == 0);
}

TEST(LifeFixture, test_102) {

  Life<Cell> l;

  stringstream output;
  auto old_buf = cout.rdbuf(output.rdbuf());
  stringstream input;
  input << "10 10\n----------\n----------\n----------\n----------\n"
           "----------\n----------\n----------\n"
           "----------\n----------\n----------\n";
  l.lifeSetup(input);
  cout.rdbuf(old_buf);
  ASSERT_TRUE(
      output.str().compare("\nGeneration = 0, Population = 0."
      	"\n----------\n----------\n----------\n----------\n----------\n"
      	"----------\n----------\n----------\n----------\n----------\n") == 0);
}

TEST(LifeFixture, test_103) {

  Life<Cell> l;

  stringstream output;
  auto old_buf = cout.rdbuf(output.rdbuf());
  stringstream input;
  input << "1 1\n-";
  l.lifeSetup(input);
  l.runTurn();
  l.printGrid();
  cout.rdbuf(old_buf);
  ASSERT_TRUE(output.str().compare(
  	"\nGeneration = 0, Population = 0.\n-\n"
    "\nGeneration = 1, Population = 0.\n-\n") == 0);
}

TEST(LifeFixture, test_104) {

  Life<Cell> l;

  stringstream output;
  auto old_buf = cout.rdbuf(output.rdbuf());
  stringstream input;
  input << "1 1\n0";
  l.lifeSetup(input);

  for (int i = 0; i < 2; i++) {
    l.runTurn();
    l.printGrid();
  }

  cout.rdbuf(old_buf);
  ASSERT_TRUE(output.str().compare(
  	"\nGeneration = 0, Population = 1.\n0\n"
	"\nGeneration = 1, Population = 0.\n-\n"
	"\nGeneration = 2, Population = 0.\n-\n") == 0);
}