//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#ifndef PegJumpView_h
#define PegJumpView_h

#include <iostream>
using namespace std;

class PegJumpView {
public:
	// Null constructor
	PegJumpView() {}

	void printStart();

	void gameSelect();

	void printMenu(int gamescore[]);

	void invalidChoice();

	void playAgain();
};

#endif
