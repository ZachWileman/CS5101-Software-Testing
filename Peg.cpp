//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include "Peg.h"

// Parameters:
//			  current_val: what the value of the current peg is
//			  layer: what layer the peg is located on
void Peg::assignValues(char current_val, int layer, int row, int col) {
	m_current_val = current_val;
	m_layer = layer;
	m_row = row;
	m_col = col;
}

//returns peg character
char Peg::getPeg() {
	return m_current_val;
}

//returns layer value i.e. row
char Peg::getLayer() {
	return m_layer;
}

//returns row value
int Peg::getRow() {
	return m_row;
}

//returns column value
int Peg::getCol() {
	return m_col;
}

// Updates peg to a new passed character
void Peg::updatePeg(char current_val) {
	m_current_val = current_val;
}

/*
// returns true/false
bool Peg::isValid() {
	return m_valid_location;
}

//sets peg as a valid location i.e. true
void Peg::setValidLocation() {
	m_valid_location = true;
}

// Changes the current value to a Space since the value has disappeared from the board.
void Peg::setToSpace() {
	m_current_val = ' ';
}
*/
