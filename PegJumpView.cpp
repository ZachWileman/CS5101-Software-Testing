//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include "PegJumpView.h"

void PegJumpView::printStart(){
	cout << endl << "If you wish to exit the game or display the current cumulative scores at any time during the game,\n" <<
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

void PegJumpView::menu(){
	cout << endl;
	cout << "Please enter the number corresponding to what you would like to do:" << endl;
	cout << "1.) Display cumulative game scores for each game" << endl;
	cout << "2.) Exit the program" << endl;
	cout << "3.) Return to what you were doing" << endl;
}

void PegJumpView::printScores(int numGames, string gameNames[], int gameScore[]){
	for(int i = 0; i < numGames; i++)
		cout << gameNames[i] << " Score: " << gameScore[i] << endl;
}
