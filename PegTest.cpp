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

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class PegTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(PegTest);
    CPPUNIT_TEST(testAssignValues);
    CPPUNIT_TEST(testUpdatePeg);
    CPPUNIT_TEST(testGetPeg);
    CPPUNIT_TEST(testGetLayer);
    CPPUNIT_TEST(testGetRow);
    CPPUNIT_TEST(testGetColumn);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testAssignValues(void);
    void testUpdatePeg(void);
    void testGetPeg(void);
    void testGetLayer(void);
    void testGetRow(void);
    void testGetColumn(void);

private:
    Peg *mTestObj;
};

//-----------------------------------------------------------------------------

void PegTest::testGetPeg(void)
{
	Peg testPeg;
	CPPUNIT_ASSERT(testPeg.getPeg() == ' ');
}

void PegTest::testGetLayer(void)
{
	Peg testPeg;
	CPPUNIT_ASSERT(testPeg.getLayer() == -1);
}

void PegTest::testGetRow(void)
{
	Peg testPeg;
	CPPUNIT_ASSERT(testPeg.getRow() == -1);
}

void PegTest::testGetColumn(void)
{
	Peg testPeg;
	CPPUNIT_ASSERT(testPeg.getCol() == -1);
}

void PegTest::testAssignValues(void)
{
    Peg testPeg1;
    testPeg1.assignValues('A', 2, 2, 3);
    CPPUNIT_ASSERT(testPeg1.getPeg() == 'A');
    CPPUNIT_ASSERT(testPeg1.getLayer() == 2);
    CPPUNIT_ASSERT(testPeg1.getRow() == 2);
    CPPUNIT_ASSERT(testPeg1.getCol() == 3);
}

void PegTest::testUpdatePeg(void)
{
	Peg testPeg;
	testPeg.updatePeg('B');
	CPPUNIT_ASSERT(testPeg.getPeg() == 'B');
}

void PegTest::setUp(void)
{
    mTestObj = new Peg();
}

void PegTest::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( PegTest );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppPegTestResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
