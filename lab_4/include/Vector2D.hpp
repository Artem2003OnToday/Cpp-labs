#pragma once

#include <iostream>

namespace lab_4 {

class Vector2D {
public:
    double x, y;
};

inline std::ostream& operator <<(std::ostream &os, const Vector2D& v) {
    return os << "x = " << v.x << ", y = " << v.y;
}

inline std::istream& operator >>(std::istream& in, Vector2D& v) {
    in >> v.x >> v.y;
    return in;
}

}  // namespace lab_4
