#include <iostream>
#include <sstream>

#include "include/lab_3.hpp"
#include "doctest.h"

TEST_CASE("explicit >>, 1 element") {
    auto stack = lab_3::Stack();
    std::istringstream iss("12");
    iss >> stack;

    CHECK(stack.size() == 1);
    CHECK(stack.back() == 12);
}

TEST_CASE(">>, 1 element") {
    lab_3::Stack stack;
    std::istringstream iss("12");
    iss >> stack;

    CHECK(stack.size() == 1);
    CHECK(stack.back() == 12);
}

TEST_CASE("explicit <<, 1 element") {
    auto stack = lab_3::Stack();
    int x = 10;
    stack.add(x);
    std::cout << stack;

    CHECK(!stack.size()); 
}

TEST_CASE("<<, 1 element") {
    lab_3::Stack stack;
    int x = 10;
    stack.add(x);
    std::cout << stack;

    CHECK(!stack.size()); 
}

TEST_CASE(">>, <<") {
    lab_3::Stack stack;

    int n = 5;
    std::string s;
    for (int i = 0; i < n; i++) {
        s += std::to_string(i) + " ";
    }

    std::istringstream iss(s);
    for (int i = 0; i < 5; i++) {
        iss >> stack;
    }

    CHECK(stack.size() == 5);

    std::ostringstream os;
    for (int i = 0; i < 5; i++) {
        os << stack;
    }

    s.erase(remove_if(s.begin(), s.end(), isspace), s.end());
    std::reverse(s.begin(), s.end());

    CHECK(os.str() == s);
    CHECK(!stack.size());
}