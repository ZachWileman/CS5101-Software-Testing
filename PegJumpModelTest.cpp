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

#include "PegJumpModel.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class PegJumpModelTest: public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE (PegJumpModelTest);
	CPPUNIT_TEST (testAutoSolver);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp(void);
	void tearDown(void);

protected:
	void testAutoSolver(void);

private:
	PegJumpModelTest *mTestObj;
};

//-----------------------------------------------------------------------------

void PegJumpModelTest::testAutoSolver(void){
	Board testBoard;
	PegJumpModel Model;
	vector<Peg> remPegs;
	vector<char> solutionList;
	char expectedList[16] = {'G', 'D', 'A', 'G', 'F', 'C', 'A', 'E', 'J', 'A', 'F', 'J', 'H', 'I', 'H', 'F'};

	testBoard.setupBoard(1);
	testBoard.updateBoard('B', SPACE);
	CPPUNIT_ASSERT(Model.autoSolver(testBoard, remPegs, solutionList) == true);
	for(int i = 0; i < solutionList.size(); i++)
		CPPUNIT_ASSERT( solutionList[i] == expectedList[i]);
}

void PegJumpModelTest::setUp(void) {
	mTestObj = new PegJumpModelTest();
}

void PegJumpModelTest::tearDown(void) {
	delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION (PegJumpModelTest);

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
	ofstream xmlFileOut("cppPegJumpModelTestResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
