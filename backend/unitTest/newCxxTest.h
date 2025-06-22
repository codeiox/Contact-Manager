//"copyright 2025"

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
// Include your classes header file(s) below and uncomment.
// #include "myClass.h"

class newCxxTest : public CxxTest::TestSuite {
   public:
    // test
    static void testExample() { TS_ASSERT(true); }
};
#endif /* NEWCXXTEST_H */
