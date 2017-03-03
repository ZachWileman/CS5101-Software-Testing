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

// Check Move
// Function: This function checks to see if the user input a valid move
// Returns: bool value that returns True if the user input a valid move
bool Board::checkMove(char input1, char input2) {
	bool input1_valid = false;
	bool input2_valid = false;
	Peg peg1, peg2, tempPeg;
	int layerDiff, col_diff, row_diff;

	if (input2 == SPACE) {
		input2_valid = true;

		for (int i = 0; i < m_numBoardPositions; i++) {
			if (input1 == boardPositions[i])
				input1_valid = true;
		}
	}

	else {
		// Checks if input1 and input2 are valid characters
		for (int i = 0; i < m_numBoardPositions; i++) {
			if (input1 == boardPositions[i])
				input1_valid = true;
			if (input2 == boardPositions[i])
				input2_valid = true;
		}

		if (input1_valid && input2_valid) {
			// Reset for more testing
			input1_valid = false;
			input2_valid = false;

			// Grabs peg objects
			for (int i = 0; i < m_row; i++) {
				for (int j = 0; j < m_col; j++) {
					if (input1 == board[i][j].getPeg())
						peg1 = board[i][j];
					else if (input2 == board[i][j].getPeg())
						peg2 = board[i][j];
				}
			}

			// Check if the pegs are in the same layer or in adjacent layers
			layerDiff = abs(peg1.getLayer() - peg2.getLayer());

			switch (layerDiff) {
			case 0:
				col_diff = peg1.getCol() - peg2.getCol();

				if (abs(col_diff) == 2) {
					if (col_diff == -2) {
						tempPeg = board[peg2.getRow()][peg2.getCol() + 2];
						if (tempPeg.getPeg() == SPACE && tempPeg.isValid()) {
							input1_valid = true;
							input2_valid = true;
						}
					} else {
						tempPeg = board[peg2.getRow()][peg2.getCol() - 2];
						if (tempPeg.getPeg() == SPACE && tempPeg.isValid()) {
							input1_valid = true;
							input2_valid = true;
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
							tempPeg =
									board[peg2.getRow() - 1][peg2.getCol() - 1];
							if (tempPeg.getPeg() == SPACE
									&& tempPeg.isValid()) {
								input1_valid = true;
								input2_valid = true;
							}
						} else {
							tempPeg =
									board[peg2.getRow() - 1][peg2.getCol() + 1];
							if (tempPeg.getPeg() == SPACE
									&& tempPeg.isValid()) {
								input1_valid = true;
								input2_valid = true;
							}
						}
					} else {
						if (col_diff == 1) {
							tempPeg =
									board[peg2.getRow() + 1][peg2.getCol() - 1];
							if (tempPeg.getPeg() == SPACE
									&& tempPeg.isValid()) {
								input1_valid = true;
								input2_valid = true;
							}
						} else {
							tempPeg =
									board[peg2.getRow() + 1][peg2.getCol() + 1];
							if (tempPeg.getPeg() == SPACE
									&& tempPeg.isValid()) {
								input1_valid = true;
								input2_valid = true;
							}
						}
					}
				}

				break;

			default:
				break;
			}
		}
	}

	if (input1_valid && input2_valid)
		return true;
	else
		return false;

}

// Returns: the remaining pegs inside the calling object's Board
vector<Peg> Board::remainingPegs() {
	vector<Peg> currentPegs;

	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			if (board[i][j].getPeg() != SPACE && board[i][j].isValid())
				currentPegs.push_back(board[i][j]);
		}
	}

	return currentPegs;
}

// Check Board
// Function: This function tests to see if any moves are still available to the user
// Returns: bool value representing whether or not there are still moves to make on the board
//			true: there are moves left
//			false: there are no moves left
bool Board::checkBoard() {
	vector<Peg> currentPegs = remainingPegs();

	for (int i = 0; i < currentPegs.size(); i++) {
		for (int j = (i + 1); j < currentPegs.size(); j++) {
			if (checkMove(currentPegs[i].getPeg(), currentPegs[j].getPeg()))
				return true;
			else if (checkMove(currentPegs[j].getPeg(),
					currentPegs[i].getPeg()))
				return true;
		}
	}

	return false;
}

// Check Win
// Function: Checks if the user has won the game
bool Board::checkWin() {
	int counter = 0;

	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			for (int k = 0; k < m_numBoardPositions; k++) {
				if (board[i][j].getPeg() == boardPositions[k])
					counter++;
			}
		}
	}

	if (counter > 1)
		return false;
	else
		return true;
}
