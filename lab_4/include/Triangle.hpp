#pragma once

#include <iostream>

#include "Vector2D.hpp"
#include "IPhysObject.hpp"
#include "Figure.hpp"

namespace lab_4 {

namespace {

double sqr(double a) {
    return a * a;
}

}  // namespace

class Triangle : public Figure {
private:
    Vector2D point_1_, point_2_, point_3_;
    double weight_;

    double get_a() const {
        return sqrt(sqr(point_1_.x - point_2_.x) + sqr(point_1_.y - point_2_.y));
    }

public:
    Triangle() = default;
    Triangle(const Vector2D& point_1, const Vector2D& point_2, const Vector2D& point_3): point_1_(point_1), point_2_(point_2), point_3_(point_3) {}

    double square() const override {
        return sqr(get_a()) * sqrt(3) / 4;
    }

    double perimeter() const override {
        return get_a() * 3;
    }

    double mass() const override {
        return weight_;
    }

    Vector2D position() const override {
        return {
            .x = (point_1_.x + point_2_.x + point_3_.x) / 3,
            .y = (point_1_.y + point_2_.y + point_3_.y) / 3
        };
    }

    bool operator== (const IPhysObject& obj) const override {
        return mass() == obj.mass();
    }

    bool operator< (const IPhysObject& obj) const override {
        return mass() < obj.mass();
    }

    void draw() const override {
        std::cout << "triange coordinates: " << point_1_ << ", " << point_2_ << ", " << point_3_;
    }

    void initFromDialog() override {
        std::cout << "print 3 triangle points";
        std::cin >> point_1_ >> point_2_ >> point_3_;
    }

    const char* classname() override {
        return "Triangle";
    }

    unsigned int size() const override {
        return sizeof(Triangle);
    }
};

}  // namespace lab_4
