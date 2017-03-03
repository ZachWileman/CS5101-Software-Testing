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
	CPPUNIT_ASSERT(testBoard.testLocation(1, 6, ' ') == true);
}

void BoardTest::testCheckMove(void) {
	Board testBoard;
	testBoard.setupBoard(1);
	CPPUNIT_ASSERT(testBoard.checkMove('B', 'C') == false);
}

void BoardTest::testClearBoard(void){
	Board testBoard;
	testBoard.setupBoard(1);
	testBoard.clearBoard();
	CPPUNIT_ASSERT(testBoard.testLocation(2, 6, ' ') == true);
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
