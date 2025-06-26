/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_testContact_init = false;
#include "../unitTest/testContact.h"

static testContact suite_testContact;

static CxxTest::List Tests_testContact = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_testContact( "/Users/codex/Developer/Contact-Manager/backend/unitTest/testContact.h", 11, "testContact", suite_testContact, Tests_testContact );

static class TestDescription_suite_testContact_testPersonClass : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_testContact_testPersonClass() : CxxTest::RealTestDescription( Tests_testContact, suiteDescription_testContact, 13, "testPersonClass" ) {}
 void runTest() { suite_testContact.testPersonClass(); }
} testDescription_suite_testContact_testPersonClass;

static class TestDescription_suite_testContact_testContactClass : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_testContact_testContactClass() : CxxTest::RealTestDescription( Tests_testContact, suiteDescription_testContact, 42, "testContactClass" ) {}
 void runTest() { suite_testContact.testContactClass(); }
} testDescription_suite_testContact_testContactClass;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
