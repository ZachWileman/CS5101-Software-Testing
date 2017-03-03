//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#ifndef PegJumpView_h
#define PegJumpView_h

#include <iostream>
#include <cstdlib>
using namespace std;

class PegJumpView {
public:
	// Null constructor
	PegJumpView() {}

	void printStart();

	void gameSelect();

	void invalidChoice();

	void playAgain();

	void menu();

	void printScores(int numGames, const string gameNames[], int gameScore[]);

	void selectDifficulty();

};

#endif
