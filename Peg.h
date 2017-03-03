//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#ifndef PEG_H
#define PEG_H

class Peg
{
private:
	char m_current_val;
	int m_layer;
	int m_row;
	int m_col;
	bool m_valid_location;
public:
	// In-line Constructor
	Peg(): m_current_val(' '), m_layer(-1), m_row(-1), m_col(-1), m_valid_location(false) {}

	void assignValues(char current_val, int layer, int row, int col);

	char getPeg();

	void updatePeg(char current_val);

	char getLayer();

	int getRow();

	int getCol();
/*
	bool isValid();

	void setValidLocation();

	void setToSpace();
*/
};
#endif
