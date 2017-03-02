//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#ifndef PegTest_h
#define PegTest_h

#include <cppunit/extensions/HelperMacros.h>

using namespace CppUnit;

class PegTest : public TestFixture
{
	CPPUNIT_TEST_SUITE(PegTest);
	CPPUNIT_TEST(testAssignValues);
	/*CPPUNIT_TEST(testUpdatePeg(char current_val));
	CPPUNIT_TEST(testIsValid());
	CPPUNIT_TEST(testSetValidLocation());
	CPPUNIT_TEST(testSetToSpace());
	CPPUNIT_TEST(testGetPeg());
	CPPUNIT_TEST(testGetLayer());
	CPPUNIT_TEST(testGetRow());
	CPPUNIT_TEST(testGetCol());*/
	CPPUNIT_TEST_SUITE_END();

public:
	void setup(void);

	void teardown(void);

protected:
	void testAssignValues();
/*
	void testUpdatePeg();

	void testIsValid();

	void testSetValidLocation();

	void testSetToSpace();

	void testGetPeg();

	void testGetLayer();

	void testGetRow();

	void testGetCol();
*/
};

#endif
