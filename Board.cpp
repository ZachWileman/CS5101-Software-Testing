#include "Board.h"

using namespace std;

int Board::getCol() {
	return m_col;
}

int Board::getRow() {
	return m_row;
}

int Board::getNumBoardPositions() {
	return m_numBoardPositions;
}

bool Board::testLocation(int row, int col, char expectedVal) {
	if (board[row][col].getPeg() == expectedVal)
		return true;
	else
		return false;
}

void Board::clearBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 15; j++) {
			board[i][j].updatePeg(SPACE);
			board[i][j].setInvalidLocation();
		}
	}
}

// Sets up board dependent on difficulty level
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

// Update Function
// Function: This function updates the board after the user makes a move
void Board::updateBoard(char input1, char input2) {
	Peg peg1, peg2, tempPeg;
	int layerDiff, col_diff, row_diff;

	// Used for when the user removes the first peg
	if (input2 == SPACE) {
		for (int i = 0; i < m_row; i++) {
			for (int j = 0; j < m_col; j++) {
				if (board[i][j].getPeg() == input1)
					board[i][j].setToSpace();
			}
		}
	}

	else {
		for (int i = 0; i < m_row; i++) {
			for (int j = 0; j < m_col; j++) {
				if (board[i][j].getPeg() == input1)
					peg1 = board[i][j];
				if (board[i][j].getPeg() == input2)
					peg2 = board[i][j];
			}
		}

		layerDiff = abs(peg1.getLayer() - peg2.getLayer());

		switch (layerDiff) {
		case 0:
			col_diff = peg1.getCol() - peg2.getCol();

			if (abs(col_diff) == 2) {
				if (col_diff == -2) {
					if (board[peg2.getRow()][peg2.getCol() + 2].getPeg()
							== SPACE) {
						board[peg2.getRow()][peg2.getCol() + 2].updatePeg(
								peg1.getPeg());
						board[peg1.getRow()][peg1.getCol()].setToSpace();
						board[peg2.getRow()][peg2.getCol()].setToSpace();
					}
				} else {
					if (board[peg2.getRow()][peg2.getCol() - 2].getPeg()
							== SPACE) {
						board[peg2.getRow()][peg2.getCol() - 2].updatePeg(
								peg1.getPeg());
						board[peg1.getRow()][peg1.getCol()].setToSpace();
						board[peg2.getRow()][peg2.getCol()].setToSpace();
					}
				}
			}
			break;

		case 1:
			col_diff = peg1.getCol() - peg2.getCol();
			row_diff = peg1.getRow() - peg2.getRow();

			if (abs(row_diff) == 1 && abs(col_diff) == 1) {
				if (row_diff == 1) {
					if (col_diff == 1) {
						board[peg2.getRow() - 1][peg2.getCol() - 1].updatePeg(
								peg1.getPeg());
						board[peg1.getRow()][peg1.getCol()].setToSpace();
						board[peg2.getRow()][peg2.getCol()].setToSpace();
					} else {
						board[peg2.getRow() - 1][peg2.getCol() + 1].updatePeg(
								peg1.getPeg());
						board[peg1.getRow()][peg1.getCol()].setToSpace();
						board[peg2.getRow()][peg2.getCol()].setToSpace();
					}
				} else {
					if (col_diff == 1) {
						board[peg2.getRow() + 1][peg2.getCol() - 1].updatePeg(
								peg1.getPeg());
						board[peg1.getRow()][peg1.getCol()].setToSpace();
						board[peg2.getRow()][peg2.getCol()].setToSpace();
					} else {
						board[peg2.getRow() + 1][peg2.getCol() + 1].updatePeg(
								peg1.getPeg());
						board[peg1.getRow()][peg1.getCol()].setToSpace();
						board[peg2.getRow()][peg2.getCol()].setToSpace();
					}
				}
				break;

				default:
				break;
			}
		}
	}
}
