#pragma once

#include <iostream>

#include "Vector2D.hpp"
#include "IPhysObject.hpp"
#include "Figure.hpp"

namespace lab_4 {

namespace {
constexpr auto pi = 3.1415926535;
}  // namespace

class Circle : public Figure {
private:
    Vector2D center_;
    double radius_;
    double weight_;

public:
    Circle() = default;
    Circle(const Vector2D& center, double radius, double weight): center_(center), radius_(radius), weight_(weight) {}

    double square() const override {
        return pi * radius_ * radius_;
    }

    double perimeter() const override {
        return 2 * pi * radius_;
    }

    double mass() const override {
        return weight_;
    }

    Vector2D position() const override {
        return center_;
    }

    bool operator== (const IPhysObject& obj) const override {
        return mass() == obj.mass();
    }

    bool operator< (const IPhysObject& obj) const override {
        return mass() < obj.mass();
    }

    void draw() const override {
        std::cout << "center = " << center_ << ", radius = " << radius_ << ", weight = " << weight_;
    }

    void initFromDialog() override {
        std::cout << "print center point: ";
        std::cin >> center_;
        std::cout << "print radius: ";
        std::cin >> radius_;
        std::cout << "print weight: ";
        std::cin >> weight_;
    }

    const char* classname() override {
        return "Circle";
    }

    unsigned int size() const override {
        return sizeof(Circle);
    }
};

}  // namespace lab_4
