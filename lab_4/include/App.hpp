#pragma once

#include <memory>
#include <vector>

#include "Circle.hpp"
#include "Figure.hpp"
#include "Triangle.hpp"

namespace lab_4 {

class App {
public:
    App() = default;

    void addCircle() {
        Circle circle;
        circle.initFromDialog();
        figures_.push_back(std::make_unique<Circle>(circle));
    }

    void addTriangle() {
        Triangle trian;
        trian.initFromDialog();
        figures_.push_back(std::make_unique<Triangle>(trian));
    }

    void printAllFigure() const {
        for (const auto& f : figures_) {
            f->draw();
            std::cout << std::endl;
        }
    }

    double allSquare() const {
        double res = 0.;
        for (const auto& f : figures_) {
            res += f->square();
        }
        return res;
    }

    double allPerimeter() const {
        double res = 0.;
        for (const auto& f : figures_) {
            res += f->perimeter();
        }
        return res;
    }

    Vector2D centerOfMass() const {
        double x = 0.;
        double y = 0.;
        double m = 0.;
        for (const auto& f : figures_) {
            x += (f->mass() * f->position().x);
            y += (f->mass() * f->position().y);
            m += f->mass();
        }
        return {.x = x / m, .y = y / m};
    }

    uint allMemory() const {
        uint res = 0;
        for (const auto& f : figures_) {
            res += f->size();
        }
        return res;
    }

    void sortByMass() {
        std::sort(figures_.begin(), figures_.end());
    }
private:
    std::vector<std::unique_ptr<Figure>> figures_;
};

}  // namespace lab_4
