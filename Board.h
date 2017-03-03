#ifndef BOARD_H
#define BOARD_H

#include "Peg.h"
#include <cmath>

const char boardPerimeter = '*';
const char boardPositions[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};
const char SPACE = ' ';

class Board
{
private:
	Peg board[8][15]; //Creates the max board size possible
	int m_row;
	int m_col;
	int m_numBoardPositions;
public:
	// Default constructor
	Board(): m_row(-1), m_col(-1), m_numBoardPositions(-1) {}

	int getCol();

	int getRow();

	int getNumBoardPositions();

	bool testLocation(int row, int col, char expectedVal);

	// Sets up board dependent on difficulty level
	void setupBoard (int difficulty);

	// Update Function
	// Function: This function updates the board after the user makes a move
	void updateBoard(char input1, char input2);

	// Check Move
	// Function: This function checks to see if the user input a valid move
	// Returns: bool value that returns True if the user input a valid move
	bool checkMove(char input1, char input2);

	// Clears the current board
	void clearBoard();

};

#endif
