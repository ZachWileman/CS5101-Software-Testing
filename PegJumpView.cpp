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

void PegJumpView::printScores(int numGames, const string gameNames[], int gameScore[]){
	for(int i = 0; i < numGames; i++)
		cout << gameNames[i] << " Score: " << gameScore[i] << endl;
}

void PegJumpView::selectDifficulty(){
	cout << endl <<"Please enter a difficulty level (select the number)" << endl;
	cout << "1.) Easy" << endl;
	cout << "2.) Medium" << endl;
	cout << "3.) Hard" << endl;
}

void PegJumpView::firstPeg(){
	cout << "Please enter the fist peg to remove on the board by entering a letter corresponding to the peg board." << endl;
}

void PegJumpView::twoPeg(){
	cout << "Please enter the first and second peg separated by space (ex. \"A B\") where the first character is the peg \n"
		 <<	"you want to move and the second character is the position of the peg you wish to jump over. If at any point,\n"
		 <<	"you would like to automatically solve your game, enter the number 8" << endl;
}

void PegJumpView::solutionFound(vector<char> &solutionList){
	cout << endl << "The following moves, in order, are the solution to the current Peg Board." << endl << endl;
	for(int i = 0; i < solutionList.size(); i+=2)
		cout << solutionList[i] << " " << solutionList[i+1] << endl;
}

void PegJumpView::noSolution(){
	cout << endl << "No solution found" << endl;
}

void PegJumpView::win(){
	cout << "You win!" << endl << endl;
}

void PegJumpView::lose(){
	cout << "You lose!" << endl << endl;
}

void PegJumpView::cumScore(int gameScore[], int gameSelected){
	cout << "Cumulative score: " << gameScore[gameSelected-1] << endl;
}
