//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#ifndef Peg_h
#define Peg_h

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

	void updatePeg(char current_val);

	bool isValid();

	void setValidLocation();

	void setToSpace();

	char getPeg();

	char getLayer();

	int getRow();

	int getCol();
};
#endif
