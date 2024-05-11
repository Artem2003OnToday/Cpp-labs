#include "src/lab_1.cpp"
#include "doctest.h"

TEST_CASE("& cases") {
    int a = 5;
    int b = 6;
    lab_1::swap(a, b);
    CHECK(a == 6);
    CHECK(b == 5);
}

TEST_CASE("pointer (*) cases") {
    int a = 5;
    int b = 6;
    int *pa = &a; // *pa = 5
    int *pb = &b; // *pb = 6

    lab_1::swap(pa, pb);
    // CHECK(pa == &b); pa == &a, if we want to swap address, 
    // CHECK(pb == &a); pa == &b     we need use *& or **
    CHECK(*pa == 5);
    CHECK(*pb == 6);
}
