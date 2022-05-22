#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;
using namespace std;

TEST_CASE("Calculation") {
    Matrix a ({2,2,2,2}, 2,2);
    Matrix b ({2,2,2,2}, 2,2);
    double c = 5;
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

TEST_CASE("bool"){
    Matrix tmp ({0,0,0,0},2,2);
    Matrix tmp2 ({1,1,1,1},2,2);
    Matrix tmp3 ({2,2,2,2},2,2);
    Matrix tmp4 ({0,0,0,0},2,2);
     
    CHECK_THROWS(bool ans = tmp == tmp2);
    CHECK_THROWS(bool ans =tmp == tmp3);
    CHECK_THROWS(bool ans = tmp2 == tmp3);
    CHECK_THROWS(bool ans = tmp == tmp4);
    CHECK_THROWS(bool ans = tmp == tmp);
    CHECK_THROWS(bool ans = tmp <= tmp2);
    CHECK_THROWS(bool ans = tmp <= tmp3);
    CHECK_THROWS(bool ans = tmp2 <= tmp2);
    CHECK_THROWS(bool ans = tmp >= tmp2);
    CHECK_THROWS(bool ans = tmp >= tmp3);
    CHECK_THROWS(bool ans = tmp2 >= tmp2);
    CHECK_THROWS(bool ans = tmp < tmp2);
    CHECK_THROWS(bool ans = tmp < tmp3);
    CHECK_THROWS(bool ans = tmp2 < tmp2);
    CHECK_THROWS(bool ans = tmp > tmp2);
    CHECK_THROWS(bool ans = tmp > tmp3);
    CHECK_THROWS(bool ans = tmp2 > tmp2);
    CHECK_THROWS(bool ans = tmp != tmp2);
    CHECK_THROWS(bool ans = tmp != tmp3);
    CHECK_THROWS(bool ans = tmp2 != tmp2);
    CHECK_THROWS(bool ans = tmp != tmp4);
}


TEST_CASE("Plus and Minus"){
    Matrix tmp ({0,0,0,0},2,2);
    Matrix tmp2 ({1,1,1,1},2,2);
    Matrix tmp3 ({2,2,2,2},2,2);
    Matrix tmp4 ({0,0,0,0},2,2);
    double skalar = 8;
    CHECK_THROWS(tmp + tmp2);
    CHECK_THROWS(tmp + tmp3);
    CHECK_THROWS(tmp2 + tmp3);
    CHECK_THROWS(tmp + tmp4);
    CHECK_THROWS(tmp - tmp2);
    CHECK_THROWS(tmp  -tmp3);
    CHECK_THROWS(tmp2 - tmp3);
    CHECK_THROWS(tmp - tmp4);
    CHECK(tmp += skalar);
    CHECK(tmp2 += skalar);
    CHECK(tmp3 += skalar);
    CHECK(tmp -= skalar);
    CHECK(tmp2 -= skalar);
    CHECK(tmp3 -= skalar);

}


TEST_CASE("Multiplication"){
    Matrix tmp ({0,0,0,0},2,2);
    Matrix tmp2 ({1,1,1,1},2,2);
    Matrix tmp3 ({2,2,2,2},2,2);
    Matrix tmp4 ({0,0,0,0},2,2);
    double skalar = 4;
    CHECK_THROWS(tmp * skalar);
    CHECK_THROWS(tmp2 * skalar);
    CHECK_THROWS(tmp3 * skalar);
    CHECK_THROWS(skalar * tmp);
    CHECK_THROWS(skalar * tmp2);
    CHECK_THROWS(skalar * tmp3);
    CHECK_THROWS(tmp *= skalar);
    CHECK_THROWS(tmp2 *= skalar);
    CHECK_THROWS(tmp3 *= skalar);
    CHECK_THROWS(tmp2 * tmp);
    CHECK_THROWS(tmp3 * tmp2);
    CHECK_THROWS(tmp * tmp3);
    
}


    

