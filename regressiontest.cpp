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

class regressiontest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE (regressiontest);
	CPPUNIT_TEST (testGetBoardRow);
	CPPUNIT_TEST (testGetBoardCol);
	CPPUNIT_TEST (testGetNumBoardPositions);
	CPPUNIT_TEST (testSetupBoard);
	CPPUNIT_TEST (testUpdateBoard);
	CPPUNIT_TEST (testCheckMove);
	CPPUNIT_TEST (testClearBoard);
	CPPUNIT_TEST (testRemainingPegs);
	CPPUNIT_TEST (testCheckBoard);
	CPPUNIT_TEST (testCheckWin);
    CPPUNIT_TEST(testAssignValues);
    CPPUNIT_TEST(testUpdatePeg);
    CPPUNIT_TEST(testGetPeg);
    CPPUNIT_TEST(testGetLayer);
    CPPUNIT_TEST(testGetRow);
    CPPUNIT_TEST(testGetColumn);
    CPPUNIT_TEST(testIsValid);
    CPPUNIT_TEST(testSetInvalidLocation);
    CPPUNIT_TEST(testSetValidLocation);
    CPPUNIT_TEST(testSetToSpace);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(void);
	void tearDown(void);

protected:
	void testGetBoardRow(void);
	void testGetBoardCol(void);
	void testGetNumBoardPositions(void);
	void testSetupBoard(void);
	void testUpdateBoard(void);
	void testCheckMove(void);
	void testClearBoard(void);
	void testRemainingPegs(void);
	void testCheckBoard(void);
	void testCheckWin(void);
    void testAssignValues(void);
    void testUpdatePeg(void);
    void testGetPeg(void);
    void testGetLayer(void);
    void testGetRow(void);
    void testGetColumn(void);
    void testIsValid(void);
    void testSetValidLocation(void);
    void testSetToSpace(void);
    void testSetInvalidLocation(void);

private:
	regressiontest *mTestObj;
};

//-----------------------------------------------------------------------------

void regressiontest::testGetBoardRow(void) {
	Board testBoard;
	CPPUNIT_ASSERT(testBoard.getRow() == -1);
}

void regressiontest::testGetBoardCol(void) {
	Board testBoard;
	CPPUNIT_ASSERT(testBoard.getCol() == -1);
}

void regressiontest::testGetNumBoardPositions(void) {
	Board testBoard;
	CPPUNIT_ASSERT(testBoard.getNumBoardPositions() == -1);
}

void regressiontest::testSetupBoard(void) {
	Board testBoard;
	testBoard.setupBoard(2);
	CPPUNIT_ASSERT(testBoard.getCol() == 13);
	CPPUNIT_ASSERT(testBoard.getRow() == 7);
	CPPUNIT_ASSERT(testBoard.getNumBoardPositions() == 15);
	CPPUNIT_ASSERT(testBoard.testLocation(0, 6, '*') == true);
}

void regressiontest::testUpdateBoard(void) {
	Board testBoard;
	testBoard.updateBoard('A', SPACE);
	CPPUNIT_ASSERT(testBoard.testLocation(1, 6, ' ') == true);
}

void regressiontest::testCheckMove(void) {
	Board testBoard;
	testBoard.setupBoard(1);
	CPPUNIT_ASSERT(testBoard.checkMove('B', 'C') == false);
}

void regressiontest::testClearBoard(void){
	Board testBoard;
	testBoard.setupBoard(1);
	testBoard.clearBoard();
	CPPUNIT_ASSERT(testBoard.testLocation(2, 6, ' ') == true);
}

void regressiontest::testRemainingPegs(void){
	Board testBoard;
	vector<Peg> remainingPegs;
	testBoard.setupBoard(1);
	remainingPegs = testBoard.remainingPegs();
	CPPUNIT_ASSERT(remainingPegs.size() == 10);
}

void regressiontest::testCheckBoard(void){
	Board testBoard;
	testBoard.setupBoard(1);
	testBoard.updateBoard('B', SPACE);
	CPPUNIT_ASSERT(testBoard.checkBoard() == true);
}

void regressiontest::testCheckWin(void){
	Board testBoard;
	testBoard.setupBoard(1);
	CPPUNIT_ASSERT(testBoard.checkWin() == false);
}

void regressiontest::testGetPeg(void)
{
	Peg testPeg;
	CPPUNIT_ASSERT(testPeg.getPeg() == ' ');
}

void regressiontest::testGetLayer(void)
{
	Peg testPeg;
	CPPUNIT_ASSERT(testPeg.getLayer() == -1);
}

void regressiontest::testGetRow(void)
{
	Peg testPeg;
	CPPUNIT_ASSERT(testPeg.getRow() == -1);
}

void regressiontest::testGetColumn(void)
{
	Peg testPeg;
	CPPUNIT_ASSERT(testPeg.getCol() == -1);
}

void regressiontest::testAssignValues(void)
{
    Peg testPeg1;
    testPeg1.assignValues('A', 2, 2, 3);
    CPPUNIT_ASSERT(testPeg1.getPeg() == 'A');
    CPPUNIT_ASSERT(testPeg1.getLayer() == 2);
    CPPUNIT_ASSERT(testPeg1.getRow() == 2);
    CPPUNIT_ASSERT(testPeg1.getCol() == 3);
}

void regressiontest::testUpdatePeg(void)
{
	Peg testPeg;
	testPeg.updatePeg('B');
	CPPUNIT_ASSERT(testPeg.getPeg() == 'B');
}

void regressiontest::testIsValid(void)
{
	Peg testPeg;
	CPPUNIT_ASSERT(false == testPeg.isValid());
}

void regressiontest::testSetValidLocation(void)
{
	Peg testPeg;
	testPeg.setValidLocation();
	CPPUNIT_ASSERT(testPeg.isValid() == true);
}

void regressiontest::testSetInvalidLocation(void)
{
	Peg testPeg;
	testPeg.setInvalidLocation();
	CPPUNIT_ASSERT(testPeg.isValid() == false);
}

void regressiontest::testSetToSpace(void)
{
	Peg testPeg;
	testPeg.setToSpace();
	CPPUNIT_ASSERT(testPeg.getPeg() == ' ');
}


void regressiontest::setUp(void) {
	mTestObj = new regressiontest();
}

void regressiontest::tearDown(void) {
	delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION (regressiontest);

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
	ofstream xmlFileOut("cppRegressionTestResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
