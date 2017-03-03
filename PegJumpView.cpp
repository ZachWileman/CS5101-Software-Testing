//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include "PegJumpView.h"

void PegJumpView::printStart(){
	cout << "If you wish to exit the game or display the current cumulative scores at any time during the game,\n" <<
			"Enter the number 9 to display a menu with these options." << endl << endl;
}

void PegJumpView::gameSelect(){
	cout << "Please select the game you would like to play" << endl;
	cout << "1.) Peg Jump" << endl;
}

void PegJumpView::invalidChoice(){
	cout << "Please enter a valid choice" << endl << endl;
}

void PegJumpView::playAgain(){
	cout << "Would you like to play another game (y=yes)?" << endl;
}
