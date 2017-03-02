//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include "../Peg.h"

using namespace std;

void PegTest::setup()
{
	//empty
}

void PegTest::teardown()
{
	//empty
}


void PegTest::testAssignValues()
{
	Peg testPeg1;
	testPeg1.assignValues('A', 2, 2, 3);
	CPPUNIT_ASSERT(testPeg1.getPeg() == 'A');
}

void PegTest::testUpdatePeg()
{
	CPPUNIT_ASSERT();
}

void PegTest::testIsValid()
{
	CPPUNIT_ASSERT();
}

void PegTest::testSetValidLocation()
{
	CPPUNIT_ASSERT();
}

void PegTest::testSetToSpace()
{
	CPPUNIT_ASSERT();
}

void PegTest::testGetPeg()
{
	CPPUNIT_ASSERT();
}

void PegTest::testGetLayer()
{
	CPPUNIT_ASSERT();
}

void PegTest::testGetRow()
{
	CPPUNIT_ASSERT();
}

void PegTest::testGetCol()
{
	CPPUNIT_ASSERT();
}