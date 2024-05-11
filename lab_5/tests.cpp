#include "include/lab_5.hpp"
#include "doctest.h"

TEST_CASE("find minimum from int") {
    int a = 1;
    int b = 4;

    CHECK(lab_5::FindMinimumFromTwo(a, b) == a);
    std::swap(a, b); // a = 4, b = 1
    CHECK(lab_5::FindMinimumFromTwo(a, b) == b);

    a = 1;
    CHECK(lab_5::FindMinimumFromTwo(a, b) == a);
}

TEST_CASE("find minimum from string") {
    std::string a = "1101010avadfds";
    std::string b = "a0110120adfjav";

    CHECK(lab_5::FindMinimumFromTwo(a, b) == a);
}

TEST_CASE("my type") {
    struct Type {
        int a, b;
        bool operator< (const Type& tp) const {
            return a * b < tp.a * tp.b;
        }
        bool operator== (const Type& tp) const {
            return a == tp.a && b == tp.b;
        }
    };

    Type a{.a = 1, .b = 8};
    Type b{.a = 3, .b = 5};

    CHECK(lab_5::FindMinimumFromTwo(a, b) == a);
}

TEST_CASE("array of strings") {
    lab_5::Array<10, std::string> ar;

    ar[0] = "1";
    CHECK(ar[0] == "1");
    CHECK_THROWS_AS(ar[10], lab_5::OutOfBounds);
}