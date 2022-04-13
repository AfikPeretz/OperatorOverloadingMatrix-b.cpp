#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;
using namespace std;

TEST_CASE("Calculation") {
    Matrix a ({2,2,2,2}, 2,2);
    Matrix b ({2,2,2,2}, 2,2);
    double c = 5;
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
    CHECK_THROWS( a + b);
   
    // CHECK( a == b);
    // CHECK( a <= b);
    // CHECK( a >= b);
    // CHECK( a < b);
    // CHECK( a < b);
    // CHECK_THROWS(a+b);
    // CHECK_THROWS(a*b);
    // CHECK_THROWS(a*=b);
    // CHECK_THROWS(a<=b);
    // CHECK_THROWS(a>=b);
    // CHECK_THROWS(a+=b);
    // CHECK_THROWS(a-=b);
    // CHECK_THROWS(a*=c);
    // CHECK_THROWS(b*=c);
    // CHECK_THROWS(a*b);
    // CHECK_THROWS(a*c < b);
    // CHECK_THROWS(b*c < a);
    // CHECK_THROWS(a*a*a <= b*b*b);
    // CHECK_THROWS(c*a);
    // CHECK_THROWS(c*b == a);
}