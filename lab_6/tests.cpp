#include <stdexcept>
#include <vector>

#include "include/lab_6.hpp"
#include "doctest.h"

TEST_CASE("all_of") {
    auto is_even = [](int a) -> bool {
        return !(a % 2);
    };

    std::vector<int> v = {1, 2, 3, 4, 5};
    CHECK(!lab_6::all_of(v.begin(), v.end(), is_even));

    for (auto& i : v) i *= 2;
    CHECK(lab_6::all_of(v.begin(), v.end(), is_even));
}

TEST_CASE("any_of") {
    auto is_not_null = [](int a) -> bool {
        return a;
    };

    std::vector<int> v = {0, 0, 1, 0, 0, 1, 0, 1};
    CHECK(lab_6::any_of(v.begin(), v.end(), is_not_null));

    std::erase_if(v, [](const auto& x) -> bool { return x; });
    CHECK(!lab_6::any_of(v.begin(), v.end(), is_not_null));
}

TEST_CASE("none_of") {
    auto is_odd = [](int a) -> bool {
        return (a % 2);
    };

    std::vector<int> v = {2, 4, 6, 8, 10};
    CHECK(lab_6::none_of(v.begin(), v.end(), is_odd));

    v.push_back(1);
    CHECK(!lab_6::none_of(v.begin(), v.end(), is_odd));
}

TEST_CASE("one_of") {
    auto is_one = [](int a) -> bool {
        return a == 1;
    };

    std::vector<int> v = {0, 0, 1, 0, 0, 0, 0};
    CHECK(lab_6::one_of(v.begin(), v.end(), is_one));

    v.push_back(1);
    CHECK(!lab_6::one_of(v.begin(), v.end(), is_one));
}

TEST_CASE("is_sorted") {
    auto comp = [](int a, int b) -> bool {
        return a < b;
    };

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 1, 2, 3};
    //                                      ^                 last = v.begin() + 6
    //                                         ^          last = v.begin() + 7
    CHECK(lab_6::is_sorted(v.begin(), v.begin() + 6, comp));

    v.push_back(1);
    CHECK(!lab_6::is_sorted(v.begin(), v.begin() + 7, comp));
}

TEST_CASE("is_partitioned") {
    auto is_eleven = [](int a) -> bool {
        return a == 11;
    };

    std::vector<int> v = {1, 11, 3, 4, 5};
    CHECK(!lab_6::is_partitioned(v.begin(), v.end(), is_eleven));

    v[0] = 11;
    CHECK(lab_6::is_partitioned(v.begin(), v.end(), is_eleven));
}

TEST_CASE("find_not") {
    std::vector<int> v = {1, 1, 1, 1, 1, 2, 3, 4, 5, 6};
    CHECK(lab_6::find_not(v.begin(), v.end(), 1) == v.begin() + 5);
    CHECK(lab_6::find_not(v.begin(), v.end(), 2) == v.begin());

    CHECK_THROWS_AS(lab_6::find_not(v.begin(), v.begin() + 5, 1), std::runtime_error);
}

TEST_CASE("find_backward") {
    std::vector<int> v = {1, 1, 1, 1, 1, 2, 3, 4, 5, 6};
    CHECK(lab_6::find_backward(v.begin(), v.end(), 5) == v.end() - 2);
    CHECK(lab_6::find_backward(v.begin(), v.end(), 6) == v.end() - 1);

    CHECK_THROWS_AS(lab_6::find_backward(v.begin(), v.end(), 0), std::runtime_error);
}

TEST_CASE("is_palindrome") {
    auto pred = [](char a, char b) -> bool {
        return a == b;
    };

    std::string not_palindrome = "abbabababbbbbb";
    CHECK(!lab_6::is_palindrome(not_palindrome.begin(), not_palindrome.end(), pred));

    std::string palindrome = "abacaba";
    CHECK(lab_6::is_palindrome(palindrome.begin(), palindrome.end(), pred));
}

struct CPoint {
    int x, y;
};

TEST_CASE("all_of my structures") {
    auto on_the_axes = [](const CPoint& a) -> bool {
        return a.x == 0 || a.y == 0;
    };

    std::vector<CPoint> points = {{.x=0, .y=1}, {.x=0, .y=0}, {.x=1, .y=0}, {.x=-1, .y=-1}};
    CHECK(!lab_6::all_of(points.begin(), points.end(), on_the_axes));

    points.pop_back();
    CHECK(lab_6::all_of(points.begin(), points.end(), on_the_axes));
}
