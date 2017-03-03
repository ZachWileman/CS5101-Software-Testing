#ifndef BOARD_H
#define BOARD_H

#include "Peg.h"

const char boardPerimeter = '*';
const char boardPositions[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};

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

	// Constructor: Sets up board
	void setupBoard (int difficulty);

};

#endif
