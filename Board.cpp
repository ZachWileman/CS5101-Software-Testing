#include "Board.h"

int Board::getCol()
{
	return m_col;
}

int Board::getRow()
{
	return m_row;
}

int Board::getNumBoardPositions()
{
	return m_numBoardPositions;
}

bool Board::testLocation(int row, int col, char expectedVal)
{
	if(board[row][col].getPeg() == expectedVal)
		return true;
	else
		return false;
}

// Constructor: Sets up board
void Board::setupBoard(int difficulty) {
	// Set the row and col size based on difficulty
	switch (difficulty) {
	case 1:
		m_row = 6;
		m_col = 11;
		m_numBoardPositions = 10;
		break;
	case 2:
		m_row = 7;
		m_col = 13;
		m_numBoardPositions = 15;
		break;
	case 3:
		m_row = 8;
		m_col = 15;
		m_numBoardPositions = 21;
		break;
	}

	int leftCounter = m_row - 1;
	int rightCounter = m_row - 1;
	int pegCounter = m_row - 1;
	int pegSymbolCounter = 0;
	int secondaryPegCounter;

	for (int i = 0; i < (m_row - 1); i++) {
		board[i][leftCounter].assignValues(boardPerimeter, -1, i, leftCounter);
		board[i][rightCounter].assignValues(boardPerimeter, -1, i,
				rightCounter);

		if (i > 0) {
			secondaryPegCounter = pegCounter;

			for (int j = 0; j < i; j++) {
				board[i][secondaryPegCounter].assignValues(
						boardPositions[pegSymbolCounter], i, i,
						secondaryPegCounter);
				board[i][secondaryPegCounter].setValidLocation();
				secondaryPegCounter += 2;
				pegSymbolCounter++;
			}

			pegCounter--;
		}

		leftCounter--;
		rightCounter++;
	}

	for (int i = 0; i < m_col; i++)
		board[(m_row - 1)][i].assignValues(boardPerimeter, -1, (m_row - 1), i);
}
