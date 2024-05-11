#pragma once

#include "Vector2D.hpp"

namespace lab_4 {

class IPhysObject {
public:
    virtual double mass() const = 0;
    virtual Vector2D position() const = 0;
    virtual bool operator== (const IPhysObject& obj) const = 0;
    virtual bool operator< (const IPhysObject& obj) const = 0;
};

}  // namespace lab_4
