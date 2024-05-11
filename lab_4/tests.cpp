#include "include/App.hpp"
#include "doctest.h"

#include <sstream>
#include <streambuf>

constexpr auto eps = 1e-6;
constexpr auto pi = 3.1415926535;;

TEST_CASE("Circles") {
    lab_4::App app;

    std::streambuf* previous_cin_buf = std::cin.rdbuf();

    std::istringstream input("1 1 1 1");
    std::cin.rdbuf(input.rdbuf());

    app.addCircle();
    auto cm = app.centerOfMass();
    CHECK(cm.x == 1);
    CHECK(cm.y == 1);

    CHECK(app.allMemory() == 72);
    CHECK(abs(app.allSquare() - pi) < eps);
    CHECK(abs(app.allPerimeter() - 2 * pi) < eps);


    std::cin.rdbuf(previous_cin_buf);
}


TEST_CASE("Triangles") {
    lab_4::App app;

    std::streambuf* previous_cin_buf = std::cin.rdbuf();

    std::istringstream input("1 1 3 3 4 0");
    std::cin.rdbuf(input.rdbuf());

    app.addTriangle();
    auto cm = app.centerOfMass();
    CHECK(abs(cm.x - 2.6666666666) < eps);
    CHECK(abs(cm.y - 1.3333333334) < eps);
    CHECK(abs(app.allSquare() - 3.4641016151) < eps);
    CHECK(abs(app.allPerimeter() - 8.4852813742) < eps);

    std::cin.rdbuf(previous_cin_buf);
}

TEST_CASE("Circles and triangles") {
    lab_4::App app;

    std::streambuf* previous_cin_buf = std::cin.rdbuf();

    std::istringstream input("1 1 1 1 1 1 3 3 4 0");
    std::cin.rdbuf(input.rdbuf());

    app.addCircle();
    app.addTriangle();

    CHECK(abs(app.allSquare() - (pi + 3.4641016151)) < eps);
    CHECK(abs(app.allPerimeter() - (8.4852813742 + 2 * pi)) < eps);

    std::cin.rdbuf(previous_cin_buf);
}