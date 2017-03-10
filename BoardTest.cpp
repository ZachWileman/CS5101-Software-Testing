//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "Peg.h"
#include "Board.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class BoardTest: public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE (BoardTest);
	CPPUNIT_TEST (testGetRow);
	CPPUNIT_TEST (testGetCol);
	CPPUNIT_TEST (testGetNumBoardPositions);
	CPPUNIT_TEST (testSetupBoard);
	CPPUNIT_TEST (testUpdateBoard);
	CPPUNIT_TEST (testCheckMove);
	CPPUNIT_TEST (testClearBoard);
	CPPUNIT_TEST (testRemainingPegs);
	CPPUNIT_TEST (testCheckBoard);
	CPPUNIT_TEST (testCheckWin);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(void);
	void tearDown(void);

protected:
	void testGetRow(void);
	void testGetCol(void);
	void testGetNumBoardPositions(void);
	void testSetupBoard(void);
	void testUpdateBoard(void);
	void testCheckMove(void);
	void testClearBoard(void);
	void testRemainingPegs(void);
	void testCheckBoard(void);
	void testCheckWin(void);

private:
	Board *mTestObj;
};

//-----------------------------------------------------------------------------

void BoardTest::testGetRow(void) {
	Board testBoard;
	CPPUNIT_ASSERT(testBoard.getRow() == -1);
}

void BoardTest::testGetCol(void) {
	Board testBoard;
	CPPUNIT_ASSERT(testBoard.getCol() == -1);
}

void BoardTest::testGetNumBoardPositions(void) {
	Board testBoard;
	CPPUNIT_ASSERT(testBoard.getNumBoardPositions() == -1);
}

void BoardTest::testSetupBoard(void) {
	Board testBoard;
	testBoard.setupBoard(2);
	CPPUNIT_ASSERT(testBoard.getCol() == 13);
	CPPUNIT_ASSERT(testBoard.getRow() == 7);
	CPPUNIT_ASSERT(testBoard.getNumBoardPositions() == 15);
	CPPUNIT_ASSERT(testBoard.testLocation(0, 6, '*') == true);
}

void BoardTest::testUpdateBoard(void) {
	Board testBoard;
	testBoard.updateBoard('A', SPACE);
	CPPUNIT_ASSERT(testBoard.testLocation(1, 6, SPACE) == true);
}

void BoardTest::testCheckMove(void) {
	Board testBoard;
	testBoard.setupBoard(1);
	CPPUNIT_ASSERT(testBoard.checkMove('B', 'C') == false);
	CPPUNIT_ASSERT(testBoard.checkMove('B', 'A') == false);
	CPPUNIT_ASSERT(testBoard.checkMove('D', 'B') == false);
	CPPUNIT_ASSERT(testBoard.checkMove('H', 'G') == false);
	CPPUNIT_ASSERT(testBoard.checkMove('E', 'D') == false);
	CPPUNIT_ASSERT(testBoard.checkMove('E', 'F') == false);
	CPPUNIT_ASSERT(testBoard.checkMove('I', 'J') == false);
	testBoard.updateBoard('A', SPACE);
	CPPUNIT_ASSERT(testBoard.checkMove('D', 'B') == true);
	CPPUNIT_ASSERT(testBoard.checkMove('F', 'C') == true);
}

void BoardTest::testClearBoard(void){
	Board testBoard;
	testBoard.setupBoard(1);
	testBoard.clearBoard();

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 15; j++)
			CPPUNIT_ASSERT(testBoard.testLocation(i, j, SPACE) == false);
	}
}

void BoardTest::testRemainingPegs(void){
	Board testBoard;
	vector<Peg> remainingPegs;
	testBoard.setupBoard(1);
	remainingPegs = testBoard.remainingPegs();
	CPPUNIT_ASSERT(remainingPegs.size() == 10);
	testBoard.updateBoard('A', SPACE);
	testBoard.updateBoard('D', 'B');
	CPPUNIT_ASSERT(remainingPegs.size() == 8);
}

void BoardTest::testCheckBoard(void){
	Board testBoard;
	testBoard.setupBoard(1);
	testBoard.updateBoard('B', SPACE);
	CPPUNIT_ASSERT(testBoard.checkBoard() == true);
	testBoard.updateBoard('I', 'E');
	testBoard.updateBoard('G', 'H');
	testBoard.updateBoard('J', 'G');
	testBoard.updateBoard('I', 'D');
	testBoard.updateBoard('I', 'E');
	testBoard.updateBoard('I', 'J');
	testBoard.updateBoard('C', 'F');
	testBoard.updateBoard('C', 'I');
	CPPUNIT_ASSERT(testBoard.checkBoard() == false);
}

void BoardTest::testCheckWin(void){
	Board testBoard;
	testBoard.setupBoard(1);
	CPPUNIT_ASSERT(testBoard.checkWin() == false);
	testBoard.updateBoard('B', SPACE);
	testBoard.updateBoard('G', 'D');
	testBoard.updateBoard('A', 'G');
	testBoard.updateBoard('F', 'C');
	testBoard.updateBoard('A', 'E');
	testBoard.updateBoard('J', 'A');
	testBoard.updateBoard('F', 'J');
	testBoard.updateBoard('H', 'I');
	testBoard.updateBoard('H', 'F');
	CPPUNIT_ASSERT(testBoard.checkWin() == true);
}

void BoardTest::setUp(void) {
	mTestObj = new Board();
}

void BoardTest::tearDown(void) {
	delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION (BoardTest);

int main(int argc, char* argv[]) {
	// informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;

	// register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener(&collectedresults);

	// register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);

	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest(
			CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);

	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults,
			std::cerr);
	compileroutputter.write();

	// Output XML for Jenkins CPPunit plugin
	ofstream xmlFileOut("cppBoardTestResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
